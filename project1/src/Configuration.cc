#include "Configuration.h"
#include <fstream>
#include <sstream>
using std::ifstream;
using std::istringstream;
Configuration::Configuration(const string& filepath)
    : _filepath(filepath)
{
    ifstream ifs(_filepath);
    string line;
    while (getline(ifs, line)) {
        istringstream iss(line);
        string first, second;
        iss >> first;
        iss >> second;
        _configMap.insert(std::make_pair(first, second));
    }
    ifs.close();
}
Configuration::~Configuration()
{
}
map<string, string>& Configuration::getConfigMap()
{
    return _configMap;
}
