#include "ProgramFrame.h"

template <typename T>
void ProgramFrame<T>::startMessage(std::ostream &out)
{
    out << "Welcome! Pls entering data: \n";
}

template <typename T>
void ProgramFrame<T>::errorMessage(std::ostream &out)
{
    out << "Input data error! \n";
}

template <typename T>
bool ProgramFrame<T>::askContinue(std::istream &in, std::ostream &out)
{
    out << "Continue? (y/n): ";
    char answer;
    in >> answer;
    return (answer == 'y' || answer == 'Y');
}

template <typename T>
void ProgramFrame<T>::run(std::istream &in, std::ostream &out)
{
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
}

template class ProgramFrame<int>;
template class ProgramFrame<double>;
