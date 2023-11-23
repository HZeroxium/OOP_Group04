#pragma once

#include <iostream>
#include <string>
#include "cDate.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

class cSchoolStaff
{
private:
    string m_sFullName;
    cDate m_dateBirth;
    string m_sID;

protected:
    unsigned long m_ulSalary;
    void setSalary(unsigned long ulSalary);

public: // Constructors & Destructor
    cSchoolStaff(string = "", cDate = cDate(), string = "");

public: // Setters
    void setFullName(string sFullName);
    void setDateBirth(cDate dateBirth);
    void setID(string sID);

public: // Getters
    string getFullName() const;
    cDate getDateBirth() const;
    string getID() const;
    unsigned long getSalary() const;

public: // Methods
    virtual void calcSalary() = 0;

public: // Input & Output
    friend std::ostream &operator<<(std::ostream &out, const cSchoolStaff &schoolStaff);
    friend std::istream &operator>>(std::istream &in, cSchoolStaff &schoolStaff);
};