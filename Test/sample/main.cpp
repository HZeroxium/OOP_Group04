#include "fraction.h"
#include "array.h"
#include <iostream>
#include <fstream>
int main()
{
    Array<int> int_array;
    cin >> int_array;
    cout << int_array << endl;
    fstream file("array.bin", ios::out | ios::binary);
    file.write(reinterpret_cast<char *>(&int_array), sizeof(int_array));
    cout << "Size of int_array: " << sizeof(int_array) << endl;
    file.close();
    Array<int> int_array2;
    file.open("array.bin", ios::in | ios::binary);
    file.read(reinterpret_cast<char *>(&int_array2), sizeof(int_array2));
    file.close();
    cout << int_array2 << endl;
    cout << "Size of int_array2: " << sizeof(int_array2) << endl;
}