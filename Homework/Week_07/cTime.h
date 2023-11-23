#pragma once

#include <iostream>
#include <sstream>
#include <string>

class cTime
{
private: // Properties
    unsigned int m_uiHour;
    unsigned int m_uiMinute;
    unsigned int m_uiSecond;

public: // Constructors & Destructor
    cTime(unsigned int uiHour = 0, unsigned int uiMinute = 0, unsigned int uiSecond = 0);
    ~cTime();

public: // Getters
    unsigned int getHour() const;
    unsigned int getMinute() const;
    unsigned int getSecond() const;

public: // Setters
    void setHour(unsigned int uiHour);
    void setMinute(unsigned int uiMinute);
    void setSecond(unsigned int uiSecond);

public: // Conversions
    std::string toString() const;

public: // Input & Output
    friend std::ostream &operator<<(std::ostream &out, const cTime &time);
    friend std::istream &operator>>(std::istream &in, cTime &time);
};