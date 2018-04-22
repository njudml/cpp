#include "String.h"
#include <iostream>
using namespace std;
int main(void)
{
    String s1;
    cin >> s1;
    cout << s1 << endl;
    String s2;
    cin >> s2;
    cout << s2 << endl;
    cout << (s1 == s2) << endl;

    cout << (s1 + s2) << endl;

    cout << s1[1] << endl;

    return 0;
}
