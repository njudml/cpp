#include "Configuration.h"
#include <fstream>
#include <sstream>
Configuration::Configuration(const string& filepath)
    : _filepath(filepath)
{
    ifstream ifs(_filepath);
    string line;
    while (getline(ifs, line)) {
        istringstream iss(line);
        string key, value;
        iss >> key >> value;
        _configMap[key] = value;
    }
    ifs.close();
    ifstream ifss(_configMap["my_zh_stopwords"]);
    string word;
    while (ifss >> word) {
        _stopWordList.insert(word);
    }
    ifss.close();
}
