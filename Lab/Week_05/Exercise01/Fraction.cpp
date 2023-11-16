#include "Fraction.h"

/////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////// CONSTRUCTORS AND DESTRUCTOR //////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////

Fraction::Fraction(int numerator, int denominator)
{
    if (denominator == 0)
    {
        throw std::invalid_argument("Denominator cannot be zero");
    }

    int *pNumerator = new int(numerator);
    int *pDenominator = new int(denominator);

    if (pNumerator == nullptr || pDenominator == nullptr)
    {
        delete pNumerator;
        delete pDenominator;
        throw std::bad_alloc();
    }

    this->numerator = pNumerator;
    this->denominator = pDenominator;
}

Fraction::Fraction(const Fraction &fraction)
{
    int *pNumerator = new int(*fraction.numerator);
    int *pDenominator = new int(*fraction.denominator);

    if (pNumerator == nullptr || pDenominator == nullptr)
    {
        delete pNumerator;
        delete pDenominator;
        numerator = denominator = nullptr;
        throw std::bad_alloc();
    }

    this->numerator = pNumerator;
    this->denominator = pDenominator;
}

Fraction::~Fraction()
{
    delete numerator;
    delete denominator;
    numerator = denominator = nullptr;
}

/////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////// GETTERS AND SETTERS //////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////

int Fraction::getNumerator() const
{
    return *numerator;
}

int Fraction::getDenominator() const
{
    return *denominator;
}

void Fraction::setNumerator(int numerator)
{
    if (this->numerator == nullptr)
    {
        this->numerator = new int();
        if (this->numerator == nullptr)
        {
            throw std::bad_alloc();
        }
    }
    *this->numerator = numerator;
}

void Fraction::setDenominator(int denominator)
{
    if (denominator == 0)
    {
        throw std::invalid_argument("Denominator cannot be zero");
    }

    if (this->denominator == nullptr)
    {
        this->denominator = new int();
        if (this->denominator == nullptr)
        {
            throw std::bad_alloc();
        }
    }

    *this->denominator = denominator;
}

/////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////// OVERLOAD OPERATORS FOR ARITHMETIC ////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////

Fraction Fraction::operator=(const Fraction &fraction)
{
    if (this == &fraction)
    {
        return *this;
    }

    *numerator = *fraction.numerator;
    *denominator = *fraction.denominator;

    return *this;
}

Fraction Fraction::operator+(const Fraction &fraction) const
{
    int numerator = *this->numerator * *fraction.denominator + *fraction.numerator * *this->denominator;
    int denominator = *this->denominator * *fraction.denominator;

    return Fraction(numerator, denominator);
}

Fraction Fraction::operator-(const Fraction &fraction) const
{
    int numerator = *this->numerator * *fraction.denominator - *fraction.numerator * *this->denominator;
    int denominator = *this->denominator * *fraction.denominator;

    return Fraction(numerator, denominator);
}

Fraction Fraction::operator*(const Fraction &fraction) const
{
    int numerator = *this->numerator * *fraction.numerator;
    int denominator = *this->denominator * *fraction.denominator;

    return Fraction(numerator, denominator);
}

Fraction Fraction::operator/(const Fraction &fraction) const
{
    int numerator = *this->numerator * *fraction.denominator;
    int denominator = *this->denominator * *fraction.numerator;

    return Fraction(numerator, denominator);
}

Fraction Fraction::operator+=(const Fraction &fraction)
{
    *this = *this + fraction;
    return *this;
}

Fraction Fraction::operator-=(const Fraction &fraction)
{
    *this = *this - fraction;
    return *this;
}

Fraction Fraction::operator*=(const Fraction &fraction)
{
    *this = *this * fraction;
    return *this;
}

Fraction Fraction::operator/=(const Fraction &fraction)
{
    *this = *this / fraction;
    return *this;
}

/////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////// OVERLOAD OPERATORS FOR COMPARISON ////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////

bool Fraction::operator==(const Fraction &fraction) const
{
    return *this->numerator * *fraction.denominator == *fraction.numerator * *this->denominator;
}

bool Fraction::operator!=(const Fraction &fraction) const
{
    return !(*this == fraction);
}

bool Fraction::operator>(const Fraction &fraction) const
{
    return *this->numerator * *fraction.denominator > *fraction.numerator * *this->denominator;
}

bool Fraction::operator<(const Fraction &fraction) const
{
    return *this->numerator * *fraction.denominator < *fraction.numerator * *this->denominator;
}

bool Fraction::operator>=(const Fraction &fraction) const
{
    return *this->numerator * *fraction.denominator >= *fraction.numerator * *this->denominator;
}

bool Fraction::operator<=(const Fraction &fraction) const
{
    return *this->numerator * *fraction.denominator <= *fraction.numerator * *this->denominator;
}

/////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////// OVERLOAD OPERATORS FOR INCREMENT AND DECREMENT ///////////////////
/////////////////////////////////////////////////////////////////////////////////////////////

Fraction Fraction::operator++(int dummy)
{
    Fraction temp(*this);
    *this += 1;
    return temp;
}

Fraction Fraction::operator--(int dummy)
{
    Fraction temp(*this);
    *this -= 1;
    return temp;
}

Fraction Fraction::operator++()
{
    *this += 1;
    return *this;
}

Fraction Fraction::operator--()
{
    *this -= 1;
    return *this;
}

/////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////// OVERLOAD OPERATORS FOR INPUT AND OUTPUT //////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////

std::ostream &operator<<(std::ostream &os, const Fraction &fraction)
{
    os << *fraction.numerator << "/" << *fraction.denominator;
    return os;
}

std::istream &operator>>(std::istream &is, Fraction &fraction)
{
    int numerator, denominator;

    std::cout << "Enter numerator: ";
    is >> numerator;
    std::cout << "Enter denominator: ";
    is >> denominator;

    try
    {
        fraction.setNumerator(numerator);
        fraction.setDenominator(denominator);
    }
    catch (const std::invalid_argument &e)
    {
        std::cout << e.what() << std::endl;
        is >> fraction;
    }
    catch (const std::bad_alloc &e)
    {
        std::cout << e.what() << std::endl;
        is >> fraction;
    }

    return is;
}
