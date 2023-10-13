#include "MyFraction.h"

MyFraction::MyFraction(int numerator, int denominator) noexcept
{
    numerator_ = numerator;
    denominator_ = denominator;
}

MyFraction::MyFraction(const MyFraction &fraction) noexcept
{
    numerator_ = fraction.numerator_;
    denominator_ = fraction.denominator_;
}

int MyFraction::getNumerator() const noexcept
{
    return numerator_;
}

int MyFraction::getDenominator() const noexcept
{
    return denominator_;
}

void MyFraction::setNumerator(int numerator) noexcept
{
    numerator_ = numerator;
}

void MyFraction::setDenominator(int denominator) noexcept
{
    denominator_ = denominator;
}

MyFraction MyFraction::operator+(const MyFraction &other) const noexcept
{
    MyFraction result;
    result.numerator_ = numerator_ * other.denominator_ + other.numerator_ * denominator_;
    result.denominator_ = denominator_ * other.denominator_;
    return result;
}

MyFraction MyFraction::operator-(const MyFraction &other) const noexcept
{
    MyFraction result;
    result.numerator_ = numerator_ * other.denominator_ - other.numerator_ * denominator_;
    result.denominator_ = denominator_ * other.denominator_;
    return result;
}

MyFraction MyFraction::operator*(const MyFraction &other) const noexcept
{
    MyFraction result;
    result.numerator_ = numerator_ * other.numerator_;
    result.denominator_ = denominator_ * other.denominator_;
    return result;
}

MyFraction MyFraction::operator/(const MyFraction &other) const noexcept
{
    MyFraction result;
    result.numerator_ = numerator_ * other.denominator_;
    result.denominator_ = denominator_ * other.numerator_;
    return result;
}

MyFraction MyFraction::operator-() const noexcept
{
    MyFraction result;
    result.numerator_ = -numerator_;
    result.denominator_ = denominator_;
    return result;
}

MyFraction &MyFraction::operator=(const MyFraction &other) noexcept
{
    numerator_ = other.numerator_;
    denominator_ = other.denominator_;
    return *this;
}

MyFraction &MyFraction::operator+=(const MyFraction &other) noexcept
{
    numerator_ = numerator_ * other.denominator_ + other.numerator_ * denominator_;
    denominator_ = denominator_ * other.denominator_;
    return *this;
}

MyFraction &MyFraction::operator-=(const MyFraction &other) noexcept
{
    numerator_ = numerator_ * other.denominator_ - other.numerator_ * denominator_;
    denominator_ = denominator_ * other.denominator_;
    return *this;
}

MyFraction &MyFraction::operator*=(const MyFraction &other) noexcept
{
    numerator_ = numerator_ * other.numerator_;
    denominator_ = denominator_ * other.denominator_;
    return *this;
}

MyFraction &MyFraction::operator/=(const MyFraction &other) noexcept
{
    numerator_ = numerator_ * other.denominator_;
    denominator_ = denominator_ * other.numerator_;
    return *this;
}

void MyFraction::reduce() noexcept
{
    int gcd = 1;
    int a = this->numerator_;
    int b = this->denominator_;
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    gcd = a;
    this->numerator_ /= gcd;
    this->denominator_ /= gcd;

    if (denominator_ < 0)
    {
        denominator_ = -denominator_;
        numerator_ = -numerator_;
    }
}

double MyFraction::toDouble() const noexcept
{
    return (double)numerator_ / denominator_;
}

void MyFraction::inverse() noexcept
{
    int temp = numerator_;
    numerator_ = denominator_;
    denominator_ = temp;
}

ostream &operator<<(ostream &os, const MyFraction &fraction) noexcept
{
    os << fraction.numerator_ << "/" << fraction.denominator_;
    return os;
}

istream &operator>>(istream &is, MyFraction &fraction)
{
    try
    {
        cout << "+ Numerator: ";
        is >> fraction.numerator_;
        cout << "+ Denominator: ";
        is >> fraction.denominator_;
        if (fraction.denominator_ == 0)
            throw "# Denominator cannot be zero!";
    }
    catch (const char *msg)
    {
        cout << msg << endl;
        is >> fraction;
    }
    return is;
}

void MyFraction::input(const string &msg)
{
    try
    {
        cout << msg << endl;
        cout << "+ Numerator: ";
        cin >> this->numerator_;
        cout << "+ Denominator: ";
        cin >> this->denominator_;
        if (this->denominator_ == 0)
            throw "# Denominator cannot be zero!";
    }
    catch (const char *msg)
    {
        cout << msg << endl;
        this->input(msg);
    }
}

void MyFraction::output(const string &msg) noexcept
{
    reduce();
    cout << msg << numerator_ << "/" << denominator_ << endl;
}