//
// Created by demiaowu on 17-3-5.
//

#ifndef MYTEST_SINGLETON_H
#define MYTEST_SINGLETON_H

#include <sys/param.h>
#include <pthread.h>
#include <cassert>
#include <cstdlib>
#include "nocopyable.h"


template <typename T>
class Singleton : public nocopyable {
public:
    static T* instance() {
        pthread_once(&ponce_, &Singleton::init);
        assert(nullptr != value_);
        return value_;
    }
private:
    static void destory() {
        delete value_;
        value_ = nullptr;
    }

    static void init() {
        value_ = new T();
        ::atexit(destory);
    }

private:
    static pthread_once_t ponce_;
    static T* value_;
};

template <typename T>
pthread_once_t Singleton<T>::ponce_ = PTHREAD_ONCE_INIT;

template <typename T>
T* Singleton<T>::value_ = nullptr;

#endif //MYTEST_SINGLETON_H
