#include "String.h"
using std::cin;
using std::cout;

String::String()
    : _pstr(new char[1]())
{
}

String::String(const char* str)
    : _pstr(new char[strlen(str) + 1]())
{
    strcpy(_pstr, str);
}

String::String(const String& rhs)
    : _pstr(new char[rhs.size() + 1]())
{
    strcpy(_pstr, rhs._pstr);
}

std::size_t String::size() const
{
    return strlen(_pstr);
}

const char* String::c_str() const
{
    return _pstr;
}

String::~String()
{
    delete[] _pstr;
}

String& String::operator=(const String& rhs)
{
    if (this != &rhs) {
        delete[] _pstr;
        _pstr = new char[rhs.size() + 1]();
        strcpy(_pstr, rhs._pstr);
    }
    return *this;
}

String& String::operator=(const char* str)
{
    delete[] _pstr;
    _pstr = new char[strlen(str) + 1]();
    strcpy(_pstr, str);
    return *this;
}

String& String::operator+=(const String& rhs)
{
    String tmp = *this;
    delete[] _pstr;
    _pstr = new char[tmp.size() + rhs.size() + 1]();
    strcpy(_pstr, tmp._pstr);
    strcat(_pstr, rhs._pstr);
    return *this;
}
String& String::operator+=(const char* str)
{
    String tmp = str;
    return *this += tmp;
}

char& String::operator[](std::size_t index)
{
    if (index > this->size()) {
        static char nullchar = 0;
        return nullchar;
    } else
        return _pstr[index];
}

const char& String::operator[](std::size_t index) const
{
    if (index > this->size()) {
        static char nullchar = 0;
        return nullchar;
    } else
        return _pstr[index];
}

bool operator==(const String& lhs, const String& rhs)
{
    return !strcmp(lhs._pstr, rhs._pstr);
}

bool operator!=(const String& lhs, const String& rhs)
{
    return !(lhs == rhs);
}

bool operator>(const String& lhs, const String& rhs)
{
    return strcmp(lhs._pstr, rhs._pstr) > 0;
}

bool operator<(const String& lhs, const String& rhs)
{
    return strcmp(lhs._pstr, rhs._pstr) < 0;
}

bool operator<=(const String& lhs, const String& rhs)
{
    return !(lhs > rhs);
}

bool operator>=(const String& lhs, const String& rhs)
{
    return !(lhs < rhs);
}

std::ostream& operator<<(std::ostream& os, const String& s)
{
    os << s._pstr;
    return os;
}

std::istream& operator>>(std::istream& is, String& s)
{
    char m[1024] = { 0 };
    is >> m;
    s = m;
    return is;
}

String operator+(const String& lhs, const String& rhs)
{
    String tmp;
    tmp += lhs;
    tmp += rhs;
    return tmp;
}

String operator+(const String& lhs, const char* str)
{
    String tmp;
    tmp += lhs;
    tmp += str;
    return tmp;
}

String operator+(const char* str, const String& rhs)
{
    String tmp;
    tmp += str;
    tmp += rhs;
    return tmp;
}
