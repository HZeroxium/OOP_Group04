#include "MyString.h"

/* How To Run:

    Step 1: Summon command prompt
        Press Window + R
        Type "cmd"
        Press Enter

    Step 2: Create the main.exe file
        Run the following command
        ```
        g++ MyString.h MyString.cpp main.cpp -o main
        ```

    Step 3: Run the main.exe file
        Run the following command
        ```
        ./main.exe
        ```
*/
class MyProgram
{
private:
    MyString str;
    void handleExample();
    void handleFunction();

public:
    MyProgram();
    void run();
};

int main()
{
    MyProgram program;
    program.run();
    return 0;
}

MyProgram::MyProgram()
{
    str = MyString();
}

void MyProgram::run()
{
    using namespace std;
    while (true)
    {
        cout << "====================================================\n";
        cout << "Welcome to MyString Program\n";
        cout << "====================================================\n";
        cout << "1. Example\n";
        cout << "2. Functions\n";
        cout << "0. Exit\n";
        cout << "====================================================\n";
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;
        cin.ignore();
        if (choice == 0)
        {
            cout << "Goodbye!\n";
            return;
        }
        if (choice < 0 || choice > 2)
        {
            cout << "Invalid choice! Choose option from 0 to 2.\n";
            continue;
        }
        if (choice == 1)
        {
            handleExample();
        }
        else
        {
            handleFunction();
        }
    }
}

void MyProgram::handleExample()
{
    using std::cerr;
    using std::cin;
    using std::cout;
    using std::endl;
    cout << "====================================================\n";
    cout << "Example\n";
    cout << "====================================================\n";
    MyString s("Hello"), t("World");

    cout << endl;
    cerr << "String s: " << s << endl;
    cerr << "String t: " << t << endl;

    cout << endl;
    cout << "Length of string s: " << s.length() << endl;

    cout << endl;
    cout << "Result of s.subString(2, 3) = " << s.subString(2, 3) << endl;
    cerr << "String s after taking substring: " << s << endl;

    cout << endl;
    cout << "s + \" \" + t = " << s + " " + t << endl;
    cerr << "String s after addition operation: " << s << endl;
    cerr << "String t after addition operation: " << t << endl;

    cout << endl;
    s.insert(1, "!");
    cout << "Result of s.insert(1, \"!\") = " << s << endl;
    cerr << "String s after insertion: s = " << s << endl;

    cout << endl;
    s.erase(0, 2);
    cout << "s.erase(0, 2) = " << s << endl;
    cerr << "String after erasure: s = " << s << endl;

    cout << endl;
    s.replace(0, 2, "abc");
    cout << "Result of s.replace(0, 2, \"abc\") = " << s << endl;
    cerr << "String after replacement: s = " << s << endl;

    cout << endl;
    cout << "Result of s.find(0, \"ll\") = " << s.find(0, "ll") << endl;
    cerr << "String after finding: s = " << s << endl;
}

void MyProgram::handleFunction()
{
    using namespace std;
    while (true)
    {
        cout << "====================================================\n";
        cout << "Functions\n";
        cout << "====================================================\n";
        cout << "1. Input string\n";
        cout << "2. Output string\n";
        cout << "3. Length of string\n";
        cout << "4. Substring\n";
        cout << "5. Addition of two strings\n";
        cout << "6. Insertion\n";
        cout << "7. Erasure\n";
        cout << "8. Replacement\n";
        cout << "9. Finding\n";
        cout << "0. Exit\n";
        cout << "====================================================\n";
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;
        cin.ignore();
        if (choice == 0)
        {
            cout << "Goodbye!\n";
            return;
        }
        if (choice < 0 || choice > 9)
        {
            cout << "Invalid choice! Choose option from 0 to 9.\n";
            return;
        }
        switch (choice)
        {
        case 1:
        {
            cout << "Enter string: ";
            cin >> str;
            break;
        }
        case 2:
        {
            cout << "String: " << str << endl;
            break;
        }
        case 3:
        {
            cout << "Length of string: " << str.length() << endl;
            break;
        }
        case 4:
        {
            cout << "Enter start index: ";
            int start;
            cin >> start;
            cout << "Enter length: ";
            int length;
            cin >> length;
            char *substr = str.subString(start, length);
            if (substr == nullptr)
            {
                cout << "Invalid start index or length!\n";
            }
            else
            {
                cout << "Substring: " << substr << endl;
            }
            break;
        }
        case 5:
        {
            cout << "Enter string to concatenate: ";
            MyString other;
            cin >> other;
            cout << "Result of concatenation = " << str + other << endl;
            break;
        }
        case 6:
        {
            cout << "Enter start index: ";
            int start;
            cin >> start;
            cin.ignore();
            cout << "Enter string to insert: ";
            MyString insert_data;
            cin >> insert_data;
            if (str.insert(start, insert_data.value()))
            {
                cout << "Result of insertion = " << str << endl;
            }
            else
            {
                cout << "Invalid start index!\n";
            }
            break;
        }
        case 7:
        {
            cout << "Enter start index: ";
            int start;
            cin >> start;
            cout << "Enter length: ";
            int length;
            cin >> length;
            if (str.erase(start, length))
            {
                cout << "Result of erasure = " << str << endl;
            }
            else
            {
                cout << "Invalid start index or length!\n";
            }
            break;
        }
        case 8:
        {
            cout << "Enter start index: ";
            int start;
            cin >> start;
            cout << "Enter length: ";
            int length;
            cin >> length;
            cin.ignore();
            cout << "Enter string to replace: ";
            MyString replace_data;
            cin >> replace_data;
            if (str.replace(start, length, replace_data.value()))
            {
                cout << "Result of replacement = " << str << endl;
            }
            else
            {
                cout << "Invalid start index or length!\n";
            }
            break;
        }
        case 9:
        {
            cout << "Enter start index: ";
            int start;
            cin >> start;
            cin.ignore();
            cout << "Enter string to find: ";
            MyString pattern;
            cin >> pattern;
            int idx = str.find(start, pattern.value());
            if (idx == -1)
            {
                cout << "Not found!\n";
            }
            else
            {
                cout << "Found at index " << idx << endl;
            }
            break;
        }
        }
    }
}
