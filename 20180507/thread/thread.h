#ifndef THREAD_H
#define THREAD_H
#include <pthread.h>
class Thread {
public:
    Thread();
    void start();
    void join();
    virtual ~Thread();
    bool isrunning() const { return _running; }

private:
    virtual void run() = 0;
    static void* threadfunc(void*);

private:
    pthread_t _pthread;
    bool _running;
};

#endif /* THREAD_H */
