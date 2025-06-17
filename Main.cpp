#include <iostream>
#include <string>
#include "ContactsBook.h"
#include "Contact.h"
#include "SearchHistory.h"
#include "Group.h"
#include <windows.h>

using namespace std;

const int LIGHT_BLUE = 9;

void setColor(int textColor) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, textColor);
}

int main() {
    ContactsBook contactsBook(10);
    SearchHistory searchHistory;
    ContactsBook c;
    Group group;
    int choice;
    string fileName;
    string searchName;
    string searchPhone;
    Address searchAddress;
    string sortChoice;
    int index;

    do {
        setColor(LIGHT_BLUE);
        cout << "\n====================Contacts Book Menu=====================";
        cout << "\n||                                                       ||\n";
        cout << "||1. Create a contacts list with given size              ||\n";
        cout << "||2. Add New Contact                                     ||\n";
        cout << "||3. Merge Duplicates                                    ||\n";
        cout << "||4. Store To File                                       ||\n";
        cout << "||5. Load From File                                      ||\n";
        cout << "||6. Print Contacts Sorted                               ||\n";
        cout << "||7. Print Contacts Unsorted                             ||\n";
        cout << "||8. Search contacts                                     ||\n";
        cout << "||9. Display Count of Contacts                           ||\n";
        cout << "||10. View Contact Details                               ||\n"; 
        cout << "||11. Update Contact Details                             ||\n";
        cout << "||12. Delete Contact                                     ||\n"; 
        cout << "||13. View Search History                                ||\n"; 
        cout << "||14. View Frequently Searched Contacts                  ||\n";
        cout << "||15. Create a Group                                     ||\n";
        cout << "||16. Add Contact to Group                               ||\n";
        cout << "||17. Remove Contact from Group                          ||\n";
        cout << "||18. View Contact's Groups                              ||\n";
        cout << "||19. Delete Group                                       ||\n";
        cout << "||0. Exit                                                ||\n";
        cout << "===========================================================\n";
        cout << "     Enter your choice: ";
        cin >> choice;
        system("cls");
        switch (choice) {
        case 1: {
            int size;
            cout << "Enter the size of the contacts list: ";
            cin >> size;
            contactsBook = ContactsBook(size);
            cout << "Contacts list created with size " << size << endl;
            break;
        }
        case 2: {
            string firstName, lastName, mobileNumber, emailAddress, house, street, city, country;
            cout << "Enter First Name: ";
            cin >> firstName;
            cout << "Enter Last Name: ";
            cin >> lastName;
            cout << "Enter Mobile Number: ";
            cin >> mobileNumber;
            cout << "Enter Email Address: ";
            cin >> emailAddress;
            cout << "Enter House: ";
            cin >> house;
            cout << "Enter Street: ";
            cin >> street;
            cout << "Enter City: ";
            cin >> city;
            cout << "Enter Country: ";
            cin >> country;
            Address* address = new Address(house, street, city, country);
            Contact contact(firstName, lastName, mobileNumber, emailAddress, address);
            contactsBook.add_contact(contact);
            cout << "Contact added successfully!\n";
            break;
            system("cls");
        }
        case 3: {
            contactsBook.merge_duplicates();
            cout << "Duplicates merged successfully!\n";
            break;
        }
        case 4: {
            cout << "Enter file name to store: ";
            cin >> fileName;
            contactsBook.save_to_file(fileName);
            cout << "Contacts stored to file successfully!\n";
            break;
        }
        case 5: {
            cout << "Enter file name to load: ";
            cin >> fileName;
            contactsBook.load_from_file(fileName);
            cout << "Contacts loaded from file successfully!\n";
            break;
        }
        case 6: {
            cout << "Enter choice for sorting First name (F or f) or Last Name (L or l): ";
            cin >> sortChoice;
            contactsBook.print_contacts_sorted(sortChoice);
            break;
        }
        case 7: {
            contactsBook.print_contacts();
            break;
        }
        case 8: {
            string searchQuery;
            cout << "Enter search query: ";
            cin >> searchQuery;
            contactsBook.advance_search(searchQuery);
            break;
        }
        case 9: {
            cout << "Total number of contacts: " << contactsBook.total_contacts() << endl;
            break;
        }

        case 10: {
            cout << "Enter index of contact to view: ";
            cin >> index;
            contactsBook.view_contact_details(index);
            break;
        }
        case 11: {
            cout << "Enter index of contact to update: ";
            cin >> index;
            contactsBook.update_contact_details(index);
            cout << "Contact Updated Successfully!" << endl;
            break;
        }
        case 12: {
            cout << "Enter index of contact to delete: ";
            cin >> index;
            contactsBook.delete_contact(index);
            cout << "Contact deleted successfully!\n";
            break;
        }
        case 13: { 
            searchHistory.view_search_history(); 
            break;
        }
        case 14: { 
            searchHistory.view_frequently_searched_contacts(); 
            break;
        }
        case 15: {
            string groupName;
            cout << "Enter group name: ";
            cin >> groupName;
            group = Group(groupName); 
            cout << "Group '" << groupName << "' created successfully!" << endl;
            break;
        }
        case 16: {
            int contactID;
            cout << "Enter contact ID: ";
            cin >> contactID;
            group.addContact(contactID); 
            cout << "Contact added to group successfully!" << endl;
            break;
        }
        case 17: {
            int contactID;
            cout << "Enter contact ID: ";
            cin >> contactID;
            group.removeContact(contactID); 
            cout << "Contact removed from group successfully!" << endl;
            break;
        }
        case 18: {
            group.viewContacts(); 
            break;
        }
        case 19: {
            group = Group(); 
            cout << "Group deleted successfully!" << endl;
            break;
        }
        case 0: {
            cout << "Exiting program...\n";
            break;
        }
        default: {
            cout << "Invalid choice! Please try again.\n";
            break;
        }
        }
    } while (choice != 0);

    return 0;
}