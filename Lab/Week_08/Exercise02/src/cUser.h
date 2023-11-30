#pragma once

#include "cPlayList.h"
#include <fstream>
#include <sstream>

using std::string;

constexpr unsigned int VIP_PRICE = 10;

class cUser
{
private:
    string m_sUsername;             ///< Username of the user
    string m_sPassword;             ///< Password of the user
    double m_dBalance;              ///< Balance of the user
    vector<cPlayList> m_vPlayLists; ///< List of playlists
    bool m_bIsVip;                  ///< Is the user VIP?
    unsigned int m_uiVipMonths;     ///< Number of months the user has been VIP

public: // Constructors & Destructor
    cUser(const string &sUsername = "", const string &sPassword = "12345678", double dBalance = 0.0, const vector<cPlayList> &vPlayLists = vector<cPlayList>(), bool bIsVip = false, unsigned int uiVipMonths = 0);
    ~cUser() = default;

public: // Setters
    void setUsername(const string &sUsername);
    void setPassword(const string &sPassword);
    void setBalance(double dBalance);
    void setPlayLists(const vector<cPlayList> &vPlayLists);
    void setVip(bool bIsVip);
    void setVipMonths(unsigned int uiVipMonths);

public: // Getters
    string getUsername() const;
    string getPassword() const;
    double getBalance() const;
    const vector<cPlayList> &getPlayLists() const;
    bool isVip() const;
    unsigned int getVipMonths() const;

public: // Methods
    bool addPlayList(const string &sName);
    bool removePlayList(const string &sName);

    bool addSongToPlayList(const string &sPlayListName, cSong *pSong);
    bool removeSongFromPlayList(const string &sPlayListName, const cSong *pSong);
    bool extendVip(unsigned int uiMonths);
    bool payMonthlyFee();
    bool loadPlayLists(const string &sFileName);
    bool savePlayLists(const string &sFilePath) const;

private: // Methods
    bool buySong(const cSong *pSong);

public: // Output
    friend std::ostream &operator<<(std::ostream &os, const cUser &user);
};

/*
cUser
- string m_sUsername
- string m_sPassword
- double m_dBalance
- vector<cPlayList> m_vPlayLists
- bool m_bIsVip
- unsigned int m_uiVipMonths
+ cUser(const string &sUsername, const string &sPassword, double dBalance, const vector<cPlayList> &vPlayLists, bool bIsVip, unsigned int uiVipMonths)
+ ~cUser()
+ void setUsername(const string &sUsername)
+ void setPassword(const string &sPassword)
+ void setBalance(double dBalance)
+ void setPlayLists(const vector<cPlayList> &vPlayLists)
+ void setVip(bool bIsVip)
+ void setVipMonths(unsigned int uiVipMonths)
+ string getUsername() const
+ string getPassword() const
+ double getBalance() const
+ const vector<cPlayList> &getPlayLists() const
+ bool isVip() const
+ unsigned int getVipMonths() const
+ bool addPlayList(const string &sName)
+ bool removePlayList(const string &sName)
+ bool addSongToPlayList(const string &sPlayListName, cSong *pSong)
+ bool removeSongFromPlayList(const string &sPlayListName, const cSong *pSong)
+ bool extendVip(unsigned int uiMonths)
+ bool payMonthlyFee()
+ bool loadPlayLists(const string &sFileName)
+ bool savePlayLists(const string &sFilePath) const
- bool buySong(const cSong *pSong)
+ friend std::ostream &operator<<(std::ostream &os, const cUser &user)
*/