#include "Address.h"

Address::Address(const string &country, const string &city, const string &street) :
        country(country), city(city), street(street) {}
//constructor

Address::Address(const Address&obj) {
    this->country = obj.country;
    this->city = obj.city;
    this->street = obj.street;
}

ostream &operator<<(ostream &strm, const Address &obj) {
    strm << obj.country << "-" << obj.city << "-" << obj.street;
    return strm;
}//output operator

istream &operator>>(istream &strm, Address &obj) {
    cout << "Enter country: ";
    strm >> obj.country;
    cout << "Enter city: ";
    strm >> obj.city;
    cout << "Enter street: ";
    strm >> obj.street;
    return strm;
}//input operator

const string &Address::getCountry() const {
    return country;
}//getter

void Address::setCountry(const string &country) {
    Address::country = country;
}//setter

const string &Address::getCity() const {
    return city;
}//getter

void Address::setCity(const string &city) {
    Address::city = city;
}//setter

const string &Address::getStreet() const {
    return street;
}//getter

void Address::setStreet(const string &street) {
    Address::street = street;
}//setter