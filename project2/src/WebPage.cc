#include "Simhasher.hpp"
#include "WebPage.h"
#include <fstream>
#include <iostream>
#include <sstream>
string findword(const string& line, const string& word1, const string& word2)
{
    auto i = line.find(word1);
    auto j = line.find(word2);
    i += word1.size();
    return line.substr(i, j - i);
}
WebPage::WebPage(const string& doc, Configuration& conf)
    : _doc(doc)
    , _conf(conf)
    , _simhasher()
{
    string docid = findword(_doc, "<docid>", "</docid>");
    istringstream iss(docid);
    iss >> _docID;
    _docUrl = findword(_doc, "<url>", "</url>");
    _docTitle = findword(_doc, "<doctitle>", "</doctitle>");
    _docContent = findword(_doc, "<content>", "</content>");
}
void WebPage::processDoc()
{
    if (_docContent != string()) {
        simhash();
        cout << _u64 << endl;
        // ZhSplitTool zst;
        // vector<string> words = zst.cut(_docContent);
        // for (auto word : words) {
        //     ++_wordsMap[word];
        // }
        // set<string> stopwords = _conf.getStopWordlist();
        // for (auto s : stopwords) {
        //     auto stopfind = _wordsMap.find(s);
        //     if (stopfind != _wordsMap.end())
        //         _wordsMap.erase(stopfind);
        // }
    }
}
void WebPage::simhash()
{
    _simhasher.make(_docContent, 10, _u64);
}

bool operator==(const WebPage& lhs, const WebPage& rhs)
{
    int cnt = 0;
    uint64_t u1 = lhs._u64;
    uint64_t u2 = rhs._u64;
    u1 ^= u2;
    while (u1 && cnt <= 3) {
        u1 &= u1 - 1;
        cnt++;
    }
    if (cnt <= 3)
        return true;
    return false;
}
bool operator<(const WebPage& lhs, const WebPage& rhs)
{
    return lhs._docID < rhs._docID;
}
