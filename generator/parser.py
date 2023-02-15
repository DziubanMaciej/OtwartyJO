from bison import BisonParser
from nodes import *

import utils


class OpenclHeaderParser(BisonParser):
    def __init__(self, **kwargs):
        self.bisonEngineLibName = self.__class__.__name__ + "_engine"

        self.options = [
            "%define api.pure full",
            "%define api.push-pull push",
            "%lex-param {yyscan_t scanner}",
            "%parse-param {yyscan_t scanner}",
            "%define api.value.type {void *}",
        ]

        tokens = [[x.strip() for x in y.split("=")] for y in self.__doc__.split("\n") if y.strip() != "" and not y.strip().startswith("//")]

        self.precedences = ()

        self.start = "file"
        return_location = kwargs.pop("return_location", False)
        if return_location:
            fmt = "{} {{ returntoken_loc({}); }}"
        else:
            fmt = "{} {{ returntoken({}); }}"
        lex_rules = "\n".join([fmt.format(*x) if x[1][0] != "_" else "{} {{ {} }}".format(x[0], x[1][1:]) for x in tokens])

        self.tokens = list(set([x[1] for x in tokens if not x[1].startswith("_")]))
        self.tokens.append("CL_VERSION_MACROS_DEFINITION")
        self.tokens = sorted(self.tokens)
        self.lexscript = (
            r"""
%option reentrant bison-bridge bison-locations
%{
// Start node is: """
            + self.start
            + r"""
#include "tmp.tab.h"
#include "Python.h"
extern void *py_parser;
extern void (*py_input)(PyObject *parser, char *buf, int *result, int max_size);
PyMODINIT_FUNC PyInit_Parser(void) { /* windows needs this function */ }
#define returntoken(tok)                                       \
        *yylval = (void*)PyUnicode_FromString(strdup(yytext)); \
        return tok;
#define YY_INPUT(buf,result,max_size) {                        \
    (*py_input)(py_parser, buf, &result, max_size);            \
}
%}

%x C_COMMENT
%x C_CL_VERSION_MACROS_DEFINITION

%%

"/*"            { BEGIN(C_COMMENT); }
<C_COMMENT>"*/" { BEGIN(INITIAL); }
<C_COMMENT>\n   { }
<C_COMMENT>.    { }

#ifdef\ CL_VERSION_3_0\n\n\/\*\ cl_version\ \*\/ { BEGIN(C_CL_VERSION_MACROS_DEFINITION); }
<C_CL_VERSION_MACROS_DEFINITION>#endif { BEGIN(INITIAL); returntoken(CL_VERSION_MACROS_DEFINITION); }
<C_CL_VERSION_MACROS_DEFINITION>\n   { }
<C_CL_VERSION_MACROS_DEFINITION>.    { }

"""
            + lex_rules
            + """
%%
int yywrap(yyscan_t scanner) { return 1; }
    """
        )
        super().__init__(**kwargs)


