#include "timer.h"
#include <unistd.h>
#include <sys/timerfd.h>
#include <stdio.h>
#include <poll.h>
#include <iostream>

int createTimefd()
{
    int fd=timerfd_create(CLOCK_REALTIME,0);
    if(fd==-1)
    {
        perror("timerfd_create");
    }
    return fd;
}

void setTimerfd(int fd,int init_sec,int interval_sec)
{
    struct itimerspec it;
    it.it_value.tv_sec=init_sec;
    it.it_value.tv_nsec=0;
    it.it_interval.tv_sec=interval_sec;
    it.it_interval.tv_nsec=0;
    int ret=timerfd_settime(fd,0,&it,NULL);
    if(ret==-1)
    {
        perror("timerfd_settime");
        exit(EXIT_FAILURE);
    }

}

void stopTimerfd(int fd)
{
    setTimerfd(fd,0,0);
}

int readTimerfd(int fd)
{
    uint64_t howmany;
    ssize_t ret=read(fd,&howmany,sizeof(howmany));
    if(ret!=sizeof(howmany))
    {
        perror("read error");
    }
    return howmany;
}

Timer::Timer(TimerCallback cb,int init_sec,int interval_sec)
    :_fd(createTimefd())
    ,_cb(cb)
     ,_isstarted(false)
{
    setTimerfd(_fd,init_sec,interval_sec);
}

void Timer::start()
{
    _isstarted=true;
    struct pollfd pfd;
    pfd.fd=_fd;
    pfd.events=POLLIN;
    while(_isstarted)
    {
        int ret=poll(&pfd,1,-1);
        if(ret==-1)
        {
            if(errno==EINTR)
                continue;
            else 
            {
                perror("poll error");
                exit(EXIT_FAILURE);
            }
        }
        else if(0==ret)
        {
            printf(">poll timeout!\n");
        }
        else{
            if(pfd.events==POLLIN)
            {
                readTimerfd(_fd);
                if(_cb)
                    _cb();
            }
        }
    }
}

void Timer::stop()
{
    if(_isstarted)
    {
        stopTimerfd(_fd);
        _isstarted=false;
    }
}

Timer::~Timer()
{
    if(_isstarted)
        stop();
}
