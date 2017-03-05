//
// Created by demiaowu on 17-3-5.
//


#include <iostream>

#include <gtest/gtest.h>

class ScopeTest {
public:
    ScopeTest() {
        data_ = (char*) malloc(sizeof(char)*4);
        strcpy(data_, "nish");
        std::cout << "ScopeTest()" << std::endl;
    }

    ~ScopeTest() {
        free(data_);
        data_ = nullptr;
        std::cout << "~ScopeTest()" << std::endl;
    }

    const char* data() const {
        return data_;
    }
private:
    char* data_;
};


TEST(ScopeTest, test) {
    {
        ScopeTest scope;
    }
    std::cout << "before" << std::endl;
//    EXPECT_STREQ(nullptr, scope.data());
}