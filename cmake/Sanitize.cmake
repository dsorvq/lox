set(USAN_COMPILE_FLAGS -fsanitize=undefined -fno-sanitize-recover=all)
set(USAN_LINK_FLAGS -fsanitize=undefined)

if(USAN)
    add_compile_options(${USAN_COMPILE_FLAGS})
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${USAN_LINK_FLAGS}")
endif()

set(ASAN_COMPILE_FLAGS -fsanitize=address,undefined -fno-sanitize-recover=all)
set(ASAN_LINK_FLAGS -fsanitize=address,undefined)

if(ASAN)
    add_compile_options(${ASAN_COMPILE_FLAGS})
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${ASAN_LINK_FLAGS}")
endif()
