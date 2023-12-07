#pragma once

#include "cFileSystemComponent.h"

// Leaf class in Composite Pattern
class cFile final : public cFileSystemComponent
{
public: // Constructors & Destructor
    cFile(const string &sName = "", float fSize = 0.0f);
    ~cFile() override = default;

public: // Override Methods
    string getName() const override;
    float getSize() const override;
};

/*
cFile
+ cFile(sName: string = "", fSize: float = 0.0f)
+ ~cFile()
+ getName(): string
+ getSize(): float
*/