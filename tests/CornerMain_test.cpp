//
// Created by demiaowu on 17-3-8.
//

#include <gtest/gtest.h>

#include "CornerTestEnvironment.h"

int main(int argc, char*argv[]) {
    ::testing::AddGlobalTestEnvironment(new CornerTestEnvironment());
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}

