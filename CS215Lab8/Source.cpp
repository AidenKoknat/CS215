//-------------------------------------------------------------------
//                      CS 215 - Spring 2019
//                            Lab 8 
//-------------------------------------------------------------------
// Name:        Aiden Koknat
// Section:     003
// Description: Test driver program for the contact and contactList
//              classes
//-------------------------------------------------------------------
#include <iostream>
#include <string>
#include "contactList.h"

using namespace std;

const int EXIT_OPT = 7;

//------------------------------------------------------------
//							getOpt
//------------------------------------------------------------
int getOpt() {
	int opt = 0;
	cout << endl << "1. Add contact" << endl;
	cout << "2. Get contact by index" << endl;
	cout << "3. Search by name" << endl;
	cout << "4. Print contact list" << endl;
	cout << "5. Name the list" << endl;
	cout << "6. Get contact list stats" << endl;
	cout << "7. Exit" << endl;
	cout << "Enter option: ";
	cin >> opt;
	cin.ignore();
	return opt;
}

//------------------------------------------------------------
//							testAddContact
//------------------------------------------------------------
void testAddContact(contactList & list) {
	string name, phone;
	cout << "Enter new contact name:  ";
	getline(cin, name);
	cout << "Enter new contact phone: ";
	getline(cin, phone);
	contact c;
	c.setName(name);
	c.setPhone(phone);
	list.addContact(c);
} // testAddContact()

//------------------------------------------------------------
//							testByIndex
//------------------------------------------------------------
void testByIndex(contactList& list) {
	int index;
	cout << "Enter index: ";
	cin >> index;
	cin.ignore();
	contact c = list.getContact(index);
	c.print();
} // testByIndex()

//------------------------------------------------------------
//							testSearch
//------------------------------------------------------------
void testSearch(contactList& list) {
	string name;

	cout << "Enter search name: ";
	getline(cin, name);
	int index = list.searchByName(name);
	if (index == contactList::NOT_FOUND)
		cout << "Not Found." << endl;
	else {
		contact c = list.getContact(index);
		c.print();
	}
} // testSearch()

//------------------------------------------------------------
//							testSetName
//------------------------------------------------------------
void testSetName(contactList& list) {
	string name;
	cout << "Enter list name: ";
	getline(cin, name);
	list.setName(name);
} // testSetName()

//------------------------------------------------------------
//							testGetStats
//------------------------------------------------------------
void testGetStats(contactList& list) {
	cout << "Number of Contacts: " << list.getNumContacts() << endl << "Name of List: " << list.getName() << endl;
} // testGetStats()

//------------------------------------------------------------
//							main
//------------------------------------------------------------
int main() {
	contactList list;

	int option = 0;
	while (option != EXIT_OPT) {
		option = getOpt();
		switch (option) {
		case 1: testAddContact(list); break;
		case 2: testByIndex(list);    break;
		case 3: testSearch(list);     break;
		case 4: list.print();
			break;
		case 5: testSetName(list);    break;
		case 6: testGetStats(list);   break;
		case EXIT_OPT: cout << "Thanks for playing!" << endl; break;
		default: cout << "Invalid option, try again" << endl;
		} // end switch
	} // end while not EXIT option

	system("pause");
	return 0;
} // main()