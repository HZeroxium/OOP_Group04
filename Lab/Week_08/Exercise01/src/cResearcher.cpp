#include "cResearcher.h"

cResearcher::cResearcher(const string &sFullName, const cDate &dateBirth, const string &sID, unsigned int usResearchingTime, const vector<string> &vResearchingFields)
    : cLabStaff(sFullName, dateBirth, sID, usResearchingTime, vResearchingFields)
{
    m_sType = "Researcher";
}

void cResearcher::calcSalary()
{
    // Find number of fields start with "D"
    unsigned int usNumOfFields = 0;
    for (auto &field : m_vResearchingFields)
    {
        if (field[0] == 'D')
        {
            usNumOfFields++;
        }
    }

    unsigned long ulSalary = (m_usResearchingTime * 2 + usNumOfFields) * 20000;
    setSalary(ulSalary);
}
