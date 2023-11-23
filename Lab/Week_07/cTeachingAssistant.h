#pragma once

#include "cSchoolStaff.h"

class cTeachingAssistant : public cSchoolStaff
{
private:
    unsigned short m_usNumCourses; ///< Number of courses that the teaching assistant is teaching

public:
    cTeachingAssistant(string sFullName = "", cDate dateBirth = cDate(), string sID = "", unsigned short usNumCourses = 0);

public: // Setters
    void setNumCourses(unsigned short usNumCourses);

public: // Getters
    unsigned short getNumCourses() const;

public: // Methods
    void calcSalary() override;

public: // Input & Output
    friend std::ostream &operator<<(std::ostream &out, const cTeachingAssistant &teachingAssistant);
    friend std::istream &operator>>(std::istream &in, cTeachingAssistant &teachingAssistant);
};