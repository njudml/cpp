#ifndef MUTEX_H
#define MUTEX_H
#include "noncopyable.h"
#include <pthread.h>
class Mutex : public Noncopyable {
public:
    Mutex();
    ~Mutex();
    void lock();
    void unlock();
    bool islock() const { return _islocked; }
    pthread_mutex_t* getptr() { return &_mutex; }

private:
    pthread_mutex_t _mutex;
    bool _islocked;
};
class MutexLockGuard :public Noncopyable{
public:
    MutexLockGuard(Mutex& mutex)
        : _mutex(mutex)
    {
        _mutex.lock();
    }
    ~MutexLockGuard()
    {
        _mutex.unlock();
    }

private:
    Mutex& _mutex;
};
#endif /* MUTEX_H */
