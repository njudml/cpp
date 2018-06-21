#ifndef MYINDEX_H
#define MYINDEX_H
#include "Configuration.h"
#include <fstream>
#include <unordered_map>
#include <set>
using std::ifstream;
using std::ofstream;
using std::unordered_map;
using std::set;

class MyIndex
{
public:
    MyIndex(){}
    virtual ~MyIndex(){}
    void creatindex(const string& dictpath);
    void store_index(const string& filename);
private:
    unordered_map<string,set<int>> _hashtable;    

};

#endif /*  */
