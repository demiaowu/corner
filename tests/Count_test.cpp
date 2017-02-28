//
// Created by demiaowu on 17-2-28.
//

#include "gtest/gtest.h"

#include "Count.h"


TEST(CountTest, unlockAddOneMethod) {
    Count cnt;
    EXPECT_EQ(0, cnt.getCount());
    cnt.unlockAddOne();
    EXPECT_EQ(1, cnt.getCount());
}

TEST(CountTest, unlockAddNMethod) {
    Count cnt;
    EXPECT_EQ(0, cnt.getCount());
    cnt.unlockAddN(4);
    EXPECT_EQ(4, cnt.getCount());
}
