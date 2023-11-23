#pragma once

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

class cRectangle
{
private:
    double m_dWidth;
    double m_dHeight;

public:
    cRectangle(double dWidth = 0, double dHeight = 0);
    virtual ~cRectangle() = default;

    void setWidth(double dWidth);
    void setHeight(double dHeight);
    void setDimensions(double dWidth, double dHeight);

    double getWidth() const;
    double getHeight() const;
    double getArea() const;
    double getPerimeter() const;

    virtual void input(std::istream &in);
    virtual void output(std::ostream &out) const;

    friend std::ostream &operator<<(std::ostream &out, const cRectangle &rectangle);
    friend std::istream &operator>>(std::istream &in, cRectangle &rectangle);
};