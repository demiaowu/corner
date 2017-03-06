//
// Created by demiaowu on 17-3-6.
//
#include <map>

#include <gtest/gtest.h>

#include <Count.h>
#include <ThreadLocal.h>

#include <utiltest.h>

ThreadLocal<Count> cnt;
std::vector<pthread_t> pts;
std::vector<int64_t> cnts;

void* fun_(void*) {
    cnt.value().unlockAddOne();
    cnts.push_back(cnt.value().getCountWithoutLock());
    pts.push_back(pthread_self());
}

TEST(ThreadLocalTest, usage) {
//    std::thread t1(fun_);
//    std::thread t2(fun_);
    pthread_t t1,t2;

    int status;
    status = pthread_create(&t1, NULL, fun_, NULL);;
    EXPECT_EQ(0, status);
    status = pthread_create(&t2, NULL, fun_, NULL);
    EXPECT_EQ(0, status);



    sleep(2);   //
    EXPECT_EQ(0, cnt.value().getCountWithoutLock());
    EXPECT_EQ(1, cnts[0]);
    EXPECT_EQ(1, cnts[1]);

    CUTOFFLINE("pts")
    std::cout << "pts size: " << pts.size() << std::endl;
    for(auto i : pts) {
        std::cout << i << std::endl;
    }


//    pthread_exit(0);
}
