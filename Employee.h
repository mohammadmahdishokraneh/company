#ifndef SOAL_2_EMPLOYEE_H
#define SOAL_2_EMPLOYEE_H

#include "Person.h"

class Employee : public Person {
private:
    int hourWork;
    int salaryPerHour;
    int workToDo;
    int workDone;
public:
    Employee();//constructor no_arg
    Employee(const string &string, const string &string1, const Address &address, int hourWork, int salaryPerHour,
             int workToDo, int workDone);//constructor
    Employee(const Employee &);//copy constructor

    friend ostream& operator << (ostream&, Employee&);
    friend istream& operator >> (istream&, Employee&);
};

#endif //SOAL_2_EMPLOYEE_H
