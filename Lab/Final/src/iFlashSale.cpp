#include "iFlashSale.h"
#include <iostream>

//=====================================================================================================================
//==================================== FLASH SALE =====================================================================
//=====================================================================================================================

//*********************************************************************************************************************
//************************************** OBSERVER METHODS *************************************************************
//*********************************************************************************************************************

void FlashSale::addObserver(Observer *observer)
{
    m_vObservers.push_back(observer);
}

void FlashSale::removeObserver(Observer *observer)
{
    m_vObservers.erase(std::remove(m_vObservers.begin(), m_vObservers.end(), observer), m_vObservers.end());
}

void FlashSale::notifyObservers()
{
    for (auto observer : m_vObservers)
    {
        observer->update(this->m_bIsOnFlashSale);
    }
}

//********************************************************************************************************************
//************************************** FLASH SALE METHODS **********************************************************
//********************************************************************************************************************

void FlashSale::setFlashSaleStatus(bool bIsOnFlashSale)
{
    this->m_bIsOnFlashSale = bIsOnFlashSale;
    notifyObservers();
}