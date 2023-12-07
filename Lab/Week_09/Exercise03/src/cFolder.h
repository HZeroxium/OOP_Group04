#pragma once

#include "cFileSystemComponent.h"
#include <vector>

using std::vector;

// Composite class in Composite Pattern

class cFolder final : public cFileSystemComponent
{
private: // Attributes
    cFolder *m_pParent;
    vector<cFileSystemComponent *> m_vComponents;

public: // Constructors & Destructor
    cFolder(const string &sName = "");
    ~cFolder() override;

public: // Getter & Setter
    vector<cFileSystemComponent *> getComponents() const;
    cFolder *getParent() const;
    void setParent(cFolder *parent);

public: // Override Methods
    string getName() const override;
    float getSize() const override;
    void addComponent(cFileSystemComponent *component);
    void removeComponent(cFileSystemComponent *component);

    void print() const;
};

/*
cFolder
- m_pParent: cFolder *
- m_vComponents: vector<cFileSystemComponent *>
+ cFolder(sName: string = "")
+ ~cFolder()
+ getComponents(): vector<cFileSystemComponent *>
+ getParent(): cFolder *
+ setParent(parent: cFolder *): void
+ getName(): string
+ getSize(): float
+ addComponent(component: cFileSystemComponent *): void
+ removeComponent(component: cFileSystemComponent *): void
+ print(): void
*/
