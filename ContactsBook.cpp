#include "ContactsBook.h"
#include <fstream>
#include <iostream>

using namespace std;

ContactsBook::~ContactsBook() {}

ContactsBook::ContactsBook() {}

ContactsBook::ContactsBook(int size_of_list)
    : contacts_list(size_of_list) {}

Contact& ContactsBook::get_contact(int index) {
    return contacts_list.GetItem(index);
}

void ContactsBook::add_contact(const Contact& contact) {
    contacts_list.AddItem(contact);
}

int ContactsBook::total_contacts() {
    return contacts_list.GetSize();
}

void ContactsBook::print_contacts_sorted(string choice) {
    if (choice != "f" && choice != "l" && choice != "F" && choice != "L") {
        cout << "Invalid choice for sorting contacts." << endl;
        return;
    }

    for (int i = 0; i < contacts_list.GetSize() - 1; ++i) {
        for (int j = 0; j < contacts_list.GetSize() - i - 1; ++j) {
            bool swap_needed = false;
            if (choice == "F" || choice == "f") {
                if (contacts_list.GetItem(j).getFirstName() > contacts_list.GetItem(j + 1).getFirstName()) {
                    swap_needed = true;
                }
            }
            else { 
                if (contacts_list.GetItem(j).getLastName() > contacts_list.GetItem(j + 1).getLastName()) {
                    swap_needed = true;
                }
            }

            if (swap_needed) {
                
                Contact temp = contacts_list.GetItem(j);
                contacts_list.SetItem(j, contacts_list.GetItem(j + 1));
                contacts_list.SetItem(j + 1, temp);
            }
        }
    }

    for (int i = 0; i < contacts_list.GetSize(); ++i) {
        contacts_list.GetItem(i).print_contact();
    }
}

void ContactsBook::merge_duplicates() {
    for (int i = 0; i < contacts_list.GetSize(); ++i) {
        for (int j = i + 1; j < contacts_list.GetSize(); ++j) {
            if (contacts_list.GetItem(i).equals(contacts_list.GetItem(j))) {
                contacts_list.RemoveItem(j);
                j--; // Adjust the index as contacts shifted one position left
            }
        }
    }
}

void ContactsBook::load_from_file(string file_name) {
    std::ifstream file(file_name);
    if (!file.is_open()) {
        cout << "Error: Unable to open file: " << file_name << endl;
        return;
    }

    // Read contacts from file
    while (!file.eof()) {
        string first_name, last_name, mobile_number, email_address, house, street, city, country;
        file >> first_name >> last_name >> mobile_number >> email_address >> house >> street >> city >> country;
        Address* address = new Address(house, street, city, country);
        Contact contact(first_name, last_name, mobile_number, email_address, address);
        add_contact(contact);
    }

    file.close();
}

void ContactsBook::save_to_file(string file_name) {
    std::ofstream file(file_name);
    if (!file.is_open()) {
        cout << "Error: Unable to open file: " << file_name << endl;
        return;
    }

    // Write contacts to file
    for (int i = 0; i < contacts_list.GetSize(); ++i) {
        file << contacts_list.GetItem(i).getFirstName() << " " << contacts_list.GetItem(i).getLastName() << " "
            << contacts_list.GetItem(i).getMobileNumber() << " " << contacts_list.GetItem(i).getEmailAddress() << " "
            << contacts_list.GetItem(i).getAddress()->getHouse() << " " << contacts_list.GetItem(i).getAddress()->getStreet() << " "
            << contacts_list.GetItem(i).getAddress()->getCity() << " " << contacts_list.GetItem(i).getAddress()->getCountry() << endl;
    }

    file.close();
}

//Contact* ContactsBook::search_contact(string first_name, string last_name) {
//    for (int i = 0; i < contacts_list.GetSize(); ++i) {
//        if (contacts_list.GetItem(i).getFirstName() == first_name &&
//            contacts_list.GetItem(i).getLastName() == last_name) {
//            return &contacts_list.GetItem(i);
//        }
//    }
//    return nullptr; // Contact not found
//}
//
//Contact* ContactsBook::search_contact(string phone) {
//    for (int i = 0; i < contacts_list.GetSize(); ++i) {
//        if (contacts_list.GetItem(i).getMobileNumber() == phone) {
//            return &contacts_list.GetItem(i);
//        }
//    }
//    return nullptr; // Contact not found
//}
//
//Contact* ContactsBook::search_contact(const Address& address) {
//    for (int i = 0; i < contacts_list.GetSize(); ++i) {
//        if (contacts_list.GetItem(i).getAddress()->equals(address)) {
//            return &contacts_list.GetItem(i);
//        }
//    }
//    return nullptr; // Contact not found
//}

