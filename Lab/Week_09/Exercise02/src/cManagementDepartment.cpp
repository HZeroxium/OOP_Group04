#include "cManagementDepartment.h"

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////// CONSTRUCTORS AND DESTRUCTORS //////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

cManagementDepartment::~cManagementDepartment()
{
    m_vpSchoolStaff.clear();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////// SINGLETON METHODS //////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

cManagementDepartment *cManagementDepartment::getInstance()
{
    if (m_pInstance == nullptr)
    {
        m_pInstance = new cManagementDepartment();
    }
    return m_pInstance;
}

void cManagementDepartment::destroyInstance()
{
    if (m_pInstance != nullptr)
    {
        delete m_pInstance;
        m_pInstance = nullptr;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////// GETTERS & SETTERS //////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

const vector<unique_ptr<cSchoolStaff>> &cManagementDepartment::getStaffList() const
{
    return m_vpSchoolStaff;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////// METHODS //////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void cManagementDepartment::updateSalary()
{
    for (auto &staff : m_vpSchoolStaff)
    {
        staff->calcSalary();
    }
}

unsigned long cManagementDepartment::calcTotalSalary()
{
    unsigned long totalSalary = 0;
    for (auto &staff : m_vpSchoolStaff)
    {
        totalSalary += staff->getSalary();
    }
    return totalSalary;
}

void cManagementDepartment::addStaff()
{
    unique_ptr<cSchoolStaff> staff;
    cout << "Enter type of staff (1: Researcher, 2: Specialist, 3: Lecturer, 4: Teaching Assistant, 5: Intern): ";
    int type;
    cin >> type;

    cSchoolStaff *pStaff = nullptr;

    switch (type)
    {
    case 1:
        pStaff = cSchoolStaff::createStaff("Researcher");
        break;
    case 2:
        pStaff = cSchoolStaff::createStaff("Specialist");
        break;
    case 3:
        pStaff = cSchoolStaff::createStaff("Lecturer");
        break;
    case 4:
        pStaff = cSchoolStaff::createStaff("Teaching Assistant");
        break;
    case 5:
        pStaff = cSchoolStaff::createStaff("Intern");
        break;
    default:
        cout << "Invalid type." << endl;
        break;
    }
    staff = unique_ptr<cSchoolStaff>(pStaff);
    cout << "Enter information of staff (" << staff->getType() << "): " << endl;
    cin >> *staff;
    cout << "----------------------------------------" << endl;
    m_vpSchoolStaff.push_back(std::move(staff));
}

void cManagementDepartment::removeStaff(const string &sID)
{
    for (auto it = m_vpSchoolStaff.begin(); it != m_vpSchoolStaff.end(); ++it)
    {
        if ((*it)->getID() == sID)
        {
            m_vpSchoolStaff.erase(it);
            break;
        }
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////// PRINT METHODS //////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void cManagementDepartment::printHighestSalary()
{
    unsigned long highestSalary = 0;
    for (auto &staff : m_vpSchoolStaff)
    {
        if (staff->getSalary() > highestSalary)
        {
            highestSalary = staff->getSalary();
        }
    }

    cout << "Highest salary: " << highestSalary << endl;
}

void cManagementDepartment::printStaffInformation(const string &sType)
{
    for (auto &staff : m_vpSchoolStaff)
    {
        if (staff->getType() == sType)
        {
            cout << *staff;
        }
    }
}

void cManagementDepartment::printAllStaff()
{
    cout << "School Staff List: " << endl;
    for (auto &staff : m_vpSchoolStaff)
    {
        cout << "----------------------------------------" << endl;
        cout << *staff;
    }
}

void cManagementDepartment::printAllLecturers()
{
    cout << "Lecturer List: " << endl;
    printStaffInformation("Lecturer");
}

void cManagementDepartment::printAllTeachingAssistants()
{
    cout << "Teaching Assistant List: " << endl;
    printStaffInformation("Teaching Assistant");
}

void cManagementDepartment::printAllResearchers()
{
    cout << "Researcher List: " << endl;
    printStaffInformation("Researcher");
}

void cManagementDepartment::printAllSpecialists()
{
    cout << "Specialist List: " << endl;
    printStaffInformation("Specialist");
}

void cManagementDepartment::printAllInterns()
{
    cout << "Intern List: " << endl;
    printStaffInformation("Intern");
}
