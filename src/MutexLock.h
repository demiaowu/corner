//
// Created by demiaowu on 17-2-28.
//

#ifndef MYTEST_MUTEXLOCK_H
#define MYTEST_MUTEXLOCK_H


#include <sys/types.h>

#include "nocopyable.h"

class MutexLock : public nocopyable{
public:
    MutexLock();
    virtual ~MutexLock();

    void lock() const;
    void unlock() const;

    pthread_mutex_t* getPthreadMutex() {
        return &mutex_;
    }

private:
    mutable pthread_mutex_t mutex_;
};


#endif //MYTEST_MUTEXLOCK_H
