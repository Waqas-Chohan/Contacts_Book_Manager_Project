#pragma once
#include <string>
using namespace std;

class Address {
private:
    string house;
    string street;
    string city;
    string country;

public:
    Address();
    Address(string house, string street, string city, string country);

    string getHouse() const;
    void setHouse(string house);

    string getStreet() const;
    void setStreet(string street);

    string getCity() const;
    void setCity(string city);

    string getCountry() const;
    void setCountry(string country);

    bool equals(const Address& address);
    void print_address();
    Address copy_address();
};
