#pragma once

#include "cSchoolStaff.h"
#include "cLabStaff.h"
#include "cResearcher.h"
#include "cSpecialist.h"
#include "cLecturer.h"
#include "cTeachingAssistant.h"
#include "cIntern.h"

#include <memory>

using std::make_unique;
using std::unique_ptr;

class cUniversity
{
private:
    vector<unique_ptr<cSchoolStaff>> m_vpSchoolStaff;

public: // Constructors & Destructor
    cUniversity() = default;
    ~cUniversity() = default;

public: // Getter & Setter
    const vector<unique_ptr<cSchoolStaff>> &getStaffList() const;

public: // Methods
    void updateSalary();
    unsigned long calcTotalSalary();
    void addStaff();
    void removeStaff(const string &sID);

private:
    void printStaffInformation(const string &sType);

public: // Print methods
    void printHighestSalary();

    void printAllStaff();

    void printAllLecturers();
    void printAllTeachingAssistants();
    void printAllResearchers();
    void printAllSpecialists();
    void printAllInterns();
};

/*
cUniversity
- vector<unique_ptr<cSchoolStaff>> m_vpSchoolStaff
+ const vector<unique_ptr<cSchoolStaff>>& getStaffList() const
+ void updateSalary()
+ unsigned long calcTotalSalary()
+ void addStaff()
+ void removeStaff(const string& sID)
- void printStaffInformation(const string& sType)
+ void printHighestSalary()
+ void printAllStaff()
+ void printAllLecturers()
+ void printAllTeachingAssistants()
+ void printAllResearchers()
+ void printAllSpecialists()
+ void printAllInterns()
*/
