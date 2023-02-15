add_library(OtwartyJo STATIC jo.c ${CMAKE_CURRENT_LIST_DIR}/include/JO/jo.h)
target_include_directories(OtwartyJo PUBLIC ${CMAKE_CURRENT_LIST_DIR}/include)

if (CMAKE_COMPILER_IS_GNUCC)
    target_compile_options(OtwartyJo PRIVATE -Wall -Wextra)
endif()
if (MSVC)
    target_compile_options(OtwartyJo PRIVATE /W4)
endif()
