#include <utility>
#include <vector>
#include <string>
#include <iostream>
#include <map>
using namespace std;

class Animal
{
protected:
    vector<unsigned int> phases;

public:
    virtual ~Animal() = default;
    virtual const vector<pair<unsigned int, unsigned int>> &getPhaseRanges() const = 0;
    bool isValid() const
    {
        if (phases.size() != getPhaseRanges().size())
            return false;
        for (unsigned int i = 0; i < phases.size(); i++)
        {
            if (phases[i] < getPhaseRanges()[i].first || phases[i] > getPhaseRanges()[i].second)
                return false;
        }
        return true;
    }
    virtual string getSpeciesName() const = 0;
    friend ostream &operator<<(ostream &os, const Animal &animal)
    {
        os << "{" << animal.getSpeciesName() << ": [";
        for (unsigned int i = 0; i < animal.phases.size(); i++)
        {
            os << animal.phases[i];
            if (i != animal.phases.size() - 1)
                os << ", ";
        }
        os << "]}" << endl;
        return os;
    }
};

class Mosquito : public Animal
{
public:
    inline static const vector<pair<unsigned int, unsigned int>> phaseRanges = {{1, 3}, {4, 10}, {2, 3}, {5, 8}};
    Mosquito(unsigned int phase1, unsigned int phase2, unsigned int phase3, unsigned int phase4)
    {
        phases.resize(4);
        phases[0] = phase1;
        phases[1] = phase2;
        phases[2] = phase3;
        phases[3] = phase4;
    }
    const vector<pair<unsigned int, unsigned int>> &getPhaseRanges() const override
    {
        return phaseRanges;
    }
    string getSpeciesName() const override
    {
        return "Mosquito";
    }

    friend istream &operator>>(istream &is, Mosquito &mosquito)
    {
        cout << "Enter 4 phases of Mosquito: ";
        is >> mosquito.phases[0] >> mosquito.phases[1] >> mosquito.phases[2] >> mosquito.phases[3];
        return is;
    }
};

class Frog : public Animal
{
public:
    inline static const vector<pair<unsigned int, unsigned int>> phaseRanges = {{1, 3}, {4, 4}, {6, 9}, {1, 4}, {104, 208}};
    Frog(unsigned int phase1, unsigned int phase2, unsigned int phase3, unsigned int phase4, unsigned int phase5)
    {
        phases.resize(5);
        phases[0] = phase1;
        phases[1] = phase2;
        phases[2] = phase3;
        phases[3] = phase4;
        phases[4] = phase5;
    }
    const vector<pair<unsigned int, unsigned int>> &getPhaseRanges() const override
    {
        return phaseRanges;
    }
    string getSpeciesName() const override
    {
        return "Frog";
    }
    friend istream &operator>>(istream &is, Frog &frog)
    {
        cout << "Enter 5 phases of Frog: ";
        is >> frog.phases[0] >> frog.phases[1] >> frog.phases[2] >> frog.phases[3] >> frog.phases[4];
        return is;
    }
};

class Butterfly : public Animal
{
public:
    inline static const vector<pair<unsigned int, unsigned int>> phaseRanges = {{3, 8}, {15, 16}, {10, 10}, {2, 3}};
    Butterfly(unsigned int phase1, unsigned int phase2, unsigned int phase3, unsigned int phase4)
    {
        phases.resize(4);
        phases[0] = phase1;
        phases[1] = phase2;
        phases[2] = phase3;
        phases[3] = phase4;
    }
    const vector<pair<unsigned int, unsigned int>> &getPhaseRanges() const override
    {
        return phaseRanges;
    }
    string getSpeciesName() const override
    {
        return "Butterfly";
    }
    friend istream &operator>>(istream &is, Butterfly &butterfly)
    {
        cout << "Enter 4 phases of Butterfly: ";
        is >> butterfly.phases[0] >> butterfly.phases[1] >> butterfly.phases[2] >> butterfly.phases[3];
        return is;
    }
};

class BiologicalSystem
{
private:
    vector<Animal *> animals;

public:
    void input()
    {
        unsigned int n;
        cout << "Enter number of animals: ";
        cin >> n;
        for (unsigned int i = 0; i < n; i++)
        {
            cout << "Enter information of animal " << i + 1 << endl;
            cout << "1. Mosquito" << endl;
            cout << "2. Frog" << endl;
            cout << "3. Butterfly" << endl;
            cout << "Your choice: ";
            unsigned int choice;
            cin >> choice;
            switch (choice)
            {
            case 1:
            {
                Mosquito *mosquito = new Mosquito(0, 0, 0, 0);
                cin >> *mosquito;
                animals.push_back(mosquito);
                break;
            }
            case 2:
            {
                Frog *frog = new Frog(0, 0, 0, 0, 0);
                cin >> *frog;
                animals.push_back(frog);
                break;
            }
            case 3:
            {
                Butterfly *butterfly = new Butterfly(0, 0, 0, 0);
                cin >> *butterfly;
                animals.push_back(butterfly);
                break;
            }
            default:
                cout << "Invalid choice" << endl;
                i--;
                break;
            }
        }
    }

    void output()
    {
        for (unsigned int i = 0; i < animals.size(); i++)
        {
            cout << *animals[i];
        }
    }

    void checkValid()
    {
        for (unsigned int i = 0; i < animals.size(); i++)
        {
            bool valid = animals[i]->isValid();
            if (!valid)
                cout << "Animal " << i + 1 << " is invalid" << endl;
        }
    }

    bool isBioDiversity()
    {
        map<string, unsigned int> speciesCount;
        for (unsigned int i = 0; i < animals.size(); i++)
        {
            string speciesName = animals[i]->getSpeciesName();
            if (speciesCount.find(speciesName) == speciesCount.end())
                speciesCount[speciesName] = 1;
            else
                speciesCount[speciesName]++;
        }

        return speciesCount.size() == 3;
    }
};

int main()
{
    BiologicalSystem biologicalSystem;
    biologicalSystem.input();
    biologicalSystem.output();
    biologicalSystem.checkValid();
    cout << "Is bio diversity: " << biologicalSystem.isBioDiversity() << endl;
    return 0;
}