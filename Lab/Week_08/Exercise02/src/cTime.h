#pragma once

#include <iostream>
#include <string>

class cTime
{
private:
    unsigned int m_uiHour;   ///< Hour of the time
    unsigned int m_uiMinute; ///< Minute of the time
    unsigned int m_uiSecond; ///< Second of the time

public:
    cTime(unsigned int uiHour = 0, unsigned int uiMinute = 0, unsigned int uiSecond = 0);
    ~cTime() = default;

    void setHour(unsigned int uiHour);
    void setMinute(unsigned int uiMinute);
    void setSecond(unsigned int uiSecond);

    unsigned int getHour() const;
    unsigned int getMinute() const;
    unsigned int getSecond() const;

    std::string toString() const;

    friend std::ostream &operator<<(std::ostream &out, const cTime &time);
    friend std::istream &operator>>(std::istream &in, cTime &time);
};

/*
cTime
- unsigned int m_uiHour
- unsigned int m_uiMinute
- unsigned int m_uiSecond
+ cTime(unsigned int uiHour = 0, unsigned int uiMinute = 0, unsigned int uiSecond = 0)
+ ~cTime() = default
+ void setHour(unsigned int uiHour)
+ void setMinute(unsigned int uiMinute)
+ void setSecond(unsigned int uiSecond)
+ unsigned int getHour() const
+ unsigned int getMinute() const
+ unsigned int getSecond() const
+ std::string toString() const
+ friend std::ostream& operator<<(std::ostream& out, const cTime& time)
+ friend std::istream& operator>>(std::istream& in, cTime& time)
*/