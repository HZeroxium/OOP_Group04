#pragma once

#include "cLabStaff.h"

class cResearcher final : public cLabStaff
{
public:
    cResearcher(string sFullName = "", cDate dateBirth = cDate(), string sID = "", unsigned int usResearchingTime = 0, vector<string> vResearchingFields = vector<string>());
    ~cResearcher() override = default;
    void calcSalary() override;
};