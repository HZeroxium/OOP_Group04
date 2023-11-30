#pragma once

#include <string>
#include "cTime.h"
#include "cLyrics.h"
#include <vector>

using std::string;
using std::vector;

class cSong
{
private:                           // Attributes
    string m_sName;                ///< Name of the song
    cLyrics m_lLyrics;             ///< Lyrics of the song
    string m_sArtist;              ///< Name of the artist
    string m_sGenre;               ///< Name of the genre
    unsigned int m_uiCreationYear; ///< Year of creation
    cTime m_tDuration;             ///< Duration of the song
    unsigned long m_ulViews;       ///< Number of views
    float m_fRating;               ///< Rating of the song
    double m_dPrice;               ///< Price of the song

public: // Constructors & Destructor
    cSong(const string &sName = "", const string &sArtist = "", const string &sGenre = "", unsigned int uiCreationYear = 0, const cTime &tDuration = cTime(), unsigned long ulViews = 0, float fRating = 0.0f, double dPrice = 0.0, const cLyrics &vLyrics = cLyrics());
    ~cSong() = default;

public: // Setters
    void setName(const string &sName);
    void setLyrics(const cLyrics &vLyrics);
    void setArtist(const string &sArtist);
    void setGenre(const string &sGenre);
    void setCreationYear(unsigned int uiCreationYear);
    void setDuration(const cTime &tDuration);
    void setViews(unsigned long ulViews);
    void setRating(float fRating);
    void setPrice(double dPrice);

public: // Getters
    string getName() const;
    const cLyrics &getLyrics() const;
    string getArtist() const;
    string getGenre() const;
    unsigned int getCreationYear() const;
    cTime getDuration() const;
    unsigned long getViews() const;
    float getRating() const;
    double getPrice() const;

    string getShortInfo() const;

public: // Methods
    string toString() const;
    void play() const;

public: // Input & Output
    friend std::ostream &operator<<(std::ostream &out, const cSong &song);
    friend std::istream &operator>>(std::istream &in, cSong &song);
};

/*
cSong
- string m_sName
- cLyrics m_lLyrics
- string m_sArtist
- string m_sGenre
- unsigned int m_uiCreationYear
- cTime m_tDuration
- unsigned long m_ulViews
- float m_fRating
- double m_dPrice
+ cSong(const string& sName = "", const string& sArtist = "", const string& sGenre = "", unsigned int uiCreationYear = 0, const cTime& tDuration = cTime(), unsigned long ulViews = 0, float fRating = 0.0f, double dPrice = 0.0, const cLyrics& vLyrics = cLyrics())
+ ~cSong() = default
+ void setName(const string& sName)
+ void setLyrics(const cLyrics& vLyrics)
+ void setArtist(const string& sArtist)
+ void setGenre(const string& sGenre)
+ void setCreationYear(unsigned int uiCreationYear)
+ void setDuration(const cTime& tDuration)
+ void setViews(unsigned long ulViews)
+ void setRating(float fRating)
+ void setPrice(double dPrice)
+ string getName() const
+ const cLyrics& getLyrics() const
+ string getArtist() const
+ string getGenre() const
+ unsigned int getCreationYear() const
+ cTime getDuration() const
+ unsigned long getViews() const
+ float getRating() const
+ double getPrice() const
+ string getShortInfo() const
+ string toString() const
+ void play() const
+ friend std::ostream& operator<<(std::ostream& out, const cSong& song)
+ friend std::istream& operator>>(std::istream& in, cSong& song)
*/