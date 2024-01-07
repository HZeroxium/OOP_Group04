#pragma once

#include <vector>

using namespace std;

template <class T>
class Array
{
private:
    vector<T> arr;

public:
    Array();
    Array(int n);
    Array(int n, T val);
    Array(const Array &a);
    Array(const vector<T> &v);
    Array(const initializer_list<T> &v);
    void print();
};

template <class T>
void my_swap(T &a, T &b);
