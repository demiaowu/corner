//
// Created by demiaowu on 17-3-5.
//

#ifndef CORNER_ATOMIC_H
#define CORNER_ATOMIC_H


#include <cstdint>
#include "nocopyable.h"

// Return old value
static inline int atomic_add(volatile int *mem, int add) {
    asm volatile(
    "lock xadd %0, (%1);"
    : "=a"(add)
    : "r"(mem), "a"(add)
    : "memory"
    );
    return add;
}
static inline long atomic_add64(volatile long* mem, long add) {
    asm volatile (
    "lock xaddq %0, (%1)"
    : "=a" (add)
    : "r" (mem), "a" (add)
    : "memory"
    );
    return add;
}

static inline void atomic_inc(volatile int *mem) {
    asm volatile(
    "lock incl %0;"
    : "=m"(*mem)
    : "m"(*mem)
    );
}

static inline void atomic_inc64(volatile long *mem) {
    asm volatile(
    "lock incq %0;"
    : "=m"(*mem)
    : "m"(*mem)
    );
}

static inline void atomic_dec(volatile int *mem) {
    asm volatile(
    "lock decl %0;"
    : "=m"(*mem)
    : "m"(*mem)
    );
}

static inline void atomic_dec64(volatile long *mem) {
    asm volatile(
    "lock decq %0;"
    : "=m"(*mem)
    : "m"(*mem)
    );
}
// Swap, return old value
static inline int atomic_swap(volatile void *lockword, int value) {
    asm volatile(
    "lock xchg %0, (%1);"
    : "=a"(value)
    : "r"(lockword), "a"(value)
    : "memory"
    );
    return value;
}
static inline long atomic_swap64(volatile void *lockword, long value) {
    asm volatile(
    "lock xchg %0, (%1);"
    : "=a"(value)
    : "r"(lockword), "a"(value)
    : "memory"
    );
    return value;
}

// @brief
// if (*mem == cmp)
//      *mem = xchg;
// else
//      cmp = *mem;
// return old value
// like: test_cmp. then set xchg
static inline int atomic_cmp_swap(volatile void *mem, int xchg, int cmp) {
    asm volatile(
    "lock cmpxchg %1, (%2)"
    :"=a"(cmp)
    :"d"(xchg), "r"(mem), "a"(cmp)
    );
    return cmp;
}

static inline long atomic_cmp_swap64(volatile void *mem, long long xchg, long long cmp) {
    asm volatile(
    "lock cmpxchg %1, (%2)"
    :"=a"(cmp)
    :"d"(xchg), "r"(mem), "a"(cmp)
    );
    return cmp;
}

class AtomicInt32 : public nocopyable {
public:
    AtomicInt32(int32_t value = 0): value_(value) {  }

    int32_t get() { return atomic_cmp_swap(&value_, 0, 0); }

    int32_t getAndAdd(int32_t add) {
        return atomic_add(&value_, add);
    }

    int32_t addAndGet(int32_t add) {
        return atomic_add(&value_, add) + add;
    }

    int32_t getAndSub(int32_t sub) {
        return atomic_add(&value_, -sub);
    }

    int32_t subAndGet(int32_t sub) {
        return atomic_add(&value_, -sub) - sub;
    }

    int32_t incrementAndGet() {
        return addAndGet(1);
    }

    int32_t decrementAndGet() {
        return subAndGet(1);
    }

    void increment() {
        atomic_inc(&value_);
    }

    void decrement() {
        atomic_dec(&value_);
    }

    void add(int32_t add) {
        atomic_add(&value_, add);
    }

    void sub(int32_t sub) {
        atomic_add(&value_, -sub);
    }

    int32_t getAndSet(int32_t value) {
        return atomic_swap(&value_, value);
    }
public:
    volatile int32_t value_;
};

#endif //CORNER_ATOMIC_H
