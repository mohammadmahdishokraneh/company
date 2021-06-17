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

int Company::getBudget() const {
    return budget;
}//getter

void Company::setBudget(int budget) {
    Company::budget = budget;
}//setter

Boss Company::getBoss() const {
    return *boss;
}//getter

void Company::setBoss(Boss &boss) {
    Company::boss = new Boss(boss);
}//setter

Employee **Company::getEmployees() const {
    return employees;
}//getter

void Company::setEmployees(Employee **employees) {
    this->employees = new Employee *[this->boss->getNumberOfEmployees()];
    for (int i = 0; i < this->boss->getNumberOfEmployees(); ++i) {
        this->employees[i] = new Employee(*employees[i]);
    }
}//setter

Employee &Company::maxEfficiency() {
    int max = this->employees[0]->efficiency();
    for (int i = 1; i < this->boss->getNumberOfEmployees(); ++i) {
        if (max > this->employees[i]->efficiency())
            max = this->employees[i]->efficiency();
    }
    for (int i = 0; i < this->boss->getNumberOfEmployees(); ++i) {
        if (max == this->employees[i]->efficiency())
            return *this->employees[i];
    }
    return *this->employees[0];
}//find the most efficient employee

double Company::averageEfficiency() {
    double average = 0;
    for (int i = 0; i < this->boss->getNumberOfEmployees(); ++i) {
        average += this->employees[i]->efficiency();
    }
    return average / this->boss->getNumberOfEmployees();
}//average efficiency of employees

void Company::changeOfBoss() {
    Employee newBoss = maxEfficiency();
    if (this->boss->efficiency() < 40) {
        for (int i = 0; i < this->boss->getNumberOfEmployees(); ++i) {
            if (*this->employees[i] == newBoss) {
                int numberOfEmployees = this->boss->getNumberOfEmployees();
                Employee temp = *this->employees[i];
                *this->employees[i] = static_cast<Employee>(*this->boss);
                this->setBoss(static_cast<Boss &>(temp));
                this->boss->setNumberOfEmployees(numberOfEmployees);
                break;
            }
        }
    }
}//replace the boss with the best employee

void Company::gift() {
    for (int i = 0; i < this->boss->getNumberOfEmployees(); ++i) {
        char *ch = new char[10];
        strcpy(ch, this->employees[i]->getId().c_str());
        if (ch[0] == '8')
            this->employees[i]->setHourWork(this->employees[i]->getHourWork() + 5);
        if (*this->employees[i] == this->maxEfficiency())
            this->employees[i]->setHourWork(this->employees[i]->getHourWork() + 10);
        delete[] ch;
    }
}//gift for employees

void Company::payForService() {
    for (int i = 0; i < this->boss->getNumberOfEmployees(); ++i) {
        if (strcmp(this->employees[i]->getAddress().getCity().c_str(), "tehran") != 0 &&
            strcmp(this->employees[i]->getAddress().getCity().c_str(), "Tehran") != 0)
            this->employees[i]->setHourWork(this->employees[i]->getHourWork() + 7);
    }
}

bool Company::isEnoughBudget() {
    int sum = this->boss->calculateSalary();
    for (int i = 0; i < this->boss->getNumberOfEmployees(); ++i) {
        sum += this->employees[i]->calculateSalary();
    }
    if (sum <= this->budget)
        return true;
    return false;
}//check the budget

void Company::toSave() {
    ofstream save("company.txt");
    for (int i = 0; i < this->boss->getNumberOfEmployees(); ++i) {
        save << this->employees[i]->getName() << this->employees[i]->getId() << this->employees[i]->efficiency() <<
             this->employees[i]->calculateSalary();
    }
}//save information