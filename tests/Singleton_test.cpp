//
// Created by demiaowu on 17-3-5.
//
#include <gtest/gtest.h>
#include <Slice.h>

#include "Singleton.h"

TEST(SingletonTest, test) {
    Slice* sli1 = Singleton<Slice>::instance();
    Slice* sli3 = Singleton<Slice>::instance();

    EXPECT_EQ(0, sli1->size());
    EXPECT_TRUE(sli1 == sli3);
}
