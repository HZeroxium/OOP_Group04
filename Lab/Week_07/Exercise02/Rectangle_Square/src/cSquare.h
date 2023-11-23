#pragma once

#include "cRectangle.h"

class cSquare final : public cRectangle
{
public:
    cSquare(double dSide = 0);
    ~cSquare() override = default;

    void setSide(double dSide);

    double getSide() const;

    void input(std::istream &in) override;
    void output(std::ostream &out) const override;

    friend std::ostream &operator<<(std::ostream &out, const cSquare &square);
    friend std::istream &operator>>(std::istream &in, cSquare &square);
};

/**
+ cSquare(dSide: double = 0)
+ setSide(dSide: double): void
+ getSide(): double
+ input(in: istream): virtual void
+ output(out: ostream) const: virtual void
+ operator<<(out: ostream, square: cSquare): ostream
+ operator>>(in: istream, square: cSquare): istream
 */