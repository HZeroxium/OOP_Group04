#pragma once

#include "SortArray.h"

template <typename T>
class InterchangeS final : public SortArray<T>
{
public:
    void sort(std::vector<T> &array) override
    {
        for (int i = 0; i < array.size() - 1; i++)
        {
            for (int j = i + 1; j < array.size(); j++)
            {
                if (this->compare(array[i], array[j]))
                {
                    T temp = array[i];
                    array[i] = array[j];
                    array[j] = temp;
                }
            }
        }
    }
};
