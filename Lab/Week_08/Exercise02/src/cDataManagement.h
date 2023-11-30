#pragma once

#include "cUser.h"
#include "cSong.h"

#include <map>
using std::map;
// Singleton class
class cDataManagement
{
private:
    cDataManagement() = default;
    ~cDataManagement() = default;
    vector<cUser> m_vUsers;
    vector<cSong> m_vSongs;
    map<string, cSong *> m_mSongs;

public: // Delete copy constructor and assignment operator
    cDataManagement(const cDataManagement &) = delete;
    cDataManagement &operator=(const cDataManagement &) = delete;

public: // Getters
    static cDataManagement &getInstance();
    const vector<cUser> &getUsers() const;
    const vector<cSong> &getSongs() const;
    cSong *getSong(const string &sName) const;

private: // Loader helpers
    bool loadUsers(const string &sFileName);
    bool loadSongs(const string &sFileName);

public: // Loader
    bool loadData();

private: // Saver helpers
    bool saveUsers(const string &sFilePath) const;
    bool saveSongs(const string &sFilePath) const;

public: // Saver
    bool saveData() const;

public: // Methods
    bool addUser(const cUser &user);
};

/*
cDataManagement
- vector<cUser> m_vUsers
- vector<cSong> m_vSongs
- cDataManagement()
- ~cDataManagement()
+ static cDataManagement& getInstance()
+ const vector<cUser>& getUsers() const
+ const vector<cSong>& getSongs() const
+ cSong* getSong(const string& sName) const
- bool loadUsers(const string& sFileName)
- bool loadSongs(const string& sFileName)
+ bool loadData()
- bool saveUsers(const string& sFilePath) const
- bool saveSongs(const string& sFilePath) const
+ bool saveData() const
+ bool addUser(const cUser& user)
*/
