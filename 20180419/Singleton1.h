#ifndef SINGLETON1_H
#define SINGLETON1_H
#include <iostream>
class Singleton {
    class autoRelease {
    public:
        ~autoRelease()
        {
            if (_pstr)
                delete _pstr;
        }
    };

public:
    static Singleton* getInctance()
    {
        if (_pstr == NULL)
            _pstr = new Singleton();
        return _pstr;
    }

private:
    Singleton();
    ~Singleton();
    static Singleton* _pstr;
    static autoRelease ar;
};
Singleton* Singleton::_pstr=Singleton::getInctance();
Singleton::autoRelease Singleton::ar;

#endif /* SINGLETON1_H */
