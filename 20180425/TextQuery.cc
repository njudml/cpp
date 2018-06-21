#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
using namespace std;
class TextQuery {
public:
    void readFile(const string&);
    void Query(const string&);

private:
    unordered_map<int, string> _file;
    map<string, set<int>> word2line;
};

void TextQuery::readFile(const string& filename)
{
    ifstream ifs(filename);
    string line;
    string word;
    int n = 0;
    while (getline(ifs, line)) {
        n++;
        auto mypair = make_pair(n, line);
        _file.insert(mypair);
        istringstream iss(line);
        while (iss >> word) {
            word2line[word].insert(n);
        }
    }
}

void TextQuery::Query(const string& word)
{
    if (word2line.find(word) == word2line.end()) {
        cout << "nodata" << endl;
    } else {
        cout<<word<<" occours "<<word2line[word].size()<<" times."<<endl; 
        for(auto i:word2line[word])
        {
            cout<<"\t(line "<<i<<") " <<_file[i]<<endl;
        }
    }
}
int main(void)
{
    string queryword("will");
    TextQuery tq;
    tq.readFile("china_daily.txt");
    tq.Query(queryword);
    return 0;
}
