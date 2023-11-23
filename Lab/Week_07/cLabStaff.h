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
    cLabStaff(string sFullName = "", cDate dateBirth = cDate(), string sID = "", unsigned int usResearchingTime = 0, vector<string> vResearchingFields = vector<string>());

public: // Setters
    void setResearchingTime(unsigned int usResearchingTime);
    void setResearchingFields(const vector<string> &vResearchingFields);

public: // Getters
    unsigned int getResearchingTime() const;
    vector<string> getResearchingFields() const;

public: // Methods
    void addResearchingField(string sResearchingField);
    virtual void calcSalary() = 0;

public: // Input & Output
    friend std::ostream &operator<<(std::ostream &out, const cLabStaff &labStaff);
    friend std::istream &operator>>(std::istream &in, cLabStaff &labStaff);
};
