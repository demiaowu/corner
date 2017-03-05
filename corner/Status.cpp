//
// Created by demiaowu on 17-3-5.
//

#include "Status.h"

const char* CopyState(const char* s) {
    int32_t size;
    memcpy(&size, s, sizeof(size));
    char* result = new char[size+5];
    memcpy(result, s, size+5);

    return result;
}

Status::Status(Code code, const Slice& msg, const Slice& msg2) {
    assert(kOk != code);

    const uint32_t len1 = msg.size();
    const uint32_t len2 = msg2.size();
    const uint32_t size = len1 + (len2 > 0 ? (len2+2) : 0);

    char* result = new char[size + 5];
    memcpy(result, &size, sizeof(size));
    result[4] = static_cast<char>(code);
    memcpy(result+5, msg.data(), msg.size());
    if (len2 > 0) {
        result[len1 + 5] = ':';
        result[len1 + 6] = ' ';
    }
    state_ = result;
}

std::string Status::ToString() const {
    const Code code = this->code();

    const char* code_str;
    switch (code) {
        case kOk:
            code_str = "Ok";
            break;
        case kNotFound:
            code_str = "NotFound";
            break;
        case kCorruption:
            code_str = "Corruption";
            break;
        case kNotSupport:
            code_str = "NotSupport";
            break;
        case kInvalidArgument:
            code_str = "InvalidArgument";
            break;
        case kIoError:
            code_str = "IoError";
            break;
        default:
            code_str = "UnKnow code";
            break;
    }

    return code_str;
}