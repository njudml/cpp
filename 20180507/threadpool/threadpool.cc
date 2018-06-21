#include "threadpool.h"
#include "workThread.h"
#include <iostream>
using std::cout;
using std::endl;
Threadpool::Threadpool(size_t threadNum, size_t quesize)
    : _threadNum(threadNum)
    , _quesize(quesize)
    , _taskque(_quesize)
    , _isExit(false)
{
    _thread.reserve(_threadNum);
}

Threadpool::~Threadpool()
{
    if (!_isExit)
        stop();
}

void Threadpool::start()
{
    for (size_t i = 0; i != _threadNum; i++) {
        unique_ptr<Thread> ptmp(new WorkThread(*this));
        _thread.push_back(std::move(ptmp));
    }
    for (auto& ithread : _thread)
        ithread->start();
}
void Threadpool::stop()
{
    cout << "stop(): enter" << endl;
    if (!_isExit) {
        while (!_taskque.empty())
            ;
        _isExit = true;
    }
    for (auto& ithread : _thread)
        ithread->join();
    cout << "stop(): exit" << endl;
}

void Threadpool::addtask(Task* ptask)
{
    _taskque.push(ptask);
}

Task* Threadpool::gettask()
{
    return _taskque.pop();
}

void Threadpool::threadFunc()
{
    while (!_isExit) {
        if (_taskque.empty())
            break;
        Task* ptask = gettask();
        if (ptask)
            ptask->process();
    }
}
