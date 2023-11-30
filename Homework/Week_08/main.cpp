#include <iostream>
#include <fstream>
#include <locale>  // Used for std::locale
#include <codecvt> // Used for std::codecvt_utf8

int main()
{
    // Set file name
    const char *fileName = "data.txt";

    // Wide character stream for input file
    std::wifstream file(fileName, std::ios::in);

    if (file.is_open())
    {
        // Set locale to UTF-8 and open file in binary mode to prevent BOM being appended to beginning of file content
        file.imbue(std::locale(file.getloc(), new std::codecvt_utf8<wchar_t>));

        // Read file content
        std::wstring content;
        wchar_t ch;
        while (file.get(ch))
        {
            content += ch;
        }

        // Close file
        file.close();

        std::wcout << "Number of characters: " << content.length() - 1 << std::endl;
    }
    else
    {
        std::cerr << "Can't open file" << std::endl;
    }

    return 0;
}
