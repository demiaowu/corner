//
// Created by root on 17-2-28.
//

#ifndef MYTEST_COUNTDOWNLATCH_H
#define MYTEST_COUNTDOWNLATCH_H


#include "nocopyable.h"
#include "Condition.h"

class CountDownLatch : public nocopyable{
public:
    explicit CountDownLatch(const int count);

    void wait();
    void countDown();
    int32_t getCount() const;
private:
    Condition cond_;
    mutable MutexLock mutex_;
    int32_t count_;
};


#endif //MYTEST_COUNTDOWNLATCH_H
