#ifndef COMPANY_H
#define COMPANY_H

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

    friend ostream &operator<<(ostream &, const Company &);//output operator
    friend istream &operator>>(istream &, Company &);//input operator

    int getBudget() const;//getter
    void setBudget(int budget);//setter

    Boss getBoss() const;//getter
    void setBoss(Boss boss);//setter

    Employee **getEmployees() const;//getter
    void setEmployees(Employee **employees);//setter

    Employee& maxEfficiency();//find the most efficient employee

    double averageEfficiency();//average efficiency of employees

//    void  changeBoss();

    void gift();//gift for employees
};

#endif //COMPANY_H
