#pragma once

#include "cSchoolStaff.h"
#include <vector>

using std::vector;

class cLecturer final : public cSchoolStaff
{
private:
    string m_sAcademicRank;
    string m_sAcademicDegree;
    unsigned short m_usTeachingTime;
    vector<string> m_vCourses;

public: // Constructors & Destructor
    cLecturer(string sFullName = "", cDate dateBirth = cDate(), string sID = "", string sAcademicRank = "", string sAcademicDegree = "", unsigned short usTeachingTime = 0, vector<string> vCourses = vector<string>());
    ~cLecturer() override = default;

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

private: // Input & Output helper methods
    void input(std::istream &in) override;
    void output(std::ostream &out) const override;

public: // Input & Output
    friend std::ostream &operator<<(std::ostream &out, const cLecturer &lecturer);
    friend std::istream &operator>>(std::istream &in, cLecturer &lecturer);
};

/**
cLecturer
- m_sAcademicRank: string
- m_sAcademicDegree: string
- m_usTeachingTime: unsigned short
- m_vCourses: vector<string>
+ cLecturer(sFullName: string = "", dateBirth: cDate = cDate(), sID: string = "", sAcademicRank: string = "", sAcademicDegree: string = "", usTeachingTime: unsigned short = 0, vCourses: vector<string> = vector<string>())
+ ~cLecturer()
+ setAcademicRank(sAcademicRank: string): void
+ setAcademicDegree(sAcademicDegree: string): void
+ setTeachingTime(usTeachingTime: unsigned short): void
+ setCourses(vCourses: vector<string>): void
+ getAcademicRank(): string
+ getAcademicDegree(): string
+ getTeachingTime(): unsigned short
+ getCourses(): vector<string>
+ calcSalary(): void
+ friend operator<<(out: std::ostream&, lecturer: cLecturer&): std::ostream&
+ friend operator>>(in: std::istream&, lecturer: cLecturer&): std::istream&
- virtual input(in: std::istream&): void
- virtual output(out: std::ostream&) const: void
 */