#include <fstream>
#include <iostream>
#include <string>
using namespace std;
int main(void)
{
    ifstream ifs("The_Holy_Bible.txt");
    string line;
    ifs.seekg(10);
    char cs[10] = { 0 };
    ifs.read(cs, 9);
    cout << cs << endl;
    return 0;
}
