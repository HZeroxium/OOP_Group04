#include "SelectionS.h"

template <typename T>
void SelectionS<T>::sort(std::vector<T> &array)
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

template class SelectionS<int>;
template class SelectionS<double>;