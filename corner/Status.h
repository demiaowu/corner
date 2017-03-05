//
// Created by demiaowu on 17-3-5.
//

#ifndef CORNER_STATUS_H
#define CORNER_STATUS_H


#include "Slice.h"

const char* CopyState(const char* s);

class Status {
public:
    Status():state_(nullptr){}
    ~Status() { delete state_; state_ = nullptr; }

    static Status NotFound(const Slice& msg, const Slice& msg2 = Slice()) {
        return Status(kNotFound, msg, msg2);
    }

    static Status Corruption(const Slice& msg, const Slice& msg2 = Slice()) {
        return Status(kCorruption, msg, msg2);
    }

    static Status NotSupport(const Slice& msg, const Slice& msg2 = Slice()) {
        return Status(kNotSupport, msg, msg2);
    }

    static Status InvalidArgument(const Slice& msg, const Slice&  msg2 = Slice()) {
        return Status(kInvalidArgument, msg, msg2);
    }

    static Status IoError(const Slice& msg, const Slice& msg2 = Slice()) {
        return Status(kIoError, msg, msg2);
    }

    Status(const Status& s);
    void operator=(const Status& s);

    bool isOk() const { nullptr == state_; }
    bool isNotFound() const { kNotFound == code(); }
    bool isCorruption() const { kCorruption == code(); }
    bool isNotSupport() const { kNotSupport == code(); }
    bool isInvalidArgument() const { kInvalidArgument == code(); }
    bool isIoError() const { kIoError == code(); }

    std::string ToString() const;

private:
    // Ok status has a NULL state_, Otherwise, state_ is a new[] char array
    // state_[0...3] is the length of message, note that the length not include the header length--5
    // state_[4]     status code
    // state_[5...]  status message
    const char* state_;
    enum Code {
        kOk = 0,
        kNotFound = 1,
        kCorruption = 2,
        kNotSupport = 3,
        kInvalidArgument = 4,
        kIoError = 5
    };

    Code code() const {
        return (nullptr == state_) ? kOk : static_cast<Code>(state_[4]);
    }

    Status(Code code, const Slice& msg, const Slice& msg2);
};

inline Status::Status(const Status &s) {
    state_ = (nullptr == state_) ? nullptr : CopyState(s.state_);
}

inline void Status::operator=(const Status &s) {
    if (state_ != s.state_) {
        delete[] state_;
        state_ = (nullptr == s.state_) ? nullptr : CopyState(s.state_);
    }
}


#endif //MYTEST_STATUS_H
