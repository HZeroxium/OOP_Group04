#pragma once

#include "cFileSystemComponent.h"
#include "cFolder.h"

// Singleton class in Singleton Pattern to manage the file system

class cFileSystemManager
{
private: // Attributes
    static cFileSystemManager *m_pInstance;
    cFolder *m_pRoot;

private: // Constructors & Destructor
    cFileSystemManager();
    ~cFileSystemManager();

public: // Copy & Move constructors
    cFileSystemManager(const cFileSystemManager &) = delete;
    cFileSystemManager &operator=(const cFileSystemManager &) = delete;
    cFileSystemManager(cFileSystemManager &&) = delete;
    cFileSystemManager &operator=(cFileSystemManager &&) = delete;

public: // Singleton Methods
    static cFileSystemManager *getInstance();
    static void destroyInstance();

public: // Getter & Setter
    cFolder *getRootFolder() const;
    void setRootFolder(cFolder *pRoot);

public: // Methods
    bool addFile(const string &sName, float fSize);
    bool addFolder(const string &sName);
    bool removeFile(const string &sName);
    bool removeFolder(const string &sName);
    void printFileSystem() const;
    void calcTotalSize() const;
    void navigateToSubFolder(const string &sName);
    void navigateToParentFolder();
};

/*
cFileSystemManager
- m_pInstance: static cFileSystemManager*
- m_pRoot: cFolder*
+ static cFileSystemManager* getInstance()
+ static void destroyInstance()
+ getRootFolder(): cFolder*
+ setRootFolder(pRoot: cFolder*): void
+ addFile(sName: const string&, fSize: float): bool
+ addFolder(sName: const string&): bool
+ removeFile(sName: const string&): bool
+ removeFolder(sName: const string&): bool
+ printFileSystem(): void
+ calcTotalSize(): void
+ navigateToSubFolder(sName: const string&): void
+ navigateToParentFolder(): void
*/