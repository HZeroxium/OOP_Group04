#pragma once

#include <vector>

template <typename T>
class SortArray
{
protected:
    bool (*compare)(const T &, const T &);

public:
    SortArray(bool (*compare)(const T &, const T &) = ascending)
    {
        this->compare = compare;
    }

    static bool ascending(const T &a, const T &b)
    {
        return a < b;
    }
    static bool descending(const T &a, const T &b)
    {
        return a > b;
    }

    void setCompare(bool (*compare)(const T &, const T &) = ascending)
    {
        if (compare == nullptr)
            compare = ascending;
        this->compare = compare;
    }

    virtual void sort(std::vector<T> &array) = 0;
};
