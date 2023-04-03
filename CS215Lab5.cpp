//-------------------------------------------------
//		CS 215-003
//-------------------------------------------------
// Author: Aiden Koknat
// Date: 2/27/20
// Description: Lab 5
//-------------------------------------------------p
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;
string name1;
string name2;
string name3;

struct precinct {
	int precinctCode;
	int firstVoteNum;
	int secondVoteNum;
	int thirdVoteNum;

};
const int MAX_PRECINCTS = 20; // Partial Array of precincts: max

int main() {
	precinct p[MAX_PRECINCTS];	// Partial Array of precincts: the array
	int precinctNum;			// Partial Array of : number (1-10)

	ifstream fin;
	fin.open("precincts.txt");
	if (fin.fail()) {
		cout << "Failed to open file 'precincts.txt'." << endl;
	}
	else {

		getline(fin, name1);	// name with space end of line
		getline(fin, name2);
		getline(fin, name3);
		fin >> precinctNum;
		for (int i = 0; i < precinctNum; i++) {
			fin >> p[i].precinctCode >> p[i].firstVoteNum >> p[i].secondVoteNum >> p[i].thirdVoteNum;
		}
		cout << "'precincts.txt' file read" << endl;

	}
	fin.close();

	// calculate the total votes for all canidates
	double total1 = 0;
	for (int i = 0; i < precinctNum; i++) {
		total1 += p[i].firstVoteNum;
	}

	double total2 = 0;
	for (int i = 0; i < precinctNum; i++) {
		total2 += p[i].secondVoteNum;
	}

	double total3 = 0;
	for (int i = 0; i < precinctNum; i++) {
		total3 += p[i].thirdVoteNum;
	}

	// sort list of precincts by values, high to low
	for (int i = 0; i < precinctNum - 1; i++) {
		for (int j = i + 1; j < precinctNum; j++)
			if (p[i].precinctCode > p[j].precinctCode) { // swap precincts!
				precinct t;		// temp is same type as h[i]
				t = p[i];		// copy entire precinct record to t
				p[i] = p[j];
				p[j] = t;
			}
	}

	// open output file and check for failure
	ofstream fout;
	fout.open("results.txt");
	if (fout.fail()) {
		cout << "Unable to open file report.txt\n";
	}
	else { // opened OK, write the report
		fout << "--------------------------------------------------------\n";
		fout << "                     ELECTION RESULTS                   \n";
		fout << "--------------------------------------------------------\n";
		fout << "PRECINCT " << name1 << " " << name2 << "   " << name3 << endl;
		fout << "-------- --------------- --------------- ---------------\n";
		for (int j = 0; j < precinctNum; j++) {		// for each horse
			fout << setw(8) << left << p[j].precinctCode << setw(16) << right << p[j].firstVoteNum << setw(16) << right << p[j].secondVoteNum << setw(16) << right << p[j].thirdVoteNum << endl;
		}
		fout << "TOTALS               " << total1 << "             " << total2 << "             " << total3 << endl;
		cout << "Results file written!" << endl;
		fout.close();
	}



	system("PAUSE");
	return 0;
}


