#include "cRectangle.h"

cRectangle::cRectangle(double dWidth, double dHeight)
{
    setDimensions(dWidth, dHeight);
}

void cRectangle::setWidth(double dWidth)
{
    if (dWidth < 0)
        dWidth = 0;
    m_dWidth = dWidth;
}

void cRectangle::setHeight(double dHeight)
{
    if (dHeight < 0)
        dHeight = 0;
    m_dHeight = dHeight;
}

void cRectangle::setDimensions(double dWidth, double dHeight)
{
    setWidth(dWidth);
    setHeight(dHeight);
}

double cRectangle::getWidth() const
{
    return m_dWidth;
}

double cRectangle::getHeight() const
{
    return m_dHeight;
}

double cRectangle::getArea() const
{
    return m_dWidth * m_dHeight;
}

double cRectangle::getPerimeter() const
{
    return (m_dWidth + m_dHeight) * 2;
}

void cRectangle::input(std::istream &in)
{
    cout << "Enter the following information of the rectangle:" << endl;
    cout << "+ Width: ";
    in >> m_dWidth;
    cout << "+ Height: ";
    in >> m_dHeight;
}

void cRectangle::output(std::ostream &out) const
{
    out << "The following is the information of the rectangle:" << endl;
    out << "+ Width: " << m_dWidth << endl;
    out << "+ Height: " << m_dHeight << endl;
    out << "+ Area: " << getArea() << endl;
    out << "+ Perimeter: " << getPerimeter() << endl;
}

std::ostream &operator<<(std::ostream &out, const cRectangle &rectangle)
{
    rectangle.output(out);
    return out;
}

std::istream &operator>>(std::istream &in, cRectangle &rectangle)
{
    rectangle.input(in);
    return in;
}