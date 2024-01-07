#include <iostream>
#include <string>
using namespace std;

class Animal
{
private:
    string name;

public:
    inline Animal(const string &name = "Unknow")
    {
        this->name = name;
        cout << "Default constructor called at animal " << name << " || " << this << endl;
    }
    inline Animal(const Animal &animal)
    {
        this->name = animal.name;
        cout << "Copy constructor called at animal " << name << " || " << this << endl;
    }
    inline virtual ~Animal()
    {
        cout << "Destructor called at animal " << name << " || " << this << endl;
    }
    inline virtual void speak() const
    {
        cout << "Animal " << name << " speak" << endl;
    }
};

class Dog final : public Animal
{
private:
    string breed;

public:
    inline Dog(const string &name = "Unknow", const string &breed = "Unknow") : Animal(name)
    {
        this->breed = breed;
        cout << "Default constructor called at dog " << breed << " || " << this << endl;
    }
    inline Dog(const Dog &dog) : Animal(dog)
    {
        this->breed = dog.breed;
        cout << "Copy constructor called at dog " << breed << " || " << this << endl;
    }
    inline ~Dog() override
    {
        cout << "Destructor called at dog " << breed << " || " << this << endl;
    }
    inline void speak() const override final
    {
        cout << "Dog " << breed << " speak" << endl;
    }
};

class Cat : public Animal
{
protected:
    string breed;

public:
    inline Cat(const string &name = "Unknow", const string &breed = "Unknow") : Animal(name)
    {
        this->breed = breed;
        cout << "Default constructor called at cat " << breed << " || " << this << endl;
    }
    inline Cat(const Cat &cat) : Animal(cat)
    {
        this->breed = cat.breed;
        cout << "Copy constructor called at cat " << breed << " || " << this << endl;
    }
    inline virtual ~Cat() override
    {
        cout << "Destructor called at cat " << breed << " || " << this << endl;
    }
    inline virtual void speak() const override
    {
        cout << "Cat " << breed << " speak" << endl;
    }
};

class Tiger final : public Cat
{
public:
    inline Tiger(const string &name = "Unknow", const string &breed = "Unknow") : Cat(name, breed)
    {
        cout << "Default constructor called at tiger " << breed << " || " << this << endl;
    }
    inline Tiger(const Tiger &tiger) : Cat(tiger)
    {
        cout << "Copy constructor called at tiger " << breed << " || " << this << endl;
    }
    inline ~Tiger() override
    {
        cout << "Destructor called at tiger " << breed << " || " << this << endl;
    }
    inline virtual void speak() const override
    {
        cout << "Tiger " << breed << " speak" << endl;
    }
};

int main()
{
    Animal a("Animal");
    Dog b("Dog", "Husky");
    Cat c("Cat", "Persian");
    Tiger d("Tiger", "Bengal");
    cout << typeid(a).name() << endl;
    cout << typeid(b).name() << endl;
    return 0;
}
