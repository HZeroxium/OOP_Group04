#pragma once

#include "SortArray.h"

template <typename T>
class InterchangeS : public SortArray<T>
{
public:
    void sort(std::vector<T> &array) override;
};

#include "InterchangeS.cpp"