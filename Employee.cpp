#include "Employee.h"

Employee::Employee(const string &string, const string &string1, const Address &address, int hourWork, int salaryPerHour,
                   int workToDo, int workDone) : Person(string, string1, address), hourWork(hourWork),
                                                 salaryPerHour(salaryPerHour), workToDo(workToDo), workDone(workDone) {}
