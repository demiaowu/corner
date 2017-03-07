//
// Created by demiaowu on 17-3-7.
//

#include <iostream>
#include "ThreadPool.h"

ThreadPool::~ThreadPool() {
    stop();
}

void ThreadPool::start(int numThreads) {
    if (!running_) {
        if (numThreads <= 0 || numThreads > CORNER_MAX_THREADS_NUMS) {
            //TODO
            //Better way ????
            std::cout << "numThreads is not rightful, recommend is 1<= numThreads <=" << CORNER_MAX_THREADS_NUMS << std::endl;
            std::exit(-1);
        }
        running_ = true;
        threads_.reserve(numThreads);   //A lit optimization, Recommend
        for (auto i = 0; i < numThreads; i++) {
            threads_.emplace_back(std::make_unique<std::thread>(std::bind(&ThreadPool::runInThread, this)));   // Recommend in cpp11
        }
    }
}

void ThreadPool::stop() {
    if (running_) {
        {
            std::unique_lock<std::mutex> ul(lock_);
            running_ = false;           //Reset the 'running' must before the notify_all()
            notEmpty_.notify_all();
        }

        // There is no necessary for the thread.join()
        for(auto& thr : threads_)
            thr->join();
    }
}

bool ThreadPool::isFull() {
//    std::lock_guard<std::mutex> lg(lock_);
    return taskQueue_.size() == maxTaskQueueSize_;
}

void ThreadPool::run(Task&& task) {
    if (threads_.empty())
        task();

    std::unique_lock<std::mutex> lg(lock_);
    while (taskQueue_.size() == maxTaskQueueSize_) {
        notFull_.wait(lg);
    }
    taskQueue_.push_back(task);

    // Recommend in cpp11
    lg.unlock();
    notEmpty_.notify_one();
}

void ThreadPool::runInThread() {
    while (running_) {
        std::unique_lock<std::mutex> ul(lock_);
        Task task;
        while(taskQueue_.empty() && running_) { // considering the stop() launch.
            notEmpty_.wait(ul);
        }

        // When the threadPool is destructed, the taskQueue_ is empty
        if (!taskQueue_.empty()) {
            task = taskQueue_.front();
            taskQueue_.pop_front();

            ul.unlock();
            notFull_.notify_one();

            // There is no necessary for the task launch
            task();
        }
    }
}



