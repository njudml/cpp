#include <iostream>
#include <string.h>
using std::cout;
using std::endl;

class String {
private:
    char* _pstr;

public:
    String();
    String(const char* pstr);
    String(const String& rhs);
    String operator=(const String& rhs);
    void print();
    int size() const;
    ~String();
};
String::String()
    : _pstr(new char[1]())
{
    strcpy(_pstr, "\0");
}
int String::size() const
{
    return strlen(_pstr);
}
String::String(const char* pstr)
    : _pstr(new char[strlen(pstr) + 1]())
{
    strcpy(_pstr, pstr);
}
String::String(const String& rhs)
    : _pstr(new char[rhs.size() + 1]())
{
    strcpy(_pstr, rhs._pstr);
}
String String::operator=(const String& rhs)
{
    this->_pstr = new char[rhs.size() + 1]();
    strcpy(this->_pstr, rhs._pstr);
    return *this;
}
void String::print()
{
    cout << _pstr << endl;
}
String::~String()
{
    cout << "I am ~String" << endl;
    delete[] _pstr;
}
int main(void)
{
    String str1;
    str1.print();

    String str2 = "Hello,world";
    String str3("wangdao");

    str2.print();
    str3.print();

    String str4 = str3;
    str4.print();

    str4 = str2;
    str4.print();

    return 0;
}
