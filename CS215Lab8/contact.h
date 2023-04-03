#ifndef CONTACT_H
#define CONTACT_H
#include <iostream>
using std::string;
class contact {
private:
	string name;
	string phone;
public:
	contact();
	string getName();
	string getPhone();
	void setName(string s);
	void setPhone(string s);
	void print();
};
#endif
