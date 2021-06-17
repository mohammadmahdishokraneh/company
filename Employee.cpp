#include "Employee.h"

Employee::Employee(const string &name, const string &id, const Address &address, int hourWork, int salaryPerHour,
                   int workToDo, int workDone) : Person(name, id, address), hourWork(hourWork),
                                                 salaryPerHour(salaryPerHour), workToDo(workToDo), workDone(workDone) {validate();}
//constructor

Employee::Employee(const Employee &obj) : Person(static_cast<const Person &>(obj)) {
    this->hourWork = obj.hourWork;
    this->salaryPerHour = obj.salaryPerHour;
    this->workToDo = obj.workToDo;
    this->workDone = obj.workDone;
}//copy constructor

ostream &operator<<(ostream &strm, const Employee &obj) {
    cout << static_cast<const Person &>(obj) << endl;
    strm << "hourWork: " << obj.hourWork << "\nsalaryPerHour: " << obj.salaryPerHour << "\nworkToDo: " <<
    obj.workToDo << "\nworkDone: " << obj.workDone;
    return strm;
}//output operator

istream &operator>>(istream &strm, Employee &obj) {
    cin >> static_cast<Person &>(obj);
    cout << "hourWork: ";
    strm >> obj.hourWork;
    cout << "salaryPerHour: ";
    strm >> obj.salaryPerHour;
    cout << "workToDo: ";
    strm >> obj.workToDo;
    cout << "workDone: ";
    strm >> obj.workDone;
    return strm;
}//input operator

Employee &Employee::operator=(const Employee &obj) {
    Person::operator=(static_cast<const Person&>(obj));
    hourWork = obj.hourWork;
    salaryPerHour = obj.salaryPerHour;
    workToDo = obj.workToDo;
    workDone = obj.workDone;
    return *this;
}//assignment operator

int Employee::getHourWork() const {
    return hourWork;
}//getter

void Employee::setHourWork(int hourWork) {
    Employee::hourWork = hourWork;
}//setter

int Employee::getSalaryPerHour() const {
    return salaryPerHour;
}//getter

void Employee::setSalaryPerHour(int salaryPerHour) {
    Employee::salaryPerHour = salaryPerHour;
}//setter

int Employee::getWorkToDo() const {
    return workToDo;
}//getter

void Employee::setWorkToDo(int workToDo) {
    Employee::workToDo = workToDo;
}//setter

int Employee::getWorkDone() const {
    return workDone;
}//getter

void Employee::setWorkDone(int workDone) {
    Employee::workDone = workDone;
}//setter

bool Employee::validate() {
    if (this->getId().c_str()[2] != '*') {
        cout << "invalid id" << endl;
        exit(0);
    }
    return Person::validate();
}//id is valid

int Employee::calculateSalary() {
    return hourWork*salaryPerHour*workDone/workToDo;
}//calculate employee's salary

int Employee::efficiency() {
    return (workDone*100/workToDo)/hourWork;
}//employee's efficient

