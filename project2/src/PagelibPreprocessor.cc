#include "PagelibPreprocessor.h"
#include <fstream>
#include <math.h>
PagelibPreprocessor::PagelibPreprocessor(Configuration& conf)
    : _conf(conf)
{
    ifstream ifs(_conf.getConfigMap()["my_offsetlib"]);
    int docID, offset, len;
    while (ifs >> docID >> offset >> len) {
        _offsetlib[docID] = make_pair(offset, len);
    }
    ifs.close();
    ifstream ifss(_conf.getConfigMap()["my_pagelib"]);
    for (int i = 1; i <= _offsetlib.size(); ++i) {
        ifss.seekg(_offsetlib[i].first);
        char* s = new char[_offsetlib[i].second + 1]();

        ifss.read(s, _offsetlib[i].second);
        _pagelib.push_back(WebPage(s, _conf));
    }
    ifss.close();
}
void PagelibPreprocessor::cutRedundantPages()
{
    for (size_t i = 0; i != _pagelib.size() - 1; ++i) {
        for (size_t j = i + 1; j != _pagelib.size(); ++j) {
            if (_pagelib[i] == _pagelib[j]) //调用了重载运算符
            {
                _pagelib[j] = _pagelib[_pagelib.size() - 1];
                _pagelib.pop_back();
                --j;
            }
        }
    }
}

void PagelibPreprocessor::bulidInvertIndexTable()
{
    int docnum = _pagelib.size();
    map<string, int> wordcounts;
    for (auto i = _pagelib.begin(); i != _pagelib.end(); ++i) {
        for (auto j : i->getWordsMap()) {
            ++wordcounts[j.first];
        }
    }

    for (auto i : _pagelib) {
        map<string, int> wordmap = i.getWordsMap();
        map<string, double> wordidf;
        for (auto wordpair : wordmap) {
            double w = wordpair.second * log(docnum / (double)++wordcounts[wordpair.first]) / log(2);
            wordidf[wordpair.first] = w;
        }
        double wsum;
        for (auto word : wordidf) {
            wsum += word.second * word.second;
        }
        wsum = sqrt(wsum);
        for (auto& word : wordidf) {
            word.second = word.second / wsum;
            int docid = i.getDocId();
            _invertIndexTable[word.first].push_back(make_pair(docid, word.second));
        }
    }
}

void PagelibPreprocessor::storeOndisk()
{
    _offsetlib.clear();
    ofstream ofs(_conf.getConfigMap()["my_pagelib"]);
    for (auto page : _pagelib) {
        int offset = ofs.tellp();
        int len = page.getDoc().size();
        int docID = page.getDocId();
        ofs << page.getDoc();
        _offsetlib[docID] = make_pair(offset, len);
    }
    ofs.close();
    ofstream ofss(_conf.getConfigMap()["my_offsetlib"]);
    for (auto i : _offsetlib) {
        ofss << i.first << "\t" << i.second.first << "\t" << i.second.second << endl;
    }
    ofss.close();
    ofstream ofsss(_conf.getConfigMap()["my_invertindextable"]);
    for (auto j : _invertIndexTable) {
        ofsss << j.first << "\t";
        for (auto k : j.second)
            ofsss << k.first << "\t" << k.second << "\t";

        ofsss << endl;
    }
    ofsss.close();
}

void PagelibPreprocessor::doProcess()
{
     for (auto i : _pagelib)
         i.processDoc();
    cutRedundantPages();
    bulidInvertIndexTable();
    storeOndisk();
}
