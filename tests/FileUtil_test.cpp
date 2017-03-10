//
// Created by demiaowu on 17-3-10.
//

#include <gtest/gtest.h>
#include "FileUtil.h"

TEST(FileUtile, usage) {
    FileUtil::ReadSmallFile file("meiyouzhegewenjian");
    EXPECT_TRUE(file.fd_ < 0);
//    EXPECT_TRUE(file.errorNumber() != 0);
//
    FileUtil::ReadSmallFile file2("/home/demiaowu/cpp/test.cpp");
    std::cout << "file2" << strerror(file2.errorNumber())  << file2.errorNumber()<< std::endl;
    EXPECT_TRUE(file2.errorNumber() == 0);
    int size = 0;
    const char * content;
    file2.readToBuffer(&size, &content);
    std::cout << "file2" << strerror(file2.errorNumber())  << file2.errorNumber()<< std::endl;
    EXPECT_TRUE(size > 0);
    EXPECT_TRUE(content != nullptr);
}

