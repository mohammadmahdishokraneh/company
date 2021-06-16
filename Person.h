#ifndef SOAL_2_PERSON_H
#define SOAL_2_PERSON_H

#include "Address.h"

class Person{
private:
    string name;
    string id;
    Address address;
public:
    Person(const string &name, const string &id, const Address &address);
    Person(const Person& obj);
};

#endif //SOAL_2_PERSON_H
