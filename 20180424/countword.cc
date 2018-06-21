#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <vector>
using namespace std;
class Countword {
public:
    void readfile(const string&);
    void savefile(const string&);
    bool isnumber(string&);

private:
    map<string, int> _map;
};
bool Countword::isnumber(string& s)
{
    istringstream iss(s);
    int number;
    if (iss >> number)
        return true;
    else
        return false;
}
void Countword::readfile(const string& filename)
{
    ifstream ifs(filename);
    string word;
    while (ifs >> word) {
        if (!isnumber(word)) {
            _map[word]++;
        }
    }
    ifs.close();
}

void Countword::savefile(const string& filename)
{
    ofstream ofs(filename);
    for (auto i : _map) {
        ofs << i.first << "\t" << i.second << endl;
    }
    ofs.close();
}

int main(void)
{
    Countword cw;
    cw.readfile("The_Holy_Bible.txt");
    cw.savefile("words.txt");
    return 0;
}
