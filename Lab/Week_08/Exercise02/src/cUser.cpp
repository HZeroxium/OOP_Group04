#include "cUser.h"
#include "cDataManagement.h"
cUser::cUser(const string &sUsername, const string &sPassword, double dBalance, const vector<cPlayList> &vPlayLists, bool bIsVip, unsigned int uiVipMonths)
{
    setUsername(sUsername);
    setPassword(sPassword);
    setBalance(dBalance);
    setPlayLists(vPlayLists);
    setVip(bIsVip);
}

void cUser::setUsername(const string &sUsername)
{
    if (sUsername.length() == 0)
    {
        std::cerr << "Username cannot be empty" << std::endl;
        return;
    }
    m_sUsername = sUsername;
}

void cUser::setPassword(const string &sPassword)
{
    if (sPassword.length() < 8)
    {
        std::cerr << "Password must be at least 8 characters long" << std::endl;
        return;
    }
    for (const char c : sPassword)
    {
        if (c == ' ')
        {
            std::cerr << "Password cannot contain spaces" << std::endl;
            return;
        }
    }
    m_sPassword = sPassword;
}

void cUser::setBalance(double dBalance)
{
    if (dBalance < 0)
    {
        std::cerr << "Balance cannot be negative" << std::endl;
        return;
    }
    m_dBalance = dBalance;
}

void cUser::setPlayLists(const vector<cPlayList> &vPlayLists)
{
    m_vPlayLists = vPlayLists;
}

void cUser::setVip(bool bIsVip)
{
    m_bIsVip = bIsVip;
    if (!isVip())
    {
        m_uiVipMonths = 0;
    }
}

void cUser::setVipMonths(unsigned int uiVipMonths)
{
    if (!m_bIsVip && uiVipMonths > 0)
    {
        std::cerr << "User is not VIP" << std::endl;
        return;
    }
    m_uiVipMonths = uiVipMonths;
}

string cUser::getUsername() const
{
    return m_sUsername;
}

string cUser::getPassword() const
{
    return m_sPassword;
}

double cUser::getBalance() const
{
    return m_dBalance;
}

const vector<cPlayList> &cUser::getPlayLists() const
{
    return m_vPlayLists;
}

bool cUser::isVip() const
{
    return m_bIsVip;
}

unsigned int cUser::getVipMonths() const
{
    return m_uiVipMonths;
}

bool cUser::addPlayList(const string &sName)
{
    if (sName.length() == 0)
    {
        std::cerr << "Playlist name cannot be empty" << std::endl;
        return false;
    }
    for (const cPlayList &playList : m_vPlayLists)
    {
        if (playList.getName() == sName)
        {
            std::cerr << "Playlist with that name already exists" << std::endl;
            return false;
        }
    }
    m_vPlayLists.push_back(cPlayList(sName));
    return true;
}

bool cUser::removePlayList(const string &sName)
{
    if (sName.length() == 0)
    {
        std::cerr << "Playlist name cannot be empty" << std::endl;
        return false;
    }
    for (auto it = m_vPlayLists.begin(); it != m_vPlayLists.end(); ++it)
    {
        if (it->getName() == sName)
        {
            m_vPlayLists.erase(it);
            return true;
        }
    }
    std::cerr << "Playlist with that name does not exist" << std::endl;
    return false;
}

bool cUser::addSongToPlayList(const string &sPlayListName, cSong *pSong)
{
    if (sPlayListName.length() == 0)
    {
        std::cerr << "Playlist name cannot be empty" << std::endl;
        return false;
    }
    if (pSong == nullptr)
    {
        std::cerr << "Song cannot be null" << std::endl;
        return false;
    }
    for (cPlayList &playList : m_vPlayLists)
    {
        if (playList.getName() == sPlayListName)
        {
            if (playList.addSong(pSong))
            {
                buySong(pSong);
            }
            return true;
        }
    }
    std::cerr << "Playlist with that name does not exist" << std::endl;
    return false;
}

