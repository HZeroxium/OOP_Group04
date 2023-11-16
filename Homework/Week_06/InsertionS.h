#pragma once

#include "SortArray.h"

template <typename T>
class InsertionS final : public SortArray<T>
{
public:
    void sort(std::vector<T> &array) override
    {
        for (int i = 1; i < array.size(); i++)
        {
            T temp = array[i];
            int j = i - 1;
            while (j >= 0 && this->compare(temp, array[j]))
            {
                array[j + 1] = array[j];
                j--;
            }
            array[j + 1] = temp;
        }
    }
};
