#include "Address.h"
#include <iostream>

using namespace std;

Address::Address() {}

Address::Address(string house, string street, string city, string country)
    : house(house), street(street), city(city), country(country) {}

string Address::getHouse() const {
    return house;
}

void Address::setHouse(string house) {
    this->house = house;
}

string Address::getStreet() const {
    return street;
}

void Address::setStreet(string street) {
    this->street = street;
}

string Address::getCity() const {
    return city;
}

void Address::setCity(string city) {
    this->city = city;
}

string Address::getCountry() const {
    return country;
}

void Address::setCountry(string country) {
    this->country = country;
}

bool Address::equals(const Address& address) {
    return (this->house == address.house &&
        this->street == address.street &&
        this->city == address.city &&
        this->country == address.country);
}

void Address::print_address() {
    cout << house << ", " << street << ", " << city << ", " << country << endl;
}

Address Address::copy_address() {
    return Address(house, street, city, country);
}
