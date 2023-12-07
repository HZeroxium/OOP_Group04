#include "cFolder.h"
#include <iomanip>
#include <iostream>

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////// CONSTRUCTORS & DESTRUCTOR /////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

cFolder::cFolder(const string &sName)
    : cFileSystemComponent(sName)
{
}

cFolder::~cFolder()
{
    for (auto component : m_vComponents)
    {
        delete component;
    }
    m_pParent = nullptr;
    m_vComponents.clear();
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////// GETTERS & SETTERS /////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

vector<cFileSystemComponent *> cFolder::getComponents() const
{
    return m_vComponents;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////// OVERRIDE METHODS //////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

string cFolder::getName() const
{
    return m_sName;
}

float cFolder::getSize() const
{
    float fTotalSize = 0.0f;

    for (const auto &component : m_vComponents)
    {
        fTotalSize += component->getSize();
    }

    return fTotalSize;
}

void cFolder::addComponent(cFileSystemComponent *component)
{
    // Check if the component is already in the folder
    for (const auto &c : m_vComponents)
    {
        if (c == component)
        {
            return;
        }
    }
    // Check if the component is a folder
    cFolder *folder = dynamic_cast<cFolder *>(component);
    if (folder != nullptr)
    {
        folder->setParent(this);
    }
    // Move memory of the component to the folder
    m_vComponents.push_back(component);
}

void cFolder::removeComponent(cFileSystemComponent *component)
{
    // Check if the component is in the folder
    for (auto it = m_vComponents.begin(); it != m_vComponents.end(); ++it)
    {
        if (*it == component)
        {
            // Check if the component is a folder
            cFolder *folder = dynamic_cast<cFolder *>(component);
            if (folder != nullptr)
            {
                folder->setParent(nullptr);
            }
            m_vComponents.erase(it);
            return;
        }
    }
}

// Use prefix to show the hierarchy of the folder structure, indent 2 spaces for each level
void cFolder::print() const
{
    static int indent = 0;
    indent += 2;

    for (const auto &component : m_vComponents)
    {
        std::cout << std::setw(indent) << " " << component->getName();

        // If the component is a folder, print its content
        cFolder *folder = dynamic_cast<cFolder *>(component);
        if (folder != nullptr)
        {
            std::cout << "/" << std::endl;
            folder->print();
        }
        else
        {
            std::cout << std::endl;
        }
    }

    indent -= 2;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////// GETTERS & SETTERS /////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

cFolder *cFolder::getParent() const
{
    return m_pParent;
}

void cFolder::setParent(cFolder *parent)
{
    m_pParent = parent;
}
