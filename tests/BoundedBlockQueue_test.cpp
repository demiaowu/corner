//
// Created by demiaowu on 17-3-6.
//

#ifndef CORNER_BOUNDEDBLOCKQUEUE_TEST_H
#define CORNER_BOUNDEDBLOCKQUEUE_TEST_H

#include <gtest/gtest.h>
#include <BoundedBlockQueue.h>


TEST(BoundedBlockQueueTest, usage) {
    BoundedBlockQueue<int> blockQueue(5);

    blockQueue.put(1);
    EXPECT_TRUE(!blockQueue.empty());
    EXPECT_TRUE(!blockQueue.full());

    blockQueue.put(2);
    EXPECT_EQ(2, blockQueue.size());
    EXPECT_EQ(1, blockQueue.take());

    int front = blockQueue.take();
    EXPECT_TRUE(blockQueue.empty());
    EXPECT_EQ(2, front);

    blockQueue.put(3);

    EXPECT_EQ(5, blockQueue.capacity());
}

#endif //CORNER_BOUNDEDBLOCKQUEUE_TEST_H
