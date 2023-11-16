#include "SATest.h"
#include "InterchangeS.h"
#include "SelectionS.h"
#include "InsertionS.h"

#include <string>
#include "ProgramFrame.h"

int main()
{
    constexpr std::ostream &out = std::cout;
    constexpr std::istream &in = std::cin;

    std::cout << "=============================================================" << std::endl;
    std::cout << "======================== Week 06 ============================" << std::endl;
    std::cout << "=============================================================" << std::endl;

    std::cout << "=============================================================" << std::endl;
    std::cout << "================ INT SELECTION SORT =========================" << std::endl;
    std::cout << "=============================================================" << std::endl;
    SATest<int> saTest_selectionS = SATest<int>(new SelectionS<int>());
    saTest_selectionS.run(in, out);

    std::cout << "=============================================================" << std::endl;
    std::cout << "================ DOUBLE INTERCHANGE SORT ====================" << std::endl;
    std::cout << "=============================================================" << std::endl;
    SATest<double> saTest_interchangeS = SATest<double>(new InterchangeS<double>());
    saTest_interchangeS.run(in, out);

    std::cout << "=============================================================" << std::endl;
    std::cout << "================ STRING INSERTION SORT ======================" << std::endl;
    std::cout << "=============================================================" << std::endl;
    SATest<std::string> saTest_insertionS = SATest<std::string>(new InsertionS<std::string>());
    saTest_insertionS.run(in, out);

    std::cout << "=============================================================" << std::endl;
    std::cout << "======================== THE END ============================" << std::endl;
    std::cout << "=============================================================" << std::endl;

    return 0;
}
