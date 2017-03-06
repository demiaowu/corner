cmake_minimum_required(VERSION 3.6)
project(corner)

set(CMAKE_CXX_STANDARD 14)

set(GOOGLE_TEST_DIR /home/demiaowu/gtest/googletest)
set(BOOST_DIR /usr/local)


include_directories(${GOOGLE_TEST_DIR}/googletest/include
        ${BOOST_DIR}/include
        ${PROJECT_SOURCE_DIR}/corner
        ${PROJECT_SOURCE_DIR}/tests)

link_directories(${GOOGLE_TEST_DIR}/googletest/make
        ${BOOST_DIR}/lib)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH  ${PROJECT_BINARY_DIR}/lib)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} -fno-access-control")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} -O2")

add_subdirectory(corner)
add_subdirectory(tests)

