#pragma once

#include <iostream>
#include <string>

class MyArray
{
private:
    int *arr;
    size_t size;

public:
    // Constructor
    MyArray(size_t = 0);
    MyArray(const int *, size_t);
    MyArray(const MyArray &);

    // Destructor
    ~MyArray();

    // Operator Overloading
    MyArray &operator=(const MyArray &);
    operator int *() const;

    // Getter
    size_t getSize() const;
    int &operator[](size_t) const;

    // Setter
    void setSize(size_t);

    // Input & Output
    friend std::istream &operator>>(std::istream &, MyArray &);
    friend std::ostream &operator<<(std::ostream &, const MyArray &);
};