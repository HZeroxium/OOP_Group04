#pragma once

#include "cDate.h"
#include "cShoppingCart.h"
#include "cOrder.h"

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
};

class Customer : public User
{
private:
    string m_sAddress;       ///< Address of the customer
    vector<Order> m_vOrders; ///< List of orders of the customer

public: // Constructors & Destructor
    Customer();
    Customer(const string &sUsername, const string &sPassword, const Date &joinDate, const string &sFullName, const string &sEmail, const string &sPhoneNumber, const Date &birthDate, const string &sGender, const string &sAddress);
    Customer(const Customer &);
    ~Customer() = default;

public: // Getters
    string getAddress() const;
    vector<Order> getOrders() const;

public: // Setters
    void setAddress(const string &sAddress);

public: // Methods
    void display() const override;
};
