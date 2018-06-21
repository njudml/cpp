#include "myConf.h"
#include <iostream>
#include <sstream>
using std::istringstream;
MyConf* MyConf::_pinstance=NULL;

MyConf* MyConf::getInstance()
{
    if (!_pinstance)
        _pinstance = new MyConf();
    return _pinstance;
}

bool MyConf::init(const string& filename)
{
    ifstream ifs(filename);
    if (!ifs) {
        std::cout << "file read error" << std::endl;
        return false;
    }
    string line;
    while (getline(ifs, line)) {
        string key, value;
        istringstream iss(line);
        iss >> key >> value;
        _map[key] = value;
    }

    ifs.close();
    return true;
}

