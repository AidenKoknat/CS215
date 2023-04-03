//-------------------------------------------------
//		CS 215 - Spring 2020
//-------------------------------------------------
// Author: Aiden Koknat
// Date: 1/29/2020
// Description: Lab 2 - Payroll Calculator
// Section: 003
//-------------------------------------------------


#include <iostream>
#include <iomanip>
using namespace std;

const double SSTaxPercent = .03;
const double StateTaxPercent = .06;
const double FedTaxPercent = .07;

int main() {
	cout << "+--------------------+\n";
	cout << "|                    |\n";
	cout << "| Payroll Calculator |\n";
	cout << "|  By Aiden Koknat   |\n";
	cout << "|    Section: 003    |\n";
	cout << "|                    |\n";
	cout << "+--------------------+\n";

	string FirstName;
	cout << "Enter First Name:   ";
	cin >> FirstName;
	string LastName;
	cout << "Enter Last Name:    ";
	cin >> LastName;
	float Hours;
	cout << "Enter Hours Worked: ";
	cin >> Hours;
	float Rate;
	cout << "Enter Pay Rate:     ";
	cin >> Rate;

	cout << "Name:           " << LastName << ", " << FirstName << "\n";
	cout << fixed << setprecision(2) << "Gross Pay $     " << right << setw(8) << (Hours * Rate) << "\n";
	cout << fixed << setprecision(2) << "State Tax $     " << right << setw(8) << (Hours * Rate) * StateTaxPercent << "\n";
	cout << fixed << setprecision(2) << "Fed Tax   $     " << right << setw(8) << (Hours * Rate) * FedTaxPercent << "\n";
	cout << fixed << setprecision(2) << "SS Tax    $     " << right << setw(8) << (Hours * Rate) * SSTaxPercent << "\n";
	cout << fixed << setprecision(2) << "Net Pay   $     " << right << setw(8) << (Hours * Rate) * (1 - (StateTaxPercent + FedTaxPercent + SSTaxPercent)) << "\n";

	
	system("pause");

	return 0;
}