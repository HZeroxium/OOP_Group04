#include <iostream>

using namespace std;

class Money
{
private:
    int iEuro;
    int iCent;

public:
    Money(int euro = 0, int cent = 0)
    {
        iEuro = euro;
        iCent = cent;
    }
    friend ostream &operator<<(ostream &out, const Money &money)
    {
        out << "(" << money.iEuro << " Euro, " << money.iCent << " Cent)" << endl;
        return out;
    }
    friend istream &operator>>(istream &in, Money &money)
    {
        cout << "+ Enter number of euro: ";
        in >> money.iEuro;
        cout << "+ Enter number of cent: ";
        in >> money.iCent;
        return in;
    }

    Money &operator++()
    {
        iCent++;
        iEuro += iCent / 100;
        iCent %= 100;
        return *this;
    }

    Money operator++(int dummy)
    {
        Money temp(iEuro, iCent);
        iCent++;
        iEuro += iCent / 100;
        iCent %= 100;
        return temp;
    }
};

int main()
{
    Money m;
    cout << m;
    cin >> m;
    cout << m;
    cout << ++m;
    cout << m;
    cout << m++;
    cout << m;
}