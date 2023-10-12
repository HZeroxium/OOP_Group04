#include "MyProgram.h"

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

MyProgram::MyProgram(const MyPupil &myPupil, const MyArray &myArray)
{
    this->myPupil = myPupil;
    this->myArray = myArray;
}

void MyProgram::run()
{
    while (true)
    {
        cout << "======================PROGRAM======================" << endl;
        cout << "1. Handle pupil" << endl;
        cout << "2. Handle array" << endl;
        cout << "0. Exit" << endl;
        cout << "Choose the following options (0 - 2): ";
        int choice;
        cin >> choice;
        cin.ignore();
        if (choice == 0)
        {
            cout << "Goodbye!" << endl;
            return;
        }
        if (choice < 0 || choice > 2)
        {
            cout << "Invalid choice! Please choose again!" << endl;
            continue;
        }
        switch (choice)
        {
        case 1:
            handle_pupil();
            break;

        case 2:
            handle_array();
            break;
        }
    }
}
