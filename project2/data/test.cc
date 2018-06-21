#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;
string findword(const string& line, const string& word1, const string& word2)
{
    auto i = line.find(word1);
    auto j = line.find(word2);
    i += word1.size();
    cout << line.size() << endl;
    cout << j << endl;
    return line.substr(i, j-i);
}
int main(void)
{
    ifstream ifs("page_lib.dat");
    string line;
    getline(ifs, line);
    cout << line << endl;
    cout << findword(line, "<title>", "</title>") << endl;
    return 0;
}
