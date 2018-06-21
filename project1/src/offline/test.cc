#include "../../include/cppjieba/Jieba.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using std::cout;
using std::endl;
using std::ifstream;
using std::string;
using std::vector;
const char* const DICT_PATH = "../../data/dict/jieba.dict.utf8"; //最大概率法(MPSegment: Max Probability)分词所使用的词典路径
const char* const HMM_PATH = "../../data/dict/hmm_model.utf8"; //隐式马尔科夫模型(HMMSegment: Hidden Markov Model)分词所使用的词典路径
const char* const USER_DICT_PATH = "../../data/dict/user.dict.utf8"; //用户自定义词典路径
const char* const IDF_PATH = "../../data/dict/idf.utf8"; //IDF路径
const char* const STOP_WORD_PATH = "../../data/dict/stop_words.utf8"; //停用词路径
int test(void)
{

    cppjieba::Jieba _jieba(DICT_PATH, HMM_PATH, USER_DICT_PATH, IDF_PATH, STOP_WORD_PATH);
    vector<string> words;
    ifstream ifs("../../data/art1/C3-Art0002.txt");
    string line;
    getline(ifs,line);
    cout << line << endl;
    _jieba.CutAll(line, words);

    for (auto s : words)
        cout << s << "\t";
    cout << endl;
    return 0;
}
int test1(void)
{
    cppjieba::Jieba _jieba(DICT_PATH, HMM_PATH, USER_DICT_PATH, IDF_PATH, STOP_WORD_PATH);
    vector<string> words;
    string str = "作为最低限度要求的指标或危险信号，也极有参考价值，本书附录的20多种报表，介绍了一个管理健全的出版社，应该有哪些在部门与部门之间沟通信息的工具，很有用";
    _jieba.CutAll(str, words);
    for (auto s : words)
        cout << s << "\t";
    cout << endl;

    return 0;
}
int main(void)
{
    test();
    return 0;
}
