#ifndef CACHEMANAGER_H
#define CACHEMANAGER_H
#include "Cache.h"
#include <iostream>
#include <vector>
#include <string>
using std::vector;
using std::string;
class Cachemanager
{
public:
    static void initCache(size_t sz,size_t cache_size,const string &filename);
    static Cache& getCache(size_t idx);
    static void perioduptate();
private:
    static vector<Cache> _cachelist;    

};

#endif /* CACHEMANAGER_H */
