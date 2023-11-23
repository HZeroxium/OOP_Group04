#include "cBook.h"

cBook::cBook(string sID, string sName, string sAuthor, unsigned int uiYear, unsigned int uiPages)
{
    m_sID = sID;
    m_sName = sName;
    m_sAuthor = sAuthor;
    m_uiYear = uiYear;
    m_uiPages = uiPages;
}

void cBook::setID(string sID)
{
    m_sID = sID;
}

void cBook::setName(string sName)
{
    m_sName = sName;
}

void cBook::setAuthor(string sAuthor)
{
    m_sAuthor = sAuthor;
}

void cBook::setYear(unsigned int uiYear)
{
    m_uiYear = uiYear;
}

void cBook::setPages(unsigned int uiPages)
{
    m_uiPages = uiPages;
}

string cBook::getID() const
{
    return m_sID;
}

string cBook::getName() const
{
    return m_sName;
}

string cBook::getAuthor() const
{
    return m_sAuthor;
}

unsigned int cBook::getYear() const
{
    return m_uiYear;
}

unsigned int cBook::getPages() const
{
    return m_uiPages;
}

std::ostream &operator<<(std::ostream &out, const cBook &book)
{
    out << "Book information:" << endl;
    out << "+ ID: " << book.m_sID << endl;
    out << "+ Name: " << book.m_sName << endl;
    out << "+ Author: " << book.m_sAuthor << endl;
    out << "+ Published Year: " << book.m_uiYear << endl;
    out << "+ Number of Pages: " << book.m_uiPages << endl;
    return out;
}

std::istream &operator>>(std::istream &in, cBook &book)
{
    cout << "Enter book information:" << endl;
    cout << "+ ID: ";
    fflush(stdin);
    getline(in, book.m_sID);
    cout << "+ Name: ";
    fflush(stdin);
    getline(in, book.m_sName);
    cout << "+ Author: ";
    fflush(stdin);
    getline(in, book.m_sAuthor);
    cout << "+ Published Year: ";
    fflush(stdin);
    in >> book.m_uiYear;
    cout << "+ Number of Pages: ";
    fflush(stdin);
    in >> book.m_uiPages;
    in.ignore();
    return in;
}