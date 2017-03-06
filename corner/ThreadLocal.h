//
// Created by demiaowu on 17-3-6.
//

#ifndef CORNER_THREADLOCAL_H
#define CORNER_THREADLOCAL_H
#include <pthread.h>

#include "nocopyable.h"

// Note that c++11 support thread_local, so this code just for practise
template <typename T>
class ThreadLocal : public nocopyable {
public:
    ThreadLocal() {
        pthread_key_create(&key_, &ThreadLocal::destructor);
    }

    ~ThreadLocal() {
        pthread_key_delete(key_);
    }

    T& value() {
        T* preValue = static_cast<T*>(pthread_getspecific(key_));

        if (! preValue) {
            T* obj = new T();
            pthread_setspecific(key_, obj);
            preValue = obj;
        }

        return *preValue;
    }
private:
    static void destructor(void* x) {
        T* obj = static_cast<T*>(x);
        delete obj;
    }
    pthread_key_t key_;
};

#endif //CORNER_THREADLOCAL_H
