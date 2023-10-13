#pragma once

#include "Common.h"

class MyComplex
{
private:
    double real_;
    double imaginary_;

public:
    // Constructor
    MyComplex(double real_ = 0, double imaginary_ = 0) noexcept; // Default constructor
    MyComplex(const MyComplex &complex) noexcept;                // Copy constructor

    // Getter
    double getReal() const noexcept;      // Get real part
    double getImaginary() const noexcept; // Get imaginary part

    // Setter
    void setReal(double real_) noexcept;           // Set real part
    void setImaginary(double imaginary_) noexcept; // Set imaginary part

    // Operator overload
    MyComplex operator+(const MyComplex &other) const noexcept; // Add two complex
    MyComplex operator-(const MyComplex &other) const noexcept; // Subtract two complex
    MyComplex operator*(const MyComplex &other) const noexcept; // Multiply two complex
    MyComplex operator/(const MyComplex &other) const noexcept; // Divide two complex
    MyComplex operator-() const noexcept;                       // Negative complex
    MyComplex &operator=(const MyComplex &other) noexcept;      // Assignment operator

    // Method
    double modulus() const noexcept; // Get modulus of complex
    void conjugate() noexcept;       // Conjugate complex

    // Friend operator overload
    friend ostream &operator<<(ostream &os, const MyComplex &complex) noexcept;
    friend istream &operator>>(istream &is, MyComplex &complex) noexcept;

    // Input and output
    void input(const string &msg = "Input complex: ") noexcept; // Input complex
    void output(const string &msg = "Complex: ") noexcept;      // Output complex
};