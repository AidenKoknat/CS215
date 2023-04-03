//-------------------------------------------------
//		CS 215-003
//-------------------------------------------------
// Author: Aiden Koknat
// Date: February 5th, 2020
// Description:  Lab 3
//-------------------------------------------------

#include <iostream>
using namespace std;
int main() 
{
	int Number1;
	cout << endl << "Enter number 1: ";
	cin >> Number1;
	int Number2;
	cout << endl << "Enter number 2: ";
	cin >> Number2;
	int Number3;
	cout << endl << "Enter number 3: ";
	cin >> Number3;
	if (Number1 < Number2)
		if(Number1 < Number3)
			if(Number2 < Number3)
				cout << endl << "Sorted they are " << Number1 << " " << Number2 << " " << Number3 << endl;
			else { // Number2 > Number3
				cout << "Sorted they are " << Number1 << " " << Number3 << " " << Number2 << endl;
			}
		else {
			cout << "Sorted they are " << Number3 << " " << Number1 << " " << Number2;
		}
	else { // Number1 > Number2
		if (Number1 > Number3)
			if (Number2 < Number3)
			cout << "Sorted they are " << Number2 << " " << Number3 << " " << Number1 << endl;
			else { // Number2 > Number3
			cout << "Sorted they are " << Number3 << " " << Number2 << " " << Number1 << endl;
			}
		else { // Number1 < Number3
			cout << "Sorted they are " << Number2 << " " << Number1 << " " << Number3 << endl;
		}
	}
	cout << endl;
	
	cout << "A. Aleppo Pepper " << endl;
	cout << "B. Banana Pepper " << endl;
	cout << "C. Cayenne Pepper " << endl;
	cout << "D. Dragons Breath " << endl;
	char n;
	cout << "Enter a letter to choose a pepper: ";
	cin >> n;
	switch (n) {
		case 'a': cout << "That's 30,000 SU of heat!";
			break;
		case 'A': cout << "That's 30,000 SU of heat!";
			break;
		case 'b': cout << "That's 1,000 SU of heat!";
			break;
		case 'B': cout << "That's 1,000 SU of heat!";
			break;
		case 'c': cout << "That's 40,000 SU of heat!";
			break;
		case 'C': cout << "That's 40,000 SU of heat!";
			break;
		case 'd': cout << "That's 2,480,000 SU of heat!";
			break;
		case 'D': cout << "That's 2,480,000 SU of heat!";
			break;
		default: cout << "This is not in the list.";
	}
	cout << endl;
	system("pause");
		return 0;
}	
