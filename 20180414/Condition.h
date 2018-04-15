#ifndef __CONDITION_H__
#define __CONDITION_H__
#include <pthread.h>
#include "Mutexlock.h"
class Condition :public Mutexlock
{
private:
    pthread_cond_t cond;    

public:
    Condition();
    virtual ~Condition();

    void wait();
    void notify();
    void notifyall();
};

Condition::Condition()
{
    pthread_cond_init(&cond,NULL);
}

Condition::~Condition()
{}

void Condition::wait()
{
   pthread_cond_wait(&cond,&mutex); 
}

void Condition::notify()
{
    pthread_cond_signal(&cond);
}

void Condition::notifyall()
{
   pthread_cond_broadcast(&cond); 
}

#endif
