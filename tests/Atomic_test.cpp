//
// Created by demiaowu on 17-3-5.
//
#include <iostream>

#include <gtest/gtest.h>

#include "Atomic.h"

TEST(AtomicTest, usage) {
    volatile int count = 0;
    // add: return old value
    EXPECT_EQ(0, atomic_add(&count, 1));
    // swap: return old value
    EXPECT_EQ(1, atomic_swap(&count, 10));
    // cmp_swap: return old value
    EXPECT_EQ(10, atomic_cmp_swap(&count, 12, 10));
    EXPECT_EQ(12, atomic_cmp_swap(&count, 14, 11));
}

TEST(AtomicTest, atomicInt32) {
    AtomicInt32 count;
    // getAndAdd(5)
    EXPECT_EQ(0, count.getAndAdd(5));
    // addAndGet(5)
    EXPECT_EQ(10, count.addAndGet(5));
    // getAndSub(2)
    EXPECT_EQ(10, count.getAndSub(2));
    // subAndGet(2)
    EXPECT_EQ(6, count.subAndGet(2));

    // sub(2)
    count.sub(2);
    EXPECT_EQ(4, count.get());
    // add(2)
    count.add(2);
    EXPECT_EQ(6, count.get());

    // cmp_and_swap(value_, 0, 0)
    EXPECT_EQ(6, count.get());
}