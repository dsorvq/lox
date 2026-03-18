get_filename_component(LIB_INCLUDE_PATH "." ABSOLUTE)
get_filename_component(LIB_SOURCE_PATH "./lox" ABSOLUTE)

add_library(${LIB_TARGET} STATIC
        ${LIB_SOURCE_PATH}/scanner/scanner.hpp
        ${LIB_SOURCE_PATH}/scanner/scanner.cpp
)

target_include_directories(${LIB_TARGET} PUBLIC ${LIB_INCLUDE_PATH})
