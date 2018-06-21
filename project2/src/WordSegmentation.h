#ifndef WORDSEGMENTATION_H
#define WORDSEGMENTATION_H

#include "../inc/cppjieba/Jieba.hpp"
#include <iostream>
#include <string>
#include <vector>
using std::cout;
using std::endl;
using std::string;
using std::vector;

const char* const DICT_PATH = "../data/dict/jieba.dict.utf8";
const char* const HMM_MODEL_PATH = "../data/dict/hmm_model.utf8";
const char* const USER_DICT_PATH = "../data/dict/user.dict.utf8";
const char* const IDF_PATH = "../data/dict/idf.utf8";
const char* const STOP_WORDS_PATH = "../data/dict/stop_words.utf8";

class WordSegmentation {
public:
    WordSegmentation()
        : _jieba(DICT_PATH, HMM_MODEL_PATH, USER_DICT_PATH, IDF_PATH, STOP_WORDS_PATH)
    {
        cout << "cppjieba init!" << endl;
    }
    vector<string> operator()(const char* src)
    {
        vector<string> words;
        _jieba.CutAll(src, words);
        return words;
    }

private:
    cppjieba::Jieba _jieba;
};

#endif
