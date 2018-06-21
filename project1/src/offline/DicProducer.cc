#include "DicProducer.h"
#include "enSplitTool.h"
#include <dirent.h>
#include <fstream>
#include <iostream>
#include <set>
#include <sstream>
#include <string.h>
#include <unistd.h>
using std::ifstream;
using std::ofstream;
using std::set;
using std::stringstream;
DicProducer::DicProducer(const string& dir)
    : _dir(dir)
    , _splitTool(new EnSplitTool())
{
    DIR* mydir;
    struct dirent* ptr;
    char base[200];
    if ((mydir = opendir(_dir.c_str())) == NULL) {
        perror("Open dir error");
        exit(1);
    }
    while ((ptr = readdir(mydir)) != NULL) {
        if (strcmp(ptr->d_name, ".") == 0 || strcmp(ptr->d_name, "..") == 0)
            continue;
        else {
            bzero(base, sizeof(base));
            sprintf(base, "%s/%s", _dir.c_str(), ptr->d_name);
            _files.push_back(string(base));
        }
    }
    closedir(mydir);
}

DicProducer::DicProducer(const string& dir, SplitTool* splitTool)
    : _dir(dir)
    , _splitTool(splitTool)
{
    DIR* mydir;
    struct dirent* ptr;
    char base[200];
    if ((mydir = opendir(_dir.c_str())) == NULL) {
        perror("Open dir error");
        exit(1);
    }
    while ((ptr = readdir(mydir)) != NULL) {
        if (strcmp(ptr->d_name, ".") == 0 || strcmp(ptr->d_name, "..") == 0)
            continue;
        else {
            bzero(base, sizeof(base));
            sprintf(base, "%s/%s", _dir.c_str(), ptr->d_name);
            _files.push_back(string(base));
        }
    }
    closedir(mydir);
}
DicProducer::~DicProducer()
{
    delete _splitTool;
}

void DicProducer::build_dict(const string& stopfile)
{
    int i = 0;
    for (auto filename : _files) {
        ifstream ifs(filename);
        stringstream buffer;
        buffer << ifs.rdbuf();
        string line(buffer.str());
        vector<string> words = _splitTool->cut(line);
        std::cout << line << std::endl;
        for (auto word : words)
            ++_dict[word];
        ifs.close();
        std::cout << "file " << i << " complate " << std::endl;
        i++;
    }
    ifstream ifss(stopfile);
    string word;
    vector<string> stopword;
    while (ifss >> word) {
        stopword.push_back(word);
    }
    for (auto s : stopword) {
        auto stopwordindict = _dict.find(s);
        if (stopwordindict != _dict.end())
            _dict.erase(stopwordindict);
    }
}
void DicProducer::build_cn_dict()
{
}

void DicProducer::store_dict(const char* filepath)
{
    ofstream ifs(filepath);
    for (auto pdict : _dict)
        ifs << pdict.first << "\t" << pdict.second << std::endl;
}
