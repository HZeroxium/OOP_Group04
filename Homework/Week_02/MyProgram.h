#pragma once

#include "Common.h"
#include "MyArray.h"
#include "MyPupil.h"
#include "MyComplex.h"
#include "MyFraction.h"
#include "MyMonomial.h"
class MyProgram
{
private:
    MyFraction myFraction;
    MyComplex myComplex;
    MyMonomial myMonomial;
    MyPupil myPupil;
    MyArray myArray;
    int handle_fraction();
    int handle_complex();
    int handle_monomial();
    int handle_pupil();
    int handle_array();

public:
    // Constructor
    MyProgram(const MyFraction & = MyFraction(), const MyComplex & = MyComplex(), const MyMonomial & = MyMonomial(), const MyPupil & = MyPupil(), const MyArray & = MyArray());

    void run();
};