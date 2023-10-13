#include "MyComplex.h"

MyComplex::MyComplex(double real, double imaginary) noexcept
{
    real_ = real;
    imaginary_ = imaginary;
}

MyComplex::MyComplex(const MyComplex &complex) noexcept
{
    real_ = complex.real_;
    imaginary_ = complex.imaginary_;
}

double MyComplex::getReal() const noexcept
{
    return real_;
}

double MyComplex::getImaginary() const noexcept
{
    return imaginary_;
}

void MyComplex::setReal(double real) noexcept
{
    real_ = real;
}

void MyComplex::setImaginary(double imaginary) noexcept
{
    imaginary_ = imaginary;
}

MyComplex MyComplex::operator+(const MyComplex &other) const noexcept
{
    MyComplex result;
    result.real_ = real_ + other.real_;
    result.imaginary_ = imaginary_ + other.imaginary_;
    return result;
}

MyComplex MyComplex::operator-(const MyComplex &other) const noexcept
{
    MyComplex result;
    result.real_ = real_ - other.real_;
    result.imaginary_ = imaginary_ - other.imaginary_;
    return result;
}

MyComplex MyComplex::operator*(const MyComplex &other) const noexcept
{
    MyComplex result;
    result.real_ = real_ * other.real_ - imaginary_ * other.imaginary_;
    result.imaginary_ = real_ * other.imaginary_ + imaginary_ * other.real_;
    return result;
}

MyComplex MyComplex::operator/(const MyComplex &other) const noexcept
{
    MyComplex result;
    double denominator = other.real_ * other.real_ + other.imaginary_ * other.imaginary_;
    result.real_ = (real_ * other.real_ + imaginary_ * other.imaginary_) / denominator;
    result.imaginary_ = (imaginary_ * other.real_ - real_ * other.imaginary_) / denominator;
    return result;
}

MyComplex MyComplex::operator-() const noexcept
{
    MyComplex result;
    result.real_ = -real_;
    result.imaginary_ = -imaginary_;
    return result;
}

MyComplex &MyComplex::operator=(const MyComplex &other) noexcept
{
    real_ = other.real_;
    imaginary_ = other.imaginary_;
    return *this;
}

double MyComplex::modulus() const noexcept
{
    return sqrt(real_ * real_ + imaginary_ * imaginary_);
}

void MyComplex::conjugate() noexcept
{
    imaginary_ = -imaginary_;
}

ostream &operator<<(ostream &os, const MyComplex &complex) noexcept
{
    os << complex.real_ << " + " << complex.imaginary_ << "i";
    return os;
}

istream &operator>>(istream &is, MyComplex &complex) noexcept
{
    cout << "+ Real part: ";
    is >> complex.real_;
    cout << "+ Imaginary part: ";
    is >> complex.imaginary_;
    return is;
}

void MyComplex::input(const string &msg) noexcept
{
    cout << msg << endl;
    cin >> *this;
}

void MyComplex::output(const string &msg) noexcept
{
    cout << msg << *this << endl;
}
