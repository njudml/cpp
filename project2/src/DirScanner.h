#ifndef DIRSCANNER_H
#define DIRSCANNER_H
#include <dirent.h>
#include <fstream>
#include <string>
#include <unistd.h>
#include <vector>
#include <set>
using namespace std;
class DirScanner {
public:
    DirScanner(const string& dir);
    set<string> getFiles() { return _vecFilesfiles; }

private:
    set<string> _vecFilesfiles;
};

#endif /* DIRSCANNER_H */
