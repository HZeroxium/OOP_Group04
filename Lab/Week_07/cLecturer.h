#pragma once

#include "cSchoolStaff.h"
#include <vector>

using std::vector;

class cLecturer : public cSchoolStaff
{
private:
    string m_sAcademicRank;
    string m_sAcademicDegree;
    unsigned short m_usTeachingTime;
    vector<string> m_vCourses;

public: // Constructors & Destructor
    cLecturer(string sFullName = "", cDate dateBirth = cDate(), string sID = "", string sAcademicRank = "", string sAcademicDegree = "", unsigned short usTeachingTime = 0, vector<string> vCourses = vector<string>());

public: // Setters
    void setAcademicRank(string sAcademicRank);
    void setAcademicDegree(string sAcademicDegree);
    void setTeachingTime(unsigned short usTeachingTime);
    void setCourses(vector<string> vCourses);

public: // Getters
    string getAcademicRank() const;
    string getAcademicDegree() const;
    unsigned short getTeachingTime() const;
    vector<string> getCourses() const;

public: // Methods
    void calcSalary() override;

public: // Input & Output
    friend std::ostream &operator<<(std::ostream &out, const cLecturer &lecturer);
    friend std::istream &operator>>(std::istream &in, cLecturer &lecturer);
};