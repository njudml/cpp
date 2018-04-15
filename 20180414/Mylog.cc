#include "log4cpp/Appender.hh"
#include "log4cpp/Category.hh"
#include "log4cpp/FileAppender.hh"
#include "log4cpp/Layout.hh"
#include "log4cpp/OstreamAppender.hh"
#include "log4cpp/PatternLayout.hh"
#include "log4cpp/Priority.hh"
#include <iostream>
#include <string>

using namespace ::std;

class Mylog {
private:
    static Mylog* _log;

    log4cpp::Category& root;
   // log4cpp::OstreamAppender* osapp;
   // log4cpp::FileAppender* fapp;
   // log4cpp::PatternLayout* playout1;
   // log4cpp::PatternLayout* playout2;

private:
    Mylog();
    ~Mylog();

public:
    void warn(int s1, const string& s2, const string& s3, const string& s);
    void error(int s1, const string& s2, const string& s3, const string& s);
    void debug(int s1, const string& s2, const string& s3, const string& s);
    void info(int s1, const string& s2, const string& s3, const string& s);

    static Mylog* getInstance();
    static void destory();
};

Mylog* Mylog::_log = NULL;

Mylog::Mylog()
    : root(log4cpp::Category::getRoot())
   // , osapp(new log4cpp::OstreamAppender("osapp", &cout))
   // , fapp(new log4cpp::FileAppender("fapp", "Mylog.txt"))
   // , playout1(new log4cpp::PatternLayout())
   // , playout2(new log4cpp::PatternLayout())
{
    log4cpp::OstreamAppender* osapp=new log4cpp::OstreamAppender("osapp", &cout);
    log4cpp::FileAppender* fapp=new log4cpp::FileAppender("fapp", "Mylog.txt");
    log4cpp::PatternLayout* playout1=new log4cpp::PatternLayout();
    log4cpp::PatternLayout* playout2=new log4cpp::PatternLayout();
    cout << "Mylog()" << endl;
    playout1->setConversionPattern("%d:%p %c %m%n");
    playout2->setConversionPattern("%d:%p %c %m%n");

    osapp->setLayout(playout1);
    fapp->setLayout(playout2);

    root.setPriority(701);
    root.setAppender(osapp);
    root.setAppender(fapp);
}

Mylog::~Mylog()
{
    log4cpp::Category::shutdown();
    // delete osapp;
    // delete fapp;
    // delete playout1;
    // delete playout2;
}

Mylog* Mylog::getInstance()
{
    if (_log == NULL)
        _log = new Mylog();
    return _log;
}

void Mylog::destory()
{
    if (_log)
        delete _log;
}

void Mylog::warn(int s1, const string& s2, const string& s3, const string& s)
{
    root << log4cpp::Priority::WARN << s << "\n"
         << s1 << "\t" << s2 << "\t" << s3;
}
void Mylog::error(int s1, const string& s2, const string& s3, const string& s)
{
    root << log4cpp::Priority::ERROR << s << "\n"
         << s1 << "\t" << s2 << "\t" << s3;
}

void Mylog::debug(int s1, const string& s2, const string& s3, const string& s)
{
    root << log4cpp::Priority::DEBUG << s << "\n"
         << s1 << "\t" << s2 << "\t" << s3;
}

void Mylog::info(int s1, const string& s2, const string& s3, const string& s)
{
    root << log4cpp::Priority::INFO << s << "\n"
         << s1 << "\t" << s2 << "\t" << s3;
}
#define warn(args) warn(__LINE__, __func__, __FILE__, args);
#define error(args) error(__LINE__, __func__, __FILE__, args);
#define debug(args) debug(__LINE__, __func__, __FILE__, args);
#define info(args) info(__LINE__, __func__, __FILE__, args);

int main(void)
{
    Mylog* log = Mylog::getInstance();
    log->warn("log warn");
    log->error("log error");
    log->debug("log debug");
    log->info("log info");

    Mylog::destory();
    return 0;
}
