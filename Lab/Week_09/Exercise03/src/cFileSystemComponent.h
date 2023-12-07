#pragma once

#include <string>

using std::string;

// Component in the Composite Design Pattern
class cFileSystemComponent
{
protected: // Attributes
    string m_sName;
    float m_fSize;

public:
    cFileSystemComponent(const string &sName = "", float fSize = 0.0f);
    virtual ~cFileSystemComponent() = default;

public: // Pure virtual methods
    virtual string getName() const = 0;
    virtual float getSize() const = 0;
};

/*
cFileSystemComponent
# m_sName: string
# m_fSize: float
+ cFileSystemComponent(const string & = "", float = 0.0f)
+ virtual ~cFileSystemComponent() = default
+ virtual string getName() const = 0
+ virtual float getSize() const = 0
*/