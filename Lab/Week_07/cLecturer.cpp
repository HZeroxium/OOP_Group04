#include "cLecturer.h"

cLecturer::cLecturer(string sFullName, cDate dateBirth, string sID, string sAcademicRank, string sAcademicDegree, unsigned short usTeachingTime, vector<string> vCourses)
    : cSchoolStaff(sFullName, dateBirth, sID), m_sAcademicRank(sAcademicRank), m_sAcademicDegree(sAcademicDegree), m_usTeachingTime(usTeachingTime), m_vCourses(vCourses)
{
}

void cLecturer::setAcademicRank(string sAcademicRank)
{
    m_sAcademicRank = sAcademicRank;
}

void cLecturer::setAcademicDegree(string sAcademicDegree)
{
    m_sAcademicDegree = sAcademicDegree;
}

void cLecturer::setTeachingTime(unsigned short usTeachingTime)
{
    m_usTeachingTime = usTeachingTime;
}

void cLecturer::setCourses(vector<string> vCourses)
{
    m_vCourses = vCourses;
}

string cLecturer::getAcademicRank() const
{
    return m_sAcademicRank;
}

string cLecturer::getAcademicDegree() const
{
    return m_sAcademicDegree;
}

unsigned short cLecturer::getTeachingTime() const
{
    return m_usTeachingTime;
}

vector<string> cLecturer::getCourses() const
{
    return m_vCourses;
}

void cLecturer::calcSalary()
{
    unsigned long salary = (m_vCourses.size() * m_usTeachingTime * 0.12) * 20000;
    setSalary(salary);
}

std::ostream &operator<<(std::ostream &out, const cLecturer &lecturer)
{
    out << (cSchoolStaff &)lecturer;
    out << "+ Academic Rank: " << lecturer.m_sAcademicRank << endl;
    out << "+ Academic Degree: " << lecturer.m_sAcademicDegree << endl;
    out << "+ Teaching Time: " << lecturer.m_usTeachingTime << endl;
    out << "+ Courses: ";
    for (unsigned int i = 0; i < lecturer.m_vCourses.size(); i++)
    {
        out << "+ " << i << ". " << lecturer.m_vCourses[i];
    }
    out << endl;
    return out;
}

std::istream &operator>>(std::istream &in, cLecturer &lecturer)
{
    in >> (cSchoolStaff &)lecturer;
    cout << "Enter lecturer's information:" << endl;
    cout << "+ Enter academic rank: ";
    fflush(stdin);
    getline(in, lecturer.m_sAcademicRank);
    cout << "+ Enter academic degree: ";
    fflush(stdin);
    getline(in, lecturer.m_sAcademicDegree);
    cout << "+ Enter teaching time: ";
    in >> lecturer.m_usTeachingTime;
    cout << "+ Enter number of courses: ";
    unsigned int uiNumOfCourses;
    in >> uiNumOfCourses;
    for (unsigned int i = 0; i < uiNumOfCourses; i++)
    {
        cout << "+ Enter course " << i << ": ";
        fflush(stdin);
        string sCourse;
        getline(in, sCourse);
        lecturer.m_vCourses.push_back(sCourse);
    }
    return in;
}