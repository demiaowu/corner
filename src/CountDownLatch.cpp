//
// Created by root on 17-2-28.
//

#include "CountDownLatch.h"
#include "MutexLockGuard.h"

CountDownLatch::CountDownLatch(const int count)
        :mutex_(),
        cond_(mutex_),
         count_(count) {

}

void CountDownLatch::wait() {
    MutexLockGuard lockGuard(mutex_);

    while(count_ > 0) {
        cond_.wait();
    }
}

void CountDownLatch::countDown() {
    MutexLockGuard lockGuard(mutex_);
    -- count_;
    if (0 == count_)
        cond_.notifyAll();
}

int32_t CountDownLatch::getCount() const {
    MutexLockGuard lockGuard(mutex_);
    return count_;
}
