set(SOURCE_FILES
        Count_test.cpp
        Slice_test.cpp
        Scope_test.cpp
        Status_test.cpp
        Singleton_test.cpp
        Atomic_test.cpp
        ThreadLocal_test.cpp
        testutil.h
        BoundedBlockQueue_test.cpp
        BlockQueue.cpp
        ThreadPool_test.cpp
        CornerTestEnvironment.h
        GoogleTest_test.cpp
        CornerMain_test.cpp
        FileUtil_test.cpp
        MyTest_test.cpp
        Logging_test.cpp)


add_executable(corner_unit_test ${SOURCE_FILES})



target_link_libraries(corner_unit_test
        corner_lib

        gtest
        pthread)       # lib of pthread must be place the last.

