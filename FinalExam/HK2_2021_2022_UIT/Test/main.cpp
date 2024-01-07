#include <iostream>

using namespace std;

// class Animal
// {
// public:
//     Animal()
//     {
//         cout << "Animal constructor" << endl;
//     }
//     virtual void speak() const = 0;
//     virtual ~Animal()
//     {
//         cout << "Animal destructor" << endl;
//     }
// };

// class Dog : public Animal
// {
// public:
//     Dog()
//     {
//         cout << "Dog constructor" << endl;
//     }
//     virtual void speak() const override
//     {
//         cout << "Woof!" << endl;
//     }
//     virtual ~Dog()
//     {
//         cout << "Dog destructor" << endl;
//     }
// };

// class HouseDog : public Dog
// {
// public:
//     HouseDog() : Dog()
//     {
//         cout << "HouseDog constructor" << endl;
//     }
//     virtual void speak() const override
//     {
//         cout << "Woof! Woof!" << endl;
//     }
//     ~HouseDog()
//     {
//         cout << "HouseDog destructor" << endl;
//     }
// };

class Level1
{
public:
    Level1()
    {
        cout << "Level1 default constructor" << endl;
    }
    Level1(int i)
    {
        cout << "Level1 parameterized constructor" << endl;
    }
    Level1(const Level1 &l)
    {
        cout << "Level1 copy constructor" << endl;
    }
    Level1 &operator=(const Level1 &l)
    {
        cout << "Level1 assignment operator" << endl;
        return *this;
    }
    virtual ~Level1()
    {
        cout << "Level1 destructor" << endl;
    }
    virtual void doSth() const
    {
        cout << "Level1 doSth" << endl;
    }
    void doSthElse() const
    {
        cout << "Level1 doSthElse" << endl;
    }
};

class Level2 : public Level1
{
public:
    Level2()
    {
        cout << "Level2 default constructor" << endl;
    }
    Level2(int i) : Level1(i)
    {
        cout << "Level2 parameterized constructor" << endl;
    }
    Level2(const Level2 &l) : Level1(l)
    {
        cout << "Level2 copy constructor" << endl;
    }
    Level2 &operator=(const Level2 &l)
    {
        cout << "Level2 assignment operator" << endl;
        return *this;
    }
    ~Level2()
    {
        cout << "Level2 destructor" << endl;
    }
    void doSth() const
    {
        cout << "Level2 doSth" << endl;
    }
    void doSthElse() const
    {
        cout << "Level2 doSthElse" << endl;
    }
    virtual void doSthElse2() const
    {
        cout << "Level2 doSthElse2" << endl;
    }
};

class Level3 : public Level2
{
public:
    Level3()
    {
        cout << "Level3 default constructor" << endl;
    }
    Level3(int i) : Level2(i)
    {
        cout << "Level3 parameterized constructor" << endl;
    }
    Level3(const Level3 &l) : Level2(l)
    {
        cout << "Level3 copy constructor" << endl;
    }
    Level3 &operator=(const Level3 &l)
    {
        cout << "Level3 assignment operator" << endl;
        return *this;
    }
    ~Level3()
    {
        cout << "Level3 destructor" << endl;
    }
    void doSth() const
    {
        cout << "Level3 doSth" << endl;
    }
    void doSthElse() const
    {
        cout << "Level3 doSthElse" << endl;
    }
    void doSthElse2() const
    {
        cout << "Level3 doSthElse2" << endl;
    }
};

void testing1(const Level1 &l)
{
    l.doSth();
    l.doSthElse();
}

void testing2(Level1 &l_1, Level1 &l_2)
{
    l_1 = l_2;
}

void testing3()
{
    Level1 *p = new Level1(1);
    p->doSth();
    p->doSthElse();
    delete p;
    p = nullptr;
    cout << "---------------------" << endl;
    p = new Level2(2);
    p->doSth();
    p->doSthElse();
    delete p;
    p = nullptr;
    cout << "---------------------" << endl;
    p = new Level3(3);
    p->doSth();
    p->doSthElse();
    delete p;
    p = nullptr;
    cout << "---------------------" << endl;
}

void testing4()
{
    Level1 l1;
    Level2 l2;
    Level3 l3;
    cout << "---------------------" << endl;
    testing1(l1);
    cout << "---------------------" << endl;
    testing1(l2);
    cout << "---------------------" << endl;
    testing1(l3);
    cout << "---------------------" << endl;
}

void testing5()
{
    Level1 l1;
    Level2 l2;
    Level3 l3;
    cout << "---------------------" << endl;
    l1.doSth();
    l1.doSthElse();
    cout << "---------------------" << endl;
    l2.doSth();
    l2.doSthElse();
    cout << "---------------------" << endl;
    l3.doSth();
    l3.doSthElse();
    cout << "---------------------" << endl;
}

void testing6(const Level1 &l = Level1())
{
    l.doSth();
    l.doSthElse();
}

void testing7()
{
    Level2 *p = new Level2();
    p->doSthElse2();
    delete p;
    p = nullptr;
    cout << "---------------------" << endl;
    p = new Level3();
    p->doSthElse2();
    delete p;
    p = nullptr;
    cout << "---------------------" << endl;
}
int main()
{
    testing7();
}
