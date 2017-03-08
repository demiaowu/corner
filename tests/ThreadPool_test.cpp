//
// Created by demiaowu on 17-3-7.
//

#include <gtest/gtest.h>

#include "ThreadPool.h"
#include "testutil.h"

std::vector<std::thread::id> results;

void print() {
    CUTOFFLINE("print")
    std::cout << std::this_thread::get_id() << std::endl;
    results.push_back(std::this_thread::get_id());
}

void printInt(int a) {
    CUTOFFLINE("print int")
    std::cout << std::this_thread::get_id() << std::endl;
    std::cout << "a=" << a << std::endl;
    results.push_back(std::this_thread::get_id());
}

TEST(ThreadPoolTest, usage) {
    ThreadPool threadPool(4, "ThreadPool-demiaowu");
    threadPool.start(2);

    EXPECT_EQ(4, threadPool.maxTaskQueueSize());
    EXPECT_EQ(0, threadPool.taskQueueSize());


    threadPool.run(std::cref(print));
    sleep(1);
    EXPECT_EQ(1, results.size());
    threadPool.run(std::cref(print));
    sleep(1);
    EXPECT_EQ(2, results.size());
    threadPool.run(std::bind(std::cref(printInt), 4));
    sleep(1);
    EXPECT_EQ(3, results.size());
}

