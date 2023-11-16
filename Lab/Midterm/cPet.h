#pragma once

#include "Common.h"
#include "cEntity.h"

class cPet : public cEntity
{
private:
    string m_sName;
    unsigned int m_uType;
    unsigned int m_uPrice;
    unsigned int m_uProductPrice;
    unsigned int m_uMaturationTime;

public: // Constructors & Destructor
    cPet(string = "", unsigned int = 1, unsigned int = 1, unsigned int = 1, unsigned int = 60);
    cPet(const cPet &);
    ~cPet();

public: // Getters
    string getName() const;
    unsigned int getType() const;
    unsigned int getPrice() const;
    unsigned int getProductPrice() const;
    unsigned int getMaturationTime() const;

public: // Setters
    void setName(string);
    void setType(unsigned int);
    void setPrice(unsigned int);
    void setProductPrice(unsigned int);
    void setMaturationTime(unsigned int);

public: // Operators
    cPet &operator=(const cPet &);
    bool operator>(const cPet &) const;
    friend ostream &operator<<(ostream &, const cPet &);
    friend istream &operator>>(istream &, cPet &);
};