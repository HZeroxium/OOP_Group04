#pragma once

#include "cProduct.h"
#include "cDate.h"
#include <vector>

using std::vector;

class Store
{
private:
    string m_sName;                ///< Name of the store
    Date m_joinDate;               ///< Join date of the store
    vector<Product *> m_vProducts; ///< List of products in the store

public: // Constructors & Destructor
    Store();
    Store(const string &sName, const Date &joinDate);
    Store(const Store &other);
    ~Store();

public: // Getters
    string getName() const;
    Date getJoinDate() const;
    vector<Product *> getProducts() const;

public: // Setters
    void setName(const string &sName);
    void setJoinDate(const Date &joinDate);

public: // Display
    void display() const;

public: // Add & Remove
    bool addProduct(Product *pProduct);
    bool removeProduct(Product *pProduct);
};