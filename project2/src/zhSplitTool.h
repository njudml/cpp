#ifndef ZHSPLITTOOL_H
#define ZHSPLITTOOL_H
#include "../inc/cppjieba/Jieba.hpp"
#include "SplitTool.h"
const char* const DICT_PATH = "../data/dict/jieba.dict.utf8"; //最大概率法(MPSegment: Max Probability)分词所使用的词典路径
const char* const HMM_PATH = "../data/dict/hmm_model.utf8"; //隐式马尔科夫模型(HMMSegment: Hidden Markov Model)分词所使用的词典路径
const char* const USER_DICT_PATH = "../data/dict/user.dict.utf8"; //用户自定义词典路径
const char* const IDF_PATH = "../data/dict/idf.utf8"; //IDF路径
const char* const STOP_WORD_PATH = "../data/dict/stop_words.utf8"; //停用词路径

class ZhSplitTool : public SplitTool {
public:
    vector<string> cut(const string& sentence)
    {
        cppjieba::Jieba _jieba(DICT_PATH, HMM_PATH, USER_DICT_PATH, IDF_PATH, STOP_WORD_PATH);
        vector<string> words;
        _jieba.Cut(sentence, words);
        return words;
    }
};

#endif /*  */
