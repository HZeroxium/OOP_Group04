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
    if (isValidDate(usDay, m_usMonth, m_uiYear))
        m_usDay = usDay;
    else
    {
        std::cout << "Invalid date" << std::endl;
    }
}

void cDate::setMonth(unsigned short usMonth)
{
    if (isValidDate(m_usDay, usMonth, m_uiYear))
        m_usMonth = usMonth;
    else
    {
        std::cout << "Invalid date" << std::endl;
    }
}

void cDate::setYear(unsigned int uiYear)
{
    if (isValidDate(m_usDay, m_usMonth, uiYear))
        m_uiYear = uiYear;
    else
    {
        std::cout << "Invalid date" << std::endl;
    }
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

bool cDate::isValidDate(unsigned short usDay, unsigned short usMonth, unsigned int uiYear)
{
    if (usDay < 1 || usDay > 31)
    {
        return false;
    }
    if (usMonth < 1 || usMonth > 12)
    {
        return false;
    }
    if (uiYear < 0)
    {
        return false;
    }
    if (usMonth == 2)
    {
        if (uiYear % 4 == 0)
        {
            if (usDay > 29)
            {
                return false;
            }
        }
        else
        {
            if (usDay > 28)
            {
                return false;
            }
        }
    }
    if (usMonth == 4 || usMonth == 6 || usMonth == 9 || usMonth == 11)
    {
        if (usDay > 30)
        {
            return false;
        }
    }
    return true;
}