#include "SortArray.h"

template <typename T>
bool SortArray<T>::ascending(const T &a, const T &b)
{
    return a < b;
}

template <typename T>
bool SortArray<T>::descending(const T &a, const T &b)
{
    return a > b;
}

template <typename T>
SortArray<T>::SortArray(bool (*compare)(const T &, const T &))
{
    this->compare = compare;
}

template <typename T>
void SortArray<T>::setCompare(bool (*compare)(const T &, const T &))
{
    if (compare == nullptr)
        compare = ascending;
    this->compare = compare;
}

template class SortArray<int>;
template class SortArray<double>;
