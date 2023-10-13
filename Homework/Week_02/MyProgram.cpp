#include "MyProgram.h"

int MyProgram::handle_fraction()
{
    while (true)
    {
        cout << "========================FRACTION========================\n";
        cout << "Choose an operation: " << endl; // endl = "\n
        cout << "1. Add two fractions" << endl;
        cout << "2. Subtract two fractions" << endl;
        cout << "3. Multiply two fractions" << endl;
        cout << "4. Divide two fractions" << endl;
        cout << "5. Negative fraction" << endl;
        cout << "6. Reduce fraction" << endl;
        cout << "7. Convert fraction to double" << endl;
        cout << "8. Inverse fraction" << endl;
        cout << "0. Exit" << endl;
        cout << "Choose the following options (0 - 8): ";
        int choice;
        cin >> choice;
        cin.ignore();
        if (choice == 0)
            return 0;
        if (choice < 0 || choice > 8)
        {
            cout << "Invalid choice! Please choose again!" << endl;
            continue;
        }
        if (choice >= 1 && choice <= 4)
        {
            MyFraction a, b;
            a.input("Enter first fraction: ");
            b.input("Enter second fraction: ");
            switch (choice)
            {
            case 1:
                myFraction = a + b;
                break;
            case 2:
                myFraction = a - b;
                break;
            case 3:
                myFraction = a * b;
                break;
            case 4:
                try
                {
                    if (b.getNumerator() == 0)
                        throw "# Denominator cannot be zero!";
                    myFraction = a / b;
                }
                catch (const char *msg)
                {
                    cout << msg << endl;
                    continue;
                }
            }
            myFraction.output("Result: ");
        }
        else
        {
            myFraction.input("Enter fraction: ");
            switch (choice)
            {
            case 5:
                myFraction = -myFraction;
                break;
            case 6:
                myFraction.reduce();
                break;
            case 7:
                cout << "Fraction to double: " << myFraction.toDouble() << endl;
                break;
            case 8:
                myFraction.inverse();
                break;
            }
            if (choice != 7)
                myFraction.output("Result: ");
        }
    }
}

int MyProgram::handle_complex()
{
    while (true)
    {
        cout << "========================COMPLEX========================\n";
        cout << "Choose an operation: " << endl;
        cout << "1. Add two complex numbers" << endl;
        cout << "2. Subtract two complex numbers" << endl;
        cout << "3. Multiply two complex numbers" << endl;
        cout << "4. Divide two complex numbers" << endl;
        cout << "5. Compute module" << endl;
        cout << "0. Exit" << endl;
        cout << "Choose the following options (0 - 5): ";
        int choice;
        cin >> choice;
        cin.ignore();
        if (choice == 0)
            return 0;
        if (choice < 0 || choice > 5)
        {
            cout << "Invalid choice! Please choose again!" << endl;
            continue;
        }
        if (choice >= 1 && choice <= 4)
        {
            MyComplex a, b;
            a.input("Enter first complex number: ");
            b.input("Enter second complex number: ");
            switch (choice)
            {
            case 1:
                myComplex = a + b;
                break;
            case 2:
                myComplex = a - b;
                break;
            case 3:
                myComplex = a * b;
                break;
            case 4:
                myComplex = a / b;
                break;
            }
            myComplex.output("Result complex: ");
        }
        else
        {
            myComplex.input("Enter complex number: ");
            cout << "Module of complex number: " << myComplex.modulus() << endl;
        }
    }
}

int MyProgram::handle_monomial()
{
    while (true)
    {
        cout << "========================MONOMIAL========================\n";
        cout << "Choose an operation: " << endl;
        cout << "1. Add two monomials" << endl;
        cout << "2. Subtract two monomials" << endl;
        cout << "3. Multiply two monomials" << endl;
        cout << "4. Divide two monomials" << endl;
        cout << "5. Compute value" << endl;
        cout << "6. Derivative" << endl;
        cout << "7. Anti-derivative" << endl;
        cout << "0. Exit" << endl;
        cout << "Choose the following options (0 - 7): ";
        int choice;
        cin >> choice;
        cin.ignore();
        if (choice == 0)
            return 0;
        if (choice < 0 || choice > 7)
        {
            cout << "Invalid choice! Please choose again!" << endl;
            continue;
        }
        if (choice >= 1 && choice <= 4)
        {
            MyMonomial a, b;
            a.input("Enter first monomial: ");
            b.input("Enter second monomial: ");
            switch (choice)
            {
            case 1:
                myMonomial = a + b;
                break;
            case 2:
                myMonomial = a - b;
                break;
            case 3:
                myMonomial = a * b;
                break;
            case 4:
                try
                {
                    if (b.getCoefficient() == 0)
                        throw "# Denominator cannot be zero!";
                    myMonomial = a / b;
                }
                catch (const char *msg)
                {
                    cout << msg << endl;
                    continue;
                }
            }
            myMonomial.output("Result monomial: ");
        }
        else
        {
            myMonomial.input("Enter monomial: ");
            switch (choice)
            {
            case 5:
                int x;
                cout << "Enter x: ";
                cin >> x;
                cin.ignore();
                cout << "Value of monomial: " << myMonomial.evaluate(x) << endl;
                break;
            case 6:
                myMonomial.derivative();
                cout << "Derivative of monomial: " << myMonomial << endl;
                break;
            case 7:
                myMonomial.antiDerivative();
                cout << "Anti-derivative of monomial: " << myMonomial << endl;
                break;
            }
        }
    }
}

