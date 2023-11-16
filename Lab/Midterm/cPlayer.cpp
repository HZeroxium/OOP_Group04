#include "cPlayer.h"

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////// CONSTRUCTORS - DESTRUCTORS //////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

cPlayer::cPlayer()
{
    m_uLevel = 1;
    m_uMoney = 1000;
    m_uEnergy = 100;
    m_pFarm = nullptr;
}

cPlayer::cPlayer(const cPlayer &player)
{
    m_uLevel = player.m_uLevel;
    m_uMoney = player.m_uMoney;
    m_uEnergy = player.m_uEnergy;
    m_pFarm = new cFarm(*player.m_pFarm);
    for (unsigned int i = 0; i < player.m_vCrops.size(); i++)
    {
        m_vCrops.push_back(new cCrop(*player.m_vCrops[i]));
    }
}

cPlayer::~cPlayer()
{
    for (unsigned int i = 0; i < m_vCrops.size(); i++)
    {
        delete m_vCrops[i];
    }
    m_vCrops.clear();
    delete m_pFarm;
    m_pFarm = nullptr;
    m_uLevel = m_uMoney = m_uEnergy = 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////// GETTERS /////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

vector<cCrop *> cPlayer::getCrops() const
{
    return m_vCrops;
}

vector<cPet *> cPlayer::getPets() const
{
    return m_vPets;
}

cFarm *cPlayer::getFarm() const
{
    return m_pFarm;
}

unsigned int cPlayer::getLevel() const
{
    return m_uLevel;
}

unsigned int cPlayer::getMoney() const
{
    return m_uMoney;
}

unsigned int cPlayer::getEnergy() const
{
    return m_uEnergy;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////// SETTERS /////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void cPlayer::setCrops(const vector<cCrop *> &vCrops)
{
    m_vCrops = vCrops;
}

void cPlayer::setPets(const vector<cPet *> &vPets)
{
    m_vPets = vPets;
}

void cPlayer::setFarm(cFarm *pFarm)
{
    m_pFarm = pFarm;
}

void cPlayer::setLevel(unsigned int uLevel)
{
    m_uLevel = uLevel;
}

void cPlayer::setMoney(unsigned int uMoney)
{
    m_uMoney = uMoney;
}

void cPlayer::setEnergy(unsigned int uEnergy)
{
    m_uEnergy = uEnergy;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////// METHODS /////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void cPlayer::plantCrop(unsigned int x, unsigned int y)
{
    if (m_uEnergy < 10)
    {
        cout << "Not enough energy to plant a crop!" << endl;
        return;
    }
    if (m_pFarm->isAvailable(x, y))
    {
        cCrop *pCrop = new cCrop();
        cin >> *pCrop;
        m_vCrops.push_back(pCrop);
        m_pFarm->getFarm()[x][y] = pCrop->getType();
        m_uEnergy -= 10;
        cout << "Crop planted!" << endl;
    }
    else
    {
        cout << "Crop already planted!" << endl;
    }
}

void cPlayer::waterCrop(unsigned int x, unsigned int y)
{
    if (m_uEnergy < 5)
    {
        cout << "Not enough energy to water a crop!" << endl;
        return;
    }
    if (m_pFarm->isAvailable(x, y))
    {
        cout << "No crop to water!" << endl;
    }
    else
    {
        cCrop *pCrop = nullptr;
        for (unsigned int i = 0; i < m_vCrops.size(); i++)
        {
            if (m_vCrops[i]->getPosX() == x && m_vCrops[i]->getPosY() == y)
            {
                pCrop = m_vCrops[i];
                break;
            }
        }
        if (pCrop == nullptr)
        {
            cout << "Crop not found!" << endl;
            return;
        }
        unsigned int newHarvestTime = pCrop->getHarvestTime() - 5;
        if (newHarvestTime < 0)
        {
            newHarvestTime = 0;
        }
        pCrop->setHarvestTime(newHarvestTime);

        m_uEnergy -= 1;
        cout << "Crop watered!" << endl;
    }
}

void cPlayer::harvestCrop(unsigned int x, unsigned int y)
{
    if (m_uEnergy < 10)
    {
        cout << "Not enough energy to harvest a crop!" << endl;
        return;
    }
    if (m_pFarm->isAvailable(x, y))
    {
        cout << "No crop to harvest!" << endl;
    }
    else
    {
        cCrop *pCrop = nullptr;
        for (unsigned int i = 0; i < m_vCrops.size(); i++)
        {
            if (m_vCrops[i]->getPosX() == x && m_vCrops[i]->getPosY() == y)
            {
                pCrop = m_vCrops[i];
                break;
            }
        }
        if (pCrop == nullptr)
        {
            cout << "Crop not found!" << endl;
            return;
        }
        if (pCrop->getHarvestTime() > 0)
        {
            cout << "Crop not ready to harvest!" << endl;
            return;
        }
        m_uMoney += pCrop->getProductPrice();
        m_pFarm->getFarm()[x][y] = 0;
        delete pCrop;
        m_vCrops.erase(m_vCrops.begin() + x * m_pFarm->getWidth() + y);
        m_uEnergy -= 10;
        cout << "Crop harvested!" << endl;
    }
}

void cPlayer::updateCropList()
{
    // Remove all crops that are ready to harvest
    for (unsigned int i = 0; i < m_vCrops.size(); i++)
    {
        if (m_vCrops[i]->getHarvestTime() == 0)
        {
            m_pFarm->getFarm()[m_vCrops[i]->getPosX()][m_vCrops[i]->getPosY()] = 0;
            delete m_vCrops[i];
            m_vCrops.erase(m_vCrops.begin() + i);
        }
    }
}

void cPlayer::buyPet(unsigned int x, unsigned int y)
{
    if (m_uEnergy < 10)
    {
        cout << "Not enough energy to buy a pet!" << endl;
        return;
    }
    if (m_pFarm->isAvailable(x, y))
    {
        cPet *pPet = new cPet();
        cin >> *pPet;
        m_vPets.push_back(pPet);
        m_pFarm->getFarm()[x][y] = 1;
        m_uEnergy -= 10;
        cout << "Pet bought!" << endl;
    }
    else
    {
        cout << "Pet already bought!" << endl;
    }
}

void cPlayer::feedPet(unsigned int x, unsigned int y)
{
    if (m_uEnergy < 5)
    {
        cout << "Not enough energy to feed a pet!" << endl;
        return;
    }
    if (m_pFarm->isAvailable(x, y))
    {
        cout << "No pet to feed!" << endl;
    }
    else
    {
        cPet *pPet = nullptr;
        for (unsigned int i = 0; i < m_vPets.size(); i++)
        {
            if (m_vPets[i]->getPosX() == x && m_vPets[i]->getPosY() == y)
            {
                pPet = m_vPets[i];
                break;
            }
        }
        if (pPet == nullptr)
        {
            cout << "Pet not found!" << endl;
            return;
        }
        unsigned int newHunger = pPet->getMaturationTime() - 5;
        if (newHunger < 0)
        {
            newHunger = 0;
        }
        pPet->setMaturationTime(newHunger);

        m_uEnergy -= 5;
        cout << "Pet fed!" << endl;
    }
}

void cPlayer::sellPet(unsigned int x, unsigned int y)
{
    if (m_uEnergy < 10)
    {
        cout << "Not enough energy to sell a pet!" << endl;
        return;
    }
    if (m_pFarm->isAvailable(x, y))
    {
        cout << "No pet to sell!" << endl;
    }
    else
    {
        cPet *pPet = nullptr;
        for (unsigned int i = 0; i < m_vPets.size(); i++)
        {
            if (m_vPets[i]->getPosX() == x && m_vPets[i]->getPosY() == y)
            {
                pPet = m_vPets[i];
                break;
            }
        }
        if (pPet == nullptr)
        {
            cout << "Pet not found!" << endl;
            return;
        }
        if (pPet->getMaturationTime() > 0)
        {
            cout << "Pet not ready to sell!" << endl;
            return;
        }
        m_uMoney += pPet->getProductPrice();
        m_pFarm->getFarm()[x][y] = 0;
        delete pPet;
        m_vPets.erase(m_vPets.begin() + x * m_pFarm->getWidth() + y);
        m_uEnergy -= 10;
        cout << "Pet sold!" << endl;
    }
}

void cPlayer::updatePetList()
{
    // Remove all pets that are ready to sell
    for (unsigned int i = 0; i < m_vPets.size(); i++)
    {
        if (m_vPets[i]->getMaturationTime() == 0)
        {
            m_pFarm->getFarm()[m_vPets[i]->getPosX()][m_vPets[i]->getPosY()] = 0;
            delete m_vPets[i];
            m_vPets.erase(m_vPets.begin() + i);
        }
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////// OPERATORS /////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

cPlayer &cPlayer::operator=(const cPlayer &player)
{
    if (this == &player)
    {
        return *this;
    }
    m_uLevel = player.m_uLevel;
    m_uMoney = player.m_uMoney;
    m_uEnergy = player.m_uEnergy;
    m_pFarm = new cFarm(*player.m_pFarm);
    for (unsigned int i = 0; i < player.m_vCrops.size(); i++)
    {
        m_vCrops.push_back(new cCrop(*player.m_vCrops[i]));
    }
    return *this;
}

ostream &operator<<(ostream &os, const cPlayer &player)
{
    os << "Player information: " << endl;
    os << "Level: " << player.m_uLevel << endl;
    os << "Money: " << player.m_uMoney << endl;
    os << "Energy: " << player.m_uEnergy << endl;
    os << "Farm: " << endl;
    os << *player.m_pFarm << endl;
    os << "Crops: " << endl;
    for (unsigned int i = 0; i < player.m_vCrops.size(); i++)
    {
        os << *player.m_vCrops[i] << endl;
    }
    os << "Pets: " << endl;
    for (unsigned int i = 0; i < player.m_vPets.size(); i++)
    {
        os << *player.m_vPets[i] << endl;
    }
    return os;
}

istream &operator>>(istream &is, cPlayer &player)
{
    cout << "Enter player information:\n";
    cout << "Level: ";
    is >> player.m_uLevel;
    cout << "Money: ";
    is >> player.m_uMoney;
    cout << "Energy: ";
    is >> player.m_uEnergy;
    return is;
}