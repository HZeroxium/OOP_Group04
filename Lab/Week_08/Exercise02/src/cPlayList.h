#pragma once

#include "cSong.h"

class cPlayList
{
private:                      // Attributes
    vector<cSong *> m_vSongs; ///< List of songs
    string m_sName;           ///< Name of the playlist

public: // Constructors & Destructor
    cPlayList(const string &sName = "", const vector<cSong *> &vSongs = vector<cSong *>());
    ~cPlayList();

public: // Setters
    void setName(const string &sName);

public: // Getters
    string getName() const;
    const vector<cSong *> &getSongs() const;

public: // Methods
    bool addSong(cSong *pSong);
    bool removeSong(const cSong *pSong);
    double getTotalCost() const;
    void removeCopyRightedSongs();

    string toString() const;

public: // Input & Output
    friend std::ostream &operator<<(std::ostream &out, const cPlayList &playList);
    friend std::istream &operator>>(std::istream &in, cPlayList &playList);
};

/*
cPlayList
- vector<cSong*> m_vSongs
- string m_sName
+ cPlayList(const string& sName = "", const vector<cSong*>& vSongs = vector<cSong*>())
+ ~cPlayList()
+ void setName(const string& sName)
+ string getName() const
+ const vector<cSong*>& getSongs() const
+ bool addSong(cSong* pSong)
+ bool removeSong(const cSong* pSong)
+ double getTotalCost() const
+ void removeCopyRightedSongs()
+ string toString() const
+ friend std::ostream& operator<<(std::ostream& out, const cPlayList& playList)
+ friend std::istream& operator>>(std::istream& in, cPlayList& playList)
*/