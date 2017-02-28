cmake_minimum_required(VERSION 3.6)
project(mytest)

set(CMAKE_CXX_STANDARD 14)

include_directories(/home/demiaowu/gtest/googletest/googletest/include
        ${PROJECT_SOURCE_DIR}/src
        ${PROJECT_SOURCE_DIR}/tests)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH  ${PROJECT_BINARY_DIR}/lib)

add_subdirectory(src)
add_subdirectory(tests)

