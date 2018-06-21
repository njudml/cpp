#include "Editdistance.h"
size_t nBytesCode(const char ch)
{
    size_t i = 1;
    size_t n = 1;
    for (int j = 0; j < 5; j++) {
        if (ch & i << (6 - j))
            n++;
        else
            break;
    }

    return n;
}

size_t length(const string& str)
{
    size_t len = 0;
    for (size_t i = 0; i < str.size();) {
        size_t nbytes = str[i];
        i += nbytes;
        ++len;
    }
    return len;
}

int tripleMin(const int& a, const int& b, const int& c)
{
    int min = a > b ? b : a;
    min = min > c ? c : min;
    return min;
}

int editDistance(const string& lhs, const string& rhs)
{
    size_t llen=length(lhs);
    size_t rlen=length(rhs);
    int d[llen+1][rlen+1];
    for(size_t idx=0;idx<=llen;idx++)
    {
        d[idx][0]=idx;
    }
    for(size_t idx=0;idx<=rlen;idx++)
    {
        d[0][idx]=idx;
    }

    string sublstr,subrstr;
    for(size_t i=1, idx_i=0;i<=llen;i++)
    {
        size_t nBytes=nBytesCode(lhs[idx_i]);
        sublstr=lhs.substr(idx_i,nBytes);
        idx_i+=nBytes;
        for(size_t j=1,idx_j=0;j<=rlen;j++)
        {
            nBytes=nBytesCode(rhs[idx_j]);
            subrstr=rhs.substr(idx_j,nBytes);
            idx_j+=nBytes;
            if(sublstr==subrstr)
            {
                d[i][j]=d[i-1][j-1];
            }
            else{
                int a=d[i-1][j]+1;
                int b=d[i-1][j-1]+1;
                int c=d[i][j-1]+1;
                d[i][j]=tripleMin(a,b,c);
            }
        }
    }
    return d[llen][rlen];

}
