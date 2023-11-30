#include "cTime.h"

cTime::cTime(unsigned int uiHour, unsigned int uiMinute, unsigned int uiSecond)
{
    setHour(uiHour);
    setMinute(uiMinute);
    setSecond(uiSecond);
}

void cTime::setHour(unsigned int uiHour)
{
    if (uiHour > 23 || uiHour < 0)
    {
        m_uiHour = 0;
    }
    else
    {
        m_uiHour = uiHour;
    }
}

void cTime::setMinute(unsigned int uiMinute)
{
    if (uiMinute > 59 || uiMinute < 0)
    {
        m_uiMinute = 0;
    }
    else
    {
        m_uiMinute = uiMinute;
    }
}

void cTime::setSecond(unsigned int uiSecond)
{
    if (uiSecond > 59 || uiSecond < 0)
    {
        m_uiSecond = 0;
    }
    else
    {
        m_uiSecond = uiSecond;
    }
}

unsigned int cTime::getHour() const
{
    return m_uiHour;
}

unsigned int cTime::getMinute() const
{
    return m_uiMinute;
}

unsigned int cTime::getSecond() const
{
    return m_uiSecond;
}

std::string cTime::toString() const
{
    std::string sTime = "";

    if (m_uiHour < 10)
    {
        sTime += "0";
    }
    sTime += std::to_string(m_uiHour) + ":";

    if (m_uiMinute < 10)
    {
        sTime += "0";
    }
    sTime += std::to_string(m_uiMinute) + ":";

    if (m_uiSecond < 10)
    {
        sTime += "0";
    }
    sTime += std::to_string(m_uiSecond);

    return sTime;
}

std::ostream &operator<<(std::ostream &out, const cTime &time)
{
    out << time.toString();
    return out;
}

std::istream &operator>>(std::istream &in, cTime &time)
{
    unsigned int uiHour, uiMinute, uiSecond;
    char cColon;

    in >> uiHour >> cColon >> uiMinute >> cColon >> uiSecond;

    time.setHour(uiHour);
    time.setMinute(uiMinute);
    time.setSecond(uiSecond);

    return in;
}