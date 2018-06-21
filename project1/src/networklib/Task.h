#ifndef TASK_H
#define TASK_H
#include "TcpServer.h"
#include "Myresult.h"
#include <queue>
#include <string>
using std::string;
using namespace wd;
class Task
{
public:
    Task();
    virtual ~Task();
    void process();

    int calcDistance(std::string &rhs);
private:
    TcpConnectionPtr _conn;
    string _query;
    std::priority_queue<MyResult> _que ;

};

#endif /* TASK_H */
