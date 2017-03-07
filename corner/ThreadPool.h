//
// Created by demiaowu on 17-3-7.
//

#ifndef CORNER_THREADPOOL_H
#define CORNER_THREADPOOL_H


#include <mutex>
#include <condition_variable>
#include <thread>
#include <vector>
#include <deque>

//
// Implementation by cpp11
//

const int CORNER_MAX_THREADS_NUMS = 32;
const int CORNER_MIN_TASK_QUEUE_SIZE = 1;
const int CORNER_MAX_TASK_QUEUE_SIZE = 64;


class ThreadPool {
public:
    typedef std::function<void ()> Task;

    typedef size_t task_queue_size_type;

    explicit ThreadPool(size_t maxTaskQueueSize, const std::string& name = "ThreadPool") :
            lock_(),
            notEmpty_(),
            notFull_(),
            maxTaskQueueSize_(maxTaskQueueSize),
            running_(false){
                if (maxTaskQueueSize < CORNER_MIN_TASK_QUEUE_SIZE || maxTaskQueueSize > CORNER_MAX_TASK_QUEUE_SIZE) {
                    //TODO
                    //Better way ????
                    std::cout << "maxTaskQueueSize is not rightful, recommend is " << CORNER_MIN_TASK_QUEUE_SIZE << "<= maxTaskQueueSize <=" << CORNER_MAX_TASK_QUEUE_SIZE << std::endl;
                    std::exit(-1);
                }
            }
    ~ThreadPool();

    void start(int numThreads);
    void stop();

    void run(Task&& task);

    size_t maxTaskQueueSize() const { return maxTaskQueueSize_; }

    size_t taskQueueSize() const    {
        std::lock_guard<std::mutex> lg(lock_);
        return taskQueue_.size();
    }

private:
    void runInThread();
    bool isFull();

private:
    std::string name_;
    mutable std::mutex lock_;
    std::condition_variable notFull_;
    std::condition_variable notEmpty_;
    size_t maxTaskQueueSize_;
    std::vector<std::unique_ptr<std::thread>> threads_;
    std::deque<Task> taskQueue_;
    bool running_;

};


#endif //CORNER_THREADPOOL_H
