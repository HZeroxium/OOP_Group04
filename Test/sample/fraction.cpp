#include "fraction.h"
#include <iostream>
//**********************************************************************************************************************
//************************************** CONSTRUCTORS AND DESTRUCTOR ***************************************************
//**********************************************************************************************************************

/// @brief Default constructor
Fraction::Fraction()
{
    numerator = 0;
    denominator = 1;
    cout << "Default constructor called at fraction " << this->toString() << endl;
}

/// @brief Parameterized constructor
Fraction::Fraction(int numerator, int denominator)
{
    this->numerator = numerator;
    this->denominator = denominator;
    cout << "Parameterized constructor called at fraction " << this->toString() << endl;
}

/// @brief Copy constructor
Fraction::Fraction(const Fraction &fraction)
{
    numerator = fraction.numerator;
    denominator = fraction.denominator;
    cout << "Copy constructor called at fraction " << this->toString() << endl;
}

/// @brief Move constructor
Fraction::Fraction(Fraction &&fraction)
{
    numerator = fraction.numerator;
    denominator = fraction.denominator;
    cout << "Move constructor called at fraction " << this->toString() << endl;
}

/// @brief Copy assignment operator
Fraction &Fraction::operator=(const Fraction &fraction)
{
    numerator = fraction.numerator;
    denominator = fraction.denominator;
    cout << "Copy assignment operator called at fraction " << this->toString() << endl;
    return *this;
}

/// @brief Move assignment operator
Fraction &Fraction::operator=(Fraction &&fraction)
{
    numerator = fraction.numerator;
    denominator = fraction.denominator;
    cout << "Move assignment operator called at fraction " << this->toString() << endl;
    return *this;
}

/// @brief Destructor
Fraction::~Fraction()
{
    cout << "Destructor called at fraction " << this->toString() << endl;
}

//**********************************************************************************************************************
//********************************************* GETTERS AND SETTERS ****************************************************
//**********************************************************************************************************************

/// @brief Getter for numerator
int Fraction::getNumerator() const
{
    return numerator;
}

/// @brief Setter for numerator
void Fraction::setNumerator(int numerator)
{
    this->numerator = numerator;
}

/// @brief Getter for denominator
int Fraction::getDenominator() const
{
    return denominator;
}

/// @brief Setter for denominator
void Fraction::setDenominator(int denominator)
{
    this->denominator = denominator;
}

//**********************************************************************************************************************
//********************************************* ARITHMETIC OPERATORS ****************************************************
//**********************************************************************************************************************

/// @brief Addition with another fraction
Fraction Fraction::operator+(const Fraction &fraction) const
{
    int numerator = this->numerator * fraction.denominator + fraction.numerator * this->denominator;
    int denominator = this->denominator * fraction.denominator;
    return Fraction(numerator, denominator);
}

/// @brief Subtraction with another fraction
Fraction Fraction::operator-(const Fraction &fraction) const
{
    int numerator = this->numerator * fraction.denominator - fraction.numerator * this->denominator;
    int denominator = this->denominator * fraction.denominator;
    return Fraction(numerator, denominator);
}

/// @brief Multiplication with another fraction
Fraction Fraction::operator*(const Fraction &fraction) const
{
    int numerator = this->numerator * fraction.numerator;
    int denominator = this->denominator * fraction.denominator;
    return Fraction(numerator, denominator);
}

/// @brief Division with another fraction
Fraction Fraction::operator/(const Fraction &fraction) const
{
    int numerator = this->numerator * fraction.denominator;
    int denominator = this->denominator * fraction.numerator;
    return Fraction(numerator, denominator);
}

/// @brief Unary minus
Fraction Fraction::operator-() const
{
    return Fraction(-numerator, denominator);
}

/// @brief Pre-increment
Fraction &Fraction::operator++()
{
    numerator += denominator;
    return *this;
}

/// @brief Post-increment
Fraction Fraction::operator++(int)
{
    Fraction temp = *this;
    numerator += denominator;
    return temp;
}

/// @brief Pre-decrement
Fraction &Fraction::operator--()
{
    numerator -= denominator;
    return *this;
}

/// @brief Post-decrement
Fraction Fraction::operator--(int)
{
    Fraction temp = *this;
    numerator -= denominator;
    return temp;
}

/// @brief Addition assignment with another fraction
Fraction &Fraction::operator+=(const Fraction &fraction)
{
    numerator = numerator * fraction.denominator + fraction.numerator * denominator;
    denominator *= fraction.denominator;
    return *this;
}

/// @brief Subtraction assignment with another fraction
Fraction &Fraction::operator-=(const Fraction &fraction)
{
    numerator = numerator * fraction.denominator - fraction.numerator * denominator;
    denominator *= fraction.denominator;
    return *this;
}

/// @brief Multiplication assignment with another fraction
Fraction &Fraction::operator*=(const Fraction &fraction)
{
    numerator *= fraction.numerator;
    denominator *= fraction.denominator;
    return *this;
}

/// @brief Division assignment with another fraction
Fraction &Fraction::operator/=(const Fraction &fraction)
{
    numerator *= fraction.denominator;
    denominator *= fraction.numerator;
    return *this;
}

/// @brief Addition with an integer
Fraction Fraction::operator+(int value) const
{
    int numerator = this->numerator + value * denominator;
    int denominator = this->denominator;
    return Fraction(numerator, denominator);
}

