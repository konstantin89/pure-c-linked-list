cmake_minimum_required(VERSION 3.1.2)

cmake_minimum_required(VERSION 3.1.2)


set(TESTS_BINARY_NAME tests)

set(TESTS_SOURCES main.cpp)

add_executable(${TESTS_BINARY_NAME} ${TESTS_SOURCES})

target_include_directories(
    ${TESTS_BINARY_NAME} PRIVATE 
    ${PURE_C_LINKED_LIST_INCLUDE_PATH})