#include "Boss.h"

Boss::Boss(const string &name, const string &id, const Address &address,
           int hourWork, int salaryPerHour, int workToDo, int workDone, int numberOfEmployees) :
           Employee(name, id, address, hourWork, salaryPerHour, workToDo, workDone),
           numberOfEmployees(numberOfEmployees) {}//constructor

Boss::Boss(const Boss &obj) : Employee(static_cast<const Employee &>(obj)) {
    numberOfEmployees = obj.numberOfEmployees;
}//copy constructor

ostream &operator<<(ostream &strm, const Boss &obj) {
    strm << static_cast<const Employee &>(obj)<< endl;
    strm << "number of employee: " << obj.numberOfEmployees;
    return strm;
}//output operator

istream &operator>>(istream &strm, Boss &obj) {
    strm >> static_cast<Employee &>(obj);
    cout << "number of employee: ";
    strm >> obj.numberOfEmployees;
    return strm;
}//input operator

Boss &Boss::operator=(const Boss &obj) {
    Employee::operator=(static_cast<const Employee &>(obj));
    numberOfEmployees = obj.numberOfEmployees;
    return *this;
}//assignment operator

int Boss::getNumberOfEmployees() const {
    return numberOfEmployees;
}//getter

void Boss::setNumberOfEmployees(int numberOfEmployees) {
    Boss::numberOfEmployees = numberOfEmployees;
}//setter

int Boss::calculateSalary() {
    int hourWork = this->getHourWork();
    int salaryPerHour = this->getSalaryPerHour();
    int workDone = this->getWorkDone();
    int workToDo = this->getWorkToDo();
    return hourWork*salaryPerHour*((workDone*100/workToDo)+15)/100;
}//calculate employee's salary
