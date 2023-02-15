#ifdef __linux__
#include <dlfcn.h>
#elif _WIN32
#include <libloaderapi.h>
#error "Unknown OS"
#endif

#include <CL/cl_icd.h>

#define VERIFY_FUNCTION_LOADED_FUNCTION_AND_RETURN_ERROR(functionName) if(dispatch.functionName == NULL) { return CL_INVALID_OPERATION; }
#define VERIFY_FUNCTION_LOADED_FUNCTION_AND_SET_ERROR(functionName, errorVariable) if(dispatch.functionName == NULL) { if(errorVariable) *errorVariable = CL_INVALID_OPERATION; return NULL; }
#define VERIFY_FUNCTION_LOADED_FUNCTION_AND_RETURN_NULL(functionName) if(dispatch.functionName == NULL) { return NULL; }
#define INITIALIZE_FUNCTION(functionName) dispatch.functionName = getFunctionPointer(openclLibrary, #functionName);

void *openclLibrary;
cl_icd_dispatch dispatch;

void loadOpenclLibrary() {
#ifdef __linux__
    openclLibrary = dlopen("libOpenCL.so", RTLD_NOW | RTLD_GLOBAL );
#elif _WIN32
    openclLibrary = LoadLibraryA("OpenCL.dll");
#endif
}

void* getFunctionPointer(void* library, const char *functionName) {
#ifdef __linux__
    if(library) {
        return dlsym(library, functionName);
    } else {
        return dlsym(RTLD_NEXT, functionName);
    }
#elif _WIN32
    if(library) {
        HMODULE hModule = (HMODULE) library;
        return GetProcAddress( hModule, functionName);
    } else {
        return NULL;
    }
#endif
}
