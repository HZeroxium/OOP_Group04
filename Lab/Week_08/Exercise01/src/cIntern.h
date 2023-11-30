#pragma once

#include "cLabStaff.h"

class cIntern final : public cLabStaff
{
public: // Constructors & Destructor
    cIntern(const string &sFullName = "", const cDate &dateBirth = cDate(), const string &sID = "", unsigned int usResearchingTime = 0, const vector<string> &vResearchingFields = vector<string>());
    ~cIntern() override = default;

public: // Methods
    void calcSalary() override;
    void addResearchingField(const string &sResearchingField) override;
};

/*
cIntern
+ cIntern(const string& sFullName = "", const cDate& dateBirth = cDate(), const string& sID = "", unsigned int usResearchingTime = 0, const vector<string>& vResearchingFields = vector<string>())
+ ~cIntern() override = default
+ void calcSalary()
+ void addResearchingField(const string& sResearchingField)
*/
