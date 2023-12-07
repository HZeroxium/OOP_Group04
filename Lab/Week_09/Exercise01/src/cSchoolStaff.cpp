#include "cSchoolStaff.h"

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////// CONSTRUCTORS AND DESTRUCTORS ////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

cSchoolStaff::cSchoolStaff(const string &sFullName, const cDate &dateBirth, const string &sID, const string &sType)
{
    setFullName(sFullName);
    setDateBirth(dateBirth);
    setID(sID);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////// SETTERS ///////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void cSchoolStaff::setFullName(const string &sFullName)
{
    m_sFullName = sFullName;
}

void cSchoolStaff::setDateBirth(const cDate &dateBirth)
{
    m_dateBirth = dateBirth;
}

void cSchoolStaff::setID(const string &sID)
{
    m_sID = sID;
}

void cSchoolStaff::setSalary(unsigned long ulSalary)
{
    m_ulSalary = ulSalary;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////// GETTERS ///////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////// INPUT & OUTPUT //////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////// STATIC PROTOTYPE VECTOR ///////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Initialize static vector
vector<unique_ptr<cSchoolStaff>> cSchoolStaff::m_vPrototypes;

void cSchoolStaff::addPrototype(unique_ptr<cSchoolStaff> &&prototype)
{
    m_vPrototypes.push_back(move(prototype));
}

cSchoolStaff *cSchoolStaff::createStaff(const string &sType)
{
    for (unsigned int i = 0; i < m_vPrototypes.size(); i++)
    {
        if (m_vPrototypes[i]->getType() == sType)
        {
            return m_vPrototypes[i]->clone();
        }
    }
    return nullptr;
}

void cSchoolStaff::removePrototype(const string &sType)
{
    for (unsigned int i = 0; i < m_vPrototypes.size(); i++)
    {
        if (m_vPrototypes[i]->getType() == sType)
        {
            m_vPrototypes.erase(m_vPrototypes.begin() + i);
            return;
        }
    }
}

void cSchoolStaff::removeAllPrototypes()
{
    m_vPrototypes.clear();
}
