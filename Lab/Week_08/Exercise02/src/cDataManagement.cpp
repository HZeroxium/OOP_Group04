#include "cDataManagement.h"
#include <fstream>
#include "cTime.h"
using std::cerr;
using std::endl;

cDataManagement &cDataManagement::getInstance()
{
    static cDataManagement instance;
    return instance;
}

const vector<cUser> &cDataManagement::getUsers() const
{
    return m_vUsers;
}

const vector<cSong> &cDataManagement::getSongs() const
{
    return m_vSongs;
}

cSong *cDataManagement::getSong(const string &sName) const
{
	const auto it = m_mSongs.find(sName);
    if (it == m_mSongs.end())
    {
        return nullptr;
    }
    return it->second;
}

bool cDataManagement::loadUsers(const string &sFileName)
{
    std::ifstream ifs(sFileName);
    if (!ifs.is_open())
    {
        return false;
    }

    string sLine;
    getline(ifs, sLine); // Skip the first line
    while (getline(ifs, sLine))
    {
        if (sLine.length() == 0)
        {
            break;
        }
        std::istringstream iss(sLine);
        string sUsername, sPassword, sBalance, sFilePlayLists;
        bool bIsVip;
        unsigned int uiVipMonths;
        char delimiter;
        getline(iss, sUsername, ',');
        getline(iss, sPassword, ',');
        getline(iss, sBalance, ',');
        iss >> bIsVip >> delimiter >> uiVipMonths >> delimiter;
        getline(iss, sFilePlayLists);

        // std::clog << "Username: " << sUsername << endl;
        // std::clog << "Password: " << sPassword << endl;
        // std::clog << "Balance: " << sBalance << endl;
        // std::clog << "IsVip: " << bIsVip << endl;
        // std::clog << "VipMonths: " << uiVipMonths << endl;
        // std::clog << "FilePlayLists: " << sFilePlayLists << endl;

        if (sUsername.length() == 0 || sPassword.length() == 0 || sBalance.length() == 0 || sFilePlayLists.length() == 0)
        {
            std::cerr << "Invalid user data" << std::endl;
            return false;
        }
        double dBalance = std::stod(sBalance);
        cUser user(sUsername, sPassword, dBalance, vector<cPlayList>(), bIsVip, uiVipMonths);
        if (!user.loadPlayLists(sFilePlayLists))
        {
            std::cerr << "Could not load playlists for user " << user.getUsername() << std::endl;
            return false;
        }
        m_vUsers.push_back(user);
    }
    ifs.close();
    return true;
}

bool cDataManagement::loadSongs(const string &sFileName)
{
    /*
    File format:
    Name,Artist,Genre,CreationYear,Duration,Views,Rating,Price,
    Hay Trao Cho Anh,Son Tung MTP,VPOP,2019,4:59,100000000,4.5,0,
    Lac Troi,Son Tung MTP,VPOP,2017,4:59,100000000,4.5,0.99,
    Chay Ngay Di,Son Tung MTP,VPOP,2018,4:59,100000000,4.5,0,
    Nguoi La Oi,Orange,VPOP,2019,4:59,100000000,4.5,0.99,
    Kill This Love,Black Pink,KPOP,2019,4:59,100000000,4.5,0.99,
    Ddu-Du Ddu-Du,Black Pink,KPOP,2018,4:59,100000000,4.5,0,
    Pink Venom,Black Pink,KPOP,2019,4:59,100000000,4.5,0,
    Shape of You,Ed Sheeran,USUK,2017,4:59,100000000,4.5,0.99,
    Perfect,Ed Sheeran,USUK,2017,4:59,100000000,4.5,0,
    Old Town Road,Lil Nas X,USUK,2019,4:59,100000000,4.5,0.99,
    */
    std::ifstream ifs(sFileName);
    if (!ifs.is_open())
    {
        std::cerr << "Load Songs: File " << sFileName << " could not be opened" << endl;
        return false;
    }
    string sLine;
    getline(ifs, sLine); // Skip the first line
    while (getline(ifs, sLine))
    {
        std::istringstream iss(sLine);
        string sName, sArtist, sGenre, sCreationYear, sViews, sRating, sPrice;
        cTime tDuration;
        char delimiter;
        getline(iss, sName, ',');
        getline(iss, sArtist, ',');
        getline(iss, sGenre, ',');
        getline(iss, sCreationYear, ',');
        iss >> tDuration >> delimiter;
        getline(iss, sViews, ',');
        getline(iss, sRating, ',');
        getline(iss, sPrice, ',');

        // std::clog << "Name: " << sName << endl;
        // std::clog << "Artist: " << sArtist << endl;
        // std::clog << "Genre: " << sGenre << endl;
        // std::clog << "CreationYear: " << sCreationYear << endl;
        // std::clog << "Duration: " << tDuration << endl;
        // std::clog << "Views: " << sViews << endl;
        // std::clog << "Rating: " << sRating << endl;
        // std::clog << "Price: " << sPrice << endl;

        if (sName.length() == 0 || sArtist.length() == 0 || sGenre.length() == 0 || sCreationYear.length() == 0 || sViews.length() == 0 || sRating.length() == 0 || sPrice.length() == 0)
        {
            std::cerr << "Invalid song data" << std::endl;
            return false;
        }
        unsigned int uiCreationYear = std::stoi(sCreationYear);
        unsigned int uiViews = std::stoi(sViews);
        float fRating = std::stof(sRating);
        double dPrice = std::stod(sPrice);
        cSong song = cSong(sName, sArtist, sGenre, uiCreationYear, tDuration, uiViews, fRating, dPrice);

        m_vSongs.push_back(song);
    }
    for (cSong &song : m_vSongs)
    {
        m_mSongs[song.getName()] = &song;
    }
    ifs.close();
    return true;
}

