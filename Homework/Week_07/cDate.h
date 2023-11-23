#pragma once

#include <iostream>
#include <string>
#include <sstream>

class cDate
{
private:
    unsigned short m_usDay;
    unsigned short m_usMonth;
    unsigned int m_uiYear;

public:
    cDate(unsigned short usDay = 28, unsigned short usMonth = 8, unsigned int uiYear = 2004);
    ~cDate();

    void setDay(unsigned short usDay);
    void setMonth(unsigned short usMonth);
    void setYear(unsigned int uiYear);
    void setDate(unsigned short usDay, unsigned short usMonth, unsigned int uiYear);

    unsigned short getDay() const;
    unsigned short getMonth() const;
    unsigned int getYear() const;
    std::string toString() const;

    friend std::ostream &operator<<(std::ostream &out, const cDate &date);
    friend std::istream &operator>>(std::istream &in, cDate &date);

    static bool isValidDate(unsigned short usDay, unsigned short usMonth, unsigned int uiYear);
};
