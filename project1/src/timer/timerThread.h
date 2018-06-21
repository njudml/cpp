#ifndef TIMERTHREAD_H
#define TIMERTHREAD_H
#include "timer.h"
#include "../networklib/Thread.h"
#include <functional>
namespace wd {
class TimerThread {
public:
    typedef std::function<void()> TimerThreadCallback;

    TimerThread (TimerThreadCallback cb,int init_sec,int interval_sec);

    void start();
    void stop();
private:
    Timer _timer;
    Thread _thread;
};
} //end wd
#endif /* TIMERTHREAD_H */
