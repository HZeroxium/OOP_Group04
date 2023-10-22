#include "MyString.h"
#include <iostream>

int MyStringExample()
{
    using std::cerr;
    using std::cin;
    using std::cout;
    using std::endl;

    MyString s, t;
    cout << "Enter string s: ";
    cin >> s;

    cout << "Enter string t: ";
    cin >> t;

    cout << endl;
    cout << "String s: " << s << endl;
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
    return 0;
}

int main()
{
    MyStringExample();
    return 0;
}

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