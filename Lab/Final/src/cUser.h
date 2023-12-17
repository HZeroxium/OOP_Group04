#pragma once

#include "cDate.h"
#include "cShoppingCart.h"
#include "cOrder.h"
#include "iCustomerRank.h"

class User
{
private:
    string m_sUsername;    ///< Username of the user
    string m_sPassword;    ///< Password of the user
    Date m_joinDate;       ///< Join date of the user
    string m_sFullName;    ///< Full name of the user
    string m_sEmail;       ///< Email of the user
    string m_sPhoneNumber; ///< Phone number of the user
    Date m_birthDate;      ///< Birth date of the user
    string m_sGender;      ///< Gender of user

public: // Constructors & Destructor
    User();
    User(const string &sUsername, const string &sPassword);
    User(const string &sUsername, const string &sPassword, const Date &joinDate, const string &sFullName, const string &sEmail, const string &sPhoneNumber, const Date &birthDate, const string &sGender);
    User(const User &);
    ~User() = default;

public: // Getters
    string getUsername() const;
    string getPassword() const;
    Date getJoinDate() const;
    string getFullName() const;
    string getEmail() const;
    string getPhoneNumber() const;
    Date getBirthDate() const;
    string getGender() const;

public: // Setters
    void setUsername(const string &sUsername);
    void setPassword(const string &sPassword);
    void setJoinDate(const Date &joinDate);
    void setFullName(const string &sFullName);
    void setEmail(const string &sEmail);
    void setPhoneNumber(const string &sPhoneNumber);
    void setBirthDate(const Date &birthDate);
    void setGender(const string &sGender);

public: // Methods
    virtual void display() const;
    virtual void loadAdditionalData();
};

class Customer : public User
{
private:
    string m_sAddress;       ///< Address of the customer
    vector<Order> m_vOrders; ///< List of orders of the customer
    CustomerRank *m_pRank;   ///< Rank of the customer
    string m_sRankName;      ///< Name of the rank of the customer

public: // Constructors & Destructor
    Customer();
    Customer(const string &sUsername, const string &sPassword, const Date &joinDate, const string &sFullName, const string &sEmail, const string &sPhoneNumber, const Date &birthDate, const string &sGender, const string &sAddress, const vector<Order> &vOrders, CustomerRank *pRank);
    Customer(const Customer &);
    ~Customer() = default;

public: // Getters
    string getAddress() const;
    vector<Order> getOrders() const;
    CustomerRank *getRank() const;
    string getRankName() const;

public: // Setters
    void setAddress(const string &sAddress);
    void setOrders(const vector<Order> &vOrders);
    void setRank(CustomerRank *pRank);
    void setRankName(const string &sRankName);

public: // Methods
    void display() const override;
    void loadAdditionalData() override;
};
