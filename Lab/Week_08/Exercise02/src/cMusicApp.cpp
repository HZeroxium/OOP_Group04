#include "cMusicApp.h"
#include <algorithm>
#include "cDataManagement.h"
using std::cin;
using std::cout;
using std::endl;
using std::sort;

cMusicApp::cMusicApp()
{
    m_pCurrentUser = nullptr;
    m_pCurrentSong = nullptr;
}

cMusicApp::~cMusicApp()
{
    m_pCurrentSong = nullptr;
    m_pCurrentUser = nullptr;
}

cMusicApp& cMusicApp::getInstance()
{
    static cMusicApp instance;
    return instance;
}
bool cMusicApp::login(const string& sUsername, const string& sPassword)
{
    // Find user by username
    for (const auto& user : cDataManagement::getInstance().getUsers()) {
        if (user.getUsername() == sUsername) {
            // Check if password is correct
            if (user.getPassword() == sPassword) {
                cUser* pUser = const_cast<cUser*>(&user);
                m_pCurrentUser = pUser;
                cout << "User " << user.getUsername() << " logged in!" << endl;
                return true;
            }
            else {
                cout << "Incorrect password!" << endl;
                return false;
            }
        }
    }
    cout << "User with username " << sUsername << " does not exist!" << endl;
    return false;
}

bool cMusicApp::logout()
{
    if (m_pCurrentUser != nullptr) {
        cout << "User " << m_pCurrentUser->getUsername() << " logged out!" << endl;
        m_pCurrentUser = nullptr;
        m_pCurrentSong = nullptr;
        return true;
    }
    else {
        cout << "No user is currently logged in!" << endl;
        return false;
    }
}

bool cMusicApp::registerUser(const string& sUsername, const string& sPassword)
{
    // Check if user already exists
    for (auto user : cDataManagement::getInstance().getUsers()) {
        if (user.getUsername() == sUsername) {
            cout << "User with username " << sUsername << " already exists!" << endl;
            return false;
        }
    }
    // Check if password is valid
    if (sPassword.length() < 8) {
        cout << "Password must be at least 8 characters long!" << endl;
        return false;
    }
    // Create new user
    const cUser newUser(sUsername, sPassword);

    // Add user to database
    if (!cDataManagement::getInstance().addUser(newUser)) {
        cout << "User " << newUser.getUsername() << " could not be registered!" << endl;
        return false;
    }
    cout << "User " << newUser.getUsername() << " registered!" << endl;
    return true;
}

void cMusicApp::displayTop5SongsByViews()
{
    // Sort songs by views
    vector<cSong> vSortedSongs = cDataManagement::getInstance().getSongs();
    sort(vSortedSongs.begin(), vSortedSongs.end(), [](const cSong& s1, const cSong& s2) { return s1.getViews() > s2.getViews(); });

    // Display top 5 songs
    cout << "Top 5 songs by views:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << i + 1 << ". " << vSortedSongs[i].getShortInfo() << endl;
    }
}

void cMusicApp::displayTop5SongsByViews(const string& genre)
{
    // Sort songs by views
    vector<cSong> vSortedSongs;
    for (const cSong& song : cDataManagement::getInstance().getSongs()) {
        if (song.getGenre() == genre) {
            vSortedSongs.push_back(song);
        }
    }
    sort(vSortedSongs.begin(), vSortedSongs.end(), [](const cSong& s1, const cSong& s2) { return s1.getViews() > s2.getViews(); });

    // Display top 5 songs
    cout << "Top 5 songs by views:" << endl;
    for (int i = 0; i < 5; i++) {
        if (vSortedSongs[i].getGenre() == genre) {
            cout << i + 1 << ". " << vSortedSongs[i].getName() << " - " << vSortedSongs[i].getArtist() << endl;
        }
    }
}

void cMusicApp::extendVip() const
{
    unsigned int uiMonths;

    cout << "Enter number of months you want to extend VIP: ";
    std::cin >> uiMonths;
    std::cin.ignore();

    if (m_pCurrentUser->extendVip(uiMonths))
        cout << "User " << m_pCurrentUser->getUsername() << " extended VIP!" << endl;
    else {
        cout << "User " << m_pCurrentUser->getUsername() << " could not extend VIP!" << endl;
    }
}

void cMusicApp::addSongToPlayList() const
{

    // Get song Name
    string sName;
    string sPlayListName;
    cout << "Enter song name: ";
    getline(cin, sName);
    cout << "Enter playlist name: ";
    getline(cin, sPlayListName);

    // Find song by Name
    for (const cSong& song : cDataManagement::getInstance().getSongs()) {
        if (song.getName() == sName) {
            // Add song to playlist
            cSong* pSong = const_cast<cSong*>(&song);
            m_pCurrentUser->addSongToPlayList(sPlayListName, pSong);
            cout << "Song " << song.getName() << " added to playlist!" << endl;
            return;
        }
    }
    cout << "Song with Name " << sName << " does not exist!" << endl;
}

void cMusicApp::removeSongFromPlayList() const
{
    // Get song Name
    string sName;
    string sPlayListName;
    cout << "Enter song name: ";
    getline(cin, sName);
    cout << "Enter playlist name: ";
    getline(cin, sPlayListName);

    // Find song by Name
    for (const cSong& song : cDataManagement::getInstance().getSongs()) {
        if (song.getName() == sName) {
            // Remove song from playlist
            cSong* pSong = const_cast<cSong*>(&song);
            m_pCurrentUser->removeSongFromPlayList(sPlayListName, pSong);
            cout << "Song " << song.getName() << " removed from playlist!" << endl;
            return;
        }
    }
    cout << "Song with Name " << sName << " does not exist!" << endl;
}

