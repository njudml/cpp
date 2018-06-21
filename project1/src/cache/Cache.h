#ifndef CACHE_H
#define CACHE_H
#include <iostream>
#include <list>
#include <string>
#include <unordered_map>
using std::list;
using std::string;
using std::unordered_map;
struct Cachenode {
    string _key;
    string _value;
    Cachenode *_pre, *_next;
    Cachenode(const string& k, const string& v)
        : _key(k)
        , _value(v)
        , _pre(NULL)
        , _next(NULL)
    {
    }
};
class Cache {
public:
    Cache(int capacity);
    void readFromFile(const string& filename);

    void writeToFile(const string& filename);

    void update(const Cache& rhs);

    void addElement(const string& key, const string& value);

    void remove(Cachenode* node);

    void sethead(Cachenode* node);


    void debug();

    string query(const string& word);

private:
    unordered_map<string, Cachenode*> _hashMap;
    size_t _size;
    Cachenode *_head,*_tail;
};

#endif /* CACHE_H */
