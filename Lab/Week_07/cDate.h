#pragma once

#include <iostream>
#include <string>

class cDate
{
private:
    unsigned short m_usDay;
    unsigned short m_usMonth;
    unsigned int m_uiYear;

public:
    cDate(unsigned short usDay = 0, unsigned short usMonth = 0, unsigned int uiYear = 0);
    ~cDate();

    void setDay(unsigned short usDay);
    void setMonth(unsigned short usMonth);
    void setYear(unsigned int uiYear);
    void setDate(unsigned short usDay, unsigned short usMonth, unsigned int uiYear);

    unsigned short getDay() const;
    unsigned short getMonth() const;
    unsigned int getYear() const;
    std::string getDate() const;

    friend std::ostream &operator<<(std::ostream &out, const cDate &date);
    friend std::istream &operator>>(std::istream &in, cDate &date);
};