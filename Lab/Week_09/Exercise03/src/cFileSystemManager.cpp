#include "cFileSystemManager.h"
#include "cFile.h"
#include <iostream>

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////// CONSTRUCTORS ///////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

cFileSystemManager::cFileSystemManager()
{
    m_pRoot = new cFolder("root");
}

cFileSystemManager::~cFileSystemManager()
{
    if (m_pRoot != nullptr)
    {
        delete m_pRoot;
        m_pRoot = nullptr;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////// SINGLETON METHODS //////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

cFileSystemManager *cFileSystemManager::getInstance()
{
    if (m_pInstance == nullptr)
    {
        m_pInstance = new cFileSystemManager();
    }
    return m_pInstance;
}

void cFileSystemManager::destroyInstance()
{
    if (m_pInstance != nullptr)
    {
        delete m_pInstance;
        m_pInstance = nullptr;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////// GETTERS & SETTERS //////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

cFolder *cFileSystemManager::getRootFolder() const
{
    return m_pRoot;
}

void cFileSystemManager::setRootFolder(cFolder *pRoot)
{
    m_pRoot = pRoot;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////// METHODS //////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool cFileSystemManager::addFile(const string &sName, float fSize)
{
    if (m_pRoot == nullptr)
    {
        std::cerr << "ERROR: Root folder is not set" << std::endl;
        return false;
    }

    cFile *file = new cFile(sName, fSize);
    m_pRoot->addComponent(file);
    return true;
}

bool cFileSystemManager::addFolder(const string &sName)
{
    if (m_pRoot == nullptr)
    {
        std::cerr << "ERROR: Root folder is not set" << std::endl;
        return false;
    }

    cFolder *folder = new cFolder(sName);
    m_pRoot->addComponent(folder);
    return true;
}

bool cFileSystemManager::removeFile(const string &sName)
{
    if (m_pRoot == nullptr)
    {
        std::cerr << "ERROR: Root folder is not set" << std::endl;
        return false;
    }

    // Check if the file is in the root folder
    for (const auto &component : m_pRoot->getComponents())
    {
        if (component->getName() == sName)
        {
            m_pRoot->removeComponent(component);
            return true;
        }
    }

    std::cerr << "ERROR: File " << sName << " not found in current folder " << m_pRoot->getName() << std::endl;
    return false;
}

bool cFileSystemManager::removeFolder(const string &sName)
{
    if (m_pRoot == nullptr)
    {
        std::cerr << "ERROR: Root folder is not set" << std::endl;
        return false;
    }

    // Check if the folder is in the root folder
    for (const auto &component : m_pRoot->getComponents())
    {
        if (component->getName() == sName)
        {
            m_pRoot->removeComponent(component);
            return true;
        }
    }

    std::cerr << "ERROR: Folder " << sName << " not found in current folder " << m_pRoot->getName() << std::endl;
    return false;
}

void cFileSystemManager::printFileSystem() const
{
    if (m_pRoot == nullptr)
    {
        std::cerr << "ERROR: Root folder is not set" << std::endl;
        return;
    }

    m_pRoot->print();
}

void cFileSystemManager::calcTotalSize() const
{
    if (m_pRoot == nullptr)
    {
        std::cerr << "ERROR: Root folder is not set" << std::endl;
        return;
    }

    float fTotalSize = m_pRoot->getSize();
    std::cout << "Total size of current folder " << m_pRoot->getName() << " is " << fTotalSize << " bytes" << std::endl;
}

void cFileSystemManager::navigateToSubFolder(const string &sName)
{
    if (m_pRoot == nullptr)
    {
        std::cerr << "ERROR: Root folder is not set" << std::endl;
        return;
    }

    // Check if the folder is in the root folder
    for (const auto &component : m_pRoot->getComponents())
    {
        if (component->getName() == sName)
        {
            cFolder *folder = dynamic_cast<cFolder *>(component);
            if (folder != nullptr)
            {
                std::cout << "Navigate from current folder " << m_pRoot->getName() << " to sub folder " << folder->getName() << std::endl;
                m_pRoot = folder;
                return;
            }
        }
    }

    std::cerr << "ERROR: Folder " << sName << " not found in current folder " << m_pRoot->getName() << std::endl;
}

void cFileSystemManager::navigateToParentFolder()
{
    if (m_pRoot == nullptr)
    {
        std::cerr << "ERROR: Root folder is not set" << std::endl;
        return;
    }

    if (m_pRoot->getParent() != nullptr)
    {
        std::cout << "Navigate from current folder " << m_pRoot->getName() << " to parent folder " << m_pRoot->getParent()->getName() << std::endl;
        m_pRoot = m_pRoot->getParent();
    }
    else
    {
        std::cerr << "ERROR: Current folder " << m_pRoot->getName() << " is root folder" << std::endl;
    }
}