//-------------------------------------------------
//		CS 215-003
//-------------------------------------------------
// Author: Aiden Koknat
// Date:3/9/20
// Description: Lab 6
//-------------------------------------------------

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

struct frac { // structure used to have denominator and numerator for each fraction
	int numerator;
	int denominator;
};

void PrintLogo() {
	cout << "+-------------------------------------------+" << endl;
	cout << "|               FRACTION FUN                |" << endl;
	cout << "|              by Aiden Koknat              |" << endl;
	cout << "+-------------------------------------------+" << endl;
}

int AskFraction(frac& f) { // gets fraction values
	cout << "Enter numerator: ";
	cin >> f.numerator;
	cout << "Enter denominator: ";
	cin >> f.denominator;
	if (f.denominator == 0) {
		cout << "Please enter denominator value other than 0: ";
		cin >> f.denominator;
	}
	return f.numerator;
	return f.denominator;
}

double DecimalValue(frac f) {
	double decimal = (float(f.numerator) / f.denominator);
	return decimal;
}

void PrintFraction(frac f) {
	cout << f.numerator << "/" << f.denominator;
}

 frac Add(frac fraction1, frac fraction2) {
	 frac addedFrac;
	 if (fraction1.denominator == fraction2.denominator) {
		
		 addedFrac.numerator = fraction1.numerator + fraction2.numerator;
		 addedFrac.denominator = fraction1.denominator;
	 }
	 else {
		 addedFrac.numerator = ((fraction1.numerator * fraction2.denominator) + (fraction2.numerator * fraction1.denominator));
		 addedFrac.denominator = (fraction1.denominator * fraction2.denominator);
	 }
	return addedFrac;
 }


int main() {
	frac f1;
	frac f2;
	frac sum;

	PrintLogo();
	AskFraction(f1);
	AskFraction(f2);
	DecimalValue(f1);
	sum = Add(f1, f2);

	cout << "Decimal Value of "; 
	PrintFraction(f1);
	cout << " is " << DecimalValue(f1);
	
	

	cout << endl;
	
	PrintFraction(f1);
	cout << " + ";
	PrintFraction(f2);
	cout << " = ";
	PrintFraction(sum);
	cout << endl;

	system("pause");
	return 0;
}
