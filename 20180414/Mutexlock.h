#ifndef __MUTEXLOCK_H__
#define __MUTEXLOCK_H__
#include <pthread.h>
class Mutexlock
{
protected:
    pthread_mutex_t mutex;

public:
    Mutexlock();
    virtual ~Mutexlock();

    void lock();
    void unlock();
};

Mutexlock::Mutexlock()
{
    pthread_mutex_init(&mutex,NULL);
}

Mutexlock::~Mutexlock()
{
}

void Mutexlock::lock()
{
    pthread_mutex_lock(&mutex);
}

void Mutexlock::unlock()
{
    pthread_mutex_unlock(&mutex);
}
#endif
