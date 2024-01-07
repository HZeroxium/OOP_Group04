#include <iostream>
#include <string>
using namespace std;

class Int
{
private:
    int val;

public: // Constructor & Destructor
    inline Int() : val(0)
    {
        cout << "Default Constructor called at " << this << endl;
    }
    inline Int(int n) : val(n)
    {
        cout << "Parameterized Constructor called at " << this << endl;
    }
    inline Int(const Int &n) : val(n.val)
    {
        cout << "Copy Constructor called at " << this << endl;
    }
    inline ~Int()
    {
        cout << "Destructor called at " << this << endl;
    }

public: // Getter & Setter
    inline int get() const { return val; }
    inline void set(int n) { val = n; }

public: // Operator Overloading
    operator string() const
    {
        cout << "String cast called at " << this->val << endl;
        return to_string(val);
    }

    operator int() const
    {
        cout << "Int cast called at " << this->val << endl;
        return val;
    }

    Int &operator=(const Int &n)
    {
        cout << "Assignment operator called at " << this << endl;
        val = n.val;
        return *this;
    }
};

int main()
{
    Int a;
    Int b(1);
    Int c(b);
    Int d = c;
    d = c;
    Int e = 2;
    Int f = Int(3);
    Int g = (Int)4;
    Int h = static_cast<Int>(5);
    string i = static_cast<string>(h);
    int j = static_cast<int>(h);
}