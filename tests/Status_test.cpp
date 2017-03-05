//
// Created by demiaowu on 17-3-5.
//

#include <gtest/gtest.h>
#include <Status.h>


TEST(StatusTest, cons) {
    Status st1;
    EXPECT_TRUE(st1.isOk());

    Status st2 = Status::IoError("IoError");
    EXPECT_TRUE(st2.isIoError());
    std::cout << "\ncode: " << st2.code() << std::endl;
    EXPECT_STREQ("IoError", st2.ToString().c_str());
}
