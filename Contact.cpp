#include "Contact.h"
#include <iostream>

using namespace std;

Contact::Contact() {}

Contact::Contact(string first_name, string last_name, string mobile_number, string email_address, Address* address)
    : first_name(first_name), last_name(last_name), mobile_number(mobile_number), email_address(email_address), address(address) {}

string Contact::getFirstName() const {
    return first_name;
}

void Contact::setFirstName(string first_name) {
    this->first_name = first_name;
}

string Contact::getLastName() const {
    return last_name;
}

void Contact::setLastName(string last_name) {
    this->last_name = last_name;
}

string Contact::getMobileNumber() const {
    return mobile_number;
}

void Contact::setMobileNumber(string mobile_number) {
    this->mobile_number = mobile_number;
}

string Contact::getEmailAddress() const {
    return email_address;
}

void Contact::setEmailAddress(string email_address) {
    this->email_address = email_address;
}

Address* Contact::getAddress() const {
    return address;
}

void Contact::setAddress(Address* address) {
    this->address = address;
}

bool Contact::equals(const Contact& contact) {
    return (this->first_name == contact.first_name &&
        this->last_name == contact.last_name &&
        this->mobile_number == contact.mobile_number &&
        this->email_address == contact.email_address &&
        this->address->equals(*contact.address));
}

Contact* Contact::copy_contact() {
    Address copiedAddress = address->copy_address();
    return new Contact(first_name, last_name, mobile_number, email_address, &copiedAddress);
}

void Contact::print_contact() {
    cout << "First Name: " << first_name << endl;
    cout << "Last Name: " << last_name << endl;
    cout << "Mobile Number: " << mobile_number << endl;
    cout << "Email Address: " << email_address << endl;
    cout << "Address: ";
    if (address != nullptr) {
        address->print_address();
    }
    else {
        cout << "N/A" << endl;
    }
    cout << endl;
}
