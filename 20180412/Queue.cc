#include <iostream>
using std::cout;
using std::endl;
class Queue {
public:
    Queue();
    void push(int);
    void pop();
    int front();
    int back();
    bool empty();
    bool full();

private:
    int _data[11] = { 0 };
    int _front, _back;
};

Queue::Queue()
    : _front(0)
    , _back(0)
{
}
bool Queue::empty()
{
    return _front == _back;
}

bool Queue::full()
{
    return (_back + 1) % 11 == _front;
}

void Queue::push(int data)
{
    if (!this->full()) {
        _data[_back] = data;
        _back = (_back + 1) % 11;
    }
}

void Queue::pop()
{
    if (!this->empty()) {
        _front = (_front + 1) % 11;
    }
}

int Queue::front()
{
    return _data[_front];
}

int Queue::back()
{
    return _data[_back];
}

int main(void)
{
    Queue pr;
    int i, j;
    for (i = 0; i < 11; i++) {
        pr.push(i);
    }
    for (i = 0; i < 11; i++) {
        j = pr.front();
        cout << j << " ";
        pr.pop();
    }
    cout << endl;
    return 0;
}
