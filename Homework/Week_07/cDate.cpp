#include "cDate.h"

cDate::cDate(unsigned short usDay, unsigned short usMonth, unsigned int usYear)
{
    setDate(usDay, usMonth, usYear);
}

cDate::~cDate() = default;

void cDate::setDay(unsigned short usDay)
{
    if (usDay > 0 && usDay < 32)
        m_usDay = usDay;
    else
    {
        m_usDay = 0;
        std::cerr << "Invalid day" << std::endl;
    }
}

void cDate::setMonth(unsigned short usMonth)
{
    if (usMonth > 0 && usMonth < 13)
        m_usMonth = usMonth;
    else
    {
        m_usMonth = 0;
        std::cerr << "Invalid month" << std::endl;
    }
}

void cDate::setYear(unsigned int uiYear)
{
    if (uiYear > 0)
        m_uiYear = uiYear;
    else
    {
        m_uiYear = 0;
        std::cerr << "Invalid year" << std::endl;
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

std::string cDate::toString() const
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
    std::string sDate;
    std::getline(in, sDate);
    std::stringstream ss(sDate);

    std::string token = "";

    std::getline(ss, token, '/');
    date.setDay(static_cast<unsigned short>(std::stoi(token)));
    std::getline(ss, token, '/');
    date.setMonth(static_cast<unsigned short>(std::stoi(token)));
    std::getline(ss, token);
    date.setYear(static_cast<unsigned int>(std::stoi(token)));

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