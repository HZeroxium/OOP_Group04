#include "cPlayList.h"
#include <sstream>

cPlayList::cPlayList(const string &sName, const vector<cSong *> &vSongs)
    : m_sName(sName), m_vSongs(vSongs)
{
}

cPlayList::~cPlayList()
{
    for (auto &song : m_vSongs)
    {
        song = nullptr;
    }
}

void cPlayList::setName(const string &sName)
{
    m_sName = sName;
}

string cPlayList::getName() const
{
    return m_sName;
}

const vector<cSong *> &cPlayList::getSongs() const
{
    return m_vSongs;
}

bool cPlayList::addSong(cSong *pSong)
{
    // Check if the song is already in the playlist
    for (const auto &song : m_vSongs)
    {
        if (song == pSong)
        {
            return false;
        }
    }
    m_vSongs.push_back(pSong);
    return true;
}

bool cPlayList::removeSong(const cSong *pSong)
{
    // Check if the song is in the playlist
    for (auto it = m_vSongs.begin(); it != m_vSongs.end(); ++it)
    {
        if (*it == pSong)
        {
            m_vSongs.erase(it);
            return true;
        }
    }
    return false;
}

double cPlayList::getTotalCost() const
{
    double totalCost = 0;
    for (auto &song : m_vSongs)
    {
        totalCost += song->getPrice();
    }
    return totalCost;
}

void cPlayList::removeCopyRightedSongs()
{
    // Remove all songs that price is greater than 0
    for (auto it = m_vSongs.begin(); it != m_vSongs.end(); ++it)
    {
        if ((*it)->getPrice() > 0)
        {
            m_vSongs.erase(it);
        }
    }
}

string cPlayList::toString() const
{
    std::stringstream ss;
    ss << "Playlist: " << m_sName << std::endl;
    for (auto &song : m_vSongs)
    {
        ss << song->getShortInfo() << std::endl;
    }
    return ss.str();
}

std::ostream &operator<<(std::ostream &out, const cPlayList &playList)
{
    out << playList.toString();
    return out;
}
