#include "cTeachingAssistant.h"

cTeachingAssistant::cTeachingAssistant(string sFullName, cDate dateBirth, string sID, unsigned short usNumCourses)
    : cSchoolStaff(sFullName, dateBirth, sID), m_usNumCourses(usNumCourses)
{
    m_sType = "Teaching Assistant";
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
    unsigned long salary = (m_usNumCourses * 0.1) * 20000;
    setSalary(salary);
}

void cTeachingAssistant::input(std::istream &in)
{
    cSchoolStaff::input(in);
    cout << "Enter the following information of the teaching assistant:" << endl;
    cout << "+ Number of Courses: ";
    in >> m_usNumCourses;
}

void cTeachingAssistant::output(std::ostream &out) const
{
    cSchoolStaff::output(out);

    out << "+ Number of Courses: " << m_usNumCourses << endl;
}

std::ostream &operator<<(std::ostream &out, const cTeachingAssistant &teachingAssistant)
{
    teachingAssistant.output(out);
    return out;
}

std::istream &operator>>(std::istream &in, cTeachingAssistant &teachingAssistant)
{
    teachingAssistant.input(in);
    return in;
}
