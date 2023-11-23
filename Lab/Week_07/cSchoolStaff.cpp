#include "cSchoolStaff.h"

cSchoolStaff::cSchoolStaff(string sFullName, cDate dateBirth, string sID)
{
    setFullName(sFullName);
    setDateBirth(dateBirth);
    setID(sID);
}

void cSchoolStaff::setFullName(string sFullName)
{
    m_sFullName = sFullName;
}

void cSchoolStaff::setDateBirth(cDate dateBirth)
{
    m_dateBirth = dateBirth;
}

void cSchoolStaff::setID(string sID)
{
    m_sID = sID;
}

void cSchoolStaff::setSalary(unsigned long ulSalary)
{
    m_ulSalary = ulSalary;
}

string cSchoolStaff::getFullName() const
{
    return m_sFullName;
}

cDate cSchoolStaff::getDateBirth() const
{
    return m_dateBirth;
}

string cSchoolStaff::getID() const
{
    return m_sID;
}

unsigned long cSchoolStaff::getSalary() const
{
    return m_ulSalary;
}

std::ostream &operator<<(std::ostream &out, const cSchoolStaff &schoolStaff)
{
    out << "School staff information:" << endl;
    out << "Full name: " << schoolStaff.m_sFullName << endl;
    out << "Date of birth: " << schoolStaff.m_dateBirth << endl;
    out << "ID: " << schoolStaff.m_sID << endl;
    out << "Salary: " << schoolStaff.m_ulSalary << endl;

    return out;
}

std::istream &operator>>(std::istream &in, cSchoolStaff &schoolStaff)
{
    cout << "Enter school staff information:" << endl;
    cout << "+ Full name: ";
    fflush(stdin);
    getline(in, schoolStaff.m_sFullName);

    cout << "+ Date of birth: " << endl;
    fflush(stdin);
    in >> schoolStaff.m_dateBirth;

    cout << "+ ID: ";
    fflush(stdin);
    getline(in, schoolStaff.m_sID);

    return in;
}
