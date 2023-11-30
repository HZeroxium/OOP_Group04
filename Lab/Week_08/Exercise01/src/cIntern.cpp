#include "cIntern.h"

cIntern::cIntern(const string &sFullName, const cDate &dateBirth, const string &sID, unsigned int usResearchingTime, const vector<string> &vResearchingFields)
    : cLabStaff(sFullName, dateBirth, sID, usResearchingTime, vResearchingFields)
{
    m_sType = "Intern";
}

void cIntern::calcSalary()
{
    unsigned long salary = m_vResearchingFields.size() * 10000 * 0.1;
    setSalary(salary);
}

void cIntern::addResearchingField(const string &sResearchingField)
{
    if (sResearchingField[0] != 'T')
    {
        cout << "Error: Intern researching field must start with 'R'." << endl;
        return;
    }
    m_vResearchingFields.push_back(sResearchingField);
}