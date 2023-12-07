#include "cManagementDepartment.h"
#include "cSchoolStaff.h"
#include "cLabStaff.h"
#include "cResearcher.h"
#include "cSpecialist.h"
#include "cLecturer.h"
#include "cTeachingAssistant.h"
#include "cIntern.h"

using std::cerr;

cManagementDepartment *cManagementDepartment::m_pInstance = nullptr;

int main()
{
    cSchoolStaff::addPrototype(make_unique<cLecturer>());
    cSchoolStaff::addPrototype(make_unique<cTeachingAssistant>());
    cSchoolStaff::addPrototype(make_unique<cResearcher>());
    cSchoolStaff::addPrototype(make_unique<cSpecialist>());
    cSchoolStaff::addPrototype(make_unique<cIntern>());

    while (true)
    {
        cout << "============================================================================" << endl;
        cout << "=============== SCHOOL STAFF MANAGEMENT SYSTEM - ManagementDepartment ================" << endl;
        cout << "============================================================================" << endl;
        cout << "1. Add new staff." << endl;
        cout << "2. Remove staff." << endl;
        cout << "3. Update salary." << endl;
        cout << "4. Calculate total salary." << endl;
        cout << "5. Print highest salary." << endl;
        cout << "6. Print staff information." << endl;
        cout << "0. Exit." << endl;
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;
        cin.ignore();
        if (choice == 0)
        {
            cout << "Goodbye!" << endl;
            break;
        }
        switch (choice)
        {
        case 1:
        {
            cManagementDepartment::getInstance()->addStaff();
            break;
        }
        case 2:
        {
            cout << "Enter ID of staff to remove: ";
            string sID = "";
            std::getline(cin, sID);
            cManagementDepartment::getInstance()->removeStaff(sID);
            break;
        }
        case 3:
        {
            cManagementDepartment::getInstance()->updateSalary();
            break;
        }
        case 4:
        {
            cout << "Total salary: " << cManagementDepartment::getInstance()->calcTotalSalary() << endl;
            break;
        }
        case 5:
        {
            if (cManagementDepartment::getInstance()->getStaffList().empty())
            {
                cerr << "Staff list is empty." << endl;
                continue;
            }
            cManagementDepartment::getInstance()->printHighestSalary();
            break;
        }

        case 6:
        {
            cout << "============================================================================" << endl;
            cout << "============================ PRINT STAFF INFORMATION ========================" << endl;
            cout << "============================================================================" << endl;
            cout << "1. Print all staff." << endl;
            cout << "2. Print all lecturers." << endl;
            cout << "3. Print all teaching assistants." << endl;
            cout << "4. Print all researchers." << endl;
            cout << "5. Print all specialists." << endl;
            cout << "6. Print all interns." << endl;
            cout << "0. Exit." << endl;
            cout << "Enter your choice: ";
            int choice2;
            cin >> choice2;
            cin.ignore();
            if (choice2 == 0)
            {
                cout << "Exit print staff information." << endl;
                break;
            }
            if (choice2 < 1 || choice2 > 6)
            {
                cerr << "Invalid choice." << endl;
                continue;
            }
            switch (choice2)
            {
            case 1:
                cManagementDepartment::getInstance()->printAllStaff();
                break;
            case 2:
                cManagementDepartment::getInstance()->printAllLecturers();
                break;
            case 3:
                cManagementDepartment::getInstance()->printAllTeachingAssistants();
                break;
            case 4:
                cManagementDepartment::getInstance()->printAllResearchers();
                break;
            case 5:
                cManagementDepartment::getInstance()->printAllSpecialists();
                break;
            case 6:
                cManagementDepartment::getInstance()->printAllInterns();
                break;
            }
            break;
        }

        default:
        {
            if (choice < 0 || choice > 6)
            {
                cerr << "Invalid choice." << endl;
                continue;
            }
        }
        }
    }
    cSchoolStaff::removeAllPrototypes();
    cManagementDepartment::destroyInstance();
}
