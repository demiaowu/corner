//
// Created by demiaowu on 17-3-6.
//
#include <map>

#include <pthread.h>

#include <gtest/gtest.h>

#include <Count.h>
#include <ThreadLocal.h>

std::map<::pthread_t, int64_t> cntMap;
ThreadLocal<Count> cnt;
std::vector<pthread_t> pts;

void* fun_(void*) {
    cnt.value().unlockAddOne();
    cntMap.insert(std::make_pair(pthread_self(), cnt.value().getCountWithoutLock()));
    pts.push_back(pthread_self());
}

TEST(ThreadLocalTest, usage) {
//    std::thread t1(fun_);
//    std::thread t2(fun_);
    pthread_t t1,t2;

    pthread_create(&t1, NULL, fun_, NULL);
    pthread_create(&t2, NULL, fun_, NULL);

//    std::cout<<std::endl;
//    std::cout << t1 << std::endl;
//    std::cout << t2 << std::endl;

//    EXPECT_EQ(1, cntMap.find(t1)->second);
//    EXPECT_EQ(1, cntMap.find(t2)->second);
    std::cout << "******************************" << std::endl;
    if (cntMap.end() != cntMap.find(t1)) {
        std::cout << cntMap.find(t1)->first << ": " << cntMap.find(t1)->second << std::endl;
    }
    if (cntMap.end() != cntMap.find(t2)) {
        std::cout << cntMap.find(t2)->first << ": " << cntMap.find(t2)->second << std::endl;
    }


    std::cout << "main ******************************" << std::endl;
    cntMap.insert(std::make_pair(pthread_self(), cnt.value().getCountWithoutLock()));
    if (cntMap.end() != cntMap.find(pthread_self())) {
        std::cout << pthread_self() << ": cnt: " << cnt.value().getCountWithoutLock() << std::endl;
    }
    EXPECT_EQ(0, cnt.value().getCountWithoutLock());

    //TODO
    // why the vector of tps is empty?
    std::cout << "pts ******************************" << std::endl;
    std::cout << "pts size: " << pts.size() << std::endl;
    for(auto i : pts) {
        std::cout << i << std::endl;
    }

//    pthread_exit(0);
}
