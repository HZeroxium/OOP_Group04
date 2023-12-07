#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "cDate.h"
#include <memory>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::unique_ptr;
using std::vector;

// Prototype pattern of cSchoolStaff
class cSchoolStaff
{
private: // Prototype vector
    static vector<unique_ptr<cSchoolStaff>> m_vPrototypes;

private: // Attributes
    string m_sFullName;
    cDate m_dateBirth;
    string m_sID;

protected:
    string m_sType;

protected:
    unsigned long m_ulSalary;
    void setSalary(unsigned long ulSalary);

public: // Constructors & Destructor
    cSchoolStaff(const string & = "", const cDate & = cDate(), const string & = "", const string & = "none");
    cSchoolStaff(const cSchoolStaff &) = default;
    virtual ~cSchoolStaff() = default;

public: // Setters
    void setFullName(const string &sFullName);
    void setDateBirth(const cDate &dateBirth);
    void setID(const string &sID);

public: // Getters
    string getFullName() const;
    cDate getDateBirth() const;
    string getID() const;
    unsigned long getSalary() const;
    string getType() const;

public: // Pure virtual methods
    virtual void calcSalary() = 0;
    virtual cSchoolStaff *clone() const = 0;

protected: // Input & Output helper methods
    virtual void input(std::istream &in);
    virtual void output(std::ostream &out) const;

public: // Input & Output
    friend std::ostream &operator<<(std::ostream &out, const cSchoolStaff &schoolStaff);
    friend std::istream &operator>>(std::istream &in, cSchoolStaff &schoolStaff);

public: // Static methods
    static void addPrototype(unique_ptr<cSchoolStaff> &&prototype);
    static cSchoolStaff *createStaff(const string &sType);
    static void removePrototype(const string &sType);
    static void removeAllPrototypes();
};

/**
cSchoolStaff
- m_sFullName: string
- m_dateBirth: cDate
- m_sID: string
# m_sType: string
# m_ulSalary: unsigned long
+ cSchoolStaff(sFullName: string = "", dateBirth: cDate = cDate(), sID: string = "", sType: string = "none")
+ ~cSchoolStaff()
+ setFullName(sFullName: string): void
+ setDateBirth(dateBirth: cDate): void
+ setID(sID: string): void
# setSalary(ulSalary: unsigned long): void
+ getFullName(): string
+ getDateBirth(): cDate
+ getID(): string
+ getSalary(): unsigned long
+ getType(): string
+ virtual calcSalary() = 0: void
+ friend operator<<(out: std::ostream&, schoolStaff: cSchoolStaff&): std::ostream&
+ friend operator>>(in: std::istream&, schoolStaff: cSchoolStaff&): std::istream&
# virtual input(in: std::istream&): void
# virtual output(out: std::ostream&) const: void
 */