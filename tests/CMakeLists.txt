set(SOURCE_FILES
        Count_test.cpp
        Slice_test.cpp
        Scope_test.cpp
        Status_test.cpp
        Singleton_test.cpp)


add_executable(corner_unit_test ${SOURCE_FILES})



target_link_libraries(corner_unit_test
        corner_lib

        gtest_main     #Modify it to your path of the gtest.a
        pthread)     #the lib of pthread must be place the last.

