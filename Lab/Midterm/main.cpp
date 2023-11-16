#include "Common.h"
#include "cPlayer.h"
#include "cFarm.h"

int main()
{
    cFarm *farm = new cFarm();
    cin >> *farm;
    cPlayer *player = new cPlayer();
    cin >> *player;
    player->setFarm(farm);
    cout << *(player->getFarm());
    cout << *player;
    delete player;
    delete farm;
    player = nullptr;
    farm = nullptr;
}