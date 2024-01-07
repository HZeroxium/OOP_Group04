#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

class Resistor
{
private:
    double resistance;

public:
    Resistor(double resistance)
    {
        this->resistance = resistance;
    }
    double getResistance()
    {
        return resistance;
    }
};

class ICircuit
{
public:
    virtual double getResistance() = 0;
    virtual void add(unique_ptr<ICircuit> circuit) = 0;
    virtual ~ICircuit() = default;
};

class Single : public ICircuit
{
private:
    unique_ptr<Resistor> pResistor;

public:
    Single(double resistance)
    {
        pResistor = make_unique<Resistor>(resistance);
    }
    Single(unique_ptr<Resistor> pResistor)
    {
        this->pResistor = move(pResistor);
    }
    double getResistance()
    {
        return pResistor->getResistance();
    }
    void add(unique_ptr<ICircuit> circuit)
    {
        cerr << "Cannot add to a single resistor" << endl;
    }
};

class Composite : public ICircuit
{
protected:
    vector<unique_ptr<ICircuit>> circuits;

public:
    void add(unique_ptr<ICircuit> circuit)
    {
        circuits.push_back(move(circuit));
    }
    virtual double getResistance() = 0;
    virtual ~Composite() = default;
};

class Series : public Composite
{
public:
    double getResistance()
    {
        double total = 0;
        for (auto &circuit : circuits)
        {
            total += circuit->getResistance();
        }
        return total;
    }
};

class Parallel : public Composite
{
public:
    double getResistance()
    {
        double total = 0;
        for (auto &circuit : circuits)
        {
            total += 1 / circuit->getResistance();
        }
        return 1 / total;
    }
};

int main()
{
    unique_ptr<ICircuit> r1 = make_unique<Single>(1);
    unique_ptr<ICircuit> r2 = make_unique<Single>(2);
    unique_ptr<ICircuit> r3 = make_unique<Single>(3);
    unique_ptr<ICircuit> r4 = make_unique<Single>(4);
    unique_ptr<ICircuit> r5 = make_unique<Single>(5);

    unique_ptr<ICircuit> r12 = make_unique<Series>();
    r12->add(move(r1));
    r12->add(move(r2));

    unique_ptr<ICircuit> r45 = make_unique<Parallel>();
    r45->add(move(r4));
    r45->add(move(r5));

    unique_ptr<ICircuit> r345 = make_unique<Series>();
    r345->add(move(r3));
    r345->add(move(r45));

    unique_ptr<ICircuit> r12345 = make_unique<Parallel>();
    r12345->add(move(r12));
    r12345->add(move(r345));

    cout << "Total resistance: " << r12345->getResistance() << endl;
}
