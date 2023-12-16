#include "cProduct.h"

//******************************************************************************************************
//************************************ CONSTRUCTORS & DESTRUCTOR ****************************************
//******************************************************************************************************

Product::Product()
{
    m_sName = "";
    m_sCategory = "";
    m_dPrice = 0;
    m_uiQuantity = 0;
}

Product::Product(const string &sName, const string &sCategory, double dPrice, unsigned int uiQuantity)
{
    m_sName = sName;
    m_sCategory = sCategory;
    m_dPrice = dPrice;
    m_uiQuantity = uiQuantity;
}

Product::Product(const Product &other)
{
    m_sName = other.m_sName;
    m_sCategory = other.m_sCategory;
    m_dPrice = other.m_dPrice;
    m_uiQuantity = other.m_uiQuantity;
}

Product::~Product()
{
}

//******************************************************************************************************
//********************************************** GETTERS ***********************************************
//******************************************************************************************************

string Product::getName() const
{
    return m_sName;
}

string Product::getCategory() const
{
    return m_sCategory;
}

double Product::getPrice() const
{
    return m_dPrice;
}

unsigned int Product::getQuantity() const
{
    return m_uiQuantity;
}

//******************************************************************************************************
//********************************************** SETTERS ***********************************************
//******************************************************************************************************

void Product::setName(const string &sName)
{
    m_sName = sName;
}

void Product::setCategory(const string &sCategory)
{
    m_sCategory = sCategory;
}

void Product::setPrice(double dPrice)
{
    m_dPrice = dPrice;
}

void Product::setQuantity(unsigned int uiQuantity)
{
    m_uiQuantity = uiQuantity;
}

//******************************************************************************************************
//********************************************** DISPLAY ***********************************************
//******************************************************************************************************

void Product::display() const
{
    // Implement here
}