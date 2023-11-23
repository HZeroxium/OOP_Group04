#include "cSchoolStaff.h"

cSchoolStaff::cSchoolStaff(string sFullName, cDate dateBirth, string sID, string sType)
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

string cSchoolStaff::getType() const
{
    return m_sType;
}

void cSchoolStaff::input(std::istream &in)
{
    cout << "Enter school staff information:" << endl;
    cout << "+ Full name: ";
    fflush(stdin);
    getline(in, m_sFullName);

    cout << "+ Date of birth: " << endl;
    fflush(stdin);
    in >> m_dateBirth;

    cout << "+ ID: ";
    fflush(stdin);
    getline(in, m_sID);
}

void cSchoolStaff::output(std::ostream &out) const
{
    out << "School staff information:" << endl;
    out << "+ Type: " << m_sType << endl;
    out << "+ Full name: " << m_sFullName << endl;
    out << "+ Date of birth: " << m_dateBirth << endl;
    out << "+ ID: " << m_sID << endl;
    out << "+ Salary: " << m_ulSalary << endl;
}

std::ostream &operator<<(std::ostream &out, const cSchoolStaff &schoolStaff)
{
    schoolStaff.output(out);
    return out;
}

std::istream &operator>>(std::istream &in, cSchoolStaff &schoolStaff)
{
    schoolStaff.input(in);
    return in;
}
