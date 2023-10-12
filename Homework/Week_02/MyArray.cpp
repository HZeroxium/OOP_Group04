#include "MyArray.h"

void MyArray::quickSort(int *arr, int left, int right, bool (*compare)(int, int))
{
    if (left < right)
    {
        int pivot = partition(arr, left, right, compare);
        quickSort(arr, left, pivot - 1, compare);
        quickSort(arr, pivot + 1, right, compare);
    }
}

int MyArray::partition(int *arr, int left, int right, bool (*compare)(int, int))
{
    int pivot = arr[right];
    int i = left - 1;
    for (int j = left; j < right; ++j)
    {
        if (compare(arr[j], pivot))
        {
            ++i;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[right]);
    return i + 1;
}

bool MyArray::ascending(int a, int b)
{
    return a < b;
}

bool MyArray::descending(int a, int b)
{
    return a > b;
}

MyArray::MyArray(size_t size)
{
    if (size < 0)
        throw "Invalid size!";
    this->size = size;
    if (size == 0)
        arr = nullptr;
    else if (size > 0)
    {
        arr = new int[size];
        if (arr == nullptr)
            throw "Memory allocation failed!";
    }
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
}

MyArray::~MyArray()
{
    if (arr != nullptr)
        delete[] arr;
    arr = nullptr;
    size = 0;
}

size_t MyArray::getSize() const
{
    return size;
}

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

void MyArray::input(const string &msg)
{
    cout << msg << endl;
    cout << "Enter size of array: ";
    int _size;
    cin >> _size;
    try
    {
        setSize(_size);
        cout << "Enter " << _size << " element(s): " << endl;
        for (int i = 0; i < _size; ++i)
        {
            cout << "Enter element " << i + 1 << ": ";
            cin >> arr[i];
        }
    }
    catch (const char *msg)
    {
        cout << msg << endl;
        return;
    }
}

void MyArray::output(const string &msg) const
{
    cout << msg << endl;
    if (size == 0)
    {
        cout << "Array is empty!" << endl;
        return;
    }
    cout << "Array has " << size << " element(s): [";
    for (size_t i = 0; i < size - 1; ++i)
        cout << arr[i] << ", ";
    cout << arr[size - 1] << "]" << endl;
}

void MyArray::sort(bool (*compare)(int, int)) const
{
    if (size == 0)
        return;
    if (compare == nullptr)
        compare = ascending;
    quickSort(arr, 0, size - 1, compare);
}

int MyArray::find(int value) const
{
    if (size == 0)
        return -1;
    for (size_t i = 0; i < size; ++i)
        if (arr[i] == value)
            return i;
    return -1;
}
