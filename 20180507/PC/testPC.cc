///
/// @file    testThread.cc
/// @author  lemon(haohb13@gmail.com)
/// @date    2018-05-07 10:09:42
///

#include "taskQueue.h"
#include "thread.h"
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#include <iostream>
#include <memory>
using std::cout;
using std::endl;
using std::unique_ptr;


class Producer
    : public Thread {
public:
    Producer(TaskQueue& taskQue)
        : _taskQue(taskQue)
    {
    }

private:
    void run()
    {
        srand(clock());
        int cnt = 20;
        while (cnt--) {
            int number = rand() % 100;
            _taskQue.push(number);
            cout << ">>> producer a number = " << number << endl;
        }
    }

private:
    TaskQueue& _taskQue;
};

class Consumer
    : public Thread {
public:
    Consumer(TaskQueue& taskQue)
        : _taskQue(taskQue)
    {
    }

private:
    void run()
    {
        int cnt = 20;
        while (cnt--) {
            int number = _taskQue.pop();
            cout << "> consume a number = " << number << endl;
        }
    }

private:
    TaskQueue& _taskQue;
};
int main(void)
{
    TaskQueue taskQueue(10);
    unique_ptr<Thread> producer(new Producer(taskQueue));
    unique_ptr<Thread> consumer(new Consumer(taskQueue));
    producer->start();
    consumer->start();
    producer->join();
    consumer->join();
    return 0;
}
