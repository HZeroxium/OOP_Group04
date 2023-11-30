#include "cDataManagement.h"
#include "cMusicApp.h"

int main()
{
    cDataManagement::getInstance().loadData();
    cMusicApp::getInstance().run();

    cDataManagement::getInstance().saveData();
    return 0;
}