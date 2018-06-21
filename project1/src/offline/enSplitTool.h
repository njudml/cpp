#ifndef ENSPLITTOOL_H
#define ENSPLITTOOL_H
#include "SplitTool.h"
#include <ctype.h>
#include <sstream>
using std::istringstream;

class EnSplitTool : public SplitTool {
public:
    EnSplitTool() {}
    virtual ~EnSplitTool() {}

    vector<string> cut(const string& sentence)
    {
        istringstream iss(sentence);
        string word;
        vector<string> words;
        while (iss >> word) {
            cutword(word);
            for (auto& c : word)
                c = tolower(c);
            if (word.size() != 0)
                words.push_back(word);
        }
        return words;
    }

private:
    void cutword(string& word)
    {
        for (auto it = word.begin(); it != word.end();) {
            if (!isalpha(*it))
                it = word.erase(it);
            else
                ++it;
        }
    }
};

#endif /* ENSPLITTOOL_H */
