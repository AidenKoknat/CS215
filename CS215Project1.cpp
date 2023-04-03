//----------------------------------------------------------------------------------------------------
//		ATM Bank Application
//----------------------------------------------------------------------------------------------------
// Author: Aiden Koknat
// Date: 2/10/2020
// CS215 Section 003
// Description: This code asks the user to input their banking info, then asks to input a menu option.
//				The user can then view their banking information, deposit, or withdraw money.
//----------------------------------------------------------------------------------------------------

#include <iostream>
#include <iomanip>
using namespace std;
int main() {
	string AccountNum; 
	float AccountBal;
	char Option;
	float DepositAmount;
	float WithdrawalAmount;
	
	while (AccountNum != "shutdown") { // While loop repeats the menu after each user sees their reciept
		cout << "+---------------------+" << endl; // Logo
		cout << "| Aiden's Spicy Bank  |" << endl;
		cout << "|      CS215-003      |" << endl;
		cout << "+---------------------+" << endl;
		cout << "Enter account number:  ";
		cin >> AccountNum;
		if (AccountNum == "shutdown") { // Typing in "shutdown" as the Account Number will close the program.
			cout << "Shutting down...bye!";
			break;
		}
		cout << "Enter account balance: ";
		cin >> AccountBal;
		cout << endl;
		cout << "B - Balance Inquiry" << endl; // Menu
		cout << "D - Deposit" << endl;
		cout << "W - Withdrawal" << endl;
		cout << "Please choose an option: ";
		cin >> Option;

		while ((Option != 'D') && (Option != 'B') && (Option != 'W')) { // While loop that prevents user from inputing incorrect Menu character
			cout << '"' << Option << '"' << " " << "is an invalid option. Enter B, D or W." << endl;
			cin >> Option;
		}
		if (Option == 'B') { // Process for Balance Inquiring
			cout << "+---------------------+" << endl;
			cout << "| Aiden's Spicy Bank  |" << endl;
			cout << "+---------------------+" << endl;
			cout << "Account:  " << AccountNum << endl;
			cout << "Balance:   $" << fixed << setprecision(2) << AccountBal << endl;
			cout << endl << "--------------------------------------" << endl << endl;
		}

		if (Option == 'D') { // Process for Depositing
			cout << "Enter deposit amount: ";
			cin >> DepositAmount;
			cout << endl;
			cout << "+---------------------+" << endl;
			cout << "| Aiden's Spicy Bank  |" << endl;
			cout << "+---------------------+" << endl;
			cout << "Account:    " << AccountNum << endl;
			cout << "Prev Ball:  $" << fixed << setprecision(2) << AccountBal << endl;
			cout << "Deposit:    $" << fixed << setprecision(2) << DepositAmount << endl;
			cout << "New Bal:    $" << fixed << setprecision(2) << AccountBal + DepositAmount << endl;
			cout << endl << "--------------------------------------" << endl << endl;
		}
		if (Option == 'W') { // Process for Withdrawing
			cout << "Enter withdrawal amount: ";
			cin >> WithdrawalAmount;
			while (WithdrawalAmount > AccountBal) { // While loop prevents user from withdrawing more than available from account
				cout << "Insufficient Funds. Current Balance is $" << fixed << setprecision(2) << AccountBal << endl;
				cout << "Enter withdrawal amount: "; 
				cin >> WithdrawalAmount;
			}
			cout << endl;
			cout << "+---------------------+" << endl;
			cout << "| Aiden's Spicy Bank  |" << endl;
			cout << "+---------------------+" << endl;
			cout << "Account:    " << AccountNum << endl;
			cout << "Prev Ball:  $" << fixed << setprecision(2) << AccountBal << endl;
			cout << "Withdrawn:  $" << fixed << setprecision(2) << WithdrawalAmount << endl;
			cout << "New Bal:    $" << fixed << setprecision(2) << AccountBal - WithdrawalAmount << endl;
			cout << endl << "--------------------------------------" << endl << endl;
		}
	}
	return 0;
	}

	