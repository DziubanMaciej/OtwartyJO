from translations import lookup_type_mapping, lookup_variable_name_mapping, lookup_define_mapping_mapping, lookup_function_mapping
import utils


class Node:
    def generate_h(self):
        return None

    def generate_c(self):
        return None

all_function_names = []

class File(Node):
    def __init__(self, lines):
        self._lines = [
            Typedef("size_t"),
            Typedef("char"),
            Typedef("cl_int"),
            Typedef("cl_uint"),
            Typedef("void"),
            Typedef("cl_ulong"),
            Typedef("unsigned char"),
        ]
        self._lines += lines

    def generate_h(self):
        prefix = """#include <CL/cl.h>

#ifdef __cplusplus
extern "C" {
#endif

"""
        content = (x.generate_h() for x in self._lines)
        content = (x for x in content if x)
        content = "\n".join(content)
        suffix = """
#ifdef __cplusplus
}
#endif
"""
        return prefix + content + suffix

    def generate_c(self):
        prefix = """#define CL_USE_DEPRECATED_OPENCL_1_0_APIS
#define CL_TARGET_OPENCL_VERSION 300
#ifdef __GNUC__
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
#endif
#include <JO/jo.h>
#include "jo_utils.h"

"""
        content = (x.generate_c() for x in self._lines)
        content = (x for x in content if x)
        content = "\n".join(content)
        return prefix + self.generate_initialization_function() + content

    def generate_initialization_function(self):
        all_function_initializations = [ f"INITIALIZE_FUNCTION({x})" for x in all_function_names]
        all_function_initializations = "\n".join(all_function_initializations)
        all_function_initializations = utils.indent(all_function_initializations)
        all_function_initializations = utils.indent(all_function_initializations)
        return f"""int _joZaincjalizowano = 0; // TODO not thread safe
pustka _joInicjalizuj() {{
    if (_joZaincjalizowano) return;
    _joZaincjalizowano = 1;
    loadOpenclLibrary();
    if (openclLibrary) {{
{all_function_initializations}
    }}
}}
"""


class Typedef(Node):
    def __init__(self, defined_type):
        self._defined_type = defined_type
        self._mapped_type = lookup_type_mapping(defined_type)

    def generate_h(self):
        return f"typedef {self._defined_type} {self._mapped_type};"


class ValueDefine(Node):
    def __init__(self, defined_name, is_macro):
        self._original_name = defined_name
        self._name = lookup_define_mapping_mapping(defined_name)
        self._is_macro = is_macro

    def generate_h(self):
        result = f"#define {self._name}"
        if self._is_macro:
            result += "(...)"
        result += f" {self._original_name}"
        if self._is_macro:
            result += "(__VA_ARGS__)"
        return result

    def generate_c(self):
        return ""


class Field(Node):
    def __init__(self, typename, name, array_size=None):
        self._typename = lookup_type_mapping(typename)
        self._name = lookup_variable_name_mapping(name)
        self._array_size = array_size

    def generate_h(self):
        if self._array_size is not None:
            array_suffix = f"[{self._array_size}]"
        else:
            array_suffix = ""
        return f"{self._typename} {self._name}{array_suffix}"


class Function(Node):
    def __init__(self, prefix, return_type, name, arguments, suffix):
        self._prefix = prefix
        self._return_type = return_type
        self._original_name = name
        self._name = lookup_function_mapping(name)
        self._arguments = arguments
        self._suffix = suffix

        all_function_names.append(self._original_name)

    def generate_h(self):
        arguments = (x.generate_h() for x in self._arguments)
        arguments = ",\n".join(arguments)
        arguments = utils.indent(arguments)
        if arguments:
            arguments = "\n" + arguments
        return f"""extern {self._prefix} {self._return_type.generate_h()} CL_API_CALL {self._name}({arguments}
) {self._suffix};
"""

    def generate_c(self):
        arguments = (x.generate_c() for x in self._arguments)
        arguments = ",\n".join(arguments)
        arguments = utils.indent(arguments)
        if arguments:
            arguments = "\n" + arguments

        arguments_passed = []
        for arg in self._arguments:
            passed_arg = arg.get_name()

            # Struct arguments need to be casted, because translated structs are technically different types
            if arg._is_translated_struct:
                data_type = arg._data_type.generate_c(translated=False)
                passed_arg = f"({data_type}) {passed_arg}"

            arguments_passed.append(passed_arg)
        arguments_passed = ", ".join(arguments_passed)

        verification_statement = self._generate_verification_statement()
        verification_statement = utils.indent(verification_statement, True)
        return_statement = "return " if self._return_type != "void" else ""

        return f"""{self._return_type.generate_c()} CL_API_CALL {self._name}({arguments}
) {{{verification_statement}
    {return_statement}dispatch.{self._original_name}({arguments_passed});
}}
"""

    def _generate_verification_statement(self):
        result = ""

        if self._original_name == "clGetPlatformIDs":
            result += "\n_joInicjalizuj();"

        for arg in self._arguments:
            if arg._original_name == "errcode_ret":
                result += f"\nVERIFY_FUNCTION_LOADED_FUNCTION_AND_SET_ERROR({self._original_name}, {arg._name});"

        return_type = self._return_type.generate_c()
        if return_type == "pustka*":
            result += f"\nVERIFY_FUNCTION_LOADED_FUNCTION_AND_RETURN_NULL({self._original_name});"
        if return_type == "jo_liczba":
            result += f"\nVERIFY_FUNCTION_LOADED_FUNCTION_AND_RETURN_ERROR({self._original_name});"
        if result == "" and self._original_name != "clSVMFree":
            raise TypeError("Could not generate verification statements")
        return result


