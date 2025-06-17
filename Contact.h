#pragma once
#include <string>
#include "Address.h"

using namespace std;

class Contact {
private:
    string first_name;
    string last_name;
    string mobile_number;
    string email_address;
    Address* address;

public:
    Contact();
    Contact(string first_name, string last_name, string mobile_number, string email_address, Address* address);

    string getFirstName() const;
    void setFirstName(string first_name);

    string getLastName() const;
    void setLastName(string last_name);

    string getMobileNumber() const;
    void setMobileNumber(string mobile_number);

    string getEmailAddress() const;
    void setEmailAddress(string email_address);

    Address* getAddress() const;
    void setAddress(Address* address);

    bool equals(const Contact& contact);
    Contact* copy_contact();
    void print_contact();
};
