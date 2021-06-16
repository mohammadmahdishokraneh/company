#include "Employee.h"

Employee::Employee() : Person() {hourWork = 0; salaryPerHour = 0; workToDo = 0; workDone = 0; validate();}//constructor no_arg

Employee::Employee(const std::basic_string<char> &name, const std::basic_string<char> &id, const Address &address, int hourWork, int salaryPerHour,
                   int workToDo, int workDone) : Person(name, id, address), hourWork(hourWork),
                                                 salaryPerHour(salaryPerHour), workToDo(workToDo), workDone(workDone) {validate();}
//constructor

Employee::Employee(const Employee &obj) : Person(obj) {
    this->hourWork = obj.hourWork;
    this->salaryPerHour = obj.salaryPerHour;
    this->workToDo = obj.workToDo;
    this->workDone = obj.workDone;
}//copy constructor

ostream &operator<<(ostream &strm, const Employee &obj) {
    strm << static_cast<const Person &>(obj);
    strm << "hourWork: " << obj.hourWork << "\nsalaryPerHour: " << obj.salaryPerHour << "\nworkToDo: " <<
    obj.workToDo << "\nworkDone" << obj.workDone << endl;
    return strm;
}//output operator

istream &operator>>(istream &strm, Employee &obj) {
    strm >> static_cast<Person &>(obj);
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
    Person::operator=(obj);
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
    char id1[10];
    strcpy(id1, id.c_str());

    if (id1[2] != '*') {
        cout << "invalid id" << endl;
        exit(0);
    }

    return Person::validate(id1);
}//id is valid

int Employee::calculateSalary() {
    return hourWork*salaryPerHour-(hourWork*salaryPerHour*workDone/workToDo);
}//calculate employee's salary

int Employee::efficiency() {
    return (workDone*100/workToDo)/hourWork;
}//employee's efficient

