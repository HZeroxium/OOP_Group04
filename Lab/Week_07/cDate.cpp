#include "cDate.h"

cDate::cDate(unsigned short usDay, unsigned short usMonth, unsigned int usYear)
{
    setDay(usDay);
    setMonth(usMonth);
    setYear(usYear);
}

cDate::~cDate() = default;

void cDate::setDay(unsigned short usDay)
{
    m_usDay = usDay;
}

void cDate::setMonth(unsigned short usMonth)
{
    m_usMonth = usMonth;
}

void cDate::setYear(unsigned int uiYear)
{
    m_uiYear = uiYear;
}

void cDate::setDate(unsigned short usDay, unsigned short usMonth, unsigned int uiYear)
{
    setDay(usDay);
    setMonth(usMonth);
    setYear(uiYear);
}

unsigned short cDate::getDay() const
{
    return m_usDay;
}

unsigned short cDate::getMonth() const
{
    return m_usMonth;
}

unsigned int cDate::getYear() const
{
    return m_uiYear;
}

std::string cDate::getDate() const
{
    return std::to_string(m_usDay) + "/" + std::to_string(m_usMonth) + "/" + std::to_string(m_uiYear);
}

std::ostream &operator<<(std::ostream &out, const cDate &date)
{
    out << date.m_usDay << "/" << date.m_usMonth << "/" << date.m_uiYear;
    return out;
}

std::istream &operator>>(std::istream &in, cDate &date)
{
    std::cout << "Enter date: " << std::endl;
    std::cout << "+ Day: ";
    in >> date.m_usDay;
    std::cout << "+ Month: ";
    in >> date.m_usMonth;
    std::cout << "+ Year: ";
    in >> date.m_uiYear;
    return in;
}
