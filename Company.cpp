#include "Company.h"

Company::Company(int budget, Boss boss, Employee **employees) {
    this->budget = budget;
    this->boss = new Boss(boss);
    this->employees = new Employee *[boss.getNumberOfEmployees()];
    for (int i = 0; i < boss.getNumberOfEmployees(); ++i) {
        this->employees[i] = new Employee(*employees[i]);
    }
}//constructor

Company::Company(const Company &obj) {
    this->budget = obj.budget;
    this->boss = new Boss(*obj.boss);
    this->employees = new Employee *[obj.boss->getNumberOfEmployees()];
    for (int i = 0; i < obj.boss->getNumberOfEmployees(); ++i) {
        this->employees[i] = new Employee(*obj.employees[i]);
    }
}//copy constructor
