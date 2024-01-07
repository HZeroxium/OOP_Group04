#pragma once

#include <string>
using namespace std;
/// @brief Fraction class represents a fraction with numerator and denominator

class Fraction
{
private: // Properties
    int numerator;
    int denominator;

public:                                            // Constructors and Destructor
    Fraction();                                    // Default constructor
    Fraction(int numerator, int denominator);      // Parameterized constructor
    Fraction(const Fraction &fraction);            // Copy constructor
    Fraction(Fraction &&fraction);                 // Move constructor
    Fraction &operator=(const Fraction &fraction); // Copy assignment operator
    Fraction &operator=(Fraction &&fraction);      // Move assignment operator
    ~Fraction();                                   // Destructor

public: // Getters and Setters
    int getNumerator() const;
    void setNumerator(int numerator);
    int getDenominator() const;
    void setDenominator(int denominator);

public:                                                 // Arithmetic operators
    Fraction operator+(const Fraction &fraction) const; // Addition with another fraction
    Fraction operator-(const Fraction &fraction) const; // Subtraction with another fraction
    Fraction operator*(const Fraction &fraction) const; // Multiplication with another fraction
    Fraction operator/(const Fraction &fraction) const; // Division with another fraction
    Fraction operator-() const;                         // Unary minus
    Fraction &operator++();                             // Pre-increment
    Fraction operator++(int);                           // Post-increment
    Fraction &operator--();                             // Pre-decrement
    Fraction operator--(int);                           // Post-decrement
    Fraction &operator+=(const Fraction &fraction);     // Addition assignment with another fraction
    Fraction &operator-=(const Fraction &fraction);     // Subtraction assignment with another fraction
    Fraction &operator*=(const Fraction &fraction);     // Multiplication assignment with another fraction
    Fraction &operator/=(const Fraction &fraction);     // Division assignment with another fraction
    Fraction operator+(int value) const;                // Addition with an integer
    Fraction operator-(int value) const;                // Subtraction with an integer
    Fraction operator*(int value) const;                // Multiplication with an integer
    Fraction operator/(int value) const;                // Division with an integer
    Fraction &operator+=(int value);                    // Addition assignment with an integer
    Fraction &operator-=(int value);                    // Subtraction assignment with an integer
    Fraction &operator*=(int value);                    // Multiplication assignment with an integer
    Fraction &operator/=(int value);                    // Division assignment with an integer

public:                                              // Comparison operators
    bool operator==(const Fraction &fraction) const; // Equality
    bool operator!=(const Fraction &fraction) const; // Inequality
    bool operator<(const Fraction &fraction) const;  // Less than
    bool operator<=(const Fraction &fraction) const; // Less than or equal to
    bool operator>(const Fraction &fraction) const;  // Greater than
    bool operator>=(const Fraction &fraction) const; // Greater than or equal to

public:                               // Type conversion operators
    explicit operator int() const;    // Conversion to int
    explicit operator double() const; // Conversion to double
    explicit operator float() const;  // Conversion to float
    explicit operator string() const; // Conversion to string

public:                                                             // Friend functions
    friend Fraction operator+(int value, const Fraction &fraction); // Addition with an integer
    friend Fraction operator-(int value, const Fraction &fraction); // Subtraction with an integer
    friend Fraction operator*(int value, const Fraction &fraction); // Multiplication with an integer
    friend Fraction operator/(int value, const Fraction &fraction); // Division with an integer
    friend ostream &operator<<(ostream &out, const Fraction &fraction);
    friend istream &operator>>(istream &in, Fraction &fraction);

public:                      // Member functions
    void simplify();         // Simplify the fraction
    void print();            // Print the fraction
    string toString() const; // Convert the fraction to string

private:                   // Helper functions
    int gcd(int a, int b); // Greatest common divisor

public:                                                                             // Static functions
    static Fraction add(const Fraction &fraction1, const Fraction &fraction2);      // Addition with two fractions
    static Fraction subtract(const Fraction &fraction1, const Fraction &fraction2); // Subtraction with two fractions
    static Fraction multiply(const Fraction &fraction1, const Fraction &fraction2); // Multiplication with two fractions
    static Fraction divide(const Fraction &fraction1, const Fraction &fraction2);   // Division with two fractions
};