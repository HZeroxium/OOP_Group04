#include "Project.h"
#include <vector>

int main()
{
    vector<Project *> projects = {
        new Idea("SuperTech", 6),
        new Mvp("FutureCar", 6, 3),
        new Idea("VirtualHouse", 7),
        new Idea("NightVision", 4),
        new Mvp("SmartKey", 4, 5)};

    cout << "Project size: " << projects.size() << endl;
    ProjectPrinter::print(projects, PRINT_TYPE::COLUMN);
}