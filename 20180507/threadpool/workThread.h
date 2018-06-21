#ifndef WORKTHREAD_H
#define WORKTHREAD_H
#include "thread.h"
#include "threadpool.h"
class WorkThread
    : public Thread {
public:
    WorkThread(Threadpool& threadpool)
        : _threadpool(threadpool)
    {
    }
    ~WorkThread(){};

private:
    void run()
    {
        _threadpool.threadFunc();
    }

private:
    Threadpool& _threadpool;
};

#endif /* WORKTHREAD_H */
