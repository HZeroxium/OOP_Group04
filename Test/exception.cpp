#include <iostream>

using namespace std;

class IntPtr
{
private:
    int *p;

public:
    IntPtr(int n)
    {
        if (n > 0)
            p = new int[n];
        else
            throw "IntPtr constructor: Invalid size";
    }
    ~IntPtr()
    {
        cout << "IntPtr destructor" << endl;
        delete[] p;
    }
};

void test(int a, int b, int t) throw(const char *)
{
    IntPtr p(t);
    if (a == b)
        throw (const char *)"Error";
}

int main()
{
    try
    {
        test(1, 1, 1);
    }
    catch (const char *s)
    {
        cout << s << endl;
    }
    return 0;
}