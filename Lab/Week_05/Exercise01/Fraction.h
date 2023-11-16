#pragma once

#include <iostream>

class Fraction
{
private:
    int *numerator;
    int *denominator;

public: // Constructors and destructor
    Fraction(int numerator = 0, int denominator = 1);
    Fraction(const Fraction &fraction);
    ~Fraction();

public: // Getters and setters
    int getNumerator() const;
    int getDenominator() const;
    void setNumerator(int numerator);
    void setDenominator(int denominator);

public: // Overload operators for arithmetic
    Fraction operator=(const Fraction &fraction);

    Fraction operator+(const Fraction &fraction) const;
    Fraction operator-(const Fraction &fraction) const;
    Fraction operator*(const Fraction &fraction) const;
    Fraction operator/(const Fraction &fraction) const;

    Fraction operator+=(const Fraction &fraction);
    Fraction operator-=(const Fraction &fraction);
    Fraction operator*=(const Fraction &fraction);
    Fraction operator/=(const Fraction &fraction);

public: // Overload operators for comparison
    bool operator==(const Fraction &fraction) const;
    bool operator!=(const Fraction &fraction) const;
    bool operator>(const Fraction &fraction) const;
    bool operator<(const Fraction &fraction) const;
    bool operator>=(const Fraction &fraction) const;
    bool operator<=(const Fraction &fraction) const;

public: // Overload operators for increment and decrement
    Fraction operator++(int dummy);
    Fraction operator--(int dummy);
    Fraction operator++();
    Fraction operator--();

public: // Overload operators for input and output
    friend std::ostream &operator<<(std::ostream &os, const Fraction &fraction);
    friend std::istream &operator>>(std::istream &is, Fraction &fraction);
};