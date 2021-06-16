#include "Boss.h"

Boss::Boss() : Employee() {numberOfEmployees = 0;}//constructor no_arg

Boss::Boss(const std::basic_string<char> &name, const std::basic_string<char> &id, const Address &address,
           int hourWork, int salaryPerHour, int workToDo, int workDone, int numberOfEmployees) :
           Employee(name, id, address, hourWork, salaryPerHour, workToDo, workDone),
           numberOfEmployees(numberOfEmployees) {}//constructor

Boss::Boss(const Boss &obj) : Employee(obj) {
    numberOfEmployees = obj.numberOfEmployees;
}//copy constructor

ostream &operator<<(ostream &strm, const Boss &obj) {
    strm << static_cast<const Person &>(obj);
    strm << "hourWork: " << obj.getHourWork() << "\nsalaryPerHour: " << obj.getSalaryPerHour() << "\nworkToDo: " <<
         obj.getWorkToDo() << "\nworkDone" << obj.getWorkDone() << endl;
    return strm;
}//output operator

istream &operator>>(istream &strm, Boss &obj) {
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