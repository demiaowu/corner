//
// Created by demiaowu on 17-3-5.
//

#include <gtest/gtest.h>

#include "Slice.h"



TEST(SliceTest, cons) {
    Slice sli1;
    EXPECT_STREQ("", sli1.data());
    EXPECT_EQ(0, sli1.size());

    Slice sli2("nihao", 5);
    EXPECT_STREQ("nihao", sli2.data());
    EXPECT_EQ(5, sli2.size());

    Slice sli3;
    std::string str1("zheshi");
    sli3 = str1;
    EXPECT_EQ(6, sli3.size());
    EXPECT_STREQ("zheshi", sli3.data());

    // Not used as follows:  ????
    Slice sli5;
    if (true) {
            std::string str3("zheshi", 6);
            sli5 = str3;
    }
    EXPECT_EQ(6, sli5.size());
//    EXPECT_STRNE("zheshi", sli5.data());  // ?????

    std::string str2("bushi ba");
    Slice sli4 = str2;
    EXPECT_EQ(str2.size(), sli4.size());
    EXPECT_STREQ("bushi ba", sli4.data());

}

