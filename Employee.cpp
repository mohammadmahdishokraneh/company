#include "Employee.h"

Employee::Employee() : Person() {hourWork = 0; salaryPerHour = 0; workToDo = 0; workDone = 0;}//constructor no_arg

Employee::Employee(const string &string, const string &string1, const Address &address, int hourWork, int salaryPerHour,
                   int workToDo, int workDone) : Person(string, string1, address), hourWork(hourWork),
                                                 salaryPerHour(salaryPerHour), workToDo(workToDo), workDone(workDone) {}
//constructor

Employee::Employee(const Employee &obj) : Person(Employee) {
    this->hourWork = obj.hourWork;
    this->salaryPerHour = obj.salaryPerHour;
    this->workToDo = obj.workToDo;
    this->workDone = obj.workDone;
}//copy constructor

ostream &operator<<(ostream &strm, Employee &obj) {
    strm << static_cast<const Person &>(employee);
    strm << "hourWork: " << obj.hourWork << "\nsalaryPerHour: " << obj.salaryPerHour << "\nworkToDo: " <<
    obj.workToDo << "\nworkDone" << obj.workDone << endl;
    return strm;
}//output operator

istream &operator>>(istream &strm, Employee &employee) {
    strm >> static_cast<Person &>(employee);
    cout << "hourWork: ";
    strm >> employee.hourWork;
    cout << "salaryPerHour: ";
    strm >> employee.salaryPerHour;
    cout << "workToDo: ";
    strm >> employee.workToDo;
    cout << "workDone: ";
    strm >> employee.workDone;
    return strm;
}//input operator

Employee &Employee::operator=(const Employee &employee) {
    Person::operator=(employee);
    hourWork = employee.hourWork;
    salaryPerHour = employee.salaryPerHour;
    workToDo = employee.workToDo;
    workDone = employee.workDone;
    return *this;
}//assignment operator