//
// Created by demiaowu on 17-2-28.
//

#ifndef CORNER_RWLOCK_H
#define CORNER_RWLOCK_H

#include <sys/param.h>
#include <pthread.h>
#include "nocopyable.h"

class RWLock : public nocopyable {
public:
    RWLock() {
        pthread_rwlock_init(&rwlock_, nullptr);
    }

    ~RWLock() {
        pthread_rwlock_destroy(&rwlock_);
    }

    void lock() {
        pthread_rwlock_wrlock(&rwlock_);
    }

    void lockShared() {
        pthread_rwlock_rdlock(&rwlock_);
    }

    void unlock() {
        pthread_rwlock_unlock(&rwlock_);
    }
private:
    pthread_rwlock_t rwlock_;
};

class ReadLock : public nocopyable {
public:
    ReadLock(RWLock &lock_) : lock_(lock_) {
        lock_.lockShared();
    }

    ~ReadLock() {
        lock_.unlock();
    }

private:
    RWLock& lock_;  //the rwlock's life cycle is not manage by ReadLock, so using the pointer is smart.
};

class WriteLock : public nocopyable {
public:
    WriteLock(RWLock &lock_) : lock_(lock_) {
        lock_.lock();
    }

    ~WriteLock() {
        lock_.unlock();
    }

private:
    RWLock& lock_;
};

#endif //CORNER_RWLOCK_H