/// @brief Subtraction with an integer
Fraction Fraction::operator-(int value) const
{
    int numerator = this->numerator - value * denominator;
    int denominator = this->denominator;
    return Fraction(numerator, denominator);
}

/// @brief Multiplication with an integer
Fraction Fraction::operator*(int value) const
{
    int numerator = this->numerator * value;
    int denominator = this->denominator;
    return Fraction(numerator, denominator);
}

/// @brief Division with an integer
Fraction Fraction::operator/(int value) const
{
    int numerator = this->numerator;
    int denominator = this->denominator * value;
    return Fraction(numerator, denominator);
}

/// @brief Addition assignment with an integer
Fraction &Fraction::operator+=(int value)
{
    numerator += value * denominator;
    return *this;
}

/// @brief Subtraction assignment with an integer
Fraction &Fraction::operator-=(int value)
{
    numerator -= value * denominator;
    return *this;
}

/// @brief Multiplication assignment with an integer
Fraction &Fraction::operator*=(int value)
{
    numerator *= value;
    return *this;
}

/// @brief Division assignment with an integer
Fraction &Fraction::operator/=(int value)
{
    denominator *= value;
    return *this;
}

//**********************************************************************************************************************
//********************************************* COMPARISON OPERATORS ****************************************************
//**********************************************************************************************************************

/// @brief Equality
bool Fraction::operator==(const Fraction &fraction) const
{
    return numerator * fraction.denominator == fraction.numerator * denominator;
}

/// @brief Inequality
bool Fraction::operator!=(const Fraction &fraction) const
{
    return numerator * fraction.denominator != fraction.numerator * denominator;
}

/// @brief Less than
bool Fraction::operator<(const Fraction &fraction) const
{
    return numerator * fraction.denominator < fraction.numerator * denominator;
}

/// @brief Less than or equal to
bool Fraction::operator<=(const Fraction &fraction) const
{
    return numerator * fraction.denominator <= fraction.numerator * denominator;
}

/// @brief Greater than
bool Fraction::operator>(const Fraction &fraction) const
{
    return numerator * fraction.denominator > fraction.numerator * denominator;
}

/// @brief Greater than or equal to
bool Fraction::operator>=(const Fraction &fraction) const
{
    return numerator * fraction.denominator >= fraction.numerator * denominator;
}

//**********************************************************************************************************************
//********************************************* TYPE CONVERSION OPERATORS ************************************************
//**********************************************************************************************************************

/// @brief Conversion to int
Fraction::operator int() const
{
    return numerator / denominator;
}

/// @brief Conversion to double
Fraction::operator double() const
{
    return (double)numerator / denominator;
}

/// @brief Conversion to float
Fraction::operator float() const
{
    return (float)numerator / denominator;
}

/// @brief Conversion to string
Fraction::operator string() const
{
    return to_string(numerator) + "/" + to_string(denominator);
}

//**********************************************************************************************************************
//********************************************* FRIEND FUNCTIONS ********************************************************
//**********************************************************************************************************************

/// @brief Addition with an integer
Fraction operator+(int value, const Fraction &fraction)
{
    int numerator = fraction.getNumerator() + value * fraction.getDenominator();
    int denominator = fraction.getDenominator();
    return Fraction(numerator, denominator);
}

/// @brief Subtraction with an integer
Fraction operator-(int value, const Fraction &fraction)
{
    int numerator = value * fraction.getDenominator() - fraction.getNumerator();
    int denominator = fraction.getDenominator();
    return Fraction(numerator, denominator);
}

/// @brief Multiplication with an integer
Fraction operator*(int value, const Fraction &fraction)
{
    int numerator = value * fraction.getNumerator();
    int denominator = fraction.getDenominator();
    return Fraction(numerator, denominator);
}

/// @brief Division with an integer
Fraction operator/(int value, const Fraction &fraction)
{
    int numerator = value * fraction.getDenominator();
    int denominator = fraction.getNumerator();
    return Fraction(numerator, denominator);
}

/// @brief Output stream operator
ostream &operator<<(ostream &os, const Fraction &fraction)
{
    os << fraction.toString();
    return os;
}

/// @brief Input stream operator
istream &operator>>(istream &is, Fraction &fraction)
{
    string str;
    is >> str;
    int pos = str.find('/');
    int numerator = stoi(str.substr(0, pos));
    int denominator = stoi(str.substr(pos + 1));
    fraction.setNumerator(numerator);
    fraction.setDenominator(denominator);
    return is;
}

//**********************************************************************************************************************
//********************************************* MEMBER FUNCTIONS ********************************************************
//**********************************************************************************************************************

/// @brief Simplify the fraction
void Fraction::simplify()
{
    int gcd = this->gcd(numerator, denominator);
    numerator /= gcd;
    denominator /= gcd;
}

/// @brief Print the fraction
void Fraction::print()
{
    cout << numerator << "/" << denominator << endl;
}

/// @brief Convert the fraction to string
string Fraction::toString() const
{
    return to_string(numerator) + "/" + to_string(denominator);
}

//**********************************************************************************************************************
//********************************************* HELPER FUNCTIONS ********************************************************
//**********************************************************************************************************************

/// @brief Greatest common divisor
int Fraction::gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

//**********************************************************************************************************************
//********************************************* END OF FILE ****************************************************************
//**********************************************************************************************************************
