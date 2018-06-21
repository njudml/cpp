#ifndef WORDQUERY_H
#define WORDQUERY_H
#include "zhSplitTool.h"
#include "Configuration.h"
#include "WebPage.h"
#include <string>
#include <unordered_map>

class WordQuery {
public:
    WordQuery();
    virtual ~WordQuery();

private:
    Confirguration& _conf;
    unordered_map<int,Webpage>

};

#endif /*  */
