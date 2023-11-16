#include "SATest.h"
#include "InterchangeS.h"
#include "SelectionS.h"
#include "InsertionS.h"

#include <string>
#include "ProgramFrame.h"

template class SATest<int>;
template class SATest<double>;
template class SATest<std::string>;

int main()
{
    constexpr std::ostream &out = std::cout;
    constexpr std::istream &in = std::cin;

    SATest<int> saTest_selectionS = SATest<int>(new SelectionS<int>());
    saTest_selectionS.run(in, out);

    SATest<double> saTest_interchangeS = SATest<double>(new InterchangeS<double>());
    saTest_interchangeS.run(in, out);

    SATest<std::string> saTest_insertionS = SATest<std::string>(new InsertionS<std::string>());
    saTest_insertionS.run(in, out);

    return 0;
}
