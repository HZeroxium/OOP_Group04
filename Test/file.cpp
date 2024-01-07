#include <iostream>
#include <fstream>

using namespace std;

void tellPosition(iostream &s)
{
    cout << "============================" << endl;
    cout << "Put pointer: " << s.tellp() << endl;
    cout << "Get pointer: " << s.tellg() << endl;
}

void upcaseStream(iostream &s)
{
    char c;
    while (s >> c)
    {
        tellPosition(s);
        c = toupper(c);
        s.seekp(-1, ios::cur);
        tellPosition(s);
        s << c;
        tellPosition(s);
    }
}

int main()
{
    fstream file("input.txt", ios::in | ios::out);
    if (file)
    {
        upcaseStream(file);
    }
}