void ContactsBook::print_contacts() {
    cout << "Printing all contacts:\n";
    for (int i = 0; i < contacts_list.GetSize(); ++i) {
        contacts_list.GetItem(i).print_contact();
    }
}
void ContactsBook::view_contact_details(int index) {
    if (index < 0 || index >= contacts_list.GetSize()) {
        cout << "Invalid index\n";
        return;
    }
    contacts_list.GetItem(index).print_contact();
}

void ContactsBook::update_contact_details(int index) {
    if (index < 0 || index >= contacts_list.GetSize()) {
        cout << "Invalid index\n";
        return;
    }

    // Retrieve the contact
    Contact& contact = get_contact(index);
    string firstName, lastName, mobileNumber, emailAddress, house, street, city, country;
    cout << "Enter updated First Name: ";
    cin >> firstName;
    contact.setFirstName(firstName);
    cout << "Enter updated Last Name: ";
    cin >> lastName;
    contact.setLastName(lastName);
    cout << "Enter updated Mobile Number: ";
    cin >> mobileNumber;
    contact.setMobileNumber(mobileNumber);
    cout << "Enter updated Email Address: ";
    cin >> emailAddress;
    contact.setEmailAddress(emailAddress);
    cout << "Enter updated House: ";
    cin >> house;
    cout << "Enter updated Street: ";
    cin >> street;
    cout << "Enter updated City: ";
    cin >> city;
    cout << "Enter updated Country: ";
    cin >> country;
    Address* updatedAddress = new Address(house, street, city, country);
    contact.setAddress(updatedAddress);
}
void ContactsBook::delete_contact(int index) {
    if (index < 0 || index >= contacts_list.GetSize()) {
        cout << "Invalid index\n";
        return;
    }
    contacts_list.RemoveItem(index);
}
void ContactsBook::advance_search(const string& query) const {
    string lowercaseQuery = query;
    for (char& c : lowercaseQuery) {
        c = tolower(c);
    }

    for (int i = 0; i < contacts_list.GetSize(); ++i) {
        const Contact& contact = contacts_list.GetItem(i);

        string firstName = contact.getFirstName();
        for (char& c : firstName) {
            c = tolower(c);
        }

        string lastName = contact.getLastName();
        for (char& c : lastName) {
            c = tolower(c);
        }

        string mobileNumber = contact.getMobileNumber();
        for (char& c : mobileNumber) {
            c = tolower(c);
        }

        string emailAddress = contact.getEmailAddress();
        for (char& c : emailAddress) {
            c = tolower(c);
        }

        string house = contact.getAddress()->getHouse();
        for (char& c : house) {
            c = tolower(c);
        }

        string street = contact.getAddress()->getStreet();
        for (char& c : street) {
            c = tolower(c);
        }

        string city = contact.getAddress()->getCity();
        for (char& c : city) {
            c = tolower(c);
        }

        string country = contact.getAddress()->getCountry();
        for (char& c : country) {
            c = tolower(c);
        }

        bool found = false;
        for (size_t j = 0; j + lowercaseQuery.size() - 1 < firstName.size(); ++j) {
            bool match = true;
            for (size_t k = 0; k < lowercaseQuery.size(); ++k) {
                if (tolower(firstName[j + k]) != lowercaseQuery[k]) {
                    match = false;
                    break;
                }
            }
            if (match) {
                found = true;
                break;
            }
        }

        if (!found) {
            for (size_t j = 0; j + lowercaseQuery.size() - 1 < lastName.size(); ++j) {
                bool match = true;
                for (size_t k = 0; k < lowercaseQuery.size(); ++k) {
                    if (tolower(lastName[j + k]) != lowercaseQuery[k]) {
                        match = false;
                        break;
                    }
                }
                if (match) {
                    found = true;
                    break;
                }
            }
        }

        if (!found) {
            for (size_t j = 0; j + lowercaseQuery.size() - 1 < mobileNumber.size(); ++j) {
                bool match = true;
                for (size_t k = 0; k < lowercaseQuery.size(); ++k) {
                    if (tolower(mobileNumber[j + k]) != lowercaseQuery[k]) {
                        match = false;
                        break;
                    }
                }
                if (match) {
                    found = true;
                    break;
                }
            }
        }

        if (found) {
            cout << "Contact found:" << endl;
            cout << "First Name: " << contact.getFirstName() << endl;
            cout << "Last Name: " << contact.getLastName() << endl;
            cout << "Mobile Number: " << contact.getMobileNumber() << endl;
            cout << "Email Address: " << contact.getEmailAddress() << endl;
            cout << "Address: " << contact.getAddress()->getHouse() << ", "
                << contact.getAddress()->getStreet() << ", "
                << contact.getAddress()->getCity() << ", "
                << contact.getAddress()->getCountry() << endl;
            cout << "------------------------" << endl;
        }
    }
}
