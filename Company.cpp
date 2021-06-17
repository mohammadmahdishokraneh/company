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

Company::~Company() {
    for (int i = 0; i < boss->getNumberOfEmployees(); ++i) {
        delete[] employees[i];
    }
    delete[] employees;
    delete boss;
}//destructor

ostream &operator<<(ostream &strm, const Company &obj) {
    cout << *obj.boss << endl;
    for (int i = 0; i < obj.boss->getNumberOfEmployees(); ++i) {
        strm << *obj.employees[i] << endl;
    }
    cout << "budget: ";
    strm << obj.budget;
    return strm;
}//output operator

istream &operator>>(istream &strm, Company &obj) {
    cin >> *obj.boss;
    for (int i = 0; i < obj.boss->getNumberOfEmployees(); ++i) {
        cin >> *obj.employees[i];
    }
    cout << "budget: ";
    strm >> obj.budget;
    return strm;
}//input operator
