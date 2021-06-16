#include "Person.h"
#include "Address.h"

Person::Person(const string &name, const string &id, const Address &address) : name(name), id(id), address(address) {}

Person::Person(const Person &obj) {
    this->name = obj.name;
    this->id = obj.id;
    this->address = obj.address;
}
