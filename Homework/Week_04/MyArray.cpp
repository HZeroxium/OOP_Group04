#include "MyArray.h"

// Constructor
MyArray::MyArray(size_t size)
{
    if (size < 0)
        throw "Invalid size!";
    this->size = size;
    if (size == 0)
    {
        arr = nullptr;
        std::cout << "Default constructor called!" << std::endl;
        return;
    }
    else if (size > 0)
    {
        arr = new int[size];
        if (arr == nullptr)
            throw "Memory allocation failed!";
        for (size_t i = 0; i < size; ++i)
            arr[i] = 0;
    }
    std::cout << "Parameterized with size constructor called!" << std::endl;
}

MyArray::MyArray(const int *arr, size_t size)
{
    if (size < 0)
        throw "Invalid size!";
    this->size = size;
    if (size == 0)
        this->arr = nullptr;
    else if (size > 0)
    {
        this->arr = new int[size];
        if (this->arr == nullptr)
            throw "Memory allocation failed!";
        for (size_t i = 0; i < size; ++i)
            this->arr[i] = arr[i];
    }
    std::cout << "Parameterized constructor called!" << std::endl;
}

MyArray::MyArray(const MyArray &other)
{
    size = other.size;
    if (size > 0)
    {
        arr = new int[size];
        if (arr == nullptr)
            throw "Memory allocation failed!";
        for (size_t i = 0; i < size; ++i)
            arr[i] = other[i];
    }
    std::cout << "Copy constructor called!" << std::endl;
}

// Destructor
MyArray::~MyArray()
{
    if (size > 0 && arr != nullptr)
    {
        std::cerr << "Destructor called!" << std::endl;
        std::cerr << "+ Deleting array at " << this << ": ";
        std::cerr << "[";
        for (size_t i = 0; i < size - 1; ++i)
            std::cerr << arr[i] << ", ";
        std::cerr << arr[size - 1] << "]" << std::endl;
        std::cerr << "+ Address of arr in Array: " << arr << std::endl;
        std::cerr << "+ Size of arr: " << size << std::endl;
        delete[] arr;
        arr = nullptr;
        size = 0;
    }
}

// Getter
size_t MyArray::getSize() const
{
    return size;
}

// Setter
int &MyArray::operator[](size_t index) const
{
    if (index < 0 || index >= size)
        throw "Invalid index!";
    return arr[index];
}

void MyArray::setSize(size_t size)
{
    if (size < 0)
        throw "Invalid size!";
    if (this->size == size)
        return;
    if (arr != nullptr)
        delete[] arr;
    this->size = size;
    if (size > 0)
        arr = new int[size];
    if (arr == nullptr)
        throw "Memory allocation failed!";
}

// Operator Overloading
MyArray &MyArray::operator=(const MyArray &other)
{
    if (this == &other)
        return *this;
    if (size > 0)
        delete[] arr;
    size = other.size;
    if (size > 0)
    {
        arr = new int[size];
        if (arr == nullptr)
            throw "Memory allocation failed!";
        for (size_t i = 0; i < size; ++i)
            arr[i] = other[i];
    }
    return *this;
}

MyArray::operator int *() const
{
    if (arr == nullptr || size == 0)
        return nullptr;
    int *temp = new int[size];
    if (temp == nullptr)
        throw "Memory allocation failed!";
    for (size_t i = 0; i < size; ++i)
        temp[i] = arr[i];
    return temp;
}

// Input & Output
std::ostream &operator<<(std::ostream &out, const MyArray &arr)
{
    if (arr.size == 0)
    {
        out << "Array is empty!";
        return out;
    }
    out << "Array has " << arr.size << " element(s): [";
    for (size_t i = 0; i < arr.size - 1; ++i)
        out << arr.arr[i] << ", ";
    out << arr.arr[arr.size - 1] << "]";
    return out;
}

std::istream &operator>>(std::istream &in, MyArray &arr)
{
    std::cout << "Enter size of array: ";
    int _size;
    in >> _size;
    try
    {
        arr.setSize(_size);
        std::cout << "Enter " << _size << " element(s): " << std::endl;
        for (int i = 0; i < _size; ++i)
        {
            std::cout << "Enter element " << i + 1 << ": ";
            in >> arr.arr[i];
        }
    }
    catch (const char *msg)
    {
        std::cout << msg << std::endl;
        return in;
    }
    return in;
}
