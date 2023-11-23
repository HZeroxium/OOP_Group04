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