#include "Mutexlock.h"
#include "Condition.h"
#include <stdio.h>
#include <unistd.h>
Condition c;
Mutexlock m;
void * func(void *p)
{
//    c.lock();
    c.wait();
    printf("hello\n");
    sleep(3);
    c.unlock();
}

void * func1(void *p)
{
   // c.lock();
    c.wait();
    printf("hello\n");
    sleep(3);
    c.unlock();
}

int main(void)
{
    pthread_t pt1;
    pthread_t pt2;
    
    pthread_create(&pt1,NULL,func,NULL);
    pthread_create(&pt2,NULL,func1,NULL);
    sleep(1);
    c.notifyall();    
    pthread_join(pt1,NULL);
    pthread_join(pt2,NULL);
    return 0;
}
