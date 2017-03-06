//
// Created by demiaowu on 17-2-28.
//

#ifndef CORNER_COUNT_H
#define CORNER_COUNT_H

#include <cstdint>

#include "nocopyable.h"
#include "MutexLock.h"


class Count : public nocopyable{
public:
    Count(): cnt_(0),
             mutex_()
    {
    }
    ~Count() {}

    int64_t getCountWithoutLock() const { return cnt_; }

    void unlockAddOne() { cnt_ += 1; }
    void unlockAddN(int n);

    void lockAddOne();
    void lockAddN(int n);
private:
    int64_t cnt_;
    mutable MutexLock mutex_;
};


#endif //CORNER_COUNT_H
