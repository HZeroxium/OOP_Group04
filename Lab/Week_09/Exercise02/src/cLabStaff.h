#pragma once

#include "cSchoolStaff.h"
#include <vector>

using std::vector;

class cLabStaff : public cSchoolStaff
{
protected:
    unsigned int m_usResearchingTime;
    vector<string> m_vResearchingFields;

public: // Constructors & Destructor
    cLabStaff(const string &sFullName = "", const cDate &dateBirth = cDate(), const string &sID = "", unsigned int usResearchingTime = 0, const vector<string> &vResearchingFields = vector<string>());
    cLabStaff(const cLabStaff &) = default;
    virtual ~cLabStaff() = default;

public: // Setters
    void setResearchingTime(unsigned int usResearchingTime);
    void setResearchingFields(const vector<string> &vResearchingFields);

public: // Getters
    unsigned int getResearchingTime() const;
    vector<string> getResearchingFields() const;

public: // Methods
    virtual void addResearchingField(const string &sResearchingField);
    virtual void calcSalary() = 0;
    virtual cSchoolStaff *clone() const = 0;

private: // Input & Output helper methods
    virtual void input(std::istream &in);
    virtual void output(std::ostream &out) const;

public: // Input & Output
    friend std::ostream &operator<<(std::ostream &out, const cLabStaff &labStaff);
    friend std::istream &operator>>(std::istream &in, cLabStaff &labStaff);
};

/**
cLabStaff
- m_usResearchingTime: unsigned int
- m_vResearchingFields: vector<string>
+ cLabStaff(sFullName: string = "", dateBirth: cDate = cDate(), sID: string = "", usResearchingTime: unsigned int = 0, vResearchingFields: vector<string> = vector<string>())
+ ~cLabStaff()
+ setResearchingTime(usResearchingTime: unsigned int): void
+ setResearchingFields(vResearchingFields: vector<string>): void
+ getResearchingTime(): unsigned int
+ getResearchingFields(): vector<string>
+ addResearchingField(sResearchingField: string): void
+ virtual calcSalary() = 0: void
+ friend operator<<(out: std::ostream&, labStaff: cLabStaff&): std::ostream&
+ friend operator>>(in: std::istream&, labStaff: cLabStaff&): std::istream&
- virtual input(in: std::istream&): void
- virtual output(out: std::ostream&) const: void
 */
