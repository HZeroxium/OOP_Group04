#include "cOrder.h"
#include <iostream>
//======================================================================================================
//============================================= ORDER ==================================================
//======================================================================================================

//******************************************************************************************************
//*********************************** CONSTRUCTORS & DESTRUCTOR ****************************************
//******************************************************************************************************

Order::Order()
{
    m_sOrderCode = "";
    m_orderDate = Date();
    m_pCurrentOrderState = nullptr;
    m_uiQuantity = 0;
    m_dTotalPrice = 0;
    m_dFinalPrice = 0;
}

Order::Order(const string &sOrderCode, const Date &orderDate, OrderState *pCurrentOrderState, unsigned int uiQuantity, double dTotalPrice, double dFinalPrice)
{
    m_sOrderCode = sOrderCode;
    m_orderDate = orderDate;
    m_pCurrentOrderState = pCurrentOrderState;
    m_uiQuantity = uiQuantity;
    m_dTotalPrice = dTotalPrice;
    m_dFinalPrice = dFinalPrice;
}

Order::Order(const Order &other)
{
    m_sOrderCode = other.m_sOrderCode;
    m_orderDate = other.m_orderDate;
    m_pCurrentOrderState = other.m_pCurrentOrderState;
    m_uiQuantity = other.m_uiQuantity;
    m_dTotalPrice = other.m_dTotalPrice;
    m_dFinalPrice = other.m_dFinalPrice;
}

Order::~Order()
{
    delete m_pCurrentOrderState;
    m_pCurrentOrderState = nullptr;
}

//******************************************************************************************************
//********************************************* GETTERS ************************************************
//******************************************************************************************************

string Order::getOrderCode() const
{
    return m_sOrderCode;
}

Date Order::getOrderDate() const
{
    return m_orderDate;
}

OrderState *Order::getCurrentOrderState() const
{
    return m_pCurrentOrderState;
}

unsigned int Order::getQuantity() const
{
    return m_uiQuantity;
}

double Order::getTotalPrice() const
{
    return m_dTotalPrice;
}

double Order::getFinalPrice() const
{
    return m_dFinalPrice;
}

//******************************************************************************************************
//********************************************* SETTERS ************************************************
//******************************************************************************************************

void Order::setOrderCode(const string &sOrderCode)
{
    m_sOrderCode = sOrderCode;
}

void Order::setOrderDate(const Date &orderDate)
{
    m_orderDate = orderDate;
}

void Order::setCurrentOrderState(OrderState *pCurrentOrderState)
{
    delete m_pCurrentOrderState;               // Delete the old state
    m_pCurrentOrderState = pCurrentOrderState; // Set the new state
}

void Order::setQuantity(unsigned int uiQuantity)
{
    m_uiQuantity = uiQuantity;
}

void Order::setTotalPrice(double dTotalPrice)
{
    m_dTotalPrice = dTotalPrice;
}

void Order::setFinalPrice(double dFinalPrice)
{
    m_dFinalPrice = dFinalPrice;
}

//******************************************************************************************************
//********************************************* ACTIONS ************************************************
//******************************************************************************************************

void Order::process()
{
    m_pCurrentOrderState->processOrder(*this);
}

void Order::ship()
{
    m_pCurrentOrderState->shipOrder(*this);
}

void Order::deliver()
{
    m_pCurrentOrderState->deliverOrder(*this);
}

void Order::cancel()
{
    m_pCurrentOrderState->cancelOrder(*this);
}

void Order::display() const
{
    // Implement here
}

//======================================================================================================
//========================================== PROCESSING STATE ==========================================
//======================================================================================================

void ProcessingState::processOrder(Order &order)
{
    std::cout << "Order " << order.getOrderCode() << " is being processed." << std::endl;
    order.setCurrentOrderState(new ShippingState());
}

void ProcessingState::shipOrder(Order &order)
{
    std::cout << "Order " << order.getOrderCode() << " cannot be shipped because it is still being processed." << std::endl;
}

void ProcessingState::deliverOrder(Order &order)
{
    std::cout << "Order " << order.getOrderCode() << " cannot be delivered because it is still being processed." << std::endl;
}

void ProcessingState::cancelOrder(Order &order)
{
    std::cout << "Order " << order.getOrderCode() << " is being canceled." << std::endl;
    order.setCurrentOrderState(new CancelledState());
}

//======================================================================================================
//============================================ SHIPPING STATE ==========================================
//======================================================================================================

void ShippingState::processOrder(Order &order)
{
    std::cout << "Order " << order.getOrderCode() << " cannot be processed because it is already being shipped." << std::endl;
}

void ShippingState::shipOrder(Order &order)
{
    std::cout << "Order " << order.getOrderCode() << " is being shipped." << std::endl;
    order.setCurrentOrderState(new DeliveredState());
}

void ShippingState::deliverOrder(Order &order)
{
    std::cout << "Order " << order.getOrderCode() << " cannot be delivered because it is already being shipped." << std::endl;
}

void ShippingState::cancelOrder(Order &order)
{
    std::cout << "Order " << order.getOrderCode() << " cannot be canceled because it is already being shipped." << std::endl;
}

//======================================================================================================
//=========================================== DELIVERED STATE ==========================================
//======================================================================================================

void DeliveredState::processOrder(Order &order)
{
    std::cout << "Order " << order.getOrderCode() << " cannot be processed because it is already being delivered." << std::endl;
}

void DeliveredState::shipOrder(Order &order)
{
    std::cout << "Order " << order.getOrderCode() << " cannot be shipped because it is already being delivered." << std::endl;
}

void DeliveredState::deliverOrder(Order &order)
{
    std::cout << "Order " << order.getOrderCode() << " is being delivered." << std::endl;
    order.setCurrentOrderState(new DeliveredState());
}

void DeliveredState::cancelOrder(Order &order)
{
    std::cout << "Order " << order.getOrderCode() << " cannot be canceled because it is already being delivered." << std::endl;
}

//======================================================================================================
//=========================================== CANCELLED STATE ==========================================
//======================================================================================================

void CancelledState::processOrder(Order &order)
{
    std::cout << "Order " << order.getOrderCode() << " cannot be processed because it is already being canceled." << std::endl;
}

void CancelledState::shipOrder(Order &order)
{
    std::cout << "Order " << order.getOrderCode() << " cannot be shipped because it is already being canceled." << std::endl;
}

void CancelledState::deliverOrder(Order &order)
{
    std::cout << "Order " << order.getOrderCode() << " cannot be delivered because it is already being canceled." << std::endl;
}

void CancelledState::cancelOrder(Order &order)
{
    std::cout << "Order " << order.getOrderCode() << " is being canceled." << std::endl;
    order.setCurrentOrderState(new CancelledState());
}

//======================================================================================================
//============================================= END ====================================================
//======================================================================================================
