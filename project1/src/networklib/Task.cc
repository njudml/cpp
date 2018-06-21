#include "Task.h"
#include <vector>
using std::vector;
int Task::calcDistance(string& rhs)
{
    auto Alen = _query.length();
    auto Blen = rhs.length();
    vector<vector<int>> d(Alen); 
    for(size_t i=0;i!=d.size();i++)
        d[i].resize(Blen);
    for(decltype(Alen) i=0;i<Alen;i++)
    {
        d[i][0]=i;
    }
    for(decltype(Alen) j=0;j<Blen;j++)
    {
        d[0][j]=j;
    }
    for(decltype(Alen) i=1;i<Alen;i++)
        for(decltype(Blen) j=1;j<Blen;j++)
        {
            if(_query[i-1]==rhs[j-1])
                d[i][j]=d[i-1][j-1];
            else
            {
                int m1=d[i-1][j]+1;
                int m2=d[i][j-1]+1;
                int m3=d[i-1][j-1]+1;
                int min=m1>m2?m2:m1;
                min=min>m3?m3:min;
                d[i][j]=min;
            }
        }
    return d[Alen][Blen];
}

void process()
{
    
}
