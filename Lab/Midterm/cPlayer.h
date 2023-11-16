#pragma once

#include "Common.h"
#include "cCrop.h"
#include "cFarm.h"
#include "cPet.h"

class cPlayer
{
private:
    vector<cCrop *> m_vCrops;
    vector<cPet *> m_vPets;
    cFarm *m_pFarm;
    unsigned int m_uLevel;
    unsigned int m_uMoney;
    unsigned int m_uEnergy;

public: // Constructors & Destructor
    cPlayer();
    cPlayer(const cPlayer &);
    ~cPlayer();

public: // Getters
    vector<cCrop *> getCrops() const;
    vector<cPet *> getPets() const;
    cFarm *getFarm() const;
    unsigned int getLevel() const;
    unsigned int getMoney() const;
    unsigned int getEnergy() const;

public: // Setters
    void setCrops(const vector<cCrop *> &);
    void setPets(const vector<cPet *> &);
    void setFarm(cFarm *);
    void setLevel(unsigned int);
    void setMoney(unsigned int);
    void setEnergy(unsigned int);

public: // Methods
    void plantCrop(unsigned int x, unsigned int y);
    void harvestCrop(unsigned int x, unsigned int y);
    void waterCrop(unsigned int x, unsigned int y);
    void updateCropList();

    void buyPet(unsigned int x, unsigned int y);
    void sellPet(unsigned int x, unsigned int y);
    void feedPet(unsigned int x, unsigned int y);
    void updatePetList();

public: // Operators
    cPlayer &operator=(const cPlayer &);
    friend ostream &operator<<(ostream &, const cPlayer &);
    friend istream &operator>>(istream &, cPlayer &);
};