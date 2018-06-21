#include "taskQueue.h"
TaskQueue::TaskQueue(int quesize)
    : _quesize(quesize)
    , _mutex()
    , _notfull(_mutex)
    , _notempty(_mutex)
{
}

bool TaskQueue::full() const
{
    return _que.size() == _quesize;
}

bool TaskQueue::empty() const
{
    return _que.size() == 0;
}

void TaskQueue::push(Type& type)
{
    MutexLockGuard autolock(_mutex);
    while (full()) {
        _notfull.wait();
    }
    _que.push(std::move(type));
    _notempty.notify();
}
TaskQueue::Type TaskQueue::pop()
{
    MutexLockGuard autolock(_mutex);
    while (empty()) {
        _notempty.wait();
    }
    Type tmp = _que.front();
    _que.pop();
    _notfull.notify();
    return tmp;
}
