#include "cUniversity.h"

const vector<unique_ptr<cSchoolStaff>> &cUniversity::getStaffList() const
{
    return m_vpSchoolStaff;
}

void cUniversity::updateSalary()
{
    for (auto &staff : m_vpSchoolStaff)
    {
        staff->calcSalary();
    }
}

unsigned long cUniversity::calcTotalSalary()
{
    unsigned long totalSalary = 0;
    for (auto &staff : m_vpSchoolStaff)
    {
        totalSalary += staff->getSalary();
    }
    return totalSalary;
}

void cUniversity::addStaff()
{
    unique_ptr<cSchoolStaff> staff;
    cout << "Enter type of staff (1: Researcher, 2: Specialist, 3: Lecturer, 4: Teaching Assistant, 5: Intern): ";
    int type;
    cin >> type;

    switch (type)
    {
    case 1:
        staff = unique_ptr<cSchoolStaff>(new cResearcher());
        break;
    case 2:
        staff = unique_ptr<cSchoolStaff>(new cSpecialist());
        break;
    case 3:
        staff = unique_ptr<cSchoolStaff>(new cLecturer());
        break;
    case 4:
        staff = unique_ptr<cSchoolStaff>(new cTeachingAssistant());
        break;
    case 5:
        staff = unique_ptr<cSchoolStaff>(new cIntern());
    default:
        cout << "Invalid type." << endl;
        break;
    }
    cout << "Enter information of staff (" << staff->getType() << "): " << endl;
    cin >> *staff;
    cout << "----------------------------------------" << endl;
    m_vpSchoolStaff.push_back(std::move(staff));
}

void cUniversity::removeStaff(const string &sID)
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

void cUniversity::printHighestSalary()
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

void cUniversity::printStaffInformation(const string &sType)
{
    for (auto &staff : m_vpSchoolStaff)
    {
        if (staff->getType() == sType)
        {
            cout << *staff;
        }
    }
}

void cUniversity::printAllStaff()
{
    cout << "School Staff List: " << endl;
    for (auto &staff : m_vpSchoolStaff)
    {
        cout << "----------------------------------------" << endl;
        cout << *staff;
    }
}

void cUniversity::printAllLecturers()
{
    cout << "Lecturer List: " << endl;
    printStaffInformation("Lecturer");
}

void cUniversity::printAllTeachingAssistants()
{
    cout << "Teaching Assistant List: " << endl;
    printStaffInformation("Teaching Assistant");
}

void cUniversity::printAllResearchers()
{
    cout << "Researcher List: " << endl;
    printStaffInformation("Researcher");
}

void cUniversity::printAllSpecialists()
{
    cout << "Specialist List: " << endl;
    printStaffInformation("Specialist");
}

void cUniversity::printAllInterns()
{
    cout << "Intern List: " << endl;
    printStaffInformation("Intern");
}
