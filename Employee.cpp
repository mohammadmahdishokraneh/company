#include "Employee.h"

Employee::Employee() : Person() {hourWork = 0; salaryPerHour = 0; workToDo = 0; workDone = 0;}//constructor no_arg

Employee::Employee(const string &string, const string &string1, const Address &address, int hourWork, int salaryPerHour,
                   int workToDo, int workDone) : Person(string, string1, address), hourWork(hourWork),
                                                 salaryPerHour(salaryPerHour), workToDo(workToDo), workDone(workDone) {}
//constructor

Employee::Employee(const Employee &obj) {
    this->hourWork = obj.hourWork;
    this->salaryPerHour = obj.salaryPerHour;
    this->workToDo = obj.workToDo;
    this->workDone = obj.workDone;
}//copy constructor
