#include "mydict.h"
#include <fstream>
#include <sstream>
using std::ifstream;
using std::istringstream;
Mydict* Mydict::_pinstance = NULL;
Mydict* Mydict::getInstance()
{
    if (!_pinstance)
        _pinstance = new Mydict();
    return _pinstance;
}

void Mydict::read_from(const char* filepath)
{
    ifstream ifs(filepath);
    string line;
    while (getline(ifs, line)) {
        istringstream iss(line);
        string key;
        int value;
        iss >> key >> value;
        _dict.push_back(std::make_pair(key, value));
    }
}

void Mydict::record_to_index(int idx)
{
    string key;
    string word = _dict[idx].first;
    for (size_t iidx = 0; iidx != word.size();) {
        char ch = word[iidx];
        size_t nBytes = nBytesCode(ch);
        key=word.substr(iidx,nBytes);
        iidx+=nBytes;
        _index_table[key].insert(idx);
    }
}

void Mydict::init(const char* dictpath, const char* cnDictpath)
{
    read_from(dictpath);
    read_from(cnDictpath);
    for (size_t idx = 0; idx != _dict.size(); ++idx) {
        record_to_index(idx);
    }
}
