#ifndef EDITDISTANCE_H
#define EDITDISTANCE_H
#include <iostream>
#include <string>
using std::string;
size_t nBytesCode(const char ch);
size_t length(const string& str);
int tripleMin(const int&a ,const int& b,const int& c);
int editDistance(const string &lhs,const string &rhs);

#endif /* EDITDISTANCE_H */
