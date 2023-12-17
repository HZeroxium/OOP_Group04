#include <string>
#include <iostream>
using namespace std;

int main()
{
    const string delimeter = ",";
    string s = "hello" + delimeter + "world";
    s += delimeter + "!";
    cout << s << endl;
}