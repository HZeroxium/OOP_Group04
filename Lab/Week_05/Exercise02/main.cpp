#include "IntArr.h"

int main()
{
    IntArr arr1;
    std::cout << "Enter arr1: ";
    std::cin >> arr1;
    std::cout << "arr1:";
    std::cout << arr1 << std::endl;

    IntArr arr2;
    std::cout << "Enter arr2: ";
    std::cin >> arr2;
    std::cout << "arr2:";
    std::cout << arr2 << std::endl;

    IntArr arr3 = arr1 + arr2;
    std::cout << "arr3 = arr1 + arr2" << std::endl;
    std::cout << arr3 << std::endl;

    std::cout << "arr3++" << std::endl;
    std::cout << arr3++ << std::endl;

    std::cout << "++arr3" << std::endl;
    std::cout << ++arr3 << std::endl;

    return 0;
}