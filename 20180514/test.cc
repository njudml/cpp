#include <string>
#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
    string s1("hellowordhowareyou");
    string s2 = s1.substr(0, 5);
    int i = s1.find('o');
    cout << s2 << endl;
    cout << i << endl;
    return 0;
}
