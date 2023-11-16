#include "IntArr.h"

///////////////////////////////////////////////////////////////////////////////////
////////////////// CONSTRUCTORS & DESTRUCTOR //////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////

IntArr::IntArr(int size)
{
    if (size < 0)
    {
        throw std::invalid_argument("Size must be greater than or equal to 0");
    }

    this->size = size;
    if (size == 0)
    {
        this->data = nullptr;
    }
    else
    {
        this->data = new int[size];
        if (this->data == nullptr)
        {
            throw std::bad_alloc();
        }
    }
}

IntArr::IntArr(const IntArr &other)
{
    this->size = other.size;
    if (this->size == 0)
    {
        this->data = nullptr;
    }
    else
    {
        this->data = new int[this->size];
        if (this->data == nullptr)
        {
            throw std::bad_alloc();
        }

        for (int i = 0; i < this->size; i++)
        {
            this->data[i] = other.data[i];
        }
    }
}

IntArr::~IntArr()
{
    delete[] data;
    data = nullptr;
}

///////////////////////////////////////////////////////////////////////////////////
////////////////// SETTERS & GETTERS //////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////

int IntArr::getSize() const
{
    return size;
}

int &IntArr::operator[](int index)
{
    if (index < 0 || index >= size)
    {
        throw std::out_of_range("Index out of range");
    }

    return data[index];
}

const int &IntArr::operator[](int index) const
{
    if (index < 0 || index >= size)
    {
        throw std::out_of_range("Index out of range");
    }

    return data[index];
}

void IntArr::resize(int newSize)
{
    if (newSize < 0)
    {
        throw std::invalid_argument("Size must be greater than or equal to 0");
    }

    if (newSize == 0)
    {
        delete[] data;
        data = nullptr;
    }
    else
    {
        int *newData = new int[newSize];
        if (newData == nullptr)
        {
            throw std::bad_alloc();
        }

        int minSize = (newSize > size) ? size : newSize;
        for (int i = 0; i < minSize; i++)
        {
            newData[i] = data[i];
        }

        for (int i = minSize; i < newSize; i++)
        {
            newData[i] = 0;
        }

        delete[] data;
        data = newData;
    }

    size = newSize;
}

///////////////////////////////////////////////////////////////////////////////////
////////////////// OVERLOADED OPERATORS ///////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////

IntArr &IntArr::operator=(const IntArr &other)
{
    if (this != &other)
    {
        delete[] data;

        this->size = other.size;
        if (this->size == 0)
        {
            this->data = nullptr;
        }
        else
        {
            this->data = new int[this->size];
            if (this->data == nullptr)
            {
                throw std::bad_alloc();
            }

            for (int i = 0; i < this->size; i++)
            {
                this->data[i] = other.data[i];
            }
        }
    }

    return *this;
}

IntArr IntArr::operator+(const IntArr &other) const
{
    int minSize = (size < other.size) ? size : other.size;
    int maxSize = (size > other.size) ? size : other.size;

    IntArr result(maxSize);
    for (int i = 0; i < minSize; i++)
    {
        result[i] = data[i] + other.data[i];
    }

    for (int i = minSize; i < maxSize; i++)
    {
        result[i] = (size > other.size) ? data[i] : other.data[i];
    }

    return result;
}

IntArr IntArr::operator++(int dummy)
{
    IntArr result(*this);
    for (int i = 0; i < size; i++)
    {
        data[i]++;
    }

    return result;
}

IntArr IntArr::operator++()
{
    for (int i = 0; i < size; i++)
    {
        data[i]++;
    }

    return *this;
}

std::istream &operator>>(std::istream &in, IntArr &arr)
{
    int newSize;
    try
    {
        std::cout << std::endl;
        std::cout << "Enter size: ";
        in >> newSize;
        arr.resize(newSize);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        in >> arr;
    }

    for (int i = 0; i < arr.size; i++)
    {
        std::cout << "+ Enter element " << i << ": ";
        in >> arr.data[i];
    }

    return in;
}

std::ostream &operator<<(std::ostream &out, const IntArr &arr)
{
    out << "[";
    for (int i = 0; i < arr.size; i++)
    {
        out << arr.data[i];
        if (i < arr.size - 1)
        {
            out << ", ";
        }
    }
    out << "]";

    return out;
}