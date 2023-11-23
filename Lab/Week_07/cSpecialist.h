#pragma once

#include "cLabStaff.h"

class cSpecialist : public cLabStaff
{
public:
    cSpecialist(string sFullName = "", cDate dateBirth = cDate(), string sID = "");
    void calcSalary() override;
};