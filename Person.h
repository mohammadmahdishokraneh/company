#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include "Address.h"

using namespace std;

class Person {
private:
    string name;
    string id;
    Address address;
public:
    Person();//constructor no_arg
    Person(const string &, const string &, const Address &);//constructor
    Person(const Person &);//copy constructor

    friend ostream &operator<<(ostream &, Person &);//output operator
    friend istream &operator>>(istream &, Person &);//input operator

    const string &getName() const;//getter
    void setName(const string &);//setter

    const string &getId() const;//getter
    void setId(const string &);//setter

    const Address &getAddress() const;//getter
    void setAddress(const Address &);//setter

    Person& operator=(const Person&);//assignment operator

    virtual bool validate();//id is valid
};

#endif //PERSON_H
