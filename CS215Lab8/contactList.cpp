#include "contactList.h"
#include <iostream>
using namespace std;
int contactList::NOT_FOUND = -1;

contactList::contactList() {
	name = "NONE";
	numContacts = 0;
}
void contactList::setName(string s) {
	name = s;
}
string contactList::getName() {
	return name;
}
int contactList::getNumContacts() {
	return numContacts;
}
void contactList::addContact(contact c) {
	
	if (numContacts < MAX_CONTACTS) {
		contacts[numContacts] = c;
		numContacts++;
	}
	else {
		cout << "contactList::addContact(): max contact exceeded!" << endl;
		cout << c.getName() << " not added!" << endl;
	}
}
int contactList::searchByName(string s) {
	for (int i = 0; i < numContacts; i++) {
		if (contacts[i].getName() == s)
			return i;
	}
	return NOT_FOUND;
}
contact contactList::getContact(int index) {
	if (index >= 0 && index < numContacts)
		return contacts[index];
	contact c;
	return c;
}
void contactList::print() {
	cout << "List: " << name << "(" << numContacts << " contacts)" << endl;
	for (int i = 0; i < numContacts; i++)
		contacts[i].print();
	cout << endl;
}