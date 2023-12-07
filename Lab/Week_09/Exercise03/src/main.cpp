#include "cFileSystemManager.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

cFileSystemManager *cFileSystemManager::m_pInstance = nullptr;

int main()
{
    cFileSystemManager *pFSM = cFileSystemManager::getInstance();

    while (true)
    {
        cout << "============================================================================" << endl;
        cout << "=============== FILE SYSTEM MANAGEMENT SYSTEM - FileSystemManager ==========" << endl;
        cout << "============================================================================" << endl;
        cout << "CURRENT FOLDER: " << pFSM->getRootFolder()->getName() << endl;
        cout << "1. Add new file." << endl;
        cout << "2. Add new folder." << endl;
        cout << "3. Remove file." << endl;
        cout << "4. Remove folder." << endl;
        cout << "5. Print file system." << endl;
        cout << "6. Calculate total size." << endl;
        cout << "7. Navigate to subfolder." << endl;
        cout << "8. Navigate to parent folder." << endl;
        cout << "0. Exit." << endl;
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;
        cin.ignore();
        if (choice == 0)
        {
            cout << "Goodbye!" << endl;
            break;
        }
        switch (choice)
        {
        case 1:
        {
            string sName;
            float fSize;
            cout << "Enter name of file: ";
            std::getline(cin, sName);
            cout << "Enter size of file: ";
            cin >> fSize;
            cin.ignore();
            bool bSuccess = pFSM->addFile(sName, fSize);
            if (bSuccess)
            {
                cout << "Add file successfully!" << endl;
            }
            else
            {
                cout << "Add file failed!" << endl;
            }
            break;
        }
        case 2:
        {
            string sName;
            cout << "Enter name of folder: ";
            std::getline(cin, sName);
            bool bSuccess = pFSM->addFolder(sName);
            if (bSuccess)
            {
                cout << "Add folder successfully!" << endl;
            }
            else
            {
                cout << "Add folder failed!" << endl;
            }
            break;
        }
        case 3:
        {
            string sName;
            cout << "Enter name of file to remove: ";
            std::getline(cin, sName);
            bool bSuccess = pFSM->removeFile(sName);
            if (bSuccess)
            {
                cout << "Remove file successfully!" << endl;
            }
            else
            {
                cout << "Remove file failed!" << endl;
            }
            break;
        }
        case 4:
        {
            string sName;
            cout << "Enter name of folder to remove: ";
            std::getline(cin, sName);
            bool bSuccess = pFSM->removeFolder(sName);
            if (bSuccess)
            {
                cout << "Remove folder successfully!" << endl;
            }
            else
            {
                cout << "Remove folder failed!" << endl;
            }
            break;
        }
        case 5:
        {
            pFSM->printFileSystem();
            break;
        }
        case 6:
        {
            pFSM->calcTotalSize();
            break;
        }
        case 7:
        {
            string sName;
            cout << "Enter name of subfolder: ";
            std::getline(cin, sName);
            pFSM->navigateToSubFolder(sName);
            break;
        }
        case 8:
        {
            pFSM->navigateToParentFolder();
            break;
        }
        default:
        {
            std::cerr << "Invalid choice!" << endl;
            break;
        }
        }
    }

    cFileSystemManager::destroyInstance();

    return 0;
}