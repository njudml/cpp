#include <iostream>
using std::cout;
using std::endl;
class Singleton {
public:
    static Singleton* sltInit();
    static void sltDetroy();

private:
    Singleton();
    ~Singleton();

    int a;
    static Singleton* _slt;
};

Singleton* Singleton::_slt;

Singleton::Singleton()
    : a(0)
{
}

Singleton::~Singleton()
{
}

Singleton* Singleton::sltInit()
{
    if (_slt == NULL) {
        _slt = new Singleton();
    }
    return _slt;
}
void Singleton::sltDetroy()
{
    if(_slt)
    delete _slt;
}
int main(void)
{
    Singleton* pr = Singleton::sltInit();
    cout << "pr=" << pr << endl;
    Singleton::sltDetroy();
    return 0;
}
