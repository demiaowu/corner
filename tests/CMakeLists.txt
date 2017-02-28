set(SOURCE_FILES
        Count_test.cpp)


add_executable(corner_unit_test ${SOURCE_FILES})


target_link_libraries(corner_unit_test
        /home/demiaowu/gtest/googletest/googletest/make/gtest_main.a     #Modify it to your path of the gtest.a
        corner_lib
        pthread)     #the lib of pthread must be place the last.

