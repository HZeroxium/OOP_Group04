#include "MyPupil.h"

MyPupil::MyPupil(const string &name, float math, float literature)
{
    this->name = name;
    this->math = math;
    this->literature = literature;
}

MyPupil::MyPupil(const MyPupil &pupil)
{
    this->name = pupil.name;
    this->math = pupil.math;
    this->literature = pupil.literature;
}

string MyPupil::getName() const
{
    return this->name;
}

float MyPupil::getMath() const
{
    return this->math;
}

float MyPupil::getLiterature() const
{
    return this->literature;
}

void MyPupil::setName(const string &name)
{
    this->name = name;
}

void MyPupil::setMath(float math)
{
    this->math = math;
}

void MyPupil::setLiterature(float literature)
{
    this->literature = literature;
}

void MyPupil::input(const string &msg)
{
    cout << msg << endl;
    cout << "+ Name: ";
    getline(cin, this->name);
    cout << "+ Math: ";
    cin >> this->math;
    cout << "+ Literature: ";
    cin >> this->literature;
    cin.ignore();
}

void MyPupil::output(const string &msg) const
{
    cout << msg << endl;
    cout << "+ Name: " << this->name << endl;
    cout << "+ Math: " << this->math << endl;
    cout << "+ Literature: " << this->literature << endl;
    cout << "+ GPA: " << this->getGPA() << endl;
    cout << "+ Rank: " << this->getRank() << endl;
}

float MyPupil::getGPA() const
{
    return (this->math + this->literature) / 2;
}

string MyPupil::getRank() const
{
    float gpa = this->getGPA();
    if (gpa >= 8)
        return "Excellent";
    if (gpa >= 7)
        return "Good";
    if (gpa >= 5)
        return "Average";
    return "Weak";
}