int MyProgram::handle_pupil()
{
    while (true)
    {
        cout << "=======================PUPIL=====================" << endl;
        cout << "1. Input information of pupil" << endl;
        cout << "2. Output information of pupil" << endl;
        cout << "3. Get GPA of pupil" << endl;
        cout << "4. Get rank of pupil" << endl;
        cout << "0. Exit" << endl;
        cout << "Choose the following options (0 - 4): ";
        int choice;
        cin >> choice;
        cin.ignore();
        if (choice == 0)
            return 0;
        if (choice < 0 || choice > 4)
        {
            cout << "Invalid choice! Please choose again!" << endl;
            continue;
        }
        switch (choice)
        {
        case 1:
            myPupil.input();
            break;

        case 2:
            myPupil.output("Information of " + myPupil.getName() + ": ");
            break;

        case 3:
            cout << "GPA of " << myPupil.getName() << " is " << myPupil.getGPA() << endl;
            break;
        case 4:
            cout << "Rank of " << myPupil.getName() << " is " << myPupil.getRank() << endl;
            break;
        }
    }
}

int MyProgram::handle_array()
{
    while (true)
    {
        cout << "========================ARRAY=====================" << endl;
        cout << "1. Input information of array" << endl;
        cout << "2. Output information of array" << endl;
        cout << "3. Get size of array" << endl;
        cout << "4. Get element at index i" << endl;
        cout << "5. Set size of array" << endl;
        cout << "6. Set element at index i" << endl;
        cout << "7. Find element in array" << endl;
        cout << "8. Sort array ascending" << endl;
        cout << "9. Sort array descending" << endl;
        cout << "0. Exit" << endl;
        cout << "Choose the following options (0 - 9): ";
        int choice;
        cin >> choice;
        cin.ignore();
        if (choice == 0)
            return 0;
        if (choice < 0 || choice > 9)
        {
            cout << "Invalid choice! Please choose again!" << endl;
            continue;
        }
        switch (choice)
        {
        case 1:
            myArray.input();
            break;

        case 2:
            myArray.output("Information of array: ");
            break;

        case 3:
            cout << "Size of array is " << myArray.getSize() << endl;
            break;

        case 4:
            cout << "Enter index i: ";
            int i;
            cin >> i;
            cin.ignore();
            try
            {
                cout << "Element at index " << i << " is " << myArray[i] << endl;
            }
            catch (const char *msg)
            {
                cout << msg << endl;
            }
            break;

        case 5:
            cout << "Enter new size: ";
            int size;
            cin >> size;
            cin.ignore();
            try
            {
                myArray.setSize(size);
                cout << "Enter " << size << " of new array: " << endl;
                for (int i = 0; i < size; ++i)
                {
                    cout << "Enter element " << i + 1 << ": ";
                    cin >> myArray[i];
                }
            }
            catch (const char *msg)
            {
                cout << msg << endl;
            }
            break;

        case 6:
            cout << "Enter index i: ";
            cin >> i;
            cin.ignore();
            cout << "Enter new value: ";
            int value;
            cin >> value;
            cin.ignore();
            myArray[i] = value;
            break;
        case 7:
            cout << "Enter value to find: ";
            cin >> value;
            cin.ignore();
            i = myArray.find(value);
            if (i != -1)
                cout << "Value " << value << " is at index " << i << endl;
            else
                cout << "Value " << value << " is not in array!" << endl;
            break;
        case 8:
            myArray.sort();
            break;
        case 9:
            myArray.sort(MyArray::descending);
            break;
        }
    }
}

MyProgram::MyProgram(const MyFraction &myFraction, const MyComplex &myComplex, const MyMonomial &myMonomial, const MyPupil &myPupil, const MyArray &myArray)
    : myFraction(myFraction), myComplex(myComplex), myMonomial(myMonomial), myPupil(myPupil), myArray(myArray)
{
}

void MyProgram::run()
{
    while (true)
    {
        cout << "======================PROGRAM======================" << endl;
        cout << "1. Handle fraction" << endl;
        cout << "2. Handle complex" << endl;
        cout << "3. Handle monomial" << endl;
        cout << "4. Handle pupil" << endl;
        cout << "5. Handle array" << endl;
        cout << "0. Exit" << endl;
        cout << "Choose the following options (0 - 5): ";
        int choice;
        cin >> choice;
        cin.ignore();
        if (choice == 0)
        {
            cout << "Goodbye!" << endl;
            return;
        }
        if (choice < 0 || choice > 5)
        {
            cout << "Invalid choice! Please choose again!" << endl;
            continue;
        }
        switch (choice)
        {
        case 1:
            handle_fraction();
            break;
        case 2:
            handle_complex();
            break;
        case 3:
            handle_monomial();
            break;
        case 4:
            handle_pupil();
            break;
        case 5:
            handle_array();
            break;
        }
    }
}
