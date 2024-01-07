#include <iostream>
#include <string>

using namespace std;

struct Date
{
    unsigned int day, month, year;
};

ostream &operator<<(ostream &out, const Date &date)
{
    out << date.day << "/" << date.month << "/" << date.year;
    return out;
}

istream &operator>>(istream &in, Date &date)
{
    char dummy;
    in >> date.day >> dummy >> date.month >> dummy >> date.year;
    in.ignore();
    return in;
}

int operator>(const Date &d1, const Date &d2)
{
    if (d1.year > d2.year)
        return 1;
    if (d1.year < d2.year)
        return -1;
    if (d1.month > d2.month)
        return 1;
    if (d1.month < d2.month)
        return -1;
    if (d1.day > d2.day)
        return 1;
    if (d1.day < d2.day)
        return -1;
    return 0;
}

class Mobile
{
private:
    string code, name, brand;
    Date manufacturingDate;

public:
    int compare(const Mobile &other)
    {
        return (manufacturingDate > other.manufacturingDate);
    }

    friend ostream &operator<<(ostream &out, const Mobile &mobile)
    {
        out << "Mobile informations: " << endl;
        out << "+ Code: " << mobile.code << endl;
        out << "+ Name: " << mobile.name << endl;
        out << "+ Brand: " << mobile.brand << endl;
        out << "+ Manufacturing date: " << mobile.manufacturingDate << endl;
        return out;
    }

    friend istream &operator>>(istream &in, Mobile &mobile)
    {
        cout << "Enter mobile informations: " << endl;
        cout << "+ Code: ";
        getline(in, mobile.code);
        cout << "+ Name: ";
        getline(in, mobile.name);
        cout << "+ Brand: ";
        getline(in, mobile.brand);
        cout << "+ Manufacturing date: ";
        in >> mobile.manufacturingDate;
        return in;
    }
};

int main()
{
    Mobile m1, m2;
    cin >> m1 >> m2;
    cout << m1 << m2;
    cout << m1.compare(m2);
}
