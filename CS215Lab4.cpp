//-------------------------------------------------
//		CS 215-003 
//-------------------------------------------------
// Author: Aiden Koknat
// Date: 2/19/2020
// Description: Game (Lab 4)
//-------------------------------------------------

#include <iostream>
using namespace std;
int main() {
	char opt;
	string answer;
	int sum = 0;
	int i;
	int j;
	int start;
	int stop;
	int box;

	do {
		cout << "S - Sum Between" << endl;
		cout << "B - Print Box" << endl;
		cout << "X - Exit" << endl;
		cout << "Enter option: ";

		cin >> answer;
		opt = answer[0];
	
		switch (opt){
			case 'X':
				cout << "Thanks for playing!" << endl;
				break;

			case 'x':
				cout << "Thanks for playing!" << endl;
				break;

			case 'S': 
				cout << "Enter start and stop numbers: ";
				cin >> start >> stop;
				for (i = start; i <= stop; i++) {
					sum = sum + i;
				}
				cout << "Sum of numbers between " << start << " and " << stop << " is " << sum << endl;
				break;

			case 's':
				cout << "Enter start and stop numbers: ";
				cin >> start >> stop;
				for (i = start; i <= stop; i++) {
					sum = sum + i;
				}
				cout << "Sum of numbers between " << start << " and " << stop << " is " << sum << endl;
				break;

			case 'B':
				cout << "Enter size of box: ";
				cin >> box;
				cout << endl;
				for (i = 0; i < box; i++) {
					for (j = 0; j < box; j++) {
						cout << "* ";
					}
					cout << endl;
				}
				break;

			case 'b':
				cout << "Enter size of box: ";
				cin >> box;
				cout << endl;
				for (i = 0; i < box; i++) {
					for (j = 0; j < box; j++) {
						cout << "* ";
					}
					cout << endl;
				}
				break;

			default:
				cout << "Invalid option! Try again!" << endl;
				break;
	
		}
	} while ((opt != 'x') && (opt != 'X'));
	
	system("PAUSE");
	return 0;
} 