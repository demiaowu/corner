//
// Created by demiaowu on 17-2-28.
//

#ifndef MYTEST_MUTEXLOCK_H
#define MYTEST_MUTEXLOCK_H


#include <sys/types.h>

#include "nocopyable.h"

class Condition;

class MutexLock : public nocopyable{
public:
    MutexLock();
    ~MutexLock();

    void lock();
    void unlock();

    // The Condition class have been set as the friend class, so the method can be delete
    pthread_mutex_t* getPthreadMutex() = delete;

private:
    friend class Condition;
    pthread_mutex_t mutex_;
};


#endif //MYTEST_MUTEXLOCK_H
