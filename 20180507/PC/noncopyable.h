#ifndef NONCOPYABLE_H
#define NONCOPYABLE_H

class Noncopyable {
public:
    Noncopyable (){}
    ~Noncopyable (){}
    Noncopyable(Noncopyable&) = delete;
    Noncopyable& operator=(Noncopyable&) = delete;
};

#endif /* NONCOPYABLE_H */
