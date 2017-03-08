//
// Created by demiaowu on 17-3-8.
//

#ifndef CORNER_CORNERTESTENVIRONMENT_H
#define CORNER_CORNERTESTENVIRONMENT_H
#include <iostream>

#include <gtest/gtest.h>

class CornerTestEnvironment : public testing::Environment {
public:
    virtual void SetUp() {
        std::cout << "1 - CornerTestEnvironment's SetUp()" << std::endl;
    }

    virtual void TearDown() {
        std::cout << "3 - CornerTestEnvironment's TearDown" << std::endl;
    }
};

#endif //CORNER_CORNERTESTENVIRONMENT_H
