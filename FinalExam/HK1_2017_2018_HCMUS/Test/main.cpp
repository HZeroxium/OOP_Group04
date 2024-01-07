#include <iostream>
#include <string>
using namespace std;

// Example of Decorator pattern

// class Beverage
// {
// protected:
//     string description = "Unknown Beverage";

// public:
//     virtual string getDescription()
//     {
//         return description;
//     }
//     virtual double cost() = 0;
//     virtual ~Beverage() = default;
// };

// class CondimentDecorator : public Beverage
// {
// public:
//     virtual string getDescription() = 0;
//     virtual ~CondimentDecorator() = default;
// };

// class Espresso : public Beverage
// {
// public:
//     Espresso()
//     {
//         description = "Espresso";
//     }
//     double cost() override
//     {
//         return 1.99;
//     }
// };

// class HouseBlend : public Beverage
// {
// public:
//     HouseBlend()
//     {
//         description = "House Blend Coffee";
//     }
//     double cost() override
//     {
//         return 0.89;
//     }
// };

// class DarkRoast : public Beverage
// {
// public:
//     DarkRoast()
//     {
//         description = "Dark Roast Coffee";
//     }
//     double cost() override
//     {
//         return 0.99;
//     }
// };

// class Decaf : public Beverage
// {
// public:
//     Decaf()
//     {
//         description = "Decaf Coffee";
//     }
//     double cost() override
//     {
//         return 1.05;
//     }
// };

// class Mocha : public CondimentDecorator
// {
// private:
//     Beverage *beverage;

// public:
//     Mocha(Beverage *beverage)
//     {
//         this->beverage = beverage;
//     }
//     string getDescription() override
//     {
//         return beverage->getDescription() + ", Mocha";
//     }
//     double cost() override
//     {
//         return 0.20 + beverage->cost();
//     }
//     ~Mocha()
//     {
//         delete beverage;
//     }
// };

// class Whip : public CondimentDecorator
// {
// private:
//     Beverage *beverage;

// public:
//     Whip(Beverage *beverage)
//     {
//         this->beverage = beverage;
//     }
//     string getDescription() override
//     {
//         return beverage->getDescription() + ", Whip";
//     }
//     double cost() override
//     {
//         return 0.10 + beverage->cost();
//     }
//     ~Whip()
//     {
//         delete beverage;
//     }
// };

// class Soy : public CondimentDecorator
// {
// private:
//     Beverage *beverage;

// public:
//     Soy(Beverage *beverage)
//     {
//         this->beverage = beverage;
//     }
//     string getDescription() override
//     {
//         return beverage->getDescription() + ", Soy";
//     }
//     double cost() override
//     {
//         return 0.15 + beverage->cost();
//     }
//     ~Soy()
//     {
//         delete beverage;
//     }
// };

// int main()
// {
//     Beverage *beverage = new Espresso();
//     cout << beverage->getDescription() << " $" << beverage->cost() << endl;

//     Beverage *beverage2 = new DarkRoast();
//     beverage2 = new Mocha(beverage2);
//     beverage2 = new Mocha(beverage2);
//     beverage2 = new Whip(beverage2);
//     cout << beverage2->getDescription() << " $" << beverage2->cost() << endl;

//     Beverage *beverage3 = new HouseBlend();
//     beverage3 = new Soy(beverage3);
//     beverage3 = new Mocha(beverage3);
//     beverage3 = new Whip(beverage3);
//     cout << beverage3->getDescription() << " $" << beverage3->cost() << endl;

//     delete beverage;
//     delete beverage2;
//     delete beverage3;
//     return 0;
// }

// class Work
// {
// public:
//     virtual void doWork() = 0;
//     virtual ~Work() = default;
// };

// class WorkA : public Work
// {
// private:
//     Work *work;

// public:
//     WorkA(Work *work)
//     {
//         this->work = work;
//     }
//     void doWork() override
//     {
//         cout << "Work A" << endl;
//         work->doWork();
//     }
//     ~WorkA()
//     {
//         delete work;
//     }
// };

// class WorkB : public Work
// {
// private:
//     Work *work;

// public:
//     WorkB(Work *work)
//     {
//         this->work = work;
//     }
//     void doWork() override
//     {
//         cout << "Work B" << endl;
//         work->doWork();
//     }
//     ~WorkB()
//     {
//         delete work;
//     }
// };

// class WorkC : public Work
// {
// private:
//     Work *work;

// public:
//     WorkC(Work *work)
//     {
//         this->work = work;
//     }
//     void doWork() override
//     {
//         cout << "Work C" << endl;
//         work->doWork();
//     }
//     ~WorkC()
//     {
//         delete work;
//     }
// };

// int main()
// {
//     Work *work = new WorkA(new WorkB(new WorkC(nullptr)));
//     work->doWork();
//     delete work;
// }

struct Level1
{
    Level1()
    {
        cout << "Level1 default constructor" << endl;
    }
    Level1(const Level1 &l1)
    {
        cout << "Level1 copy constructor" << endl;
    }
};

struct Level2 : public Level1
{
    Level2()
    {
        cout << "Level2 default constructor" << endl;
    }
    Level2(const Level2 &l2)
    {
        cout << "Level2 copy constructor" << endl;
    }
};

struct Level3 : public Level2
{
    Level3()
    {
        cout << "Level3 default constructor" << endl;
    }
};

int main()
{
    Level3 l3;
    Level3 l3_2(l3);
}