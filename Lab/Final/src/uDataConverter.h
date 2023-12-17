#pragma once

#include "cProduct.h"
#include "cUser.h"
#include "cOrder.h"
#include "cDate.h"
#include "cShoppingCart.h"
#include "cStore.h"
#include "iProductCategory.h"

/// @brief Singleton class for converting data between different types to string and vice versa.
class DataConverter
{
private:
    DataConverter() = default;         ///< Private constructor of the Singleton Pattern

public: // Singleton Methods
    static DataConverter &getInstance();
    DataConverter(const DataConverter &) = delete;
    void operator=(const DataConverter &) = delete;
    ~DataConverter() = default;

public: // Data conversion methods
    string convertProductToString(const Product &product);
    string convertCustomerToString(const Customer &customer);
    string convertOrderToString(const Order &order);
    string convertDateToString(const Date &date);
    string convertShoppingCartToString(const ShoppingCart &shoppingCart);
    string convertStoreToString(const Store &store);
    string convertProductCategoryToString(const ProductCategory &productCategory);

    Product convertStringToProduct(const string &sProduct);
    User convertStringToUser(const string &sUser);
    Order convertStringToOrder(const string &sOrder);
    Date convertStringToDate(const string &sDate);
    ShoppingCart convertStringToShoppingCart(const string &sShoppingCart);
    Store convertStringToStore(const string &sStore);
    ProductCategory convertStringToProductCategory(const string &sProductCategory);
};