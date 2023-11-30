#pragma once

#include "cLabStaff.h"

class cSpecialist final : public cLabStaff
{
public:
    cSpecialist(const string &sFullName = "", const cDate &dateBirth = cDate(), const string &sID = "", unsigned int usResearchingTime = 0, const vector<string> &vResearchingFields = vector<string>());
    ~cSpecialist() override = default;
    void calcSalary() override;
};

/**
cSpecialist
+ cSpecialist(sFullName: string = "", dateBirth: cDate = cDate(), sID: string = "")
+ ~cSpecialist()
+ calcSalary(): void
 */