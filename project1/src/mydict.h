#ifndef MYDICT_H
#define MYDICT_H
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>

using std::map;
using std::pair;
using std::set;
using std::string;
using std::vector;

size_t nBytesCode(const char ch)
{
    size_t i = 1;
    size_t n = 1;
    for (int j = 0; j < 5; j++) {
        if (ch & i << (6 - j))
            n++;
        else
            break;
    }

    return n;
}
class Mydict {
public:
    static Mydict* getInstance();
    void init(const char* dictpath, const char* cnDictpath);

    vector<pair<string, int>>& get_dict() { return _dict; }
    map<string, set<int>>& get_index_table() { return _index_table; }

private:
    Mydict() {}
    void read_from(const char* filepath);
    void record_to_index(int idx);

    static Mydict* _pinstance;
    vector<pair<string, int>> _dict;
    map<string, set<int>> _index_table;
};

#endif /* MYDICT_H */
