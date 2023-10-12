#pragma once

#include "Common.h"

class MyArray
{
private:
    int *arr;
    size_t size;
    static void quickSort(int *, int, int, bool (*compare)(int, int) = nullptr);
    static int partition(int *, int, int, bool (*compare)(int, int) = nullptr);
    static bool ascending(int, int);

public:
    // Constructor
    MyArray(size_t = 0);
    MyArray(const MyArray &);
    ~MyArray();

    // Getter
    size_t getSize() const;
    int &operator[](size_t) const;

    // Setter
    void setSize(size_t);

    // Input & Output
    void input(const string & = "Input information of array: ");
    void output(const string & = "Output information: ") const;

    // Sort
    void sort(bool (*compare)(int, int) = nullptr) const;

    // Find
    int find(int) const;

    static bool descending(int, int);
};