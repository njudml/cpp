#include "String.h"
#include <string.h>
String::String()
    : _str(new char[5]())
{
    _str += 4;
    init();
}

String::String(const char* p)
    : _str(new char[5 + strlen(p)]())
{
    _str += 4;
    strcpy(_str, p);
    init();
}

String::String(const String& str)
    : _str(str._str)
{
    increase();
}
String::~String()
{
}
size_t String::size()
{
    return strlen(_str);
}

String& String::operator=(const String& str)
{
    if (this != &str) {
        destory();
        _str = str._str;
        increase();
    }
    return *this;
}

String::mychar String::operator[](int index)
{
    return mychar(*this,index);
}
ostream& operator<<(ostream &os,String::mychar &m)
{
    //os<<m._mstr._str[m.index];
    os << m.mygetchar();
    return os;
}

const char& String::operator[](const int index) const
{
    return _str[index];
}

ostream& operator<<(ostream& os, const String& str)
{
    os << str._str;
    return os;
}

istream& operator>>(istream& is, String& str)
{
    char tmp[1024] = { 0 };
    is >> tmp;
    str._str += 4;
    str.init();
    strcpy(str._str, tmp);
    return is;
}
