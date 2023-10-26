#include "MyArray.h"

int main()
{
    MyArray a;
    std::cout << "Array a: " << std::endl;
    std::cout << a << std::endl;
    std::cout << "Enter array a: " << std::endl;
    std::cin >> a;
    std::cout << "===========================================================\n";
    std::cout << "Array a: " << std::endl;
    std::cout << a << std::endl;
    std::cout << "===========================================================\n";

    MyArray b(5);
    std::cout << "Array b: " << std::endl;
    std::cout << b << std::endl;
    std::cout << "Enter array b: " << std::endl;
    std::cin >> b;
    std::cout << "===========================================================\n";
    std::cout << "Array b: " << std::endl;
    std::cout << b << std::endl;
    std::cout << "===========================================================\n";

    MyArray c(b);
    std::cout << "Array c: " << std::endl;
    std::cout << c << std::endl;
    std::cout << "===========================================================\n";

    MyArray d = c;
    std::cout << "Array d: " << std::endl;
    std::cout << d << std::endl;
    std::cout << "===========================================================\n";

    int *e = static_cast<int *>(d);
    std::cout << "#Type-casting# Array e: " << std::endl;
    for (size_t i = 0; i < d.getSize(); ++i)
        std::cout << e[i] << " ";
    std::cout << "\n===========================================================\n";
    std::cout << std::endl;
    delete[] e;
    e = nullptr;
}