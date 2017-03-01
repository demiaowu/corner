//
// Created by demiaowu on 17-2-28.
//

#ifndef MYTEST_CONDITION_H
#define MYTEST_CONDITION_H


#include <sys/param.h>
#include <pthread.h>

#include "nocopyable.h"
#include "MutexLock.h"

class Condition : public nocopyable{
public:
    explicit Condition(MutexLock& mutex)
            :mutex_(mutex) {
        pthread_cond_init(&cond_, nullptr);
    }
    ~Condition() {
        pthread_cond_destroy(&cond_);
    }

    void wait() {
        pthread_cond_wait(&cond_, &mutex_.mutex_);
    }

    //TODO
    bool waitForSeconds(double seconds);

    void notify() {
        pthread_cond_signal(&cond_);
    }

    void notifyAll() {
        pthread_cond_broadcast(&cond_);
    }

private:
    MutexLock& mutex_;
    pthread_cond_t cond_;
};


#endif //MYTEST_CONDITION_H
