#ifndef SINGLETON2_H
#define SINGLETON2_H
#include <iostream>
#include <pthread.h>
class Singleton {
public:
    Singleton* getInstance()
    {
        pthread_once(&t,sltInit);
        return _pstr;
    }
    static void sltInit()
    {
       _pstr=new Singleton(); 
        atexit(destory);
    }

    static void destory()
    {
        if(_pstr)
            delete _pstr;
    }
private:
    Singleton();
    ~Singleton();
    static pthread_once_t t;
    static Singleton* _pstr;
};
pthread_once_t Singleton::t = PTHREAD_ONCE_INIT;
Singleton* Singleton::_pstr;
#endif /* SINGLETON2_H */
