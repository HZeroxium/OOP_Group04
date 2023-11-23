#include "cSpecialist.h"

cSpecialist::cSpecialist(string sFullName, cDate dateBirth, string sID)
    : cLabStaff(sFullName, dateBirth, sID)
{
}

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
    auto salary = static_cast<unsigned long>(m_usResearchingTime * 4 + usNumOfFields) * 20000;
    setSalary(salary);
}