//
// Created by demiaowu on 17-2-28.
//

#ifndef CORNER_SPINLOCK_H
#define CORNER_SPINLOCK_H

#include <sys/param.h>
#include <pthread.h>
#include "nocopyable.h"

class SpinLock : public nocopyable {
public:
    SpinLock() {
        pthread_spin_init(&lock_, 0);
    }

    virtual ~SpinLock() {
        pthread_spin_destroy(&lock_);
    }

    void lock() {
        pthread_spin_lock(&lock_);
    }

    bool tryLock() {
        return pthread_spin_trylock(&lock_) == 0;
    }

    void unlock() {
        pthread_spin_unlock(&lock_);
    }

private:
    pthread_spinlock_t lock_;
};

#endif //CORNER_SPINLOCK_H
