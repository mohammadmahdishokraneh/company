#ifndef BOSS_H
#define BOSS_H

#include "Employee.h"

class Boss : public Employee{
private:
    int numberOfEmployees;
public:
    Boss();//constructor no_arg
    Boss(const string &, const string &, const Address &, int, int, int, int, int);//constructor
    Boss(const Boss&);//copy constructor

    friend ostream& operator << (ostream&, const Boss&);//output operator
    friend istream& operator >> (istream&, Boss&);//input operator
};

#endif //BOSS_H