bool cDataManagement::saveUsers(const string &sFileName) const
{
    std::ofstream ofs(sFileName);
    if (!ofs.is_open())
    {
        std::cerr << "Save Users: File " << sFileName << " could not be opened" << std::endl;
        return false;
    }
    ofs << "Username,Password,Balance,Vip,VipMonths,PlayLists" << endl;
    constexpr char delimeter = ',';
    for (const cUser &user : m_vUsers)
    {
        ofs << user.getUsername() << delimeter << user.getPassword() << delimeter << user.getBalance() << delimeter << user.isVip() << delimeter << user.getVipMonths() << delimeter;
        const string sFilePath = "../data/users/" + user.getUsername() + ".txt";
        ofs << sFilePath << endl;
        if (!user.savePlayLists(sFilePath))
        {
            std::cerr << "Could not save playlists for user " << user.getUsername() << std::endl;
            return false;
        }
    }
    ofs.close();
    return true;
}

bool cDataManagement::saveSongs(const string &sFileName) const
{
    std::ofstream ofs(sFileName);
    if (!ofs.is_open())
    {
        std::cerr << "Save Songs: File " << sFileName << " could not be opened" << std::endl;
        return false;
    }
    ofs << "Name,Artist,Genre,CreationYear,Duration,Views,Rating,Price," << endl;
    for (const cSong &song : m_vSongs)
    {
        ofs << song.getName() << "," << song.getArtist() << "," << song.getGenre() << "," << song.getCreationYear() << ",";
        ofs << song.getDuration() << "," << song.getViews() << "," << song.getRating() << "," << song.getPrice() << "," << endl;
    }
    ofs.close();
    return true;
}

bool cDataManagement::loadData()
{
    if (!loadSongs("../data/songs.csv"))
    {
        std::cerr << "Could not load songs" << std::endl;
        return false;
    }
    if (!loadUsers("../data/users.csv"))
    {
        std::cerr << "Could not load users" << std::endl;
        return false;
    }
    return true;
}

bool cDataManagement::saveData() const
{
    if (!saveSongs("../data/songs.csv"))
    {
        std::cerr << "Could not save songs" << std::endl;
        return false;
    }
    if (!saveUsers("../data/users.csv"))
    {
        std::cerr << "Could not save users" << std::endl;
        return false;
    }
    return true;
}

bool cDataManagement::addUser(const cUser &user)
{
    // Check if user already exists
    for (const cUser &u : m_vUsers)
    {
        if (u.getUsername() == user.getUsername())
        {
            return false;
        }
    }
    m_vUsers.push_back(user);
    return true;
}