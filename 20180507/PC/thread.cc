#include "thread.h"
Thread::Thread()
    : _pthread(0)
    , _running(false)
{
}
Thread::~Thread()
{
    if (isrunning()) {
        pthread_detach(_pthread);
        _running = false;
    }
}

void Thread::start()
{
    pthread_create(&_pthread, NULL, threadfunc, this);
    _running = true;
}
void Thread::join()
{
    if (isrunning())
        pthread_join(_pthread, NULL);
}

void* Thread::threadfunc(void* args)
{
    Thread* tmp = static_cast<Thread*>(args);
    if (tmp)
        tmp->run();
    return NULL;
}
