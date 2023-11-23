#pragma once

#include "cBook.h"
#include "cBookShelf.h"

class cLibrary
{
private:
    string m_sName;
    vector<cBookShelf> m_vBookShelves;

public:
    cLibrary(string sName = "", const vector<cBookShelf> &vBookShelves = vector<cBookShelf>());
    ~cLibrary() = default;

    void setName(string sName);
    void setBookShelves(const vector<cBookShelf> &vBookShelves);

    string getName() const;
    vector<cBookShelf> *getBookShelves() const;

    void addBookShelf(const cBookShelf &bookShelf);
    void removeBookShelfByID(string sID);

    friend std::ostream &operator<<(std::ostream &out, const cLibrary &library);
    friend std::istream &operator>>(std::istream &in, cLibrary &library);
};