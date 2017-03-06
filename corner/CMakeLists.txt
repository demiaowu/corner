set(SOURCE_FILES
        MutexLock.cpp MutexLock.h
        nocopyable.h
        Count.cpp Count.h
        MutexLockGuard.h
        Condition.cpp Condition.h
        CountDownLatch.cpp CountDownLatch.h
        SpinLock.h
        RWLock.h
        FastLock.h
        Locks.h
        Slice.h
        Status.cpp Status.h
        Singleton.h
        Atomic.h
        ThreadLocal.h
        BoundedBlockQueue.h)

# dynamic library
#add_library(corner_lib SHARED ${SOURCE_FILES})

#static library
add_library(corner_lib ${SOURCE_FILES})


