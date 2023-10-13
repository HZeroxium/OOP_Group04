#pragma once

#include "Common.h"

class MyMonomial
{
private:
    double coefficient_;
    int exponent_;

public:
    // Constructor
    MyMonomial(double coefficient_ = 0, int exponent_ = 0) noexcept; // Default constructor
    MyMonomial(const MyMonomial &monomial) noexcept;                 // Copy constructor

    // Getter
    double getCoefficient() const noexcept; // Get coefficient
    int getExponent() const noexcept;       // Get exponent

    // Setter
    void setCoefficient(double coefficient_) noexcept; // Set coefficient
    void setExponent(int exponent_) noexcept;          // Set exponent

    // Operator overload
    MyMonomial operator+(const MyMonomial &other) const noexcept; // Add two monomial
    MyMonomial operator-(const MyMonomial &other) const noexcept; // Subtract two monomial
    MyMonomial operator*(const MyMonomial &other) const noexcept; // Multiply two monomial
    MyMonomial operator/(const MyMonomial &other) const noexcept; // Divide two monomial
    MyMonomial operator-() const noexcept;                        // Negative monomial
    MyMonomial &operator=(const MyMonomial &other) noexcept;      // Assignment operator

    // Method
    double evaluate(double x) const noexcept; // Evaluate monomial
    void derivative() noexcept;               // Derivative monomial
    void antiDerivative() noexcept;           // Anti derivative monomial

    // Friend operator overload
    friend ostream &operator<<(ostream &os, const MyMonomial &monomial) noexcept;
    friend istream &operator>>(istream &is, MyMonomial &monomial) noexcept;

    // Input and output
    void input(const string &msg = "Input monomial: ") noexcept; // Input monomial
    void output(const string &msg = "Monomial: ") noexcept;      // Output monomial
};