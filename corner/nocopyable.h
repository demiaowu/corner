//
// Created by demiaowu on 17-2-28.
//

#ifndef CORNER_NOCOPYABLE_H
#define CORNER_NOCOPYABLE_H

class nocopyable {
public:
    nocopyable() = default;
    ~nocopyable() = default;

protected:
    nocopyable(const nocopyable&) = delete;
    const nocopyable& operator = (const nocopyable&) = delete;

};

#endif //MYTEST_NOCOPYABLE_H
