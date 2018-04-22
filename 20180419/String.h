#ifndef STRING_H
#define STRING_H
#include <iostream>
#include <string.h>
using namespace std;
class String {
public:
    class mychar {
    public:
        mychar(String& str, int i)
            : _mstr(str)
            , index(i)
        {
        }
        mychar& operator=(char s)
        {
            if (*(int*)_mstr._str > 1) {
                _mstr.destory();
                char* tmp = _mstr._str;
                _mstr._str = new char[_mstr.size() + 5]();
                _mstr._str += 4;
                _mstr.init();
                strcpy(_mstr._str, tmp);
            }
            _mstr._str[index] = s;
            return *this;
        }
        char mygetchar()
        {
            return _mstr._str[index];
        }
        operator char()
        {
            return _mstr._str[index];
        }
        friend ostream& operator<<(ostream& os, mychar& m);

    private:
        String& _mstr;
        int index;
    };
    String();
    String(const char* p);
    String(const String& str);

    String& operator=(const String& str);

    mychar operator[](int index);
    const char& operator[](const int index) const;

    friend ostream& operator<<(ostream& os, const String& str);
    friend istream& operator>>(istream& is, String& str);
    friend ostream& operator<<(ostream& os, mychar& m);

    int refcount()
    {
        return *(int*)(_str - 4);
    }
    char* c_str()
    {
        return _str;
    }

    void init()
    {
        *(int*)(_str - 4) = 1;
    }
    void increase()
    {
        ++(*(int*)(_str - 4));
    }
    void destory()
    {
        if (--(*(int*)(_str - 4)) == 0)
            delete[](_str - 4);
    }

    size_t size();
    virtual ~String();

private:
    char* _str;
};
ostream& operator<<(ostream& os, const String& str);
istream& operator>>(istream& is, const String& str);
ostream& operator<<(ostream& os, String::mychar& m);
//{
//    //os<<m._mstr._str[m.index];
//    os << m.mygetchar();
//    return os;
//}
#endif /* STRING_H */
