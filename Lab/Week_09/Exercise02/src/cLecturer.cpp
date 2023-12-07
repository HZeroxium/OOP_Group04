#include "cLecturer.h"

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////// CONSTRUCTORS //////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

cLecturer::cLecturer(const string &sFullName, const cDate &dateBirth, const string &sID, const string &sAcademicRank, const string &sAcademicDegree, unsigned short usTeachingTime, const vector<string> &vCourses)
    : cSchoolStaff(sFullName, dateBirth, sID), m_sAcademicRank(sAcademicRank), m_sAcademicDegree(sAcademicDegree), m_usTeachingTime(usTeachingTime), m_vCourses(vCourses)
{
    m_sType = "Lecturer";
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////// SETTERS ///////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void cLecturer::setAcademicRank(const string &sAcademicRank)
{
    m_sAcademicRank = sAcademicRank;
}

void cLecturer::setAcademicDegree(const string &sAcademicDegree)
{
    m_sAcademicDegree = sAcademicDegree;
}

void cLecturer::setTeachingTime(unsigned short usTeachingTime)
{
    m_usTeachingTime = usTeachingTime;
}

void cLecturer::setCourses(const vector<string> &vCourses)
{
    m_vCourses = vCourses;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////// GETTERS ///////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////// OVERRIDE METHODS //////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void cLecturer::calcSalary()
{
    unsigned long salary = (m_vCourses.size() * m_usTeachingTime * 0.12) * 20000;
    setSalary(salary);
}

cSchoolStaff *cLecturer::clone() const
{
    return new cLecturer(*this);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////// INPUT & OUTPUT //////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void cLecturer::input(std::istream &in)
{
    cSchoolStaff::input(in);
    cout << "Enter lecturer's information:" << endl;
    cout << "+ Enter academic rank: ";
    fflush(stdin);
    getline(in, m_sAcademicRank);
    cout << "+ Enter academic degree: ";
    fflush(stdin);
    getline(in, m_sAcademicDegree);
    cout << "+ Enter teaching time: ";
    in >> m_usTeachingTime;
    cout << "+ Enter number of courses: ";
    unsigned int uiNumOfCourses;
    in >> uiNumOfCourses;
    for (unsigned int i = 0; i < uiNumOfCourses; i++)
    {
        cout << "+ Enter course " << i << ": ";
        fflush(stdin);
        string sCourse;
        getline(in, sCourse);
        m_vCourses.push_back(sCourse);
    }
}

void cLecturer::output(std::ostream &out) const
{
    cSchoolStaff::output(out);
    out << "+ Academic Rank: " << m_sAcademicRank << endl;
    out << "+ Academic Degree: " << m_sAcademicDegree << endl;
    out << "+ Teaching Time: " << m_usTeachingTime << endl;
    out << "+ Courses: ";
    for (unsigned int i = 0; i < m_vCourses.size(); i++)
    {
        out << "+ " << i << ". " << m_vCourses[i] << endl;
    }
    out << endl;
}

std::ostream &operator<<(std::ostream &out, const cLecturer &lecturer)
{
    lecturer.output(out);
    return out;
}

std::istream &operator>>(std::istream &in, cLecturer &lecturer)
{
    lecturer.input(in);
    return in;
}