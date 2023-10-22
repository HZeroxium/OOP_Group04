#include "MyString.h"

char *strCopy(char *dest, const char *src)
{
    char *destination = dest;
    while ((*dest++ = *src++))
        ;
    return destination;
}
char *strConCat(char *dest, const char *src)
{
    char *destination = dest;
    while (*dest)
        dest++;
    while ((*dest++ = *src++))
        ;
    return destination;
}
size_t strLength(const char *str)
{
    size_t length = 0;
    while (*str++)
    {
        length++;
    }
    return length;
}
char *strCopySize(char *dest, const char *src, size_t n)
{
    char *destination = dest;
    while (n > 0 && (*dest++ = *src++))
    {
        n--;
    }
    if (n > 0)
    {
        while (--n > 0)
        {
            *dest++ = '\0';
        }
    }
    return destination;
}

MyString::MyString()
    : data(nullptr), size(0) {}

MyString::MyString(const char *const_data)
    : size(strLength(const_data))
{
    data = new char[size + 1]; // +1 for the null terminator
    strCopy(data, const_data);
}

MyString::MyString(char *data, const int &size)
    : size(size)
{
    this->data = new char[size + 1];
    strCopySize(this->data, data, size);
    this->data[size] = '\0';
}

MyString::~MyString()
{
    if (data != nullptr)
        delete[] data;
    data = nullptr;
    size = 0;
}

// Methods
char *MyString::value() const
{
    return data;
}
int MyString::length() const
{
    return size;
}

char *MyString::subString(int position, int extract_length) const
{
    if (position < 0 || position >= this->size)
        return nullptr;
    if (extract_length < 0 || position + extract_length > this->size)
        return nullptr;

    char *SubString = new char[extract_length + 1];
    for (int i = 0; i < extract_length; i++)
    {
        SubString[i] = this->data[i + position];
    }
    SubString[extract_length] = '\0';
    return SubString;
}

char *MyString::operator+(const MyString &other) const
{
    char *new_str = new char[size + other.size + 1];
    strCopy(new_str, data);
    strConCat(new_str, other.data);
    return new_str;
}

char *MyString::operator+(const char *other) const
{
    char *new_str = new char[size + strLength(other) + 1];
    strCopy(new_str, data);
    strConCat(new_str, other);
    return new_str;
}

char *operator+(const char *lhs, const MyString &rhs)
{
    int new_size = strLength(lhs) + rhs.length();
    char *new_str = new char[new_size + 1];
    strCopy(new_str, lhs);
    strConCat(new_str, rhs.value());
    return new_str;
}

bool MyString::insert(int position, const char *insert_data)
{
    if (position < 0 || position > size)
        return false;

    const int insert_data_length = static_cast<int>(strLength(insert_data));
    int new_size = length() + insert_data_length;
    const int start_position = position;
    const int end_position = position + insert_data_length;
    char *new_string = new char[new_size + 1];
    int i = 0, j = 0, idx = 0;

    while (idx < new_size)
    {
        if (idx >= start_position && idx < end_position)
        {
            new_string[idx] = insert_data[j];
            j++;
        }
        else
        {
            new_string[idx] = this->data[i];
            i++;
        }
        idx++;
    }
    new_string[new_size] = '\0';
    delete[] this->data;
    this->data = new_string;
    this->size = new_size;
    return true;
}

bool MyString::erase(int position, int erase_length)
{
    if (position < 0 || position >= size)
        return false;
    if (erase_length < 0 || position + erase_length > size)
        return false;

    int new_size = this->size - erase_length;
    const int start_position = position;
    const int end_position = position + erase_length;
    char *new_string = new char[new_size + 1];
    int i = 0, idx = 0;

    while (i < size)
    {
        if (i >= start_position && i < end_position)
        {
            i++;
        }
        else
        {
            new_string[idx++] = this->data[i++];
        }
    }
    new_string[idx] = '\0';
    delete[] this->data;
    this->data = new_string;
    this->size = new_size;
    return true;
}

bool MyString::replace(int position, int replace_length, const char *replace_data)
{
    if (position < 0 || position >= size)
        return false;
    if (replace_length < 0 || position + replace_length > size)
        return false;

    const int replace_data_length = static_cast<int>(strLength(replace_data));
    const int end_position = position + replace_data_length;
    int new_size = length() - replace_length + replace_data_length;
    char *new_string = new char[new_size + 1];
    int i = 0, idx = 0;
    while (idx < new_size)
    {
        if (idx >= position && idx < end_position)
        {
            for (int j = 0; j < replace_data_length; j++)
            {
                new_string[idx++] = replace_data[j];
            }
            i += replace_length;
        }
        else
        {
            new_string[idx++] = this->data[i++];
        }
    }

    new_string[new_size] = '\0';
    delete[] this->data;
    this->data = new_string;
    this->size = new_size;
    return true;
}
int MyString::find(int position, const char *pattern) const
{
    if (position < 0 || position >= size)
        return -1;

    int pattern_length = (int)strLength(pattern);
    int i = position, j = 0;
    while (i < size)
    {
        if (data[i] == pattern[j])
        {
            j++;
            if (j == pattern_length)
                return i - j + 1;
        }
        else
        {
            i -= j;
            j = 0;
        }
        i++;
    }
    return -1;
}

// Input - Output
std::istream &operator>>(std::istream &inp, MyString &self)
{
    char buffer[1000];
    int new_size = 0;
    // Get the input from the user
    inp.getline(buffer, 1000);
    // Get the size of the input
    while (buffer[new_size] != '\0')
    {
        new_size++;
    }
    // Allocate memory for the string
    if (self.data != nullptr)
        delete[] self.data;
    self.data = new char[new_size + 1];
    // Copy the input to the string
    strCopy(self.data, buffer);
    self.size = new_size;
    self.data[new_size] = '\0';
    return inp;
}

std::ostream &operator<<(std::ostream &out, const MyString &self)
{
    if (&out == &std::cerr)
    { // std::cerr << MyString;
        out << "MyString(data = \"" << self.data << "\", size = " << self.size << ")";
    }
    else
    { // std::cout << MyString;
        out << self.data;
    }
    return out;
}