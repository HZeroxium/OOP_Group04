#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Staff
{
protected:
    string id;
    string name;
    string dob;
    double salaryRate;
    string beginDate;
    double baseSalary;

public:
    Staff() = default;
    Staff(string id, string name, string dob, double salaryRate, string beginDate, double baseSalary)
    {
        this->id = id;
        this->name = name;
        this->dob = dob;
        this->salaryRate = salaryRate;
        this->beginDate = beginDate;
        this->baseSalary = baseSalary;
    }
    virtual void input(istream &in = cin)
    {
        cout << "ID: ";
        in >> id;
        cout << "Name: ";
        in >> name;
        cout << "Date of birth: ";
        in >> dob;
        cout << "Salary rate: ";
        in >> salaryRate;
        cout << "Begin date: ";
        in >> beginDate;
        cout << "Base salary: ";
        in >> baseSalary;
    }
    virtual void output(ostream &out = cout)
    {
        out << "ID: " << id << endl;
        out << "Name: " << name << endl;
        out << "Date of birth: " << dob << endl;
        out << "Salary rate: " << salaryRate << endl;
        out << "Begin date: " << beginDate << endl;
        out << "Base salary: " << baseSalary << endl;
    }
    virtual double calculateSalary() = 0;
    virtual string getType() = 0;
    virtual ~Staff() = default;
    string getId()
    {
        return id;
    }

protected:
    double calculateBaseSalary()
    {
        return baseSalary * salaryRate;
    }
};

class Programmer : public Staff
{
private:
    int overtimeHours;
    inline static double SALARY_PER_OVERTIME_HOUR = 200000;

public:
    Programmer() = default;
    Programmer(string id, string name, string dob, double salaryRate, string beginDate, double baseSalary, int overtimeHours) : Staff(id, name, dob, salaryRate, beginDate, baseSalary)
    {
        this->overtimeHours = overtimeHours;
    }
    void input(istream &in = cin)
    {
        Staff::input(in);
        cout << "Overtime hours: ";
        in >> overtimeHours;
    }
    void output(ostream &out = cout)
    {
        Staff::output(out);
        out << "Overtime hours: " << overtimeHours << endl;
    }
    double calculateSalary()
    {
        return calculateBaseSalary() + overtimeHours * SALARY_PER_OVERTIME_HOUR;
    }
    string getType()
    {
        return "Programmer";
    }
};

class Designer : public Staff
{
private:
    double projectRevenue;
    inline static double REVENUE_PERCENT = 0.05;

public:
    Designer() = default;
    Designer(string id, string name, string dob, double salaryRate, string beginDate, double baseSalary, double projectRevenue) : Staff(id, name, dob, salaryRate, beginDate, baseSalary)
    {
        this->projectRevenue = projectRevenue;
    }
    void input(istream &in = cin)
    {
        Staff::input(in);
        cout << "Project revenue: ";
        in >> projectRevenue;
    }
    void output(ostream &out = cout)
    {
        Staff::output(out);
        out << "Project revenue: " << projectRevenue << endl;
    }
    double calculateSalary()
    {
        return calculateBaseSalary() + projectRevenue * REVENUE_PERCENT;
    }
    string getType()
    {
        return "Designer";
    }
};

class Tester : public Staff
{
private:
    int errorNumbers;
    inline static double SALARY_PER_ERROR = 200000;

public:
    Tester() = default;
    Tester(string id, string name, string dob, double salaryRate, string beginDate, double baseSalary, int errorNumbers) : Staff(id, name, dob, salaryRate, beginDate, baseSalary)
    {
        this->errorNumbers = errorNumbers;
    }
    void input(istream &in = cin)
    {
        Staff::input(in);
        cout << "Error numbers: ";
        in >> errorNumbers;
    }
    void output(ostream &out = cout)
    {
        Staff::output(out);
        out << "Error numbers: " << errorNumbers << endl;
    }
    double calculateSalary()
    {
        return calculateBaseSalary() - errorNumbers * SALARY_PER_ERROR;
    }
    string getType()
    {
        return "Tester";
    }
};

