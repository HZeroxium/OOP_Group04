#pragma once

#include "ProgramFrame.h"
#include "SortArray.h"

template <typename T>
class SATest : public ProgramFrame
{
private:
    SortArray<T> *sortArray;
    std::vector<T> array;

public:
    SATest(SortArray<T> *sortArray = nullptr);
    ~SATest();
    void input(std::istream &in = std::cin);
    bool check();
    void output(std::ostream &out = std::cout);
    void process();
};

#include "SATest.cpp"
