#include <iostream>

using namespace std;
class Stack {
public:
    Stack();
    ~Stack();
    void push(int);
    void pop(int&);
    void pop();
    int top();
    bool empty();
    bool full();

private:
    int *_data;
    int _top;
};
Stack::Stack()
:_data(new int[10]())
    ,_top(0)
{}

Stack::~Stack()
{
    delete [] _data;
}
void Stack::push(int data)
{
    if (!this->full()) {
        _data[_top++] = data;
    }
}

void Stack::pop(int& data)
{
    if (!this->empty()) {
        data = _data[--_top];
    }
}

void Stack::pop()
{
    _top--;
}

int Stack::top()
{
    return _data[_top - 1];
}

bool Stack::empty()
{
    return _top == 0;
}

bool Stack::full()
{
    return _top == 10;
}

int main(void)
{
    Stack st;
    st.push(10);
    st.push(12);
    st.push(14);
    int a = st.top();
    cout << a << endl;
    st.pop();
    a=st.top();
    cout << a << endl;

    return 0;
}
