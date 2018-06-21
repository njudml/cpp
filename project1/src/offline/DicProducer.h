#ifndef DICPRODUCER_H
#define DICPRODUCER_H
#include "SplitTool.h"
#include "enSplitTool.h"
#include <iostream>
#include <unordered_map>
#include <string>
#include <stdio.h>
using std::unordered_map;
using std::string;
class DicProducer {
public:
    DicProducer(const string& dir);
    DicProducer(const string& dir, SplitTool* splitTool);
    ~DicProducer();

    void build_dict(const string& stopfile);
    void build_cn_dict();
    void store_dict(const char* filepath);

private:
    string _dir;
    vector<string> _files;
    unordered_map<string, int> _dict;
    SplitTool* _splitTool;
};

#endif /* DICPRODUCER_H */
