#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "Person.h"

class Employee : public Person {
private:
    int hourWork;
    int salaryPerHour;
    int workToDo;
    int workDone;
public:
    Employee();//constructor no_arg
    Employee(const string &, const string &, const Address &, int, int, int, int);//constructor
    Employee(const Employee &);//copy constructor

    friend ostream &operator<<(ostream &, const Employee &);//output operator
    friend istream &operator>>(istream &, Employee &);//input operator

    Employee &operator=(const Employee &);//assignment operator

    int getHourWork() const;//getter
    void setHourWork(int hourWork);//setter

    int getSalaryPerHour() const;//getter
    void setSalaryPerHour(int salaryPerHour);//setter

    int getWorkToDo() const;//getter
    void setWorkToDo(int workToDo);//setter

    int getWorkDone() const;//getter
    void setWorkDone(int workDone);//setter

    bool validate() override;//id is valid

    virtual int calculateSalary();//calculate employee's salary

    int efficiency();//employee's efficient

    friend bool operator==(const Employee &, const Employee &);//check equality
};

#endif //EMPLOYEE_H
