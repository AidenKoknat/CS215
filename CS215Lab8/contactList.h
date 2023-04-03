#ifndef CONTACT_LIST
#define CONTACT_LIST
#include <iostream>coj
#include "contact.h"
int const MAX_CONTACTS = 5;
using std::string;
class contactList {
private:
	contact contacts[5];
	int numContacts;
	string name;
public:
	static int NOT_FOUND;
	contactList();
	void setName(string s);
	string getName();
	int getNumContacts();
	void addContact(contact c);
	int searchByName(string s);
	contact getContact(int index);
	void print();
};
#endif