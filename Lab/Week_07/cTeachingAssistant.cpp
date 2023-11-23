#include "cTeachingAssistant.h"

cTeachingAssistant::cTeachingAssistant(string sFullName, cDate dateBirth, string sID, unsigned short usNumCourses)
    : cSchoolStaff(sFullName, dateBirth, sID), m_usNumCourses(usNumCourses)
{
}

void cTeachingAssistant::setNumCourses(unsigned short usNumCourses)
{
    m_usNumCourses = usNumCourses;
}

unsigned short cTeachingAssistant::getNumCourses() const
{
    return m_usNumCourses;
}

void cTeachingAssistant::calcSalary()
{
    unsigned long salary = static_cast<unsigned long>(m_usNumCourses * 0.1) * 20000;
    setSalary(salary);
}

std::ostream &operator<<(std::ostream &out, const cTeachingAssistant &teachingAssistant)
{
    out << (cSchoolStaff &)teachingAssistant;

    out << "+ Number of Courses: " << teachingAssistant.m_usNumCourses << endl;
    return out;
}

std::istream &operator>>(std::istream &in, cTeachingAssistant &teachingAssistant)
{
    in >> (cSchoolStaff &)teachingAssistant;
    cout << "Enter the following information of the teaching assistant:" << endl;
    cout << "+ Number of Courses: ";
    in >> teachingAssistant.m_usNumCourses;
    return in;
}
