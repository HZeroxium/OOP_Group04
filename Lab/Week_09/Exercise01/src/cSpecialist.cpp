#include "cSpecialist.h"

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////// CONSTRUCTORS //////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

cSpecialist::cSpecialist(const string &sFullName, const cDate &dateBirth, const string &sID, unsigned int usResearchingTime, const vector<string> &vResearchingFields)
    : cLabStaff(sFullName, dateBirth, sID, usResearchingTime, vResearchingFields)
{
    m_sType = "Specialist";
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////// OVERRIDE METHODS //////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void cSpecialist::calcSalary()
{
    // Find number of fields start with "T"
    unsigned int usNumOfFields = 0;
    for (auto &field : m_vResearchingFields)
    {
        if (field[0] == 'T')
        {
            usNumOfFields++;
        }
    }
    unsigned long salary = (m_usResearchingTime * 4 + usNumOfFields) * 20000;
    setSalary(salary);
}

cSchoolStaff *cSpecialist::clone() const
{
    return new cSpecialist(*this);
}