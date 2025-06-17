#pragma once
#include <string>
#include "Contact.h"
#include "ResizableArray.h"

using namespace std;

class ContactsBook {
private:
    /*Contact* contacts_list;*/
    int size_of_contacts;
    int contacts_count;
    ResizableArray<Contact> contacts_list;

public:
    ~ContactsBook();
    ContactsBook();
    ContactsBook(int size_of_list);
    Contact& get_contact(int index);
    void add_contact(const Contact& contact);
    int total_contacts();
  /*  bool full();
    void resize_list();*/
    void print_contacts_sorted(string choice);
    void merge_duplicates();
    void load_from_file(string file_name);
    void save_to_file(string file_name);
    /*Contact* search_contact(string first_name, string last_name);
    Contact* search_contact(string phone);
    Contact* search_contact(const Address& address);*/
    void print_contacts();
    void view_contact_details(int index);
    void update_contact_details(int index);
    void delete_contact(int index);
    void advance_search(const string& query) const;

};
