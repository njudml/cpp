#ifndef THREADPOOL_H
#define THREADPOOL_H
#include "taskQueue.h"
#include "thread.h"
#include <memory>
#include <vector>
using std::unique_ptr;
using std::vector;

class Task {
public:
    virtual void process() = 0;
};
class Threadpool {
public:
    friend class WorkThread;

    Threadpool(size_t threadNum, size_t quesize);
    ~Threadpool();

    void start();
    void stop();
    void addtask(Task*);

private:
    Task* gettask();
    void threadFunc();

private:
    size_t _threadNum;
    size_t _quesize;
    vector<unique_ptr<Thread>> _thread;
    TaskQueue _taskque;
    bool _isExit;
};

#endif /* THREADPOOL_H */
