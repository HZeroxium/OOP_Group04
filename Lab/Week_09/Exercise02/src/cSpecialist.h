#pragma once

#include "cLabStaff.h"

class cSpecialist final : public cLabStaff
{
public: // Constructors & Destructor
    cSpecialist(const string &sFullName = "", const cDate &dateBirth = cDate(), const string &sID = "", unsigned int usResearchingTime = 0, const vector<string> &vResearchingFields = vector<string>());
    ~cSpecialist() override = default;

public: // Override Methods
    void calcSalary() override;
    cSchoolStaff *clone() const override;
};

/**
cSpecialist
+ cSpecialist(sFullName: string = "", dateBirth: cDate = cDate(), sID: string = "")
+ ~cSpecialist()
+ calcSalary(): void
 */