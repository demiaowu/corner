//
// Created by demiaowu on 17-3-8.
//
#include <iostream>
#include <functional>

#include "CornerTestEnvironment.h"

int addInt(int a, int b) {
    return (a + b);
}

template <typename T>
class Adder {
public:
    static T add(std::function<T ()> addFunction) {
        return addFunction();
    }
    static T add(const T& a, const T& b) {
        return a+b;
    }
};

class AdderTest : public ::testing::Test {
public:
    static void SetUpTestCase() {
        std::cout << "2 - AdderTestSetUpTestCase()" << std::endl;
    }

    static void TearDownTestCase() {
        std::cout << "2 - AdderTestTearDownTestCase() " << std::endl;
    }

protected:
    virtual void SetUp() {
        std::cout << "3 - AdderTestSetUp()" << std::endl;
    }

    virtual void TearDown() {
        std::cout << "1 - AdderTestTearDown()" << std::endl;
    }

private:
    int value_;
    static int staValue_;
};

int AdderTest::staValue_ = 12;

TEST_F(AdderTest, usage) {
    EXPECT_EQ(4, Adder<int>::add(std::bind(addInt, 1, 3)));
    EXPECT_EQ(5, Adder<int>::add(2, 3));
}

TEST_F(AdderTest, usage1) {
    EXPECT_EQ(4, Adder<int>::add(std::bind(addInt, 1, 3)));
    EXPECT_EQ(5, Adder<int>::add(2, 3));
}