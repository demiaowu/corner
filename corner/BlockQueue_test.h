//
// Created by demiaowu on 17-3-6.
//

#ifndef CORNER_BLOCKQUEUE_H
#define CORNER_BLOCKQUEUE_H
//
// Use cpp11 implement
//

#include <deque>
#include <mutex>
#include <condition_variable>
#include <cassert>

#include "nocopyable.h"

template <typename T>
class BlockQueue : public nocopyable {
public:
    typedef T value_type;
    typedef size_t size_type;

    BlockQueue() :
            lock_(),
            notEmpty_(),
            queue_() {}

    size_t size() {
        std::lock_guard<std::mutex> lg(lock_);
        return queue_.size();
    }

    void put(const T& v) {
        std::unique_lock<std::mutex> ul(lock_);
        queue_.push_back(v);
        ul.unlock();            // It may can reduce context switch
        notEmpty_.notify_one();
    }

    T font() {
        std::lock_guard<std::mutex> lg(lock_);
        return queue_.front();
    }

    T take() {
        std::unique_lock<std::mutex> ul(lock_);
        while(queue_.empty()) {
            notEmpty_.wait(ul, [] {return true;});
        }
        assert(!queue_.empty());
        T front(queue_.front());
        queue_.pop_front();

        return front;
    }

    bool empty() {
        std::lock_guard<std::mutex> lg(lock_);
        return (0 == queue_.size());
    }
private:
    mutable std::mutex lock_;
    std::condition_variable notEmpty_;
    std::deque<T> queue_;
};

#endif //CORNER_BLOCKQUEUE_H
