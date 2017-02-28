set(SOURCE_FILES
        MutexLock.cpp MutexLock.h
        nocopyable.h
        Count.cpp Count.h MutexLockGuard.h Condition.cpp Condition.h CountDownLatch.cpp CountDownLatch.h SpinLock.h RWLock.h FastLock.h)

# shared library
add_library(corner_lib SHARED ${SOURCE_FILES})



