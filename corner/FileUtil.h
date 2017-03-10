//
// Created by demiaowu on 17-3-10.
//

#ifndef CORNER_FILEUTIL_H
#define CORNER_FILEUTIL_H
#include <string>

#include "nocopyable.h"
#include "Slice.h"


namespace FileUtil {

    // read the file which size <= 6*1024. It can be used for the configure file.
    class ReadSmallFile : public nocopyable {
    public:
        ReadSmallFile(const StringArg& filename);
        ~ReadSmallFile();

        int readToBuffer(int* size, const char** content);
        int readToBuffer(int* size);

        const char* buffer() const { return buffer_; }
        int errorNumber() const { return err_; }

        static const int kMaxFileSize = 64*1024;
    private:
        int fd_;
        int err_;
        char buffer_[kMaxFileSize];
    };

    //un thread safety
    class AppendFile : public nocopyable {
    public:
        AppendFile(const StringArg& filename);

        ~AppendFile();

        void append(const char* logline, const size_t len);

        void flush();

        size_t writtenBytes() const { return writtenBytes_; }

    private:
        size_t write(const char* logline, size_t len);

        FILE* fp_;
        char buffer_[64*1024];
        size_t writtenBytes_;
    };

}

#endif //CORNER_FILEUTIL_H
