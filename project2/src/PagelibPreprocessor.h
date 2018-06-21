#ifndef PAGELIBPREPROCESSOR_H
#define PAGELIBPREPROCESSOR_H
#include "WebPage.h"
#include "Configuration.h"
#include <unordered_map>
using namespace std;
class PagelibPreprocessor
{
public:
    PagelibPreprocessor(Configuration& conf);
    void doProcess();

private:
    void cutRedundantPages();
    void bulidInvertIndexTable();
    void storeOndisk();
private:
    Configuration& _conf;
    vector<WebPage> _pagelib;
    unordered_map<int,pair<int,int>> _offsetlib;
    unordered_map<string,vector<pair<int,double>>> _invertIndexTable;

};

#endif /*  */
