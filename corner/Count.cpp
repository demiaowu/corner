//
// Created by demiaowu on 17-2-28.
//

#include <bits/unique_ptr.h>
#include "Count.h"
#include "MutexLockGuard.h"

void Count::unlockAddN(int n) {
    cnt_ += n;
}

void Count::lockAddOne() {
    MutexLockGuard lockGuard(mutex_);
    cnt_ += 1;
}

void Count::lockAddN(int n) {
    MutexLockGuard lockGuard(mutex_);
    cnt_ += n;
}
