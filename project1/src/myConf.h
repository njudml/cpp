#ifndef MYCONF_H
#define MYCONF_H
#include <fstream>
#include <map>
#include <string>
using std::ifstream;
using std::map;
using std::string;
class MyConf {
public:
    static MyConf* getInstance();
    map<string, string>& getConf() { return _map; }

    bool init(const string& filename);

private:
    MyConf() {}
    ~MyConf() {}

    static MyConf* _pinstance;
    map<string, string> _map;
};

#endif /* MYCONF_H */
