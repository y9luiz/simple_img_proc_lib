project(my_img_proc_lib)

set(IO_SRCS ${PROJECT_SOURCE_DIR}/input.cpp)

add_library(io_module MODULE ${IO_SRCS} ${PROJECT_SOURCE_DIR}/input.h)
target_include_directories(io_module PRIVATE ${COMMON_DIR})
target_sources(test_lib PRIVATE ${IO_SRCS})
