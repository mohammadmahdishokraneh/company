#include "Person.h"

Person::Person() : address() {
    name = "";
    id = "";
}//constructor no_arg

Person::Person(const string &name, const string &id, const Address &address) :
        name(name), id(id), address(address) { validate(); }//constructor

Person::Person(const Person &obj) {
    this->name = obj.name;
    this->id = obj.id;
    this->address = obj.address;
}//copy constructor

ostream &operator<<(ostream &strm, const Person &obj) {
    strm << "name: " << obj.name << "\nid: " << obj.id << "\naddress: " << obj.address;
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
    validate();
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
    char *ch = new char[10];
    strcpy(ch, id.c_str());

    if (id.length() < 8 || id.length() > 10) {
        cout << "invalid id" << endl;
        delete[] ch;
        exit(0);
    }
    if (ch[0] != '9' && ch[0] != '8') {
        cout << "invalid id" << endl;
        delete[] ch;
        exit(0);
    }
    if (ch[0] == '8') {
        if (ch[1] < '4' || ch[1] > '9') {
            cout << "invalid id" << endl;
            delete[] ch;
            exit(0);
        }
    }
    for (int i = id.length() - 1; i > id.length() - 6; --i) {
        if (ch[i] >= '4' && ch[i] <= '6' && ch[i] > '9' && ch[i] < '0') {
            cout << "invalid id" << endl;
            delete[] ch;
            exit(0);
        }
    }
    for (int i = id.length() - 6; i > 1; --i) {
        if (ch[i] > '0' && ch[i] < '9') {
            cout << "invalid id" << endl;
            delete[] ch;
            exit(0);
        }
    }
    delete[] ch;
    return true;
}//id is valid

bool operator==(const Person &obj1, const Person &obj2) {
    if (strcmp(obj1.name.c_str(), obj2.name.c_str()) == 0 &&
        strcmp(obj1.id.c_str(), obj2.id.c_str()) == 0)
        return (obj1.address == obj2.address);
    return false;
}//check equality