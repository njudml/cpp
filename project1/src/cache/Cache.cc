#include "Cache.h"
#include <fstream>
#include <iostream>
#include <sstream>
using std::cout;
using std::endl;
using std::ifstream;
using std::istringstream;
using std::ofstream;
Cache::Cache(int capacity)
    : _size(capacity)
    , _head(NULL)
    , _tail(NULL)
{
}
void Cache::addElement(const string& key, const string& value)
{
    auto it = _hashMap.find(key);
    if (it != _hashMap.end()) {
        Cachenode* node = it->second;
        remove(node);
        sethead(node);
    } else {
        Cachenode* newnode = new Cachenode(key, value);
        if (_hashMap.size() >= _size) {
            auto iter = _hashMap.find(_tail->_key);
            remove(_tail);
            _hashMap.erase(iter);
        }
        sethead(newnode);
        _hashMap[key] = newnode;
    }
}
string Cache::query(const string& word)
{
    auto it = _hashMap.find(word);
    if (it != _hashMap.end()) {
        auto node = it->second;
        remove(node);
        sethead(node);
        return node->_value;
    } else {
        return string();
    }
}

void Cache::remove(Cachenode* node)
{
    if (node->_pre != NULL) {
        node->_pre->_next = node->_next;
    } else {
        _head = node->_next;
    }
    if (node->_next != NULL) {
        node->_next->_pre = node->_pre;
    } else {
        _tail = node->_pre;
    }
}

void Cache::sethead(Cachenode* node)
{
    node->_next = _head;
    node->_pre = NULL;
    if (_head != NULL) {
        _head->_pre = node;
    }
    _head = node;
    if (_tail == NULL) {
        _tail = _head;
    }
}

void Cache::readFromFile(const string& filename)
{
    ifstream ifs(filename.c_str());
    string line;
    while (getline(ifs, line)) {
        string key, value;
        istringstream iss(line);
        iss >> key >> value;
        addElement(key, value);
    }
    ifs.close();
}

void Cache::writeToFile(const string& filename)
{
    ofstream ofs(filename);
    for (auto it : _hashMap) {
        ofs << it.second->_key;
        ofs << it.second->_value << "\n";
    }
    ofs.close();
}

void Cache::update(const Cache& rhs)
{
    for (auto it : rhs._hashMap) {
        addElement(it.second->_key, it.second->_value);
    }
}

void Cache::debug()
{
    cout << "Cache begin" << endl;
    for (auto it : _hashMap) {
        cout << it.second->_key << "\t" << it.second->_value << endl;
    }
    cout << "Cache end" << endl;
}
