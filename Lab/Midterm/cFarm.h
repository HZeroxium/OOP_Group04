#pragma once

#include "Common.h"

class cFarm
{
private:
    int **m_pFarm;
    unsigned int m_uLength;
    unsigned int m_uWidth;

public: // Constructors & Destructor
    cFarm(unsigned int = 10, unsigned int = 10);
    cFarm(const cFarm &);
    ~cFarm();

public: // Getters
    int **getFarm() const;
    unsigned int getLength() const;
    unsigned int getWidth() const;

public: // Setters
    void setFarm(int **);
    void setLength(unsigned int);
    void setWidth(unsigned int);

public: // Methods
    bool isAvailable(unsigned int, unsigned int) const;
    unsigned int getCropType(unsigned int, unsigned int) const;

public: // Operators
    cFarm &operator=(const cFarm &);
    friend ostream &operator<<(ostream &, const cFarm &);
    friend istream &operator>>(istream &, cFarm &);
};