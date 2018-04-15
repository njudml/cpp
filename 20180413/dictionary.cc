#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <unistd.h>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::fstream;
using std::string;
using std::stringstream;
using std::vector;
using std::ofstream;
bool isnum(string& s);
typedef struct {
    string str;
    int count = 0;
} word;

class Dictionary {
public:
    void read(const string& filename);
    void store(const string& filename);

private:
    string filename;
    vector<word> w;
};

void Dictionary::read(const string& filename)
{
    fstream fs(filename);
    string str;
    size_t i;
    while (fs >> str) {
        if (isnum(str))
            continue;
        for (i = 0; i != w.size(); i++) {
            if (str == w[i].str) {
                w[i].count++;
                break;
            }
        }
        if (i == w.size()) {
            word w1;
            w1.str = str;
            w1.count = 1;
            w.push_back(w1);
        }
    }
    fs.close();
}

void Dictionary::store(const string& filename)
{
    ofstream os;
    os.open(filename);
    for (size_t i = 0; i != w.size(); i++) {
        os << w[i].str << " " << w[i].count << "\n";
    }
    os.close();
}

bool isnum(string& s)
{
    stringstream ss(s);
    double t;
    if (!(ss >> t))
        return false;
    return true;
}
int main(void)
{
    Dictionary dic;
    dic.read("The_Holy_Bible.txt");
    dic.store("dic.txt");

    return 0;
}
