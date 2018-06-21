#include "cache/Cachemanager.h"
#include "myTask.h"
#include "mydict.h"
#include "spellcorrectserver.h"
#include <functional>
#include <iostream>
#include <sstream>
using std::cout;
using std::endl;

namespace wd {

Spellcorrectserver::Spellcorrectserver()
    : _tcpServer(MyConf::getInstance()->getConf()["my_ip"].c_str(), str2unshort(MyConf::getInstance()->getConf()["my_port"]))
    , _threadpoll(str2int(MyConf::getInstance()->getConf()["my_thread_num"]), str2int(MyConf::getInstance()->getConf()["my_buff_size"]))
    , _timer(std::bind(&Cachemanager::perioduptate), str2int(MyConf::getInstance()->getConf()["my_init_time"]), str2int(MyConf::getInstance()->getConf()["my_update_time"]))
{
    Mydict* pMydict = Mydict::getInstance();
    pMydict->init(MyConf::getInstance()->getConf()["my_dict"].c_str(), MyConf::getInstance()->getConf()["my_cn_dict"].c_str());
}

void Spellcorrectserver::start()
{
    _threadpoll.start();
    _timer.start();
    using namespace std::placeholders;

    _tcpServer.setConnectionCallback(std::bind(&Spellcorrectserver::onConnection, this, _1));
    _tcpServer.setMessageCallback(std::bind(&Spellcorrectserver::onMessage, this, _1));
    _tcpServer.setCloseCallback(std::bind(&Spellcorrectserver::onclose, this, _1));
    _tcpServer.start();
}
void Spellcorrectserver::onConnection(TcpConnectionPtr conn)
{
    cout << "\n> " << conn->toString() << "has connected!" << endl;
    conn->send("> welcome to SpellCorrect Server!");
}

void Spellcorrectserver::onMessage(TcpConnectionPtr conn)
{
    string msg = conn->receive();
    cout << msg << endl;
    string data;
    int pos = msg.find('\n');
    if (pos >= 0)
        data = msg.substr(0, pos);
    else
        data = msg;
    MyTask task(data, conn);
    _threadpoll.addTask(std::bind(&MyTask::execute, &task));
}
void Spellcorrectserver::onclose(TcpConnectionPtr conn)
{
    cout << "\n> " << conn->toString() << " has closed!" << endl;
}
} //wd end;
