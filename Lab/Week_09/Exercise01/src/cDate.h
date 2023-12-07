#pragma once

#include <iostream>
#include <string>

class cDate
{
private: // Attributes
    unsigned short m_usDay;
    unsigned short m_usMonth;
    unsigned int m_uiYear;

public: // Constructors & Destructor
    cDate(unsigned short usDay = 0, unsigned short usMonth = 0, unsigned int uiYear = 0);
    ~cDate() = default;

public: // Setters
    void setDay(unsigned short usDay);
    void setMonth(unsigned short usMonth);
    void setYear(unsigned int uiYear);
    void setDate(unsigned short usDay, unsigned short usMonth, unsigned int uiYear);

public: // Getters
    unsigned short getDay() const;
    unsigned short getMonth() const;
    unsigned int getYear() const;
    std::string getDate() const;

public: // Input & Output
    friend std::ostream &operator<<(std::ostream &out, const cDate &date);
    friend std::istream &operator>>(std::istream &in, cDate &date);
};

/**
cDate
- m_usDay: unsigned short
- m_usMonth: unsigned short
- m_uiYear: unsigned int
+ cDate(usDay: unsigned short = 0, usMonth: unsigned short = 0, uiYear: unsigned int = 0)
+ ~cDate()
+ setDay(usDay: unsigned short): void
+ setMonth(usMonth: unsigned short): void
+ setYear(uiYear: unsigned int): void
+ setDate(usDay: unsigned short, usMonth: unsigned short, uiYear: unsigned int): void
+ getDay(): unsigned short
+ getMonth(): unsigned short
+ getYear(): unsigned int
+ getDate(): std::string
+ friend operator<<(out: std::ostream&, date: cDate&): std::ostream&
+ friend operator>>(in: std::istream&, date: cDate&): std::istream&
+ static isValidDate(usDay: unsigned short, usMonth: unsigned short, uiYear: unsigned int): bool
 */