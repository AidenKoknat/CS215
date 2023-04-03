#include "contact.h"
#include <iomanip>
using namespace std;
contact::contact() {
	name = "EMPTY";
	phone = "";
}
string contact::getName(){
	return name;
}
string contact::getPhone() {
	return phone;
}
void contact::setName(string s) {
	name = s;
}
void contact::setPhone(string s) {
	phone = s;
}
void contact::print() {
	cout << setw(12) << phone << "" << name << endl;
}