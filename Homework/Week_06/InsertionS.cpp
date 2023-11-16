#include "InsertionS.h"

template <typename T>
void InsertionS<T>::sort(std::vector<T> &array)
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

template class InsertionS<int>;
template class InsertionS<double>;