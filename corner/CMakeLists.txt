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
        BoundedBlockQueue.h
        BlockQueue.h
        ThreadLocalSingleton.h
        ThreadPool.cpp ThreadPool.h
        FileUtil.cpp FileUtil.h
        Logging.cpp Logging.h LogFile.cpp LogFile.h)

# dynamic library
#add_library(corner_lib SHARED ${SOURCE_FILES})

#static library
add_library(corner_lib ${SOURCE_FILES})


