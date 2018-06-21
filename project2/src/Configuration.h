#ifndef CONFIGURATION_H
#define CONFIGURATION_H
#include <map>
#include <set>
#include <string>
using namespace std;
class Configuration {
public:
    Configuration(const string& filepath);
    map<string, string>& getConfigMap() { return _configMap; }
    set<string> getStopWordlist() { return _stopWordList; }

private:
    string _filepath;
    map<string, string> _configMap;
    set<string> _stopWordList;
};

#endif /* CONFIGURATION_H */
