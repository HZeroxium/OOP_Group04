#pragma once

#include "cUser.h"
#include "cSong.h"

class cMusicApp
{
private:
    cUser *m_pCurrentUser; ///< Current user
    cSong *m_pCurrentSong; ///< Current song

private: // Constructors & Destructor
    cMusicApp();
    ~cMusicApp();

public: // Singleton
    static cMusicApp &getInstance();

public: // Methods
    bool login(const string &sUsername, const string &sPassword);
    bool logout();
    static bool registerUser(const string &sUsername, const string &sPassword);

    static void displayTop5SongsByViews();
    static void displayTop5SongsByViews(const string &sGenre);

    void extendVip() const;

    void addSongToPlayList() const;
    void removeSongFromPlayList() const;
    void addPlayList() const;
    void removePlayList() const;

    void displayPlayLists() const;
    void displaySongsInPlayList() const;

    void playSong();
    void runAppService();

    void run();
};

/*
cMusicApp
- cUser* m_pCurrentUser
- cSong* m_pCurrentSong
+ cMusicApp()
+ ~cMusicApp()
+ static cMusicApp& getInstance()
+ bool login(const string& sUsername, const string& sPassword)
+ bool logout()
+ static bool registerUser(const string& sUsername, const string& sPassword)
+ static void displayTop5SongsByViews()
+ static void displayTop5SongsByViews(const string& sGenre)
+ void extendVip() const
+ void addSongToPlayList() const
+ void removeSongFromPlayList() const
+ void addPlayList() const
+ void removePlayList() const
+ void displayPlayLists() const
+ void displaySongsInPlayList() const
+ void playSong()
+ void runAppService()
+ void run()
*/
