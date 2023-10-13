#include "MyMonomial.h"

MyMonomial::MyMonomial(double coefficient, int exponent) noexcept
{
    coefficient_ = coefficient;
    exponent_ = exponent;
}

MyMonomial::MyMonomial(const MyMonomial &monomial) noexcept
{
    coefficient_ = monomial.coefficient_;
    exponent_ = monomial.exponent_;
}

double MyMonomial::getCoefficient() const noexcept
{
    return coefficient_;
}

int MyMonomial::getExponent() const noexcept
{
    return exponent_;
}

void MyMonomial::setCoefficient(double coefficient) noexcept
{
    coefficient_ = coefficient;
}

void MyMonomial::setExponent(int exponent) noexcept
{
    exponent_ = exponent;
}

MyMonomial MyMonomial::operator+(const MyMonomial &other) const noexcept
{
    MyMonomial result;
    result.coefficient_ = coefficient_ + other.coefficient_;
    result.exponent_ = exponent_;
    return result;
}

MyMonomial MyMonomial::operator-(const MyMonomial &other) const noexcept
{
    MyMonomial result;
    result.coefficient_ = coefficient_ - other.coefficient_;
    result.exponent_ = exponent_;
    return result;
}

MyMonomial MyMonomial::operator*(const MyMonomial &other) const noexcept
{
    MyMonomial result;
    result.coefficient_ = coefficient_ * other.coefficient_;
    result.exponent_ = exponent_ + other.exponent_;
    return result;
}

MyMonomial MyMonomial::operator/(const MyMonomial &other) const noexcept
{
    MyMonomial result;
    result.coefficient_ = coefficient_ / other.coefficient_;
    result.exponent_ = exponent_ - other.exponent_;
    return result;
}

MyMonomial MyMonomial::operator-() const noexcept
{
    MyMonomial result;
    result.coefficient_ = -coefficient_;
    result.exponent_ = exponent_;
    return result;
}

MyMonomial &MyMonomial::operator=(const MyMonomial &other) noexcept
{
    coefficient_ = other.coefficient_;
    exponent_ = other.exponent_;
    return *this;
}

double MyMonomial::evaluate(double x) const noexcept
{
    return coefficient_ * pow(x, exponent_);
}

void MyMonomial::derivative() noexcept
{
    coefficient_ *= exponent_;
    exponent_--;
}

void MyMonomial::antiDerivative() noexcept
{
    exponent_++;
    coefficient_ /= exponent_;
}

ostream &operator<<(ostream &os, const MyMonomial &monomial) noexcept
{
    if (monomial.coefficient_ == 0)
    {
        os << 0;
    }
    else if (monomial.exponent_ == 0)
    {
        os << monomial.coefficient_;
    }
    else
    {
        os << monomial.coefficient_ << "x^" << monomial.exponent_;
    }
    return os;
}

istream &operator>>(istream &is, MyMonomial &monomial) noexcept
{
    cout << "Input coefficient: ";
    is >> monomial.coefficient_;
    cout << "Input exponent: ";
    is >> monomial.exponent_;
    return is;
}

void MyMonomial::input(const string &msg) noexcept
{
    cout << msg << endl;
    cin >> *this;
}

void MyMonomial::output(const string &msg) noexcept
{
    cout << msg << *this << endl;
}