bool cUser::removeSongFromPlayList(const string &sPlayListName, const cSong *pSong)
{
    if (sPlayListName.length() == 0)
    {
        std::cerr << "Playlist name cannot be empty" << std::endl;
        return false;
    }
    if (pSong == nullptr)
    {
        std::cerr << "Song cannot be null" << std::endl;
        return false;
    }
    for (cPlayList &playList : m_vPlayLists)
    {
        if (playList.getName() == sPlayListName)
        {
            playList.removeSong(pSong);
            return true;
        }
    }
    std::cerr << "Playlist with that name does not exist" << std::endl;
    return false;
}

bool cUser::extendVip(unsigned int uiMonths)
{
    if (uiMonths == 0)
    {
        std::cerr << "Number of months cannot be 0" << std::endl;
        return false;
    }
    if (m_dBalance < VIP_PRICE * uiMonths)
    {
        std::cerr << "Not enough money" << std::endl;
        return false;
    }
    setVip(true);
    m_dBalance -= VIP_PRICE * uiMonths;
    m_uiVipMonths += uiMonths;
    return true;
}

bool cUser::payMonthlyFee()
{
    const float discount = isVip() ? 0.5f : 0.0f;
    double totalPayment = 0.0;
    for (const cPlayList &playList : m_vPlayLists)
    {
        totalPayment += playList.getTotalCost();
    }
    totalPayment *= (1.0f - discount);
    if (m_dBalance < totalPayment)
    {
        std::cerr << "Not enough money to pay monthly fee" << std::endl;
        for (cPlayList &playList : m_vPlayLists)
        {
            playList.removeCopyRightedSongs();
        }
        setVip(false);
        return false;
    }
    m_dBalance -= totalPayment;
    return true;
}

bool cUser::loadPlayLists(const string &sFileName)
{
    /*
    File format:
    <playlist_name1>:<song_name1>,<song_name2>,... (end with ,,)
    <playlist_name2>:<song_name1>,<song_name2>,... (end with ,,)
    ...
    */
    std::ifstream ifs(sFileName);
    if (!ifs.is_open())
    {
        std::cerr << "Load playlists: File " << sFileName << " could not be opened" << std::endl;
        return false;
    }
    string sLine;
    while (getline(ifs, sLine))
    {
        if (sLine.length() == 0)
        {
            break;
        }
        std::istringstream iss(sLine);
        string sPlayListName;
        getline(iss, sPlayListName, ':');
        if (sPlayListName.length() == 0)
        {
            std::cerr << "Playlist name cannot be empty" << std::endl;
            return false;
        }
        m_vPlayLists.push_back(cPlayList(sPlayListName));
        while (getline(iss, sLine, ','))
        {
            if (sLine.length() == 0)
            {
                break;
            }
            const auto pSong = cDataManagement::getInstance().getSong(sLine);
            if (pSong == nullptr)
            {
                std::cerr << "Song " << sLine << " does not exist" << std::endl;
                return false;
            }
            m_vPlayLists.back().addSong(pSong);
        }
    }
    ifs.close();
    return true;
}

bool cUser::savePlayLists(const string &sFilePath) const
{
    std::ofstream ofs(sFilePath);
    if (!ofs.is_open())
    {
        std::cerr << "Save PlayLists: File " << sFilePath << " could not be opened" << std::endl;
        return false;
    }
    for (const cPlayList &playList : m_vPlayLists)
    {
        ofs << playList.getName() << ":";
        for (const cSong *pSong : playList.getSongs())
        {
            ofs << pSong->getName() << ",";
        }
        ofs << "," << std::endl;
    }
    ofs.close();
    return true;
}

bool cUser::buySong(const cSong *pSong)
{
    if (pSong == nullptr)
    {
        std::cerr << "Song cannot be null" << std::endl;
        return false;
    }
    if (m_dBalance < pSong->getPrice())
    {
        std::cerr << "Not enough money to buy song " << pSong->getName() << std::endl;
        return false;
    }
    m_dBalance -= pSong->getPrice();
    return true;
}

std::ostream &operator<<(std::ostream &os, const cUser &user)
{
    os << "Username: " << user.getUsername() << std::endl;
    os << "Balance: " << user.getBalance() << std::endl;
    os << "VIP: " << (user.isVip() ? "Yes" : "No") << std::endl;
    os << "VIP Months: " << user.getVipMonths() << std::endl;
    os << "Playlists: " << std::endl;
    for (const cPlayList &playList : user.getPlayLists())
    {
        os << "+ " << playList.getName() << std::endl;
    }
    return os;
}