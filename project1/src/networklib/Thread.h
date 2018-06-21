 ///
 /// @file    Thread.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-05-07 09:50:54
 ///
 
#ifndef __WD_THREAD_H__
#define __WD_THREAD_H__

#include "Noncopyable.h"
#include <pthread.h>
#include <functional>
#include <sstream>
#include <string>

using std::string;
namespace current_thread
{
    extern __thread const char* threadname;
}

inline string int2str(int number)
{
    std::ostringstream oss;
    oss << number;
    return oss.str();
}

inline unsigned short str2unshort(const string & str)
{
    unsigned short port;
    std::istringstream iss(str);
    iss >> port;
    return port;
}

inline int str2int(const string & str)
{
    int number;
    std::istringstream iss(str);
    iss >> number;
    return number;
}

namespace wd
{

//这是一个具体类
class Thread
: Noncopyable
{
public:
	typedef std::function<void()> ThreadCallback;
	Thread(ThreadCallback && cb,const string& name=string());
	~Thread();

	void start();
	void join();

	bool isRunning() const{	return _isRunning;	}

private:
	static void * threadFunc(void * arg);//线程的执行体
private:
	pthread_t _pthid;
	bool _isRunning;
	ThreadCallback _cb;
    string _name;
};

}//end of namespace wd
#endif 



