#include "Boss.h"

Boss::Boss() : Employee() {numberOfEmployees = 0}//constructor no_arg

Boss::Boss(const std::basic_string<char> &string, const std::basic_string<char> &string1, const Address &address,
           int hourWork, int salaryPerHour, int workToDo, int workDone, int numberOfEmployees) :
           Employee(string, string1, address, hourWork, salaryPerHour, workToDo, workDone),
           numberOfEmployees(numberOfEmployees) {}//constructor

Boss::Boss(const Boss &obj) : Employee(Boss) {
    numberOfEmployees = obj.numberOfEmployees;
}//copy constructor
