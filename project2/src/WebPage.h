#ifndef WEBPAGE_H
#define WEBPAGE_H
#include "zhSplitTool.h"
#include "Simhasher.hpp"
#include "Configuration.h"
#include <map>
#include <string>
#include <vector>
using namespace std;
using namespace simhash;

string findword(const string& line,const string& word1,const string& word2);
class WebPage {
public:
    WebPage(const string& doc,Configuration& conf);
    int getDocId() { return _docID; };
    string getDoc() { return _doc; }
    map<string, int>& getWordsMap() { return _wordsMap; }
    void simhash();

    friend bool operator ==(const WebPage& lhs,const WebPage& rhs);
    friend bool operator <(const WebPage& lhs,const WebPage& rhs);
    void processDoc();

private:
    const static size_t TOPK_NUMBER = 20;
    Configuration _conf;
    string _doc;
    int _docID;
    string _docTitle;
    string _docUrl;
    string _docContent;
    string _docSummary;
    Simhasher _simhasher;
    map<string, int> _wordsMap;
    uint64_t _u64;
};

    bool operator ==(const WebPage& lhs,const WebPage& rhs);
    bool operator <(const WebPage& lhs,const WebPage& rhs);
#endif /*  */
