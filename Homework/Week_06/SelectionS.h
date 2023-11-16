#pragma once

#include "SortArray.h"

template <typename T>
class SelectionS : public SortArray<T>
{
public:
    void sort(std::vector<T> &array) override;
};

#include "SelectionS.cpp"