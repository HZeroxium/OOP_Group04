#pragma once

#include <string>
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

class GrantMoneyStrategy
{
public:
    virtual int grantMoney(int months) const = 0;
};

class IdeaGrantMoneyStrategy : public GrantMoneyStrategy
{
public:
    const static int moneyPerMonth = 20000000;
    int grantMoney(int months) const override
    {
        int totalMoney = moneyPerMonth * months;
        if (months >= 6)
        {
            totalMoney = totalMoney + moneyPerMonth * 0.2 * (months - 6);
        }
        return totalMoney;
    }
};

class MvpGrantMoneyStrategy : public GrantMoneyStrategy
{
public:
    const static int moneyPerMonth = 15000000;
    int grantMoney(int months) const override
    {
        int totalMoney = moneyPerMonth * months;
        if (months >= 6)
        {
            totalMoney = totalMoney + moneyPerMonth * 0.2 * (months - 6);
        }
        return totalMoney;
    }
};

class MoneyFormatter
{
public:
    static string format(int money, char separator = ',', const string &currency = "VND")
    {
        string result = "";
        int count = 0;
        while (money > 0)
        {
            if (count == 3)
            {
                result = separator + result;
                count = 0;
            }
            result = (char)(money % 10 + '0') + result;
            money /= 10;
            count++;
        }
        if (currency == "VND")
        {
            result += " d";
        }
        if (currency == "USD")
        {
            result = "$ " + result;
        }
        return result;
    }
};

class Project
{
private:
    string name;

public: // Constructors & Destructor
    Project(string name) : name(name) {}
    virtual ~Project() {}

public: // Getters
    string getName() const { return name; }

public: // Setters
    void setName(string name) { this->name = name; }

public: // Abstract Methods
    virtual string getType() const = 0;
    virtual string getInformation() const = 0;
    virtual int grantMoney() const = 0;
    void print() const
    {
        cout << getType() << ": " << getName() << ". " << getInformation() << ". Grant money: " << MoneyFormatter::format(grantMoney(), '.', "USD");
    }
};

class Idea : public Project
{
private:
    int developmentMonths;

public: // Constructors & Destructor
    Idea(string name, int developmentMonths) : Project(name), developmentMonths(developmentMonths) {}
    ~Idea() {}

public: // Getters
    int getDevelopmentMonths() const { return developmentMonths; }

public: // Setters
    void setDevelopmentMonths(int developmentMonths) { this->developmentMonths = developmentMonths; }

public: // Implemented Methods
    string getType() const override { return "Idea"; }
    string getInformation() const override
    {
        return "Development: " + std::to_string(developmentMonths) + " months";
    }
    int grantMoney() const override
    {
        IdeaGrantMoneyStrategy strategy;
        return strategy.grantMoney(developmentMonths);
    }
};

class Mvp : public Project
{
private:
    int marketingMonths;
    int operationalMonths;

public: // Constructors & Destructor
    Mvp(string name, int marketingMonths, int operationalMonths) : Project(name), marketingMonths(marketingMonths), operationalMonths(operationalMonths) {}
    ~Mvp() {}

public: // Getters
    int getMarketingMonths() const { return marketingMonths; }
    int getOperationalMonths() const { return operationalMonths; }

public: // Setters
    void setMarketingMonths(int marketingMonths) { this->marketingMonths = marketingMonths; }
    void setOperationalMonths(int operationalMonths) { this->operationalMonths = operationalMonths; }

public: // Implemented Methods
    string getType() const override { return "Mvp"; }
    string getInformation() const override
    {
        return "Marketing: " + std::to_string(marketingMonths) + " months, Operational: " + std::to_string(operationalMonths) + " months";
    }
    int grantMoney() const override
    {
        MvpGrantMoneyStrategy strategy;
        return strategy.grantMoney(marketingMonths + operationalMonths);
    }
};

enum PRINT_TYPE
{
    ROW,
    COLUMN
};

class ProjectPrinter
{
private: // Helper Methods
    static void printRow(const vector<Project *> &projects)
    {
        for (int i = 0; i < projects.size(); i++)
        {
            cout << i + 1 << ". ";
            projects[i]->print();
            cout << endl;
        }
    }

    static void printColumn(const vector<Project *> &projects)
    {
        constexpr int TYPE_WIDTH = 10;
        constexpr int NAME_WIDTH = 20;
        constexpr int INFO_WIDTH = 60;
        constexpr int MONEY_WIDTH = 30;
        constexpr int TOTAL_WIDTH = TYPE_WIDTH + NAME_WIDTH + INFO_WIDTH + MONEY_WIDTH;
        constexpr char ROW_SEPARATOR = '-';
        constexpr char COLUMN_SEPARATOR = '|';

        // Print header
        cout << setw(TYPE_WIDTH) << left << "Type" << COLUMN_SEPARATOR << " " << setw(NAME_WIDTH) << left << "Name" << COLUMN_SEPARATOR << " " << setw(INFO_WIDTH) << left << "Information" << COLUMN_SEPARATOR << " " << setw(MONEY_WIDTH) << left << "Grant Money" << endl;
        // Print row separator
        for (int i = 0; i < TOTAL_WIDTH; i++)
        {
            cout << ROW_SEPARATOR;
        }
        cout << endl;
        // Print content
        for (int i = 0; i < projects.size(); i++)
        {
            cout << setw(TYPE_WIDTH) << left << projects[i]->getType() << COLUMN_SEPARATOR << " " << setw(NAME_WIDTH) << left << projects[i]->getName() << COLUMN_SEPARATOR << " " << setw(INFO_WIDTH) << left << projects[i]->getInformation() << COLUMN_SEPARATOR << " " << setw(MONEY_WIDTH) << left << MoneyFormatter::format(projects[i]->grantMoney(), '.', "USD") << endl;
        }
    }

public:
    static void print(const vector<Project *> &projects, PRINT_TYPE printType = ROW)
    {
        switch (printType)
        {
        case ROW:
            printRow(projects);
            break;
        case COLUMN:
            printColumn(projects);
            break;
        };
    }
};