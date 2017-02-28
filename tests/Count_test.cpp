//
// Created by demiaowu on 17-2-28.
//

#include "gtest/gtest.h"

#include "Count.h"


TEST(CountTest, unlockAddOneMethod) {
    Count cnt;
    EXPECT_EQ(0, cnt.getCountWithoutLock());
    cnt.unlockAddOne();
    EXPECT_EQ(1, cnt.getCountWithoutLock());
}

TEST(CountTest, unlockAddNMethod) {
    Count cnt;
    EXPECT_EQ(0, cnt.getCountWithoutLock());
    cnt.unlockAddN(4);
    EXPECT_EQ(4, cnt.getCountWithoutLock());
}
