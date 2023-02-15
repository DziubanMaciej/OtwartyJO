def error(*args, **kwargs):
    print("ERROR: ", *args, **kwargs)
    # sys.exit(1)


def indent(string, strip_spaces=False):
    if len(string) == 0:
        return ""
    indent = "    "

    result = string.replace("\n", f"\n{indent}")
    result = indent + result
    if strip_spaces:
        result = result.strip(" ")
    return result


def flatten_list(values, with_separator=False):
    if len(values) == 0:
        return []
    if len(values) == 1:
        return values

    if with_separator:
        if len(values) == 3:
            return values[0] + [values[2]]
    else:
        if len(values) == 2:
            return values[0] + [values[1]]

    error("flatten_list: Unreachable code")
