//-------------------------------------------------
//		CS 215-003 - Lab 1
//-------------------------------------------------
// Author: Aiden Koknat
// Date: 1/22/2020
// Description: My first C++ program. It does arithmetic on two numbers.
//-------------------------------------------------
#include <iostream>
using namespace std;
int main() {
	cout << "+-------------------+\n|                   |\n| Calculator Wizard |\n|  By Aiden Koknat  |\n|                   |\n+-------------------+\n";
	int i;
	    cout << "Enter a number:       ";
	cin >> i;
	int j;
	    cout << "Enter another number: ";
	cin >> j;
	    cout << "Sum:                  " << i + j << "\n";
		cout << "Difference:           " << i - j << "\n";
		cout << "Product:              " << i * j << "\n";
		cout << "Int Quotient:         " << i / j << "\n";
		cout << "Float Quotient:       " << ((float) i) / j << "\n";
		system("pause");
}