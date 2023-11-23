#include "cSchoolStaff.h"
#include "cLabStaff.h"
#include "cResearcher.h"
#include "cSpecialist.h"
#include "cLecturer.h"
#include "cTeachingAssistant.h"

#include <memory>

using std::unique_ptr;

int main()
{
    vector<unique_ptr<cSchoolStaff>> vpSchoolStaff;

    unsigned int n;
    cout << "Enter number of school staff: ";
    cin >> n;

    vpSchoolStaff.resize(n);

    for (auto &staff : vpSchoolStaff)
    {
        cout << "Enter type of staff (1: Researcher, 2: Specialist, 3: Lecturer, 4: Teaching Assistant): ";
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
        default:
            cout << "Invalid type." << endl;
            break;
        }

        cin >> *staff;
    }

    cout << "School Staff List: " << endl;
    for (auto &staff : vpSchoolStaff)
    {
        staff->calcSalary();
        cout << *staff;
    }
}