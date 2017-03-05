//
// Created by demiaowu on 17-3-1.
//

#ifndef CORNER_FASTLOCK_H
#define CORNER_FASTLOCK_H

#include "SpinLock.h"
#include "MutexLock.h"

#if defined( CORNER_USE_SPINLCOK )
    typedef SpinLock FastLock;
#else
    typedef MutexLock FastLock;
#endif

#endif //MYTEST_FASTLOCK_H
