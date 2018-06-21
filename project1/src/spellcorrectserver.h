#ifndef SPELLCORRECTSERVER_H
#define SPELLCORRECTSERVER_H
#include "networklib/TcpServer.h"
#include "networklib/Threadpool.h"
#include "timer/timerThread.h"
#include <string>
using std::string;
namespace wd {
class Spellcorrectserver {
public:
    Spellcorrectserver ();

    void start();

    void onConnection(TcpConnectionPtr conn);
    void onMessage(TcpConnectionPtr conn);
    void onclose(TcpConnectionPtr conn);
private:
    TcpServer _tcpServer;
    Threadpool _threadpoll;
    TimerThread _timer;
};
}
#endif /* SPELLCORRECTSERVER_H */
