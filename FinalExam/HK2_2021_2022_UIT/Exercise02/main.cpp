#include <iostream>

using namespace std;

class Fraction
{
private:
    int numerator;
    int denominator;

public:
    Fraction(int num = 0, int den = 1)
    {
        numerator = num;
        denominator = den;
    }
    Fraction(const Fraction &f)
    {
        numerator = f.numerator;
        denominator = f.denominator;
        cout << "Copy constructor called" << endl;
    }
    friend ostream &operator<<(ostream &out, const Fraction &f)
    {
        out << f.numerator << "/" << f.denominator;
        return out;
    }
    friend istream &operator>>(istream &in, Fraction &f)
    {
        char c;
        in >> f.numerator >> c >> f.denominator;
        return in;
    }
    Fraction operator--(int)
    {
        Fraction temp = *this;
        numerator -= denominator;
        return temp;
    }
    Fraction operator+(const Fraction &f)
    {
        Fraction temp;
        temp.numerator = numerator * f.denominator + f.numerator * denominator;
        temp.denominator = denominator * f.denominator;
        return temp;
    }
    friend Fraction operator+(int n, const Fraction &f)
    {
        Fraction temp;
        temp.numerator = n * f.denominator + f.numerator;
        temp.denominator = f.denominator;
        return temp;
    }
};

int main()
{
    Fraction f1, f2(-2, 3), f3;
    cin >> f1;
    f3 = 5 + f1 + f2--;
    cout << "Fraction 1: " << f1 << endl;
    cout << "Fraction 2: " << f2 << endl;
    cout << "Fraction 3: " << f3 << endl;
}