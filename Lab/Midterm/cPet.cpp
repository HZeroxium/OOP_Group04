#include "cPet.h"

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////// CONSTRUCTORS - DESTRUCTORS /////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

cPet::cPet(string sName, unsigned int uType, unsigned int uPrice, unsigned int uProductPrice, unsigned int uMaturationTime)
{
    m_sName = sName;
    m_uType = uType;
    m_uPrice = uPrice;
    m_uProductPrice = uProductPrice;
    m_uMaturationTime = uMaturationTime;
}

cPet::cPet(const cPet &pet)
{
    m_sName = pet.m_sName;
    m_uType = pet.m_uType;
    m_uPrice = pet.m_uPrice;
    m_uProductPrice = pet.m_uProductPrice;
    m_uMaturationTime = pet.m_uMaturationTime;
}

cPet::~cPet() = default;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////// GETTERS ////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

string cPet::getName() const
{
    return m_sName;
}

unsigned int cPet::getType() const
{
    return m_uType;
}

unsigned int cPet::getPrice() const
{
    return m_uPrice;
}

unsigned int cPet::getProductPrice() const
{
    return m_uProductPrice;
}

unsigned int cPet::getMaturationTime() const
{
    return m_uMaturationTime;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////// SETTERS ////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void cPet::setName(string sName)
{
    m_sName = sName;
}

void cPet::setType(unsigned int uType)
{
    m_uType = uType;
}

void cPet::setPrice(unsigned int uPrice)
{
    m_uPrice = uPrice;
}

void cPet::setProductPrice(unsigned int uProductPrice)
{
    m_uProductPrice = uProductPrice;
}

void cPet::setMaturationTime(unsigned int uMaturationTime)
{
    m_uMaturationTime = uMaturationTime;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////// OPERATORS //////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

cPet &cPet::operator=(const cPet &pet)
{
    if (this == &pet)
    {
        return *this;
    }
    m_sName = pet.m_sName;
    m_uType = pet.m_uType;
    m_uPrice = pet.m_uPrice;
    m_uProductPrice = pet.m_uProductPrice;
    m_uMaturationTime = pet.m_uMaturationTime;
    return *this;
}

bool cPet::operator>(const cPet &pet) const
{
    return m_uProductPrice > pet.m_uProductPrice;
}

ostream &operator<<(ostream &os, const cPet &pet)
{
    os << "Pet information: " << endl;
    os << "Name: " << pet.m_sName << endl;
    os << "Type: " << pet.m_uType << endl;
    os << "Price: " << pet.m_uPrice << endl;
    os << "Product price: " << pet.m_uProductPrice << endl;
    os << "Maturation time: " << pet.m_uMaturationTime << endl;
    return os;
}

istream &operator>>(istream &is, cPet &pet)
{
    cout << "Enter pet information:\n";
    cout << "Name: ";
    getline(is, pet.m_sName);
    cout << "Type: ";
    is >> pet.m_uType;
    cout << "Price: ";
    is >> pet.m_uPrice;
    cout << "Product price: ";
    is >> pet.m_uProductPrice;
    cout << "Maturation time: ";
    is >> pet.m_uMaturationTime;
    return is;
}
