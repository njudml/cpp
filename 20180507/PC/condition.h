#ifndef CONDITION_H
#define CONDITION_H
#include "mutex.h"
#include "noncopyable.h"
#include <pthread.h>
class Condition : public Noncopyable {
public:
    Condition(Mutex& mutex);
    ~Condition();
    void wait();
    void notify();
    void notifyall();

private:
    pthread_cond_t _cond;
    Mutex& _mutex;
};

#endif /* CONDITION_H */
