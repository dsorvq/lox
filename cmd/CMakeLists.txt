set(CMD_TARGET ${LIB_TARGET}_cmd)

add_executable(${CMD_TARGET} main.cpp)
target_link_libraries(${CMD_TARGET} ${LIB_TARGET})
