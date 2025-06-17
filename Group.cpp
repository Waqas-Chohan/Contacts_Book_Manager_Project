#include "Group.h"
#include <iostream>

using namespace std;

Group::Group(){}
Group::Group(const string& name) : name(name), size(0), capacity(10) {
    contactIDs = new int[capacity];
}

Group::~Group() {
    delete[] contactIDs;
}

void Group::addContact(int contactID) {
    // Resize array if necessary
    if (size == capacity) {
        int* newArray = new int[capacity * 2];
        for (int i = 0; i < size; ++i) {
            newArray[i] = contactIDs[i];
        }
        delete[] contactIDs;
        contactIDs = newArray;
        capacity *= 2;
    }
    contactIDs[size++] = contactID;
}

void Group::removeContact(int contactID) {
    int index = -1;
    for (int i = 0; i < size; ++i) {
        if (contactIDs[i] == contactID) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        for (int i = index; i < size - 1; ++i) {
            contactIDs[i] = contactIDs[i + 1];
        }
        size--;
    }
}

void Group::viewContacts() const {
    cout << "Contacts in group '" << name << "':" << endl;
    if (size == 0) {
        cout << "No contacts in this group." << endl;
    }
    else {
        for (int i = 0; i < size; ++i) {
            cout << contactIDs[i] << endl; 
        }
    }
}
