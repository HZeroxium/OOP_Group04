#include "cBookShelf.h"

cBookShelf::cBookShelf(string sID, const vector<cBook> &vBooks)
{
    setID(sID);
    setBooks(vBooks);
}

void cBookShelf::setID(string sID)
{
    m_sID = sID;
}

void cBookShelf::setBooks(const vector<cBook> &vBooks)
{
    m_vBooks = vBooks;
}

string cBookShelf::getID() const
{
    return m_sID;
}

vector<cBook> *cBookShelf::getBooks() const
{
    return const_cast<vector<cBook> *>(&m_vBooks);
}

void cBookShelf::addBook(const cBook &book)
{
    // Check if the book is already in the bookshelf
    auto it = find_if(m_vBooks.begin(), m_vBooks.end(), [&book](const cBook &b)
                      { return b.getID() == book.getID(); });
    if (it != m_vBooks.end())
    {
        cout << "The book is already in the bookshelf." << endl;
        return;
    }
    m_vBooks.push_back(book);
}

void cBookShelf::removeBookByID(string sID)
{
    // Find the book
    auto it = find_if(m_vBooks.begin(), m_vBooks.end(), [&sID](const cBook &b)
                      { return b.getID() == sID; });
    if (it == m_vBooks.end())
    {
        cout << "The book is not in the bookshelf." << endl;
        return;
    }
    m_vBooks.erase(it);
}

std::ostream &operator<<(std::ostream &out, const cBookShelf &bookShelf)
{
    out << "Information of the bookshelf: " << endl;
    out << "+ Bookshelf ID: " << bookShelf.m_sID << endl;
    out << "+ Books: " << endl;
    for (const auto &book : bookShelf.m_vBooks)
    {
        out << book;
    }
    return out;
}

std::istream &operator>>(std::istream &in, cBookShelf &bookShelf)
{
    cout << "Enter information of the bookshelf:" << endl;
    cout << "+ Bookshelf ID: ";
    in >> bookShelf.m_sID;
    cout << "Enter number of books: ";
    unsigned int uiNumOfBooks;
    in >> uiNumOfBooks;
    cout << "Enter information of books:" << endl;
    for (unsigned int i = 0; i < uiNumOfBooks; ++i)
    {
        cBook book;
        in >> book;
        bookShelf.m_vBooks.push_back(book);
    }
    return in;
}