#pragma once

#include "SortArray.h"

template <typename T>
class SelectionS final : public SortArray<T>
{
public:
    void sort(std::vector<T> &array) override
    {
        for (int i = 0; i < array.size() - 1; i++)
        {
            int min = i;
            for (int j = i + 1; j < array.size(); j++)
            {
                if (this->compare(array[j], array[min]))
                    min = j;
            }
            if (min != i)
            {
                T temp = array[i];
                array[i] = array[min];
                array[min] = temp;
            }
        }
    }
};
