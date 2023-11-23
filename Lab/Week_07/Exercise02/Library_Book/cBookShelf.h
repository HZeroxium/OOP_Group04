#pragma once

#include "cBook.h"
#include <vector>

using std::vector;

class cBookShelf
{
private:
    string m_sID;
    vector<cBook> m_vBooks;

public:
    cBookShelf(string sID = "", const vector<cBook> &vBooks = vector<cBook>());
    ~cBookShelf() = default;

    void setID(string sID);
    void setBooks(const vector<cBook> &vBooks);

    string getID() const;
    vector<cBook> *getBooks() const;

    void addBook(const cBook &book);
    void removeBookByID(string sID);

    friend std::ostream &operator<<(std::ostream &out, const cBookShelf &bookShelf);
    friend std::istream &operator>>(std::istream &in, cBookShelf &bookShelf);
};