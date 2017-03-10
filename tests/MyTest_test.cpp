//
// Created by demiawou on 17-3-10.
//

#include <iostream>
#include <gtest/gtest.h>

namespace MyTest {
    class Cab {
    public:
        Cab() {
            std::cout << "Cab()" << std::endl;
        }

        ~Cab() {
            std::cout << "~Cab()" << std::endl;
        }
    };
}

TEST(MyTestCab,usage) {
    MyTest::Cab();
    MyTest::Cab();

    EXPECT_TRUE(1);
}

TEST(MyTestTime, usage) {
    time_t now = time(nullptr);
    std::cout << now << std::endl;
}

