#pragma once

#include "Common.h"
#include "MyArray.h"
#include "MyPupil.h"

class MyProgram
{
private:
    MyPupil myPupil;
    MyArray myArray;
    int handle_pupil();
    int handle_array();

public:
    // Constructor
    MyProgram(const MyPupil & = MyPupil(), const MyArray & = MyArray());

    void run();
};