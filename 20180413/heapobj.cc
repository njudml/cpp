#include <iostream>
using std::cout;
using std::endl;
class Heapobj {
public:
    Heapobj(int a)
        : _a(new int())
    {
        *_a = a;
    }
    void destroy()
    {
        delete this;
    }

private:
    ~Heapobj()
    {
        delete _a;
    }
    int* _a;
};
