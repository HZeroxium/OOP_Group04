#pragma once

#include <iostream>

class IntArr
{
private:
    int *data;
    int size;

public: // Constructors & Destructor
    IntArr(int size = 0);
    IntArr(const IntArr &other);
    ~IntArr();

public: // Setters & Getters
    int getSize() const;
    int &operator[](int index);
    const int &operator[](int index) const;

    void resize(int newSize);

public: // Overloaded operators
    IntArr &operator=(const IntArr &other);
    IntArr operator+(const IntArr &other) const;

    IntArr operator++(int dummy);
    IntArr operator++();

public: // Overloaded operators for input and output
    friend std::istream &operator>>(std::istream &in, IntArr &arr);
    friend std::ostream &operator<<(std::ostream &out, const IntArr &arr);
};