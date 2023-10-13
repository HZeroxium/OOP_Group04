#pragma once

#include "Common.h"

class MyFraction
{
private:
    int numerator_;
    int denominator_;

public:
    // Constructor
    MyFraction(int numerator_ = 0, int denominator_ = 1) noexcept; // Default constructor
    MyFraction(const MyFraction &fraction) noexcept;               // Copy constructor

    // Getter
    int getNumerator() const noexcept;   // Get numerator
    int getDenominator() const noexcept; // Get denominator

    // Setter
    void setNumerator(int numerator_) noexcept;     // Set numerator
    void setDenominator(int denominator_) noexcept; // Set denominator

    // Operator overload
    MyFraction operator+(const MyFraction &other) const noexcept; // Add two fraction
    MyFraction operator-(const MyFraction &other) const noexcept; // Subtract two fraction
    MyFraction operator*(const MyFraction &other) const noexcept; // Multiply two fraction
    MyFraction operator/(const MyFraction &other) const noexcept; // Divide two fraction
    MyFraction operator-() const noexcept;                        // Negative fraction
    MyFraction &operator=(const MyFraction &other) noexcept;      // Assignment operator
    MyFraction &operator+=(const MyFraction &other) noexcept;     // Add and assign two fraction
    MyFraction &operator-=(const MyFraction &other) noexcept;     // Subtract and assign two fraction
    MyFraction &operator*=(const MyFraction &other) noexcept;     // Multiply and assign two fraction
    MyFraction &operator/=(const MyFraction &other) noexcept;     // Divide and assign two fraction

    // Method
    void reduce() noexcept;           // Reduce fraction to the simplest form
    double toDouble() const noexcept; // Convert fraction to double
    void inverse() noexcept;          // Inverse fraction

    // Friend operator overload
    friend ostream &operator<<(ostream &os, const MyFraction &fraction) noexcept;
    friend istream &operator>>(istream &is, MyFraction &fraction);

    // Input and output
    void input(const string &msg = "Input fraction: ");     // Input fraction
    void output(const string &msg = "Fraction: ") noexcept; // Output fraction
};