class Manager : public Staff
{
private:
    vector<Staff *> staffs;

public:
    Manager() = default;
    Manager(string id, string name, string dob, double salaryRate, string beginDate, double baseSalary) : Staff(id, name, dob, salaryRate, beginDate, baseSalary)
    {
    }
    void addStaff(Staff *staff)
    {
        staffs.push_back(staff);
    }
    int countStaffs()
    {
        int count = 0;
        for (Staff *staff : staffs)
        {
            count++;
            if (Manager *manager = dynamic_cast<Manager *>(staff))
            {
                count += manager->countStaffs();
            }
        }
        return count;
    }
    string getType()
    {
        return "Manager";
    }
    double calculateSalary()
    {
        return calculateBaseSalary();
    }
};

int main()
{
    vector<Staff *> staffs = {
        new Programmer("1", "Nguyen Van A", "01/01/2000", 1.5, "01/01/2021", 10000000, 10),
        new Designer("2", "Nguyen Van B", "02/02/2000", 1.5, "02/02/2021", 10000000, 100000000),
        new Tester("3", "Nguyen Van C", "03/03/2000", 1.5, "03/03/2021", 10000000, 10),
        new Programmer("4", "Nguyen Van D", "04/04/2000", 1.5, "04/04/2021", 10000000, 10),
        new Designer("5", "Nguyen Van E", "05/05/2000", 1.5, "05/05/2021", 10000000, 100000000),
        new Tester("6", "Nguyen Van F", "06/06/2000", 1.5, "06/06/2021", 10000000, 10),
        new Programmer("7", "Nguyen Van G", "07/07/2000", 1.5, "07/07/2021", 10000000, 10),
        new Designer("8", "Nguyen Van H", "08/08/2000", 1.5, "08/08/2021", 10000000, 100000000),
        new Tester("9", "Nguyen Van I", "09/09/2000", 1.5, "09/09/2021", 10000000, 10),
        new Programmer("10", "Nguyen Van J", "10/10/2000", 1.5, "10/10/2021", 10000000, 10),
        new Designer("11", "Nguyen Van K", "11/11/2000", 1.5, "11/11/2021", 10000000, 100000000),
        new Tester("12", "Nguyen Van L", "12/12/2000", 1.5, "12/12/2021", 10000000, 10),
    };

    Manager *manager1 = new Manager("13", "Nguyen Van M", "13/13/2000", 1.5, "13/13/2021", 10000000);
    for (int i = 0; i < 9; i++)
    {
        manager1->addStaff(staffs[i]);
    }
    Manager *manager2 = new Manager("14", "Nguyen Van N", "14/14/2000", 1.5, "14/14/2021", 10000000);
    for (int i = 0; i < 10; i++)
    {
        manager2->addStaff(staffs[i]);
    }
    Manager *manager3 = new Manager("15", "Nguyen Van O", "15/15/2000", 1.5, "15/15/2021", 10000000);
    manager3->addStaff(manager1);
    vector<Staff *> staffs2 = {
        manager1,
        manager2,
        manager3,
        staffs[9],
        staffs[10],
    };

    for (Staff *staff : staffs2)
    {
        if (Manager *manager = dynamic_cast<Manager *>(staff))
        {
            if (manager->countStaffs() >= 10)
            {
                cout << "Manager " << manager->getId() << " has more than 10 staffs" << endl;
            }
        }
    }

    vector<Staff *> typeStaffs = {
        new Programmer(),
        new Designer(),
        new Tester(),
        new Manager(),
    };
    for (Staff *staff : typeStaffs)
    {
        const type_info &type = typeid(*staff);
        cout << type.name() << endl;
        const type_info &type2 = typeid(staff);
        cout << type2.name() << endl;
    }
    // Release memory
    for (Staff *staff : staffs)
    {
        delete staff;
    }
    cout << typeid(Manager **).name() << endl;
    delete manager1;
    delete manager2;
    delete manager3;
}