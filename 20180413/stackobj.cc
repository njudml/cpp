#include <iostream>
using std::cout;
using std::endl;
class Stackobj {
public:
    Stackobj(int a)
        : _a(new int())
    {
        *_a = a;
    }
    ~Stackobj()
    {
        delete _a;
    }

private:
    void* operator new(std::size_t count);
    void operator delete(void* ptr);
    void operator delete[](void* ptr);

    int* _a;
};
