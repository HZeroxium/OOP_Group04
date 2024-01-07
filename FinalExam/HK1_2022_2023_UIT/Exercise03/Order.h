#pragma once

#include <string>
#include <vector>
#include <iostream>

using std::istream;
using std::ostream;
using std::string;
using std::vector;

class Customer
{
private:
    string id;
    string name;
    string phoneNumer;
};

struct Date
{
    unsigned int day, month, year;
};

class Product
{
protected:
    string id;
    string name;
    double price;
};

class Picture : public Product
{
private:
    double width, height;
    string artistName;
};

class CDMusic : public Product
{
private:
    string singer;
    string producer;
};

class Order
{
private:
    string id;
    Customer *customer;
    Date orderDate;
    vector<Product *> products;
    double totalCost;

public:
    friend ostream &operator<<(ostream &out, const Order &order)
    {
    }
};