void cMusicApp::addPlayList() const
{
    // Get playlist Name
    string sName;
    cout << "Enter playlist name: ";
    getline(cin, sName);

    // Add playlist
    if (m_pCurrentUser->addPlayList(sName))
        cout << "Playlist " << sName << " added!" << endl;
    else {
        cout << "Playlist " << sName << " could not be added!" << endl;
    }
}

void cMusicApp::removePlayList() const
{
    // Get playlist Name
    string sName;
    cout << "Enter playlist name: ";
    getline(cin, sName);

    // Remove playlist
    if (m_pCurrentUser->removePlayList(sName))
        cout << "Playlist " << sName << " removed!" << endl;
    else {
        cout << "Playlist " << sName << " could not be removed!" << endl;
    }
}

void cMusicApp::displayPlayLists() const
{
    // Display playlists
    cout << "Playlists:" << endl;
    for (const cPlayList& playList : m_pCurrentUser->getPlayLists()) {
        cout << playList.getName() << endl;
    }
}

void cMusicApp::displaySongsInPlayList() const
{
    // Get playlist Name
    string sName;
    cout << "Enter playlist name: ";
    getline(cin, sName);

    // Display songs in playlist
    for (const cPlayList& playList : m_pCurrentUser->getPlayLists()) {
        if (playList.getName() == sName) {
            cout << playList << endl;
        }
    }
    cout << "Playlist with name " << sName << " does not exist!" << endl;
}

void cMusicApp::playSong()
{
    // Get song Name
    string sName;
    cout << "Enter song name: ";
    getline(cin, sName);

    // Find song by Name
    for (const cSong& song : cDataManagement::getInstance().getSongs()) {
        if (song.getName() == sName) {
            // Play song
            m_pCurrentSong = const_cast<cSong*>(&song);
            m_pCurrentSong->play();
            return;
        }
    }
    cout << "Song with Name " << sName << " does not exist!" << endl;
}

void cMusicApp::runAppService()
{
    while (true) {
        cout << "======================================================================" << endl;
        cout << "============================ APP SERVICE =============================" << endl;
        cout << "======================================================================" << endl;
        cout << "1. Pay monthly subscription" << endl;
        cout << "2. Extend VIP" << endl;
        cout << "3. Add song to playlist" << endl;
        cout << "4. Remove song from playlist" << endl;
        cout << "5. Add playlist" << endl;
        cout << "6. Remove playlist" << endl;
        cout << "7. Display playlists" << endl;
        cout << "8. Display songs in playlist" << endl;
        cout << "9. Play song" << endl;
        cout << "10. Top 5 songs by views" << endl;
        cout << "11. Top 5 songs by views in genre" << endl;
        cout << "12. Show account info" << endl;
        cout << "0. Logout" << endl;
        cout << "======================================================================" << endl;
        cout << "Enter option: ";
        int option;
        cin >> option;
        cin.ignore();
        if (option == 0) {
            cout << "Logout successful!" << endl;
            logout();
            return;
        }
        if (option < 1 || option > 12) {
            cout << "Invalid option!" << endl;
            continue;
        }
        switch (option) {
            case 1:
            {
                if (m_pCurrentUser->payMonthlyFee())
                    cout << "Monthly fee paid!" << endl;
                else {
                    cout << "Monthly fee could not be paid!" << endl;
                }
                break;
            }
            case 2:
            {
                extendVip();
                break;
            }
            case 3:
            {
                addSongToPlayList();
                break;
            }
            case 4:
            {
                removeSongFromPlayList();
                break;
            }
            case 5:
            {
                addPlayList();
                break;
            }
            case 6:
            {
                removePlayList();
                break;
            }
            case 7:
            {
                displayPlayLists();
                break;
            }
            case 8:
            {
                displaySongsInPlayList();
                break;
            }
            case 9:
            {
                playSong();
                break;
            }
            case 10:
            {
                displayTop5SongsByViews();
                break;
            }
            case 11:
            {
                if (!m_pCurrentUser->isVip()) {
                    cout << "You must be VIP to use this feature!" << endl;
                    break;
                }
                string sGenre;
                cout << "Enter genre: ";
                getline(cin, sGenre);
                displayTop5SongsByViews(sGenre);
                break;
            }
            case 12:
            {
                cout << *m_pCurrentUser << endl;
                break;
            }
            default:
                break;
        }
    }
}

void cMusicApp::run()
{
    // First, login or register
    while (true) {
        cout << "======================================================================" << endl;
        cout << "============================ MUSIC APP ===============================" << endl;
        cout << "======================================================================" << endl;
        cout << "1. Login" << endl;
        cout << "2. Register" << endl;
        cout << "0. Exit" << endl;
        cout << "======================================================================" << endl;
        cout << "Enter option: ";
        int option;
        cin >> option;
        cin.ignore();
        if (option == 0) {
            cout << "Exiting..." << endl;
            return;
        }
        if (option < 1 || option > 2) {
            cout << "Invalid option!" << endl;
            continue;
        }
        string sUsername;
        string sPassword;
        cout << "Enter username: ";
        getline(cin, sUsername);
        cout << "Enter password: ";
        getline(cin, sPassword);
        if (option == 1) {
            if (login(sUsername, sPassword)) {
                runAppService();
            }
        }
        else {
            if (registerUser(sUsername, sPassword)) {
                continue;
            }
        }
    }
}