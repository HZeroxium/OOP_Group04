#pragma once

#include <vector>

template <typename T>
class SortArray
{
protected:
    bool (*compare)(const T &, const T &);

public:
    SortArray(bool (*compare)(const T &, const T &) = ascending);

    static bool ascending(const T &, const T &);
    static bool descending(const T &, const T &);

    void setCompare(bool (*compare)(const T &, const T &) = ascending);

    virtual void sort(std::vector<T> &array) = 0;
};

#include "SortArray.cpp"