class DataType(Node):
    def __init__(self, base_content, prefixes=[], suffixes=[]):
        if type(base_content) is DataType:
            # Extend existing datatype
            self._prefixes = base_content._prefixes
            self._original_name = base_content._original_name
            self._name = base_content._name
            self._suffixes = base_content._suffixes
        elif type(base_content) is str:
            # Create a new datatype from scratch
            self._prefixes = []
            self._original_name = base_content
            self._name = lookup_type_mapping(base_content)
            self._suffixes = suffixes
        else:
            error("Unreachable code: DataType")

        self._prefixes = prefixes + self._prefixes
        self._suffixes = self._suffixes + suffixes

    def generate_h(self, translated=True):
        prefix = " ".join(self._prefixes)
        if prefix:
            prefix += " "

        suffix = "".join(self._suffixes)

        name = self._name if translated else self._original_name
        return f"{prefix}{name}{suffix}"

    def generate_c(self, translated=True):
        return self.generate_h(translated=translated)


class FunctionArgument(Node):
    def __init__(self, data_type, name, array_suffix=""):
        self._data_type = data_type
        self._original_name = name
        self._name = lookup_variable_name_mapping(name)
        self._array_suffix = array_suffix
        self._is_translated_struct = self._original_name in ["image_format", "image_formats", "image_desc"] # TODO should be done more intelligently...

    def generate_h(self):
        result = self._data_type.generate_h()
        if self._name:
            result += f" {self._name}{self._array_suffix}"
        return result

    def generate_c(self):
        return self.generate_h()

    def get_name(self):
        return self._name


class FunctionPointerFunctionArgument(Node):
    def __init__(self, return_type, name, arguments):
        self._return_type = return_type
        self._original_name = name
        self._name = lookup_variable_name_mapping(name)
        self._arguments = arguments
        self._is_translated_struct = False

    def generate_h(self):
        content = f"{self._return_type.generate_h()} (CL_CALLBACK * {self._name})("
        indent = ",\n" + " " * len(content)
        content += indent.join((x.generate_h() for x in self._arguments))
        content += ")"
        return content

    def generate_c(self):
        return self.generate_h()

    def get_name(self):
        return self._name


class Struct(Node):
    def __init__(self, name, fields):
        self._original_name = name
        self._name = lookup_type_mapping(name)
        self._fields = fields

    def generate_h(self):
        fields_string = "\n".join((x.generate_h() + ";" for x in self._fields))
        fields_string = utils.indent(fields_string)
        return f"typedef struct _{self._name} {{\n{fields_string}\n}} {self._name}; // {self._original_name}"


class Ifdef(Node):
    def __init__(self, condition, lines):
        self._condition = condition
        self._lines = lines

    def generate_h(self):
        result = self._lines
        result = [x.generate_h() for x in result]
        result = "\n".join(result)
        result = result.replace("\n", "\n  ")
        result = result.replace("\n  \n", "\n\n")
        while result.endswith(" "):
            result = result[:-1]
        result = f"#ifdef {self._condition}\n  {result}\n#endif"
        return result

    def generate_c(self):
        result = self._lines
        result = [x.generate_c() for x in result]
        result = [x for x in result if x]
        result = "\n".join(result)
        return result


class Ignored(Node):
    pass
