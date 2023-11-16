#include "SATest.h"

template <typename T>
SATest<T>::SATest(SortArray<T> *sortArray)
{
    this->sortArray = sortArray;
}

template <typename T>
SATest<T>::~SATest()
{
    delete sortArray;
}

template <typename T>
void SATest<T>::input(std::istream &in)
{
    int size;
    std::cout << "Enter size of array: ";
    in >> size;
    while (size <= 0)
    {
        std::cout << "Size must be greater than 0. Enter again: ";
        in >> size;
    }
    array.resize(size);
    // Check if array failed to allocate memory
    if (array.size() != size)
    {
        std::cout << "Failed to allocate memory for array." << std::endl;
        exit(1);
    }

    std::cout << "Enter elements of array\n: ";
    for (int i = 0; i < size; i++)
    {
        std::cout << "+ Enter element " << i + 1 << ": ";
        in >> array[i];
    }

    std::cout << "Enter 1 to sort in ascending order, 2 to sort in descending order: ";
    int choice;
    in >> choice;
    while (choice != 1 && choice != 2)
    {
        std::cout << "Invalid choice. Enter again: ";
        in >> choice;
    }

    if (choice == 1)
        sortArray->setCompare(SortArray<T>::ascending);
    else
        sortArray->setCompare(SortArray<T>::descending);
}

template <typename T>
bool SATest<T>::check()
{
    return (array.size() > 0 && sortArray != nullptr);
}

template <typename T>
void SATest<T>::output(std::ostream &out)
{
    std::cout << "Array: ";
    out << "[";
    for (int i = 0; i < array.size(); i++)
    {
        out << array[i];
        if (i < array.size() - 1)
            out << ", ";
    }
    out << "]" << std::endl;
}

template <typename T>
void SATest<T>::process()
{
    sortArray->sort(array);
}

template class SATest<int>;
template class SATest<double>;
template class SATest<std::string>;
