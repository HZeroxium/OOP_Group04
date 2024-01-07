#include <iostream>

using namespace std;

class Base
{
public:
    Base()
    {
        cout << "Base::Base()" << endl;
    }
    Base(int x)
    {
        cout << "Base::Base(int)" << endl;
    }
    Base(int x, int y)
    {
        cout << "Base::Base(int, int)" << endl;
    }
    Base(const Base &other)
    {
        cout << "Base::Base(const Base&)" << endl;
    }
    virtual ~Base()
    {
        cout << "Base::~Base()" << endl;
    }
    Base &operator=(const Base &other)
    {
        cout << "Base::operator=(const Base&)" << endl;
        return *this;
    }
    virtual void doSth(int x)
    {
        cout << "Base::doSth(int)" << endl;
    }
    void doSthE(int x)
    {
        cout << "Base::doSthE(int)" << endl;
    }
};

class Derived : public Base
{
public:
    Derived()
    {
        cout << "Derived::Derived()" << endl;
    }
    Derived(int x) : Base(x)
    {
        cout << "Derived::Derived(int)" << endl;
    }
    Derived(int x, int y)
    {
        cout << "Derived::Derived(int, int)" << endl;
    }
    Derived(const Derived &other) : Base(other)
    {
        cout << "Derived::Derived(const Derived&)" << endl;
    }
    Derived &operator=(const Derived &other)
    {
        cout << "Derived::operator=(const Derived&)" << endl;
        return *this;
    }
    void doSth(int x)
    {
        cout << "Derived::doSth(int)" << endl;
    }
    void doSthE(int x)
    {
        cout << "Derived::doSthE(int)" << endl;
    }
    ~Derived()
    {
        cout << "Derived::~Derived()" << endl;
    }
};

void testing(Base &first, Derived second)
{
    cout << "Testing 3: " << endl;
    Derived x;
    x = second;
    first.doSth(1);
    first.doSthE(2);
    cout << "Testing 4: " << endl;
    x.doSth(3);
    x.doSthE(4);
}

int main()
{
    cout << "Testing 1: " << endl;
    Derived x(5), y(3, 7);
    cout << "Testing 2: " << endl;
    testing(x, y);
    cout << "Testing 5: " << endl;
    return 0;
}