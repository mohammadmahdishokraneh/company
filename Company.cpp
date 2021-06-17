#include "Company.h"

Company::Company(int budget, Boss boss, Employee **employees) {
    this->budget = budget;
    this->boss = new Boss(boss);
    this->employees = new Employee *[boss.getNumberOfEmployees()];
    for (int i = 0; i < this->boss->getNumberOfEmployees(); ++i) {
        this->employees[i] = new Employee(*employees[i]);
    }
}