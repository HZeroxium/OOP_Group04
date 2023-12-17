#include "uDataConverter.h"

//******************************************************************************************************
//************************************ SINGLETON METHODS ***********************************************
//******************************************************************************************************

DataConverter &DataConverter::getInstance()
{
    static DataConverter instance;
    return instance;
}

//******************************************************************************************************
//************************************ DATA CONVERSION METHODS *****************************************
//******************************************************************************************************

string DataConverter::convertProductToString(const Product &product)
{
    string sProduct = "";
    sProduct += product.getID() + ",";
    sProduct += product.getName() + ",";
    sProduct += product.getCategory() + ",";
    sProduct += std::to_string(product.getPrice()) + ",";
    sProduct += std::to_string(product.getQuantity()) + ",";
    sProduct += std::to_string(product.getFlashSaleStatus());
    return sProduct;
}

string convertCustomerToString(const Customer &customer)
{
    string sCustomer = "";
    sCustomer += customer.getUsername() + ",";
    sCustomer += customer.getPassword() + ",";
    sCustomer += customer.getJoinDate().toString() + ",";
    sCustomer += customer.getFullName() + ",";
    sCustomer += customer.getEmail() + ",";
    sCustomer += customer.getPhoneNumber() + ",";
    sCustomer += customer.getBirthDate().toString() + ",";
    sCustomer += customer.getGender() + ",";
    sCustomer += customer.getAddress() + ",";
    
}