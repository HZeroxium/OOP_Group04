#pragma once

#include "SortArray.h"

template <typename T>
class InsertionS : public SortArray<T>
{
public:
    void sort(std::vector<T> &array) override;
};

#include "InsertionS.cpp"