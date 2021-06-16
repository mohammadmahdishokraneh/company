#include "Person.h"

Person::Person() : name(""), id("") {
    address.setCountry("");
    address.setCity("");
    address.setStreet("");
}//constructor no_arg

Person::Person(const string &name, const string &id, const Address &address) :
        name(name), id(id), address(address) {}//constructor

Person::Person(const Person &obj) {
    this->name = obj.name;
    this->id = obj.id;
    this->address = obj.address;
}//copy constructor

ostream &operator<<(ostream &strm, Person &obj) {
    strm << "name: " << obj.name << "id: " << obj.id << "address: " << obj.address << endl;
    return strm;
}//output operator

istream &operator>>(istream &strm, Person &obj) {
    cout << "Enter name: ";
    strm >> obj.name;
    cout << "Enter id: ";
    strm >> obj.id;
    cout << "Enter address: ";
    strm >> obj.address;
    return strm;
}//input operator

const string &Person::getName() const {
    return name;
}//getter

void Person::setName(const string &name) {
    Person::name = name;
}//setter

const string &Person::getId() const {
    return id;
}//getter

void Person::setId(const string &id) {
    Person::id = id;
}//setter

const Address &Person::getAddress() const {
    return address;
}//getter

void Person::setAddress(const Address &address) {
    Person::address = address;
}//setter

Person &Person::operator=(const Person &obj) {
    this->name = obj.name;
    this->id = obj.id;
    this->address = obj.address;

    return *this;
}//assignment operator

bool Person::validate() {

    return false;
}//id is valid