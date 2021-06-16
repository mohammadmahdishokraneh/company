#include "Address.h"
#include <iostream>

using namespace std;

Address::Address(const string &country, const string &city, const string &street) : country(country), city(city),
                                                                                    street(street) {}

ostream &operator<<(ostream &strm, Address &obj) {
    strm << obj.country << "-" << obj.city << "-" << obj.street << endl;
    return strm;
}

ostream &operator>>(ostream &strm, Address &obj) {
    cout << "Enter country: ";
    strm >> obj.country;
    cout << "Enter city: ";
    strm >> obj.city;
    cout << "Enter street: ";
    strm >> obj.street;
    return strm;
}

const string &Address::getCountry() const {
    return country;
}

void Address::setCountry(const string &country) {
    Address::country = country;
}

const string &Address::getCity() const {
    return city;
}

void Address::setCity(const string &city) {
    Address::city = city;
}

const string &Address::getStreet() const {
    return street;
}

void Address::setStreet(const string &street) {
    Address::street = street;
}

