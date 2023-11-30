#include "cSong.h"

cSong::cSong(const string &sName, const string &sArtist, const string &sGenre, unsigned int uiCreationYear, const cTime &tDuration, unsigned long ulViews, float fRating, double dPrice, const cLyrics &lLyrics)
    : m_sName(sName), m_lLyrics(lLyrics), m_sArtist(sArtist), m_sGenre(sGenre), m_uiCreationYear(uiCreationYear), m_tDuration(tDuration), m_ulViews(ulViews), m_fRating(fRating), m_dPrice(dPrice)
{
}

void cSong::setName(const string &sName)
{
    m_sName = sName;
}

void cSong::setLyrics(const cLyrics &lLyrics)
{
    m_lLyrics = lLyrics;
}

void cSong::setArtist(const string &sArtist)
{
    m_sArtist = sArtist;
}

void cSong::setGenre(const string &sGenre)
{
    m_sGenre = sGenre;
}

void cSong::setCreationYear(unsigned int uiCreationYear)
{
    m_uiCreationYear = uiCreationYear;
}

void cSong::setDuration(const cTime &tDuration)
{
    m_tDuration = tDuration;
}

void cSong::setViews(unsigned long ulViews)
{
    m_ulViews = ulViews;
}

void cSong::setRating(float fRating)
{
    m_fRating = fRating;
}

void cSong::setPrice(double dPrice)
{
    m_dPrice = dPrice;
}

string cSong::getName() const
{
    return m_sName;
}

const cLyrics &cSong::getLyrics() const
{
    return m_lLyrics;
}

string cSong::getArtist() const
{
    return m_sArtist;
}

string cSong::getGenre() const
{
    return m_sGenre;
}

unsigned int cSong::getCreationYear() const
{
    return m_uiCreationYear;
}

cTime cSong::getDuration() const
{
    return m_tDuration;
}

unsigned long cSong::getViews() const
{
    return m_ulViews;
}

float cSong::getRating() const
{
    return m_fRating;
}

double cSong::getPrice() const
{
    return m_dPrice;
}

string cSong::getShortInfo() const
{
    return m_sName + " - " + m_sArtist;
}
string cSong::toString() const
{
    string sSong = "";
    sSong += "Name: " + m_sName + "\n";
    sSong += "Lyrics: " + m_lLyrics.toString() + "\n";
    sSong += "Artist: " + m_sArtist + "\n";
    sSong += "Genre: " + m_sGenre + "\n";
    sSong += "Creation Year: " + std::to_string(m_uiCreationYear) + "\n";
    sSong += "Duration: " + m_tDuration.toString() + "\n";
    sSong += "Views: " + std::to_string(m_ulViews) + "\n";
    sSong += "Rating: " + std::to_string(m_fRating) + "\n";
    sSong += "Price: " + std::to_string(m_dPrice) + "\n";
    return sSong;
}

void cSong::play() const
{
    std::cout << "Playing " + getShortInfo() << " ... " << std::endl;
}
std::ostream &operator<<(std::ostream &out, const cSong &s)
{
    out << s.toString();
    return out;
}

std::istream &operator>>(std::istream &in, cSong &s)
{
    string sName;
    cLyrics lLyrics;
    string sArtist;
    string sGenre;
    unsigned int uiCreationYear;
    cTime tDuration;
    unsigned long ulViews;
    float fRating;
    double dPrice;

    std::cout << "Name: ";
    std::getline(in, sName);
    std::cout << "Lyrics: ";
    in >> lLyrics;
    std::cout << "Artist: ";
    std::getline(in, sArtist);
    std::cout << "Genre: ";
    std::getline(in, sGenre);
    std::cout << "Creation Year: ";
    in >> uiCreationYear;
    std::cout << "Duration: ";
    in >> tDuration;
    std::cout << "Views: ";
    in >> ulViews;
    std::cout << "Rating: ";
    in >> fRating;
    std::cout << "Price: ";
    in >> dPrice;

    s.setName(sName);
    s.setLyrics(lLyrics);
    s.setArtist(sArtist);
    s.setGenre(sGenre);
    s.setCreationYear(uiCreationYear);
    s.setDuration(tDuration);
    s.setViews(ulViews);
    s.setRating(fRating);
    s.setPrice(dPrice);

    return in;
}
