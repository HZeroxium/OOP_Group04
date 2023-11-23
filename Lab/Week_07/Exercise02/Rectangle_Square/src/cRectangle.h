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

/**
- m_dWidth: double
- m_dHeight: double
+ cRectangle(dWidth: double = 0, dHeight: double = 0)
+ setWidth(dWidth: double): void
+ setHeight(dHeight: double): void
+ setDimensions(dWidth: double, dHeight: double): void
+ getWidth(): double
+ getHeight(): double
+ getArea(): double
+ getPerimeter(): double
+ input(in: istream): virtual void
+ output(out: ostream) const: virtual void
+ operator<<(out: ostream, rectangle: cRectangle): ostream
+ operator>>(in: istream, rectangle: cRectangle): istream
 */