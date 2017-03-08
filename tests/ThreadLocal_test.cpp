//
// Created by demiaowu on 17-3-6.
//
#include <map>

#include <gtest/gtest.h>

#include <Count.h>
#include <ThreadLocal.h>

#include <testutil.h>
#include <thread>

ThreadLocal<Count> cnt;
std::vector<pthread_t> pts;
std::vector<Count::value_type > cnts;

void _fun_() {
    cnt.value().unlockAddN(11);
}

void* fun_(void*) {
    cnt.value().unlockAddOne();
    _fun_();
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


    // Must
    sleep(2);   // Must

    EXPECT_EQ(0, cnt.value().getCountWithoutLock());
    EXPECT_EQ(12, cnts[0]);
    EXPECT_EQ(12, cnts[1]);

    CUTOFFLINE("pts")
    std::cout << "pts size: " << pts.size() << std::endl;
    for(auto i : pts) {
        std::cout << i << std::endl;
    }


//    pthread_exit(0);
}

std::map<std::thread::id, Count::value_type> cntMap;

void* fun2_() {
    cnt.value().unlockAddOne();
    cntMap.insert(std::make_pair(std::this_thread::get_id(), cnt.value().getCountWithoutLock()));
}

TEST(ThreadLocalTest, cpp11usage) {
    std::thread t1(fun2_);
    std::thread t2(fun2_);

    sleep(2);

    CUTOFFLINE("cntmap")
    std::cout << cntMap.find(t1.get_id())->first << " : " << cntMap.find(t2.get_id())->second << std::endl;
    EXPECT_EQ(1, cntMap.find(t1.get_id())->second);
    EXPECT_EQ(1, cntMap.find(t2.get_id())->second);

    t1.join();
    t2.join();
}
