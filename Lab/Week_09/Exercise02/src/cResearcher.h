#pragma once

#include "cLabStaff.h"

class cResearcher final : public cLabStaff
{
public: // Constructors & Destructor
    cResearcher(const string &sFullName = "", const cDate &dateBirth = cDate(), const string &sID = "", unsigned int usResearchingTime = 0, const vector<string> &vResearchingFields = vector<string>());
    ~cResearcher() override = default;

public: // Override Methods
    void calcSalary() override;
    cSchoolStaff *clone() const override;
};

/**
cResearcher
+ cResearcher(sFullName: string = "", dateBirth: cDate = cDate(), sID: string = "", usResearchingTime: unsigned int = 0, vResearchingFields: vector<string> = vector<string>())
+ ~cResearcher()
+ calcSalary(): void
 */