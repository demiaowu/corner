//
// Created by demiaowu on 17-3-7.
//

#include <gtest/gtest.h>

#include "BlockQueue_test.h"

TEST(BlockQueueTest, usage) {
    BlockQueue<int> bq;

    bq.put(1);
    bq.put(2);
    bq.put(3);
    bq.put(4);
    EXPECT_EQ(4, bq.size());
    EXPECT_TRUE(!bq.empty());

    int front = bq.take();
    EXPECT_EQ(1, front);
    EXPECT_EQ(3, bq.size());

    bq.take();
    bq.take();
    bq.take();
    EXPECT_TRUE(bq.empty());
}
