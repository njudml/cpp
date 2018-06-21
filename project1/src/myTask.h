#ifndef MYTASK_H
#define MYTASK_H
#include "networklib/TcpConnection.h"
#include "cache/Cache.h"
#include <queue>
#include <set>
#include <string>
#include <vector>

using std::priority_queue;
using std::set;
using std::string;
using std::vector;

struct MyResult {
    string _word;
    int _iFreq;
    int _iDist;
};
struct MyCompare {
    bool operator()(const MyResult& lhs, const MyResult& rhs)
    {
        if (lhs._iDist > rhs._iDist) {
            return true;
        } else if (lhs._iDist == rhs._iDist && lhs._iFreq < rhs._iFreq) {
            return true;
        } else if (lhs._iDist == rhs._iDist && lhs._iFreq == rhs._iFreq && lhs._word > rhs._word) {
            return true;
        } else
            return false;
    }
};

class Cache;
class MyTask {
public:
    MyTask(const string& queryword,const wd::TcpConnectionPtr& conn);

    void execute();
private:
        
    void queryIndexTable();
    void statistic(set<int>& iset);
    int distance(const string &rhs);
    void response();
private:
    string _queryword;
    wd::TcpConnectionPtr _conn;
    priority_queue<MyResult,vector<MyResult>,MyCompare> _resultQue;
};

#endif /* MYTASK_H */
