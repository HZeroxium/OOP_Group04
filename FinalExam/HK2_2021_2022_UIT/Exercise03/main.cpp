#include <iostream>
#include <string>
#include <vector>
using namespace std;

enum STATUS
{
    NON_ACTIVATED = 0,
    ACTIVATED = 1
};

enum CARRIER
{
    VERIZON = 1,
    ATT,
    SPRINT
};

enum SIM_TYPE
{
    PREPAID,
    POSTPAID
};

class SIM
{
protected:
    string serialNumber;
    CARRIER carrier;
    STATUS status;
    string phoneNumber;

public:
    virtual double calDiscount(double amount) const = 0;
    virtual ~SIM() {}
    virtual SIM_TYPE getType() const = 0;
    virtual void input()
    {
        SIM_TYPE type = getType();
        if (type == PREPAID)
            cout << "Enter information for Prepaid SIM" << endl;
        else
            cout << "Enter information for Postpaid SIM" << endl;
        cout << "+ Serial number: ";
        getline(cin, serialNumber);
        cout << "+ Carrier (1: Verizon, 2: AT&T, 3: Sprint): ";
        int c;
        cin >> c;
        cin.ignore();
        carrier = (CARRIER)c;
        status = NON_ACTIVATED;
        cout << "+ Phone number: ";
        getline(cin, phoneNumber);
    }
    virtual void output()
    {
        SIM_TYPE type = getType();
        if (type == PREPAID)
            cout << "+ Type: Prepaid SIM" << endl;
        else
            cout << "+ Type: Postpaid SIM" << endl;
        cout << "+ Serial number: " << serialNumber << endl;
        cout << "+ Carrier: " << carrier << endl;
        cout << "+ Status: " << status << endl;
        cout << "+ Phone number: " << phoneNumber << endl;
    }
};

class PrepaidSIM : public SIM
{
private:
    double balance;
    unsigned int rechargeCount;

public:
    double calDiscount(double amount) const
    {
        double discount = 0;
        if (rechargeCount < 5)
            discount = 0.1;
        else if (rechargeCount <= 10)
            discount = 0.2;
        else
            discount = 0.5;
        return amount * discount;
    }
    SIM_TYPE getType() const
    {
        return PREPAID;
    }
    void input()
    {
        SIM::input();
        cout << "+ Balance: ";
        cin >> balance;
        cout << "+ Recharge count: ";
        cin >> rechargeCount;
    }
    void output()
    {
        SIM::output();
        cout << "+ Balance: " << balance << endl;
        cout << "+ Recharge count: " << rechargeCount << endl;
    }
};

enum PACKAGE
{
    LCAP,
    MCAP,
    HCAP
};

class PostpaidSIM : public SIM
{
private:
    PACKAGE package;
    double bill;

public:
    double getBill() const
    {
        return bill;
    }

public:
    double calDiscount(double amount) const
    {
        double discount = 0;
        if (package == LCAP)
            discount = 0.05;
        else if (package == MCAP)
            discount = 0.1;
        else
            discount = 0.15;
        return amount * discount;
    }
    SIM_TYPE getType() const
    {
        return POSTPAID;
    }
    void input()
    {
        SIM::input();
        cout << "+ Package (1: Low, 2: Medium, 3: High): ";
        int p;
        cin >> p;
        cin.ignore();
        package = (PACKAGE)p;
        cout << "+ Bill: ";
        cin >> bill;
    }
    void output()
    {
        SIM::output();
        cout << "+ Package: " << package << endl;
        cout << "+ Bill: " << bill << endl;
    }
};

class SIMAgent
{
private:
    vector<SIM *> simList;

public:
    void input()
    {
        int n;
        cout << "Enter number of SIMs: ";
        cin >> n;
        cin.ignore();
        simList.clear();
        simList.resize(n);
        for (int i = 0; i < n; i++)
        {
            cout << "Enter information for SIM #" << i + 1 << endl;
            cout << "1. Prepaid SIM" << endl;
            cout << "2. Postpaid SIM" << endl;
            cout << "Your choice: ";
            int choice;
            cin >> choice;
            cin.ignore();
            SIM *sim;
            if (choice == 1)
                sim = new PrepaidSIM();
            else
                sim = new PostpaidSIM();
            sim->input();
            simList[i] = sim;
        }
    }

    void output()
    {
        for (int i = 0; i < simList.size(); i++)
        {
            cout << "Information for SIM #" << i + 1 << endl;
            simList[i]->output();
        }
    }

    double calTotalDiscount()
    {
        double total = 0;
        for (int i = 0; i < simList.size(); i++)
        {
            double amount;
            cout << "Enter amount for SIM #" << i + 1 << ": ";
            cin >> amount;
            cin.ignore();
            total += simList[i]->calDiscount(amount);
        }
        return total;
    }

    ~SIMAgent()
    {
        for (int i = 0; i < simList.size(); i++)
            delete simList[i];

        simList.clear();
    }

    void findMostBill()
    {
        double maxBill = 0;
        for (int i = 0; i < simList.size(); i++)
        {
            if (simList[i]->getType() == POSTPAID)
            {
                PostpaidSIM *postpaidSIM = (PostpaidSIM *)simList[i];
                if (postpaidSIM->getBill() > maxBill)
                {
                    maxBill = postpaidSIM->getBill();
                }
            }
        }

        for (int i = 0; i < simList.size(); i++)
        {
            if (simList[i]->getType() == POSTPAID)
            {
                PostpaidSIM *postpaidSIM = (PostpaidSIM *)simList[i];
                if (postpaidSIM->getBill() == maxBill)
                {
                    cout << "Information for SIM #" << i + 1 << endl;
                    simList[i]->output();
                }
            }
        }
    }
};

int main()
{
    SIMAgent agent;
    agent.input();
    agent.output();
    cout << "Total discount: " << agent.calTotalDiscount() << endl;
    agent.findMostBill();
    return 0;
}