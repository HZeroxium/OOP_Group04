#pragma once

#include <iostream>

template <typename T>
class ProgramFrame
{
protected:
    virtual void startMessage(std::ostream &out);
    virtual void input(std::istream &in) = 0;
    virtual bool check() = 0;
    virtual void errorMessage(std::ostream &out);
    virtual void output(std::ostream &out) = 0;
    virtual void process() = 0;
    virtual bool askContinue(std::istream &in, std::ostream &out);

public:
    void run(std::istream &in, std::ostream &out);
};

#include "ProgramFrame.cpp"