#ifndef COMPANY_H
#define COMPANY_H

#include <fstream>
#include "Boss.h"

class Company {
private:
    int budget;
    Boss *boss;
    Employee **employees;
public:
    Company(int, Boss, Employee **);//constructor
    Company(const Company &);//copy constructor
    ~Company();//destructor

    friend ostream &operator<<(ostream &, Company &);//output operator
    friend istream &operator>>(istream &, Company &);//input operator

    int getBudget() const;//getter
    void setBudget(int budget);//setter

    Boss getBoss() const;//getter
    void setBoss(Boss& boss);//setter

    Employee **getEmployees() const;//getter
    void setEmployees(Employee **employees);//setter

    Employee& maxEfficiency();//find the most efficient employee

    double averageEfficiency();//average efficiency of employees

    void  changeOfBoss();//replace the boss with the best employee

    void gift();//gift for employees

    void payForService();

    bool isEnoughBudget();//check the budget

    void toSave();//save information

    void arrange();//arrange employees
};

#endif //COMPANY_H
