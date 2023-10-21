#include "MyString.h"
#include <iostream>

int MyStringExample()
{
    using std::cerr;
    using std::cin;
    using std::cout;
    using std::endl;

    MyString s;
    cout << "Input s: ";
    cin >> s;

    MyString t;
    cout << "Input t: ";
    cin >> t;

    cout << endl;
    cout << "cout << s: " << s << endl;
    cerr << "cerr << t: " << t << endl;
    cerr << "string after output: s = " << s << endl;

    cout << endl;
    cout << "s.length() = " << s.length() << endl;
    cerr << "string after taking length: s = " << s << endl;

    cout << endl;
    cout << "s.subString(2, 3) = " << s.subString(2, 3) << endl;
    cerr << "string after taking substring: s = " << s << endl;

    cout << endl;
    cout << "s+\" \"+t = " << s + " " + t << endl;
    cerr << "string after addition operation: s = " << s << endl;
    cerr << "string after addition operation: t = " << t << endl;

    cout << endl;
    cout << "s.insert(1, \"!\") = " << s.insert(1, "!") << endl;
    cerr << "string after insertion: s = " << s << endl;

    // cout << endl;
    // cout << "s.erase(0, 2) = " << s.erase(0, 2) << endl;
    // cerr << "string after erasure: s = " << s << endl;

    // cout << endl;
    // cout << "s.replace(0, 2, \"abc\") = " << s.replace(0, 2, "abc") << endl;
    // cerr << "string after replacement: s = " << s << endl;

    // cout << endl;
    // cout << "s.find(0, 11) = " << s.find(0, "11") << endl;
    // cerr << "string after finding: s = " << s << endl;
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