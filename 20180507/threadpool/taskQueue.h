#ifndef TASKQUEUE_H
#define TASKQUEUE_H
#include "condition.h"
#include "thread.h"
#include <queue>

class Task;
class TaskQueue {
public:
    using Type = Task*;
    TaskQueue(int quesize);

    bool full() const;
    bool empty() const;

    void push(Type&);
    Type pop();

private:
    size_t _quesize;
    std::queue<Type> _que;
    Mutex _mutex;
    Condition _notfull;
    Condition _notempty;
};

#endif /* TASKQUEUE_H */
