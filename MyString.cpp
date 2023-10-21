#pragma once
#include "MyString.h"

char* strCopy(char* dest, const char* src) {
    char* destination = dest;
    while ((*dest++ = *src++))
        ;
    return destination;
}
char* strConCat(char* dest, const char* src) {
    char* destination = dest;
    while (*dest)
        dest++;
    while ((*dest++ = *src++))
        ;
    return destination;
}
size_t strLength(const char* str) {
    size_t length = 0;
    while (*str++) {
        length++;
    }
    return length;
}
char* strCopySize(char* dest, const char* src, size_t n) {
    char* destination = dest;
    while (n > 0 && (*dest++ = *src++)) {
        n--;
    }
    if (n > 0) {
        while (--n > 0) {
            *dest++ = '\0';
        }
    }
    return destination;
}

MyString::MyString()
    : data(nullptr), size(0) {}

MyString::MyString(const char* const_data)
    : size(strLength(const_data)) {
    data = new char[size + 1]; // +1 for the null terminator
    strCopy(data, const_data);
}

MyString::MyString(char* data, const int& size)
    : size(size) {
    this->data = new char[size + 1];
    strCopySize(this->data, data, size);
    this->data[size] = '\0';
}

MyString::~MyString() {
    delete[] data;
    data = nullptr;
    size = 0;
}



// Methods
char* MyString::value() const {
    return data;
}
int MyString::length() const {
    return size;
}

char* MyString::subString(int position, int extract_length) const {
    if (position < 0 || position >= this->size)
        return nullptr;
    if (extract_length < 0 || position + extract_length > this->size)
        return nullptr;

    char* SubString = new char[extract_length + 1];
    for (int i = 0; i < extract_length; i++) {
        SubString[i] = this->data[i + position];
    }
    SubString[extract_length] = '\0';
    return SubString;
}

char* MyString::operator + (const MyString& other) const {
    char* new_str = new char[size + other.size + 1];
    strCopy(new_str, data);
    strConCat(new_str, other.data);
    return new_str;
}

char* MyString::operator + (const char* other) const {
    char* new_str = new char[size + strLength(other) + 1];
    strCopy(new_str, data);
    strConCat(new_str, other);
    return new_str;
}

char* operator + (const char* lhs, const MyString& rhs) {
    int new_size = strLength(lhs) + rhs.length();
    char* new_str = new char[new_size + 1];
    strCopy(new_str, lhs);
    strConCat(new_str, rhs.value());
    return new_str;
}

bool MyString::insert(int position, char* insert_data) {
    if (position < 0 || position > size) return false;

    int new_size = this->size + (int)strLength(insert_data);
    char* new_string = new char[new_size + 1];
    int i = 0, j = 0, idx = 0;

    while (idx < new_size)
    {
        if (idx >= position && idx <= position + (int)strLength(insert_data))
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
    new_string[idx] = '\0';
    delete[] this->data;
    this->data = new_string;
    this->size = new_size;
    return true;
}

bool MyString::erase(int position, int erase_length) {
    // homework
}
bool MyString::replace(int position, int replace_length, char* replace_data) {
    // homework

}
int MyString::find(int position, char* pattern) const {
    // homework
}

// Input - Output
std::istream& operator >> (std::istream& inp, MyString& self) {
    delete[] self.data;
    self.data = nullptr;
    self.size = 0;

    for (char token; inp.get(token) && token != '\n' && token != EOF; ) {
        char* newData = new char[self.size + 2]; // +2 for the new character and null terminator
        if (self.data) {
            strCopySize(newData, self.data, self.size);
            delete[] self.data;
        }
        newData[self.size] = token;
        newData[self.size + 1] = '\0';
        self.data = newData;
        ++self.size;
    }
}

std::ostream& operator << (std::ostream& out, const MyString& self) {
    if (&out == &std::cerr) { // std::cerr << MyString;
        out << "MyString(data = \"" << self.data << "\", size = " << self.size << ")";
    }
    else { // std::cout << MyString;
        out << self.data;
    }
    return out;
}
