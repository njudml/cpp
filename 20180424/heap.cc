#include <iostream>
#include <vector>
using namespace std;
template <typename T, typename Compare = std::less<T>>
class HeapSort {
public:
    HeapSort(T* arr, int size);
    void sort();
    void heapAdjust(int i, int n);
    void print()
    {
        for (auto i : _uoheap)
            cout << i << " ";
        cout << endl;
    }
    int leftchild(int i)
    {
        return 2 * i + 1;
    }

private:
    vector<T> _uoheap;
};

template <typename T, typename Compare>
HeapSort<T, Compare>::HeapSort(T* arr, int size)
    : _uoheap(arr, arr + size)
{
}

template <typename T, typename Compare>
void HeapSort<T, Compare>::heapAdjust(int i, int n)
{
    int child;
    T tmp;
    Compare c;
    for (tmp = _uoheap[i]; leftchild(i) < n; i = child) {
        child = leftchild(i);
        if (child != n - 1 && c(_uoheap[child], _uoheap[child + 1]))
            child++;
        if (c(tmp, _uoheap[child]))
            _uoheap[i] = _uoheap[child];
        else
            break;
    }
    _uoheap[i] = tmp;
}

template <typename T, typename Compare>
void HeapSort<T, Compare>::sort()
{
    for (int i = _uoheap.size() / 2; i >= 0; i--)
        heapAdjust(i, _uoheap.size());
    for (int j = _uoheap.size() - 1; j > 0; j--) {
        swap(_uoheap[0], _uoheap[j]);
        heapAdjust(0, j);
    }
}

int main(void)
{
    int arr[] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
    HeapSort<int> q(arr, 10);
    q.sort();
    q.print();
    return 0;
}
