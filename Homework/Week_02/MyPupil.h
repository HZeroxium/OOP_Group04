#pragma once

#include "Common.h"

class MyPupil
{
private:
    string name;
    float math, literature;

public:
    // Constructor
    MyPupil(const string & = "", float = 0, float = 0);
    MyPupil(const MyPupil &);

    // Getter
    string getName() const;
    float getMath() const;
    float getLiterature() const;

    // Setter
    void setName(const string &);
    void setMath(float);
    void setLiterature(float);

    // Input & Output
    void input(const string & = "Input information of pupil: ");
    void output(const string & = "Output information: ") const;

    // Calculate GPA
    float getGPA() const;

    // Classify pupil by GPA
    string getRank() const;
};