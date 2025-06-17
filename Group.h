#pragma once
#include<string>

using namespace std;
class Group {
private:
    string name;
    int* contactIDs;  
    int size;         
    int capacity;     

public:
    Group();
    Group(const string& name);
    ~Group();
    void addContact(int contactID);
    void removeContact(int contactID);
    void viewContacts() const;
};
