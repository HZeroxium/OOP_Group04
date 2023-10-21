#ifndef __MY_STRING_H__
#define __MY_STRING_H__

#include <iostream>

class MyString
{
private:
    char *data;
    int size;

public: // Constructor & Destructor
    MyString();
    MyString(const char *const_data);
    MyString(char *data, const int &size);
    ~MyString();

public: // Methods
    char *value() const;
    int length() const;
    char *subString(int position, int extract_length) const;
    char *operator+(const MyString &other) const;
    char *operator+(const char *other) const;
    friend char *operator+(const char *lhs, const MyString &rhs);
    bool insert(int position, char *insert_data);
    bool erase(int position, int erase_length);
    bool replace(int position, int replace_length, char *replace_data);
    int find(int position, char *pattern) const;

public: // Input - Output
    friend std::istream &operator>>(std::istream &inp, MyString &self);
    friend std::ostream &operator<<(std::ostream &out, const MyString &self);
};

#endif
