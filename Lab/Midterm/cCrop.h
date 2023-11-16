#pragma once

#include "Common.h"
#include "cEntity.h"

class cCrop : public cEntity
{
private:
    string m_sName;
    unsigned int m_uType;
    unsigned int m_uPrice;
    unsigned int m_uProductPrice;
    unsigned int m_uQuantity;
    unsigned int m_uHarvestTime;

public: // Constructors & Destructor
    cCrop(string = "", unsigned int = 1, unsigned int = 1, unsigned int = 1, unsigned int = 1, unsigned int = 60);
    cCrop(const cCrop &);
    ~cCrop();

public: // Getters
    string getName() const;
    unsigned int getType() const;
    unsigned int getPrice() const;
    unsigned int getProductPrice() const;
    unsigned int getQuantity() const;
    unsigned int getHarvestTime() const;

public: // Setters
    void setName(string);
    void setType(unsigned int);
    void setPrice(unsigned int);
    void setProductPrice(unsigned int);
    void setQuantity(unsigned int);
    void setHarvestTime(unsigned int);

public: // Operators
    cCrop &operator=(const cCrop &);
    bool operator>(const cCrop &) const;
    friend ostream &operator<<(ostream &, const cCrop &);
    friend istream &operator>>(istream &, cCrop &);
};
