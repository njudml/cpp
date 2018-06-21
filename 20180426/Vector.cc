#include <iostream>
#include <memory>
#include <string>
using namespace std;
template <typename T>
class Vector {
public:
    Vector();
    ~Vector();
    void push_back(const T&);
    void pop_back();
    T* begin() { return _start; }
    T* end() { return _finsh; }
    int size() { return _finsh - _start; }
    int capacity() { return _end_of_storage - _start; }

    T top() { return *(_finsh - 1); }

private:
    void reallocate();
    void free();
    static allocator<T> _alloc;
    T* _start;
    T* _finsh;
    T* _end_of_storage;
};

template <typename T>
allocator<T> Vector<T>::_alloc;

template <typename T>
Vector<T>::Vector()
    : _start(0)
    , _finsh(0)
    , _end_of_storage(0)
{
}

template <typename T>
void Vector<T>::free()
{
    if (_start) {
        for (auto i = begin(); i != end(); i++)
            _alloc.destroy(i);
        _alloc.deallocate(_start, capacity());
    }
}

template <typename T>
void Vector<T>::reallocate()
{
    size_t new_size = capacity() ? capacity() * 2 : 1;
    T* p1 = _alloc.allocate(new_size);
    T* temp = p1;
    T* p2 = p1 + new_size;
    for (auto i = begin(); i != end(); i++)
       // *p1++ = std::move(*i);
       _alloc.construct(p1++,std::move(*i));
    free();
    _start = temp;
    _finsh = p1;
    _end_of_storage = p2;
}

template <typename T>
void Vector<T>::push_back(const T& data)
{
    if (size() == capacity())
        reallocate();
    _alloc.construct(_finsh++, data);
}

template <typename T>
void Vector<T>::pop_back()
{
    if (size() > 0) {
        _alloc.destroy(--_finsh);
    }
}

template <typename T>
Vector<T>::~Vector()
{
    free();
}

int main(void)
{
    Vector<int> p;
    for (int i = 1; i != 11; i++) {
        p.push_back(i);
        cout << "size= " << p.size() << endl;
        cout << "capacity= " << p.capacity() << endl;
    }

    for (auto j = p.size(); j != 0; j--) {
        cout << p.top() << endl;
        p.pop_back();
    }
    return 0;
}
