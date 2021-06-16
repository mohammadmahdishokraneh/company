#ifndef SOAL_2_EMPLOYEE_H
#define SOAL_2_EMPLOYEE_H

#include "Person.h"

class Employee : public Person{
private:
    int hourWork;
    int salaryPerHour;
    int workToDo;
    int workDone;
public:
    Employee(const string &string, const string &string1, const Address &address, int hourWork, int salaryPerHour,
             int workToDo, int workDone);
};

#endif //SOAL_2_EMPLOYEE_H
