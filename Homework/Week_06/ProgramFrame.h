#pragma once

#include <iostream>

template <typename T>
class ProgramFrame
{
protected:
    virtual void startMessage(std::ostream &out)
    {
        out << "#############################################################" << std::endl;
        out << "Welcome! Pls entering data:\n";
    }
    virtual void input(std::istream &in) = 0;
    virtual bool check() = 0;
    virtual void errorMessage(std::ostream &out)
    {
        out << "Input data error! \n";
    }
    virtual void output(std::ostream &out) = 0;
    virtual void process() = 0;
    virtual bool askContinue(std::istream &in, std::ostream &out)
    {
        out << "Continue? (y/n): ";
        char answer;
        in >> answer;
        return (answer == 'y' || answer == 'Y');
    }

public:
    void run(std::istream &in, std::ostream &out)
    {
        std::cout << "*************************************************************" << std::endl;
        std::cout << "********************** START PROGRAM ************************" << std::endl;
        std::cout << "*************************************************************" << std::endl;
        bool b;
        do
        {
            startMessage(out);
            input(in);
            if (!check())
            {
                errorMessage(out);
                continue;
            }
            process();
            output(out);
            b = askContinue(in, out);
        } while (b);
        std::cout << "*************************************************************" << std::endl;
        std::cout << "*********************** END PROGRAM *************************" << std::endl;
        std::cout << "*************************************************************" << std::endl;
    }
};

#include "ProgramFrame.cpp"