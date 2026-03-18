cmake_minimum_required(VERSION 3.24)
project(lox)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(cmake/Sanitize.cmake)
include(cmake/CompileOptions.cmake)

add_subdirectory(third_party)

set(LIB_TARGET ${PROJECT_NAME})

add_subdirectory(library)

enable_testing()
add_subdirectory(tests)

add_subdirectory(cmd)
