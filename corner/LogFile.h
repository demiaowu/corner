//
// Created by root on 17-3-10.
//

#ifndef CORNER_LOGFILE_H
#define CORNER_LOGFILE_H

#include <string>

#include <cstdio>
#include <bits/unique_ptr.h>
#include <mutex>
#include "FileUtil.h"


class LogFile : public nocopyable{
public:
    LogFile(const std::string& basename,
        size_t rollSize,
        bool threadSafe = true,
        int flushInterval = 3,
        int checkEveryN = 1024);
    ~LogFile();

    void append(const char* logline, int len);
    void flush();

private:
    void append_unlocked(const char* logline, int len);

    const std::string basename_;
    const size_t rollSize_;
    const int flushInterval_;
    const int checkEveryN_;     //Check and determine whether flush

    int count_;

    std::unique_ptr<std::mutex> mutex_;
    time_t startOfPeriod_;
    time_t lastRoll_;
    time_t lastFlush_;
    std::unique_ptr<FileUtil::AppendFile> file_;

    const static int kRollPerSecond_ = 60*60*24;
};


#endif //CORNER_LOGFILE_H
