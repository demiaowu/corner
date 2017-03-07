//
// Created by demiaowu on 17-3-7.
//

#ifndef CORNER_THREADLOCALSINGLETON_H
#define CORNER_THREADLOCALSINGLETON_H

#include <sys/types.h>
#include <pthread.h>
#include "nocopyable.h"

template <typename T>
class ThreadLocalSingleton : public nocopyable {
public:
    static T& instance() {
        if (nullptr == value_) {
            value_ = new T();
            deleter_.set(value_);
        }

        return *value_;
    }

private:
    static void destructor() {
        delete  value_;
        value_ = nullptr;
    }

    class Deleter {
    public:
        Deleter() {
            pthread_key_create(&key_, &ThreadLocalSingleton::destructor);
        }

        ~Deleter() {
            pthread_key_delete(key_);
        }

        void set(T* t) {
            pthread_setspecific(key_, t);
        }
    private:
        pthread_key_t key_;
    };

    static __thread T* value_;
    static Deleter deleter_;
};

#endif //CORNER_THREADLOCALSINGLETON_H
