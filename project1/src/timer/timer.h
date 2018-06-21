#ifndef TIMER_H
#define TIMER_H
#include "Noncopyable.h"
#include <iostream>
#include <functional>
class Timer :wd::Noncopyable
{
public:
    typedef std::function<void()> TimerCallback;
    Timer(TimerCallback cb,int init_sec,int interval_sec);
    ~Timer();

    void start();
    void stop();
private:
    int _fd;
    TimerCallback _cb;
    bool _isstarted;

};

#endif /* TIMER_H */
