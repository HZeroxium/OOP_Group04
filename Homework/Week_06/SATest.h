#pragma once

#include "ProgramFrame.h"
#include "SortArray.h"

template <typename T>
class SATest final : public ProgramFrame<T>
{
private:
    SortArray<T> *sortArray;
    std::vector<T> array;

public:
    SATest(SortArray<T> *sortArray = nullptr)
    {
        this->sortArray = sortArray;
    }
    ~SATest()
    {
        delete sortArray;
    }
    void input(std::istream &in = std::cin)
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

        std::cout << "Enter elements of array:\n";
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
    bool check() { return (array.size() > 0 && sortArray != nullptr); }
    void output(std::ostream &out = std::cout)
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
    void process()
    {
        sortArray->sort(array);
    }
};
