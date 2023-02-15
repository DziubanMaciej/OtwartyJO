#!/bin/python

from parser import OpenclHeaderParser
from pathlib import Path
import time
import os


if __name__ == "__main__":
    # Setup correct cwd
    script_dir = Path(__file__).parent
    os.chdir(script_dir)

    # Parse header and generate translated code
    measurements = {}

    start = time.time()
    parser = OpenclHeaderParser(verbose=False, debug=False)
    measurements["parser setup"] = time.time() - start

    start = time.time()
    result_bison = parser.run(file="../otwarty_jo/include/CL/cl.h", debug=0)
    measurements["parser run"] = time.time() - start

    start = time.time()
    file_h = result_bison.generate_h()
    measurements["generating .h file contents"] = time.time() - start

    start = time.time()
    file_c = result_bison.generate_c()
    measurements["generating .c file contents"] = time.time() - start

    # Write to files
    start = time.time()
    with open("../otwarty_jo/jo.c", "w") as file:
        file.write(file_c)
    with open("../otwarty_jo/include/JO/jo.h", "w") as file:
        file.write(file_h)
    measurements["writing to filesystem"] = time.time() - start

    # Display measurements
    print("------ OtwartyJO generation -----------------------")
    for name, value in measurements.items():
        print(f"  {name:28s}: {1000 * value:.2f}ms")
    print("----------------------------------------------------")
