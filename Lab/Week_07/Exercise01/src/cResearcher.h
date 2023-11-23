#pragma once

#include "cLabStaff.h"

class cResearcher final : public cLabStaff
{
public:
    cResearcher(string sFullName = "", cDate dateBirth = cDate(), string sID = "", unsigned int usResearchingTime = 0, vector<string> vResearchingFields = vector<string>());
    ~cResearcher() override = default;
    void calcSalary() override;
};

/**
cResearcher
+ cResearcher(sFullName: string = "", dateBirth: cDate = cDate(), sID: string = "", usResearchingTime: unsigned int = 0, vResearchingFields: vector<string> = vector<string>())
+ ~cResearcher()
+ calcSalary(): void
 */