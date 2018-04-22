#include <fstream>
#include <iostream>
using namespace std;
int main(void)
{
    ifstream ifs("tst.cc");
    cout << ifs.good() << endl;
    cout << ifs.bad() << endl;
    cout << ifs.fail() << endl;
    cout << ifs.eof() << endl;
    ifs.clear(ifs.rdstate());
    //cout << unitbuf;
    cout << "hello\n";
    int a;
    cin >> a;
    fstream fs("001.txt", fstream::out);
    return 0;
}
