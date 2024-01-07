#pragma once

#include <vector>
#include <iostream>

using std::istream;
using std::ostream;
using std::vector;
using namespace std;

template <typename T>
class Array
{
private: // Properties
    vector<T> elements;

public: // Constructors and Destructor
    Array();
    Array(const vector<T> &elements);
    Array(const Array &array);
    Array(Array &&array);
    Array &operator=(const Array &array);
    Array &operator=(Array &&array);
    ~Array();

public: // Getters and Setters
    const vector<T> &getElements() const;
    void setElements(const vector<T> &elements);
    int size() const;

public: // Operators
    T &operator[](int index);
    const T &operator[](int index) const;

public: // Methods
    void print() const;

public: // Friends
    template <typename U>
    friend ostream &operator<<(ostream &out, const Array<U> &array);
    template <typename U>
    friend istream &operator>>(istream &in, Array<U> &array);
};
