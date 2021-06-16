#ifndef BOSS_H
#define BOSS_H

#include "Employee.h"

class Boss : public Employee{
private:
    int numberOfEmployees;
public:
    Boss();//constructor no_arg
    Boss(const string &string, const string &string1, const Address &address, int hourWork, int salaryPerHour,
         int workToDo, int workDone, int numberOfEmployees);//constructor
    Boss(const Boss&);//copy constructor
};

#endif //BOSS_H
