#pragma once

#include <iostream>
#include <string>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::find_if;
using std::string;

class cBook
{
private:
    string m_sID;
    string m_sName;
    string m_sAuthor;
    unsigned int m_uiYear;
    unsigned int m_uiPages;

public:
    cBook(string sID = "", string sName = "", string sAuthor = "", unsigned int uiYear = 0, unsigned int uiPages = 0);
    ~cBook() = default;

    void setID(string sID);
    void setName(string sName);
    void setAuthor(string sAuthor);
    void setYear(unsigned int uiYear);
    void setPages(unsigned int uiPages);

    string getID() const;
    string getName() const;
    string getAuthor() const;
    unsigned int getYear() const;
    unsigned int getPages() const;

    friend std::ostream &operator<<(std::ostream &out, const cBook &book);
    friend std::istream &operator>>(std::istream &in, cBook &book);
};