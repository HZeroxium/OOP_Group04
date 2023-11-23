#include "cLibrary.h"

cLibrary::cLibrary(string sName, const vector<cBookShelf> &vBookShelves)
{
    m_sName = sName;
    m_vBookShelves = vBookShelves;
}

void cLibrary::setName(string sName)
{
    m_sName = sName;
}

void cLibrary::setBookShelves(const vector<cBookShelf> &vBookShelves)
{
    m_vBookShelves = vBookShelves;
}

string cLibrary::getName() const
{
    return m_sName;
}

vector<cBookShelf> *cLibrary::getBookShelves() const
{
    return const_cast<vector<cBookShelf> *>(&m_vBookShelves);
}

void cLibrary::addBookShelf(const cBookShelf &bookShelf)
{
    // Check if the bookshelf is already in the library
    auto it = find_if(m_vBookShelves.begin(), m_vBookShelves.end(), [&bookShelf](const cBookShelf &bs)
                      { return bs.getID() == bookShelf.getID(); });
    if (it != m_vBookShelves.end())
    {
        cout << "The bookshelf is already in the library." << endl;
        return;
    }
    m_vBookShelves.push_back(bookShelf);
}

void cLibrary::removeBookShelfByID(string sID)
{
    // Find the bookshelf
    auto it = find_if(m_vBookShelves.begin(), m_vBookShelves.end(), [&sID](const cBookShelf &bs)
                      { return bs.getID() == sID; });
    if (it == m_vBookShelves.end())
    {
        cout << "The bookshelf is not in the library." << endl;
        return;
    }
    m_vBookShelves.erase(it);
}

std::ostream &operator<<(std::ostream &out, const cLibrary &library)
{
    out << "Information of the library: " << endl;
    out << "+ Library Name: " << library.m_sName << endl;
    out << "+ Bookshelves: " << endl;
    for (const auto &bookShelf : library.m_vBookShelves)
    {
        out << bookShelf;
    }
    return out;
}

std::istream &operator>>(std::istream &in, cLibrary &library)
{
    cout << "Library Name: ";
    in >> library.m_sName;
    cout << "Number of bookshelves: ";
    unsigned int uiNumOfBookShelves;
    in >> uiNumOfBookShelves;
    for (unsigned int i = 0; i < uiNumOfBookShelves; ++i)
    {
        cBookShelf bookShelf;
        in >> bookShelf;
        library.m_vBookShelves.push_back(bookShelf);
    }
    return in;
}