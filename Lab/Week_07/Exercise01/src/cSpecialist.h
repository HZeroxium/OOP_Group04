#pragma once

#include "cLabStaff.h"

class cSpecialist final : public cLabStaff
{
public:
    cSpecialist(string sFullName = "", cDate dateBirth = cDate(), string sID = "");
    ~cSpecialist() override = default;
    void calcSalary() override;
};

/**
cSpecialist
+ cSpecialist(sFullName: string = "", dateBirth: cDate = cDate(), sID: string = "")
+ ~cSpecialist()
+ calcSalary(): void
 */