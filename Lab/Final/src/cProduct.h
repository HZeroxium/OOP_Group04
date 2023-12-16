#pragma once

#include <string>

using std::string;

/// @brief Product class represents a product in the store inventory system
class Product
{
private:
    string m_sName;            ///< Name of the product
    string m_sCategory;        ///< Category of the product
    double m_dPrice;           ///< Price of the product (in VND)
    unsigned int m_uiQuantity; ///< Quantity of the product in stock

public: // Constructors & Destructor
    Product();
    Product(const string &sName, const string &sCategory, double dPrice, unsigned int uiQuantity);
    Product(const Product &other);
    ~Product();

public: // Getters
    string getName() const;
    string getCategory() const;
    double getPrice() const;
    unsigned int getQuantity() const;

public: // Setters
    void setName(const string &sName);
    void setCategory(const string &sCategory);
    void setPrice(double dPrice);
    void setQuantity(unsigned int uiQuantity);

public: // Display
    void display() const;
};