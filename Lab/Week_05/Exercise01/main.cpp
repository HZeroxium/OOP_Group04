#include "Fraction.h"

using std::cout;
using std::endl;

int main()
{
    Fraction f;
    while (true)
    {
        cout << "=========================== FRACTION ===========================" << endl;
        cout << "1. Input fraction" << endl;
        cout << "2. Output fraction" << endl;
        cout << "3 Operator +" << endl;
        cout << "4 Operator -" << endl;
        cout << "5 Operator *" << endl;
        cout << "6 Operator /" << endl;
        cout << "7 Operator += " << endl;
        cout << "8 Operator -= " << endl;
        cout << "9 Operator *= " << endl;
        cout << "10 Operator /= " << endl;
        cout << "11 Operator ++ (postfix)" << endl;
        cout << "12 Operator -- (postfix)" << endl;
        cout << "13 Operator ++ (prefix)" << endl;
        cout << "14 Operator -- (prefix)" << endl;
        cout << "15 Operator == " << endl;
        cout << "16 Operator != " << endl;
        cout << "17 Operator > " << endl;
        cout << "18 Operator < " << endl;
        cout << "19 Operator >= " << endl;
        cout << "20 Operator <= " << endl;
        cout << "0. Exit" << endl;
        cout << "================================================================" << endl;
        cout << "Choose an option (0 - 20): ";
        int option;
        std::cin >> option;
        // Exit
        if (option == 0)
        {
            break;
        }
        // Invalid option
        if (option < 0 || option > 20)
        {
            cout << "Invalid option" << endl;
            continue;
        }
        // Input and output
        if (option >= 1 && option <= 2)
        {
            if (option == 1)
            {
                cout << "Input fraction: ";
                std::cin >> f;
            }
            else
            {
                cout << "Fraction: " << f << endl;
            }
        }
        // Overload operators for arithmetic
        else if (option >= 3 && option <= 6)
        {
            Fraction f1, f2;
            cout << "Input first fraction: ";
            std::cin >> f1;
            cout << "Input second fraction: ";
            std::cin >> f2;
            if (option == 3)
            {
                cout << f1 << " + " << f2 << " = " << f1 + f2 << endl;
            }
            else if (option == 4)
            {
                cout << f1 << " - " << f2 << " = " << f1 - f2 << endl;
            }
            else if (option == 5)
            {
                cout << f1 << " * " << f2 << " = " << f1 * f2 << endl;
            }
            else
            {
                cout << f1 << " / " << f2 << " = " << f1 / f2 << endl;
            }
        }
        // Overload operators for assignment
        else if (option >= 7 && option <= 10)
        {
            Fraction f1;
            cout << "Input fraction: ";
            std::cin >> f1;
            if (option == 7)
            {
                cout << f << " += " << f1 << " = " << (f += f1) << endl;
            }
            else if (option == 8)
            {
                cout << f << " -= " << f1 << " = " << (f -= f1) << endl;
            }
            else if (option == 9)
            {
                cout << f << " *= " << f1 << " = " << (f *= f1) << endl;
            }
            else
            {
                cout << f << " /= " << f1 << " = " << (f /= f1) << endl;
            }
        }
        // Overload operators for increment and decrement
        else if (option >= 11 && option <= 14)
        {
            if (option == 11)
            {
                cout << f << " ++ = " << f++ << endl;
            }
            else if (option == 12)
            {
                cout << f << " -- = " << f-- << endl;
            }
            else if (option == 13)
            {
                cout << "++ " << f << " = " << ++f << endl;
            }
            else
            {
                cout << "-- " << f << " = " << --f << endl;
            }
        }
        // Overload operators for comparison
        else if (option >= 15 && option <= 20)
        {
            Fraction f1, f2;
            cout << "Input first fraction: ";
            std::cin >> f1;
            cout << "Input second fraction: ";
            std::cin >> f2;
            if (option == 15)
            {
                cout << f1 << " == " << f2 << " = " << (f1 == f2) << endl;
            }
            else if (option == 16)
            {
                cout << f1 << " != " << f2 << " = " << (f1 != f2) << endl;
            }
            else if (option == 17)
            {
                cout << f1 << " > " << f2 << " = " << (f1 > f2) << endl;
            }
            else if (option == 18)
            {
                cout << f1 << " < " << f2 << " = " << (f1 < f2) << endl;
            }
            else if (option == 19)
            {
                cout << f1 << " >= " << f2 << " = " << (f1 >= f2) << endl;
            }
            else
            {
                cout << f1 << " <= " << f2 << " = " << (f1 <= f2) << endl;
            }
        }
    }
}