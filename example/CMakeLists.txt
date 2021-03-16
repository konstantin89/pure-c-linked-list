cmake_minimum_required(VERSION 3.1.2)

cmake_minimum_required(VERSION 3.1.2)


set(EXAMPLE_BINARY_NAME example)

set(EXAMPLE_SOURCES main.c)

add_executable(${EXAMPLE_BINARY_NAME} ${EXAMPLE_SOURCES})

target_include_directories(
    ${EXAMPLE_BINARY_NAME} PRIVATE 
    ${PURE_C_LINKED_LIST_INCLUDE_PATH})