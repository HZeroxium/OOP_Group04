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

/**
- m_sName: string
- m_vBookShelves: vector<cBookShelf>
+ cLibrary(sName: string = "", vBookShelves: vector<cBookShelf> = vector<cBookShelf>())
+ setName(sName: string): void
+ setBookShelves(vBookShelves: vector<cBookShelf>): void
+ getName(): string
+ getBookShelves(): vector<cBookShelf> *
+ addBookShelf(bookShelf: cBookShelf): void
+ removeBookShelfByID(sID: string): void
+ operator<<(out: ostream, library: cLibrary): ostream
+ operator>>(in: istream, library: cLibrary): istream
 */