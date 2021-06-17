#ifndef COMPANY_H
#define COMPANY_H

#include "Boss.h"

class Company{
private:
    int budget;
    Boss* boss;
    Employee** employees;
public:
    Company(int, Boss, Employee **);
};

#endif //COMPANY_H
