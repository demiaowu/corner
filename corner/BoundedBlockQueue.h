//
// Created by demiaowu on 17-3-6.
//

#ifndef CORNER_BOUNDEDBLOCKQUEUE_H
#define CORNER_BOUNDEDBLOCKQUEUE_H

#include <boost/circular_buffer.hpp>

#include "nocopyable.h"
#include "MutexLock.h"
#include "Condition.h"
#include "MutexLockGuard.h"

template <typename T>
class BoundedBlockQueue : public nocopyable {
public:
    typedef size_t size_type;
    typedef T value_type;

    explicit BoundedBlockQueue(const size_t maxSize) :
            lock_(),
            notEmpty_(lock_),
            notFull_(lock_),
            queue_(maxSize) {

    }

    void put(const T& v) {
        MutexLockGuard guard(lock_);
        while (queue_.full()) {
            notFull_.wait();
        }
        assert(!queue_.full());
        queue_.push_back(v);
        notEmpty_.notify();
    }

    T take() {
        MutexLockGuard guard(lock_);
        while(queue_.empty()) {
            notEmpty_.wait();
        }
        assert(!queue_.empty());
        T front(queue_.front());
        queue_.pop_front();
        notFull_.notify();

        return front;
    }

    size_t size() {
        MutexLockGuard guard(lock_);
        return queue_.size();
    }

    bool full() {
        MutexLockGuard guard(lock_);
        return queue_.full();
    }

    bool empty() {
        MutexLockGuard guard(lock_);
        return queue_.empty();
    }

    size_t capacity() {
        MutexLockGuard guard(lock_);
        return queue_.capacity();
    }
private:
    mutable MutexLock lock_;
    Condition notFull_;
    Condition notEmpty_;
    boost::circular_buffer<T> queue_;
};
#endif //CORNER_BOUNDEDBLOCKQUEUE_H
