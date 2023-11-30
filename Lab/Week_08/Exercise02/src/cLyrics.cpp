#include "cLyrics.h"

cLyrics::cLyrics(const std::vector<std::string> &vLyrics)
{
    m_vLyrics = vLyrics;
}

void cLyrics::setLyrics(const std::vector<std::string> &vLyrics)
{
    m_vLyrics = vLyrics;
}

const std::vector<std::string> &cLyrics::getLyrics() const
{
    return m_vLyrics;
}

std::string cLyrics::toString() const
{
    std::string sLyrics = "";
    for (const std::string &line : m_vLyrics)
    {
        sLyrics += line + "\n";
    }
    return sLyrics;
}

std::ostream &operator<<(std::ostream &out, const cLyrics &lyrics)
{
    out << lyrics.toString();
    return out;
}

std::istream &operator>>(std::istream &in, cLyrics &lyrics)
{
    std::string sLyrics = "";
    getline(in, sLyrics);
    std::vector<std::string> vLyrics;
    while (sLyrics != "")
    {
        vLyrics.push_back(sLyrics);
        getline(in, sLyrics);
    }
    lyrics.setLyrics(vLyrics);
    return in;
}