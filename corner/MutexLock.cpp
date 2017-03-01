//
// Created by demiaowu on 17-2-28.
//

#include <pthread.h>
#include "MutexLock.h"

MutexLock::MutexLock() {
    pthread_mutex_init(&mutex_, nullptr);
}

MutexLock::~MutexLock() {
    pthread_mutex_destroy(&mutex_);
}

void MutexLock::lock() {
    pthread_mutex_lock(&mutex_);
}

void MutexLock::unlock() {
    pthread_mutex_unlock(&mutex_);
}
