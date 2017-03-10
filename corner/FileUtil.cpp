//
// Created by demiaowu on 17-3-10.
//
#include <cstdio>
#include <fcntl.h>
#include <cerrno>
#include <unistd.h>
#include <iostream>

#include "FileUtil.h"

FileUtil::ReadSmallFile::ReadSmallFile(const StringArg& filename)
    :fd_(::open(filename.c_str(), O_RDONLY | O_CLOEXEC)), err_(0) {
        buffer_[0] = '\0';
        if (fd_ < 0) {
            err_ = errno;
            std::cerr << strerror(errno) << std::endl;
        }
    }

FileUtil::ReadSmallFile::~ReadSmallFile() {
    if (fd_ >= 0) {
        ::close(fd_);
    }
}

int FileUtil::ReadSmallFile::readToBuffer(int *size, const char **content) {
    if (fd_ >= 0) {
        ssize_t n = ::pread(fd_, buffer_, sizeof(buffer_)-1, 0);
        if (n >= 0) {
            if (size > 0)
                *size = static_cast<int>(n);
            buffer_[n] = '\0';
            *content = buffer_;
        }
        err_ = errno;
    } else {
        content = nullptr;
    }

    return err_;
}


int FileUtil::ReadSmallFile::readToBuffer(int *size) {
    if (fd_ >= 0) {
        ssize_t n = ::pread(fd_, buffer_, sizeof(buffer_)-1, 0);
        if (n >= 0) {
            if (size > 0)
                *size = static_cast<int>(n);
            buffer_[n] = '\0';
        }
        err_ = errno;
    }

    return err_;
}

FileUtil::AppendFile(const StringArg& filename)
        :fp_(::fopen(filename.c_str(), "ae")),
         writtenBytes_(0) {
    ::setbuffer(fp_, buffer_, sizeof(buffer_));
}
FileUtil::AppendFile::~AppendFile() {
    ::fclose(fp_);
}

void FileUtil::AppendFile::append(const char *logline, const size_t len) {
    size_t n = write(logline, len);
    size_t remain = len - n;

    while (remain > 0) {
        size_t x = write(logline+n, remain);
        if (0 == x) {
            int err = ferror(fp_);
            if (err) {
                //
            }
        }
        n += x;
        remain = len - n;
    }

    writtenBytes_ += len;
}

void FileUtil::AppendFile::flush() {
    ::fflush(fp_);
}

size_t FileUtil::AppendFile::write(const char *logline, size_t len) {
    return ::fwrite_unlocked(logline, 1, len, fp_);
}