class OpenclHeaderParser(OpenclHeaderParser):
    r"""
    //--------------------- OpenCL Keywords
    CL_API_ENTRY                                                 = CL_API_ENTRY
    CL_API_CALL                                                  = CL_API_CALL
    CL_API_SUFFIX__VERSION_[0-9]_[0-9](_DEPRECATED)?             = CL_API_SUFFIX
    CL_API_PREFIX__VERSION_[0-9]_[0-9]_DEPRECATED                = CL_API_PREFIX_DEPRECATED
    CL_CALLBACK                                                  = CL_CALLBACK
    extern                                                       = EXTERN


    //--------------------- Literals
    -?[0-9]+                                                     = INTEGER
    0x[0-9A-Fa-f]+                                               = INTEGER_HEX
    "(1 << "[0-9][0-9]*")"                                       = BITSHIFT_EXPRESSSION
    -?[0-9]+([.][0-9]+)?([eE]-?[0-9]+)?                          = FLOAT
    false|true|null                                              = BOOL
    \"([^\"]|\\[.])*\"                                           = STRING
    \<([^\>]|\\[.])*\>                                           = STRING_IN_ANGLE_BRACKETS

    //---------------------------- C++ keywords
    typedef                                                      = TYPEDEF
    struct                                                       = STRUCT
    const                                                        = CONST
    unsigned\ char                                               = UNSIGNED_CHAR
    void                                                         = VOID
    [a-zA-Z_][a-zA-Z0-9_]*                                       = IDENTIFIER

    //----------------------------- Signs
    ;                                                            = SEMICOLON
    "*"                                                          = ASTERISK
    "+"                                                          = PLUS
    ","                                                          = COMMA
    "{"                                                          = CURLY_BRACE_L
    "}"                                                          = CURLY_BRACE_R
    "["                                                          = BRACKET_L
    "]"                                                          = BRACKET_R
    "("                                                          = PARENTHESIS_L
    ")"                                                          = PARENTHESIS_R

    //------------------------------- Preprocessor
    #ifdef                                                       = IFDEF
    #ifndef                                                      = IFNDEF
    #endif                                                       = ENDIF
    #define                                                      = DEFINE
    #include                                                     = INCLUDE
    #pragma                                                      = PRAGMA
    #if                                                          = IF_MACRO
    #else                                                        = ELSE_MACRO

    //-------------------------------- Black magic (don't even ask)
    typedef\ struct\ _cl_image_desc\ \{[^^]*\}\ cl_image_desc;   = CL_IMAGE_DESC_DEFINITION

    //---------------------------------- Ignores
    [ \t\n]                                                      = _
    """

    @staticmethod
    def on_file(target, option, names, values):
        """
        file : line_section
        """
        return File(values[0])

    @staticmethod
    def on_line_section(target, option, names, values):
        """
        line_section : line | line_section line
        """
        return utils.flatten_list(values)

    @staticmethod
    def on_line(target, option, names, values):
        """
        line : typedef | ifdef  | struct | cl_image_desc | value_define | cl_version_macros_definition | function | ignored
        """
        return values[0]

    @staticmethod
    def on_ifdef(target, option, names, values):
        """
        ifdef : IFDEF IDENTIFIER line_section ENDIF
        """
        return Ifdef(values[1], values[2])

    @staticmethod
    def on_typedef(target, option, names, values):
        """
        typedef :
          TYPEDEF IDENTIFIER IDENTIFIER SEMICOLON
        | TYPEDEF STRUCT IDENTIFIER ASTERISK IDENTIFIER SEMICOLON
        """
        if len(values) == 4:
            defined_type = values[2]
        elif len(values) == 6:
            defined_type = values[4]
        else:
            utils.error("Unreachable code")
        return Typedef(defined_type)

    @staticmethod
    def on_struct(target, option, names, values):
        """
        struct : TYPEDEF STRUCT IDENTIFIER CURLY_BRACE_L fields CURLY_BRACE_R IDENTIFIER SEMICOLON
        """
        return Struct(values[6], values[4])

    @staticmethod
    def on_fields(target, option, names, values):
        """
        fields : field | fields field
        """
        return utils.flatten_list(values)

    @staticmethod
    def on_field(target, option, names, values):
        """
        field :
            IDENTIFIER IDENTIFIER SEMICOLON
        |   IDENTIFIER IDENTIFIER BRACKET_L IDENTIFIER BRACKET_R SEMICOLON
        |   IDENTIFIER IDENTIFIER BRACKET_L BRACKET_R SEMICOLON
        """
        if names[2] == "SEMICOLON":
            return Field(values[0], values[1], None)
        if names[2] == "BRACKET_L":
            if names[3] == "IDENTIFIER":
                return Field(values[0], values[1], values[3])
            if names[3] == "BRACKET_R":
                return Field(values[0], values[1], "")
        utils.error("Unreachable code")

    @staticmethod
    def on_cl_image_desc(target, option, names, values):
        """
        cl_image_desc : IFDEF IDENTIFIER CL_IMAGE_DESC_DEFINITION ENDIF
        """

        # Don't even ask what is going on here.
        value = Struct(
            "cl_image_desc",
            [
                Field("cl_mem_object_type", "image_type"),
                Field("size_t", "image_width"),
                Field("size_t", "image_height"),
                Field("size_t", "image_depth"),
                Field("size_t", "image_array_size"),
                Field("size_t", "image_row_pitch"),
                Field("size_t", "image_slice_pitch"),
                Field("cl_uint", "num_mip_levels"),
                Field("cl_uint", "num_samples"),
                Field("cl_mem", "buffer"),
            ],
        )
        value = Ifdef(values[1], [value])
        return value

    @staticmethod
    def on_cl_version_macros_definition(target, option, names, values):
        """
        cl_version_macros_definition : CL_VERSION_MACROS_DEFINITION
        """

        # Better don't ask about this as well
        value = [
            ValueDefine("CL_VERSION_MAJOR_BITS", False),
            ValueDefine("CL_VERSION_MINOR_BITS", False),
            ValueDefine("CL_VERSION_PATCH_BITS", False),
            ValueDefine("CL_VERSION_MAJOR_MASK", False),
            ValueDefine("CL_VERSION_MINOR_BITS", False),
            ValueDefine("CL_VERSION_PATCH_BITS", False),
            ValueDefine("CL_VERSION_MAJOR", True),
            ValueDefine("CL_VERSION_MINOR", True),
            ValueDefine("CL_VERSION_PATCH", True),
            ValueDefine("CL_MAKE_VERSION", True),
        ]
        value = Ifdef("CL_VERSION_3_0", value)
        return value

    @staticmethod
    def on_value_define(target, option, names, values):
        """
        value_define :
            DEFINE IDENTIFIER INTEGER
        |   DEFINE IDENTIFIER INTEGER_HEX
        |   DEFINE IDENTIFIER BITSHIFT_EXPRESSSION
        |   DEFINE IDENTIFIER IDENTIFIER
        """
        return ValueDefine(values[1], False)

    @staticmethod
    def on_type(target, option, names, values):
        """
        type :
            CONST type
        |   type ASTERISK
        |   IDENTIFIER
        |   UNSIGNED_CHAR
        |   VOID
        """
        if option == 0:
            return DataType(values[1], prefixes=["const"])
        elif option == 1:
            return DataType(values[0], suffixes=["*"])
        else:
            return DataType(values[0])

    @staticmethod
    def on_function_prefix(target, option, names, values):
        """
        function_prefix : CL_API_ENTRY | CL_API_ENTRY CL_API_PREFIX_DEPRECATED
        """
        return " ".join(values)

    @staticmethod
    def on_function(target, option, names, values):
        """
        function : EXTERN function_prefix type CL_API_CALL IDENTIFIER PARENTHESIS_L function_arguments PARENTHESIS_R CL_API_SUFFIX SEMICOLON
        """
        prefix = values[1]
        return_type = values[2]
        name = values[4]
        arguments = values[6]
        suffix = values[8]
        return Function(prefix, return_type, name, arguments, suffix)

    @staticmethod
    def on_function_arguments(target, option, names, values):
        """
        function_arguments :
            function_argument
        |   function_arguments COMMA function_argument
        |
        """
        return utils.flatten_list(values, with_separator=True)

    @staticmethod
    def on_function_argument(target, option, names, values):
        """
        function_argument :
            type PARENTHESIS_L CL_CALLBACK ASTERISK IDENTIFIER PARENTHESIS_R PARENTHESIS_L function_arguments PARENTHESIS_R
        |   type IDENTIFIER
        |   type IDENTIFIER BRACKET_L BRACKET_R
        |   type
        """
        if option == 0:
            return FunctionPointerFunctionArgument(values[0], values[4], values[7])
        elif option == 1:
            return FunctionArgument(values[0], values[1])
        elif option == 2:
            return FunctionArgument(values[0], values[1], "[]")
        elif option == 3:
            return FunctionArgument(values[0], "")
        else:
            utils.error("Unreachable code")

    @staticmethod
    def on_ignored(target, option, names, values):
        """
        ignored : IFDEF IDENTIFIER CURLY_BRACE_R ENDIF
        """
        return Ignored()
