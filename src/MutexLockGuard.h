//
// Created by demiaowu on 17-2-28.
//

#ifndef MYTEST_MUTEXLOCKGUARD_H
#define MYTEST_MUTEXLOCKGUARD_H

#include "nocopyable.h"
#include "MutexLock.h"

class MutexLockGuard : public nocopyable {
public:
    MutexLockGuard(MutexLock& mutex) :mutex_(mutex) {
        mutex_.lock();
    }

   ~MutexLockGuard() {
        mutex_.unlock();
    }

private:
    MutexLock& mutex_;
};

#endif //MYTEST_MUTEXLOCKGUARD_H
