#ifndef CONFIGURATION_H
#define CONFIGURATION_H
#include <string>
#include <map>
using std::string;
using std::map;

class Configuration
{
public:
    Configuration(const string& filepath);
    virtual ~Configuration();

    map<string,string>& getConfigMap();
private:
    string _filepath;
    map<string,string>   _configMap;

};

#endif /* CONFIGURATION_H */
