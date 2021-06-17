#ifndef ADDRESS_H
#define ADDRESS_H

#include <iostream>
#include <cstring>

using namespace std;

class Address {
private:
    string country;
    string city;
    string street;
public:
    Address(const string &, const string &, const string &);//constructor
    Address(const Address &);

    friend ostream &operator<<(ostream &, const Address &);//output operator
    friend istream &operator>>(istream &, Address &);//input operator

    [[nodiscard]] const string &getCountry() const;//getter
    void setCountry(const string &country);//setter

    [[nodiscard]] const string &getCity() const;//getter
    void setCity(const string &city);//setter

    [[nodiscard]] const string &getStreet() const;//getter
    void setStreet(const string &street);//setter
};

#endif //ADDRESS_H
