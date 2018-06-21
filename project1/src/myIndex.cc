#include "myIndex.h"
#include <vector>
#include <sstream>
using std::istringstream;
using std::vector;
void MyIndex::creatindex(const string& dictpath)
{
    ifstream ifs(dictpath);
    string line;
    vector<std::pair<string,int>> mydict;
    while(getline(ifs,line))
    {
       string word,frequency; 
        istringstream iss(line); 
        iss >> word >> frequency;
        mydict.push_back(make_pair(word,stoi(frequency)));
    }
    for(size_t i=0;i!=mydict.size();i++)
    {
        for(auto c:mydict[i].first) 
        {
            if(c!='\0')
            {
                    _hashtable[string(&c)].insert(i);
            }
        }
    }
}

void store_index(const string& filename)
{
    ofstream ofs(filename);
}

