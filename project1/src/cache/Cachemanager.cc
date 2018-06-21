#include "Cachemanager.h"
#include <fstream>
using std::ifstream;
vector<Cache> Cachemanager::_cachelist;
void Cachemanager::initCache(size_t sz,size_t cache_size,const string &filename)
{
    _cachelist.resize(sz);
    Cache cache(cache_size);
    cache.readFromFile(filename);
    for(size_t i=0;i!=sz;i++)
        _cachelist.push_back(cache);
}

Cache& Cachemanager::getCache(size_t idx)
{
    return _cachelist[idx];
}

void Cachemanager::perioduptate()
{
    for(size_t i=1;i!=_cachelist.size();i++)
    {
        _cachelist[0].update(_cachelist[i]);
    }
    for(size_t i=1;i!=_cachelist.size();i++)
    {
        _cachelist[i].update(_cachelist[0]);
    }
    
    //write to file;
    
}
