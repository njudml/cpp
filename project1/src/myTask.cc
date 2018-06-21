#include "myTask.h"
#include "Editdistance.h"
#include "mydict.h"
#include "cache/Cachemanager.h"
#include "networklib/Thread.h"
#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <pthread.h>

using std::cout;
using std::endl;

MyTask::MyTask(const string& queryword,const wd::TcpConnectionPtr& conn)
    :_queryword(queryword)
     ,_conn(conn)
{}

void MyTask::execute()
{
    Cache & cache=Cachemanager::getCache(str2int(current_thread::threadname));
    string result=cache.query(_queryword);
    if(result!=string())
    {
        _conn->sendInLoop(result);
        return;
    }
    queryIndexTable();
    response();
}

void MyTask::queryIndexTable()
{
    auto indexTable=Mydict::getInstance()->get_index_table();
    string ch;
    for(int idx=0;idx!=_queryword.size();)
    {
        size_t nBytes=nBytesCode(_queryword[idx]);
        ch=_queryword.substr(idx,nBytes);
        idx+=nBytes;
        if(indexTable.count(ch))
        {
            cout << "indexTable has character "<< ch << endl;
            statistic(indexTable[ch]);
        }
    }
}

void MyTask::statistic(set<int>& iset)
{
    auto dict=Mydict::getInstance()->get_dict();
    auto iter=iset.begin();
    for(;iter!=iset.end();iter++)
    {
        string rhsword=dict[*iter].first;
        int idist=distance(rhsword);
        if(idist<3)
        {
            MyResult res;
            res._word=rhsword;
            res._iDist=idist;
            res._iFreq=dict[*iter].second;
            _resultQue.push(res);
        }
    }
}

void MyTask::response()
{
    if(_resultQue.empty())
    {
        string result("no answer");
        _conn->sendInLoop(result);
    }
    else{
        MyResult result=_resultQue.top();
        _conn->sendInLoop(result._word);
        Cache & cache=Cachemanager::getCache(str2int(current_thread::threadname));
        cache.addElement(_queryword,result._word);
    }
    cout << "response client" << endl;
}

int MyTask::distance(const string &rhs)
{
    return editDistance(_queryword,rhs); 
}
