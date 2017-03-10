//
// Created by root on 17-3-10.
//

#include "LogFile.h"

LogFile::LogFile(const std::string &basename, size_t rollSize, bool threadSafe, int flushInterval, int checkEveryN)
        : basename_(basename),
          rollSize_(rollSize),
          flushInterval_(flushInterval),
          checkEveryN_(checkEveryN),
          count_(0),
          mutex_(threadSafe ? new std::mutex(): nullptr),
          startOfPeriod_(0),
          lastRoll_(0),
          lastFlush_(0) {

}

LogFile::~LogFile() {

}

void LogFile::append(const char *logline, int len) {
    if (nullptr != mutex_) {
        std::lock_guard<std::mutex>(*mutex_);
        append_unlocked(logline, len);
    } else {
        append_unlocked(logline, len);
    }
}

void LogFile::append_unlocked(const char *logline, int len) {
    file_->append(logline, len);

    if (file_->writtenBytes() > rollSize_) {
        //
    } else {
        ++ count_;
        if (count_ >= checkEveryN_) {
            time_t now = ::time(nullptr);
            time_t thisPeriod = now / kRollPerSecond_ * kRollPerSecond_;
        }

    }
}

void LogFile::flush() {
    if (nullptr != mutex_) {
        std::lock_guard<std::mutex>(*mutex_);
        file_->flush();
    } else {
        file_->flush();
    }
}
