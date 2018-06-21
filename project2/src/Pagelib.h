#ifndef PAGELIB_H
#define PAGELIB_H
#include "DirScanner.h"
#include "tinyxml2.h"
#include <boost/algorithm/string.hpp>
#include <boost/regex.hpp>
#include "WebPage.h"
#include <regex>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
class Pagelib {
public:
    Pagelib(DirScanner& dirScanner);
    
    void process(const string & filename);
    void create();
    void store_pagelib(const string& filepath);
    void store_offsetlib(const string& filepath);

private:
    DirScanner& _dirScanner;
    vector<string> _files;
    map<int, pair<int, int>> _offsetlib;
    vector<WebPage> _pagelib;
};

#endif /* PAGELIB_H */
