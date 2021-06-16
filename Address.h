#ifndef SOAL_2_ADDRESS_H
#define SOAL_2_ADDRESS_H

class Address {
private:
    string country;
    string city;
    string street;
public:
    Address(const string &country, const string &city, const string &street);

    friend ostream &operator<<(ostream &, Address &);

    friend ostream &operator>>(ostream &, Address &);

    [[nodiscard]] const string &getCountry() const;

    void setCountry(const string &country);

    [[nodiscard]] const string &getCity() const;

    void setCity(const string &city);

    [[nodiscard]] const string &getStreet() const;

    void setStreet(const string &street);
};

#endif //SOAL_2_ADDRESS_H
