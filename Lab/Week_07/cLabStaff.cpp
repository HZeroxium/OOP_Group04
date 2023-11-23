#include "cLabStaff.h"

cLabStaff::cLabStaff(string sFullName, cDate dateBirth, string sID, unsigned int usResearchingTime, vector<string> vResearchingFields)
    : cSchoolStaff(sFullName, dateBirth, sID), m_usResearchingTime(usResearchingTime), m_vResearchingFields(vResearchingFields)
{
}

void cLabStaff::setResearchingTime(unsigned int usResearchingTime)
{
    m_usResearchingTime = usResearchingTime;
}

void cLabStaff::setResearchingFields(const vector<string> &vResearchingFields)
{
    m_vResearchingFields = vResearchingFields;
}

unsigned int cLabStaff::getResearchingTime() const
{
    return m_usResearchingTime;
}

vector<string> cLabStaff::getResearchingFields() const
{
    return m_vResearchingFields;
}

void cLabStaff::addResearchingField(string sResearchingField)
{
    // Find if the field is already in the vector
    for (auto &field : m_vResearchingFields)
    {
        if (field == sResearchingField)
        {
            cout << "The field is already in fields list." << endl;
            return;
        }
    }
    m_vResearchingFields.push_back(sResearchingField);
}

std::ostream &operator<<(std::ostream &out, const cLabStaff &labStaff)
{
    out << (cSchoolStaff &)labStaff;
    out << "+ Researching Time: " << labStaff.m_usResearchingTime << endl;
    out << "+ Researching Fields: ";
    for (auto &field : labStaff.m_vResearchingFields)
    {
        out << field << ", ";
    }
    out << endl;
    return out;
}

std::istream &operator>>(std::istream &in, cLabStaff &labStaff)
{
    in >> (cSchoolStaff &)labStaff;
    cout << "+ Researching Time: ";
    in >> labStaff.m_usResearchingTime;
    cout << "+ Researching Fields: (\"end\" to stop)" << endl;
    string sResearchingField;
    while (true)
    {
        in >> sResearchingField;
        if (sResearchingField == "end")
        {
            break;
        }
        labStaff.m_vResearchingFields.push_back(sResearchingField);
    }
    return in;
}
