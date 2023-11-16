#include "cCrop.h"

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////// CONSTRUCTORS - DESTRUCTORS //////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

cCrop::cCrop(string sName, unsigned int uType, unsigned int uPrice, unsigned int uProductPrice, unsigned int uQuantity, unsigned int uHarvestTime)
{
    m_sName = sName;
    m_uType = uType;
    m_uPrice = uPrice;
    m_uProductPrice = uProductPrice;
    m_uQuantity = uQuantity;
    m_uHarvestTime = uHarvestTime;
}

cCrop::cCrop(const cCrop &crop)
{
    m_sName = crop.m_sName;
    m_uType = crop.m_uType;
    m_uPrice = crop.m_uPrice;
    m_uProductPrice = crop.m_uProductPrice;
    m_uQuantity = crop.m_uQuantity;
    m_uHarvestTime = crop.m_uHarvestTime;
}

cCrop::~cCrop() = default;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////// GETTERS /////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

string cCrop::getName() const
{
    return m_sName;
}

unsigned int cCrop::getType() const
{
    return m_uType;
}

unsigned int cCrop::getPrice() const
{
    return m_uPrice;
}

unsigned int cCrop::getProductPrice() const
{
    return m_uProductPrice;
}

unsigned int cCrop::getQuantity() const
{
    return m_uQuantity;
}

unsigned int cCrop::getHarvestTime() const
{
    return m_uHarvestTime;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////// SETTERS /////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void cCrop::setName(string sName)
{
    m_sName = sName;
}

void cCrop::setType(unsigned int uType)
{
    m_uType = uType;
}

void cCrop::setPrice(unsigned int uPrice)
{
    m_uPrice = uPrice;
}

void cCrop::setProductPrice(unsigned int uProductPrice)
{
    m_uProductPrice = uProductPrice;
}

void cCrop::setQuantity(unsigned int uQuantity)
{
    m_uQuantity = uQuantity;
}

void cCrop::setHarvestTime(unsigned int uHarvestTime)
{
    m_uHarvestTime = uHarvestTime;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////// OPERATORS ///////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

cCrop &cCrop::operator=(const cCrop &crop)
{
    if (this == &crop)
        return *this;
    m_sName = crop.m_sName;
    m_uType = crop.m_uType;
    m_uPrice = crop.m_uPrice;
    m_uProductPrice = crop.m_uProductPrice;
    m_uQuantity = crop.m_uQuantity;
    m_uHarvestTime = crop.m_uHarvestTime;
    return *this;
}

bool cCrop::operator>(const cCrop &crop) const
{
    return m_uProductPrice > crop.m_uProductPrice;
}

istream &operator>>(istream &is, cCrop &crop)
{
    cout << "Enter crop information:\n";
    cout << "Name: ";
    getline(is, crop.m_sName);
    cout << "Type: ";
    is >> crop.m_uType;
    cout << "Price: ";
    is >> crop.m_uPrice;
    cout << "Product Price: ";
    is >> crop.m_uProductPrice;
    cout << "Quantity: ";
    is >> crop.m_uQuantity;
    cout << "Harvest Time: ";
    is >> crop.m_uHarvestTime;
    return is;
}

ostream &operator<<(ostream &os, const cCrop &crop)
{
    os << "Crop Information:\n";
    os << "Name: " << crop.m_sName << endl;
    os << "Type: " << crop.m_uType << endl;
    os << "Price: " << crop.m_uPrice << endl;
    os << "Product Price: " << crop.m_uProductPrice << endl;
    os << "Quantity: " << crop.m_uQuantity << endl;
    os << "Harvest Time: " << crop.m_uHarvestTime << endl;
    return os;
}
