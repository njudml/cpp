#include <array>
#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
    vector<int> a = { 1, 2, 3, 4, 5, 6 };
    vector<int> b = { 7, 8, 9, 10 };
    vector<int>::iterator it = a.begin();
    a.swap(b);
    cout << a.size() << endl;
    cout << *it << endl;
    auto it1 = a.begin();
    cout << *it1 << endl;
    cout << a.max_size() << endl;
    cout << a.capacity() << endl;
    a.insert(a.begin(), b.begin(), b.end());
    for (auto i : a)
        cout << i << endl;
    cout << a.front() << "  " << a.back() << endl;
    a.erase(a.begin(),a.begin()+1);
    for (auto i : a)
        cout << i << endl;
    
    return 0;
}
