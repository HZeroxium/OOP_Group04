#include "cTime.h"

cTime::cTime(unsigned int uiHour, unsigned int uiMinute, unsigned int uiSecond)
{
    setHour(uiHour);
    setMinute(uiMinute);
    setSecond(uiSecond);
}

cTime::~cTime() = default;

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

void cTime::setHour(unsigned int uiHour)
{
    if (uiHour < 24)
        m_uiHour = uiHour;
    else
    {
        m_uiHour = 0;
        std::cerr << "Invalid hour" << std::endl;
    }
}

void cTime::setMinute(unsigned int uiMinute)
{
    if (uiMinute < 60)
        m_uiMinute = uiMinute;
    else
    {
        m_uiMinute = 0;
        std::cerr << "Invalid minute" << std::endl;
    }
}

void cTime::setSecond(unsigned int uiSecond)
{
    if (uiSecond < 60)
        m_uiSecond = uiSecond;
    else
    {
        m_uiSecond = 0;
        std::cerr << "Invalid second" << std::endl;
    }
}

std::string cTime::toString() const
{
    std::string result = "";
    if (m_uiHour < 10)
        result += "0";
    result += std::to_string(m_uiHour) + ":";
    if (m_uiMinute < 10)
        result += "0";
    result += std::to_string(m_uiMinute) + ":";
    if (m_uiSecond < 10)
        result += "0";
    result += std::to_string(m_uiSecond);
    return result;
}

std::ostream &operator<<(std::ostream &out, const cTime &time)
{
    out << time.toString() << std::endl;
    return out;
}

std::istream &operator>>(std::istream &in, cTime &time)
{
    std::string input;
    std::getline(in, input);

    std::stringstream ss(input);

    std::string token;
    unsigned int uiHour, uiMinute, uiSecond;

    std::getline(ss, token, ':');
    uiHour = std::stoi(token);
    std::getline(ss, token, ':');
    uiMinute = std::stoi(token);
    std::getline(ss, token, ':');
    uiSecond = std::stoi(token);

    time.setHour(uiHour);
    time.setMinute(uiMinute);
    time.setSecond(uiSecond);

    return in;
}