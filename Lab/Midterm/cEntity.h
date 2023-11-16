#pragma once

#include "Common.h"

class cEntity
{
private: 
    unsigned int m_uPosX;
    unsigned int m_uPosY;

public: // Constructors & Destructor
    cEntity(unsigned int = 0, unsigned int = 0);
    cEntity(const cEntity &);
    ~cEntity();

public: // Getters
    unsigned int getPosX() const;
    unsigned int getPosY() const;

public: // Setters
    void setPosX(unsigned int);
    void setPosY(unsigned int);
};