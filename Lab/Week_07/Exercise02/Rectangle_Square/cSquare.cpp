#include "cSquare.h"

cSquare::cSquare(double dSide)
{
    setSide(dSide);
}

void cSquare::setSide(double dSide)
{
    if (dSide < 0)
        dSide = 0;
    setDimensions(dSide, dSide);
}

double cSquare::getSide() const
{
    return getWidth();
}

void cSquare::input(std::istream &in)
{
    cout << "Enter the following information of the square:" << endl;
    cout << "+ Side: ";
    double dSide;
    in >> dSide;
    setSide(dSide);
}

void cSquare::output(std::ostream &out) const
{
    out << "The following is the information of the square:" << endl;
    out << "+ Side: " << getWidth() << endl;
    out << "+ Area: " << getArea() << endl;
    out << "+ Perimeter: " << getPerimeter() << endl;
}

std::ostream &operator<<(std::ostream &out, const cSquare &square)
{
    square.output(out);
    return out;
}

std::istream &operator>>(std::istream &in, cSquare &square)
{
    square.input(in);
    return in;
}
