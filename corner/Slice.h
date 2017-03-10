//
// Created by demiaowu on 17-3-5.
//

#ifndef CORNER_SLICE_H
#define CORNER_SLICE_H

#include <cstddef>
#include <cstring>
#include <string>
#include <cassert>

#include "nocopyable.h"

class Slice {
public:
    Slice():data_(""), size_(0) { }

    Slice(const char* d, size_t n):data_(d), size_(n) { }

    Slice(const char* d):data_(d), size_(strlen(d)) { }

    Slice(const std::string& str):data_(str.c_str()), size_(str.size()) {
//        std::cout << "Slice(const std::string& str) " << str << std::endl;
    }

//    Slice(const Slice& slice):data_(slice.size()) { }

    size_t size() const { return size_; }

    const char* data() const { return data_; }

    const char* c_str() const {
        return data_;
    }

    bool empty() const { return (0 == size_); }

    void clear() {
        data_ = "";
        size_ = 0;
    }

    char operator[](size_t n) const {
        assert(size_ <= n);
        return data_[n];
    }

    std::string ToString() const {
        return std::string(data_, size_);
    }
private:
    const char* data_;
    size_t size_;
};

// Used for C-style string argument to a function
// char*, std::string, StringArg can be adaptor
class StringArg {
public:
    StringArg(const char* str) :
            str_(str){
    }
    StringArg(const std::string& str):
            str_(str.c_str()) {
    }
    StringArg(const Slice& slice) :
            str_(slice.c_str()) {
    }

    const char* c_str() const {
        return str_;
    }

private:
    const char* str_;
};
#endif //CORNER_SLICE_H
