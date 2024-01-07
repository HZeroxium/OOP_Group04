#include "utils.h"
#include <iostream>

template <class T>
Array<T>::Array()
{
    arr = vector<T>();
}

template <class T>
Array<T>::Array(int n)
{
    arr = vector<T>(n);
}

template <class T>
Array<T>::Array(int n, T val)
{
    arr = vector<T>(n, val);
}

template <class T>
Array<T>::Array(const Array &a)
{
    arr = a.arr;
}

template <class T>
Array<T>::Array(const vector<T> &v)
{
    arr = v;
}

template <class T>
Array<T>::Array(const initializer_list<T> &v)
{
    arr = vector<T>(v);
}

template <class T>
void Array<T>::print()
{
    for (auto i : arr)
        cout << i << " ";
    cout << endl;
}

template <class T>
void my_swap(T &a, T &b)
{
    T tmp = a;
    a = b;
    b = tmp;
}

// Forwards declaration of the template class
template class Array<int>;
template void my_swap<Array<int>>(Array<int> &, Array<int> &);