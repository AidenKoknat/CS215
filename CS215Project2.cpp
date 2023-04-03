//-------------------------------------------------
//		CS 215-003
//-------------------------------------------------
// Author: Aiden Koknat
// Date: 2/26/20
// Description: Project 2
//-------------------------------------------------

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;
const int MAX_SCORES = 5;
const int MAX_STUDENTS = 5;

struct score { // Structure for student scores.
	int pointsMade; // Amount of Points the students got.
	int pointsPossible;
};

struct student { // Structure for student information.
	int studentID;
	string firstName;
	string lastName;
	score scores[MAX_SCORES];
	int numScore;
};

void init(student p[], int& studentNum) { // Sets up the arrays.
	for (int i = 0; i < studentNum; ++i) {
		p[i].studentID = 0;
		p[i].firstName = "";
		p[i].lastName = "";
		p[i].numScore = 0;
		for (int j = 0; j < p[i].numScore; j++) {
			p[i].scores[j].pointsMade = 0;
			p[i].scores[j].pointsPossible = 0;
		}
	};
}

void load(student p[], int& studentNum) { // Loads the data from 'grades.txt'
	ifstream fin;
	fin.open("grades.txt");
	if (fin.fail()) {
		cout << "'grades.txt' file not found, starting new class." << endl;
		studentNum = 0;
	}
	else {
		fin >> studentNum;
		for (int i = 0; i < studentNum; i++) {
			fin >> p[i].studentID;
			fin >> p[i].firstName;
			fin >> p[i].lastName;
			fin >> p[i].numScore;

			for (int j = 0; j < p[i].numScore; j++) {
				fin >> p[i].scores[j].pointsMade;
				fin >> p[i].scores[j].pointsPossible;
			}
		};
		cout << "'grades.txt' file read" << endl;
	};
	fin.close();
}

void write(student p[], int& studentNum) { // Writes Data to new file called 'gradesout.txt'
	ofstream fout;
	fout.open("gradesout.txt");
	if (fout.fail()) {
		cout << "Unable to open output file." << endl;
	}
	else {
		fout << studentNum;
		fout << endl;
		for (int i = 0; i < studentNum; i++) {
			fout << p[i].studentID << " ";
			fout << p[i].firstName << " ";
			fout << p[i].lastName << " ";
			fout << p[i].numScore << " ";

			for (int j = 0; j < p[i].numScore; j++) {
				fout << p[i].scores[j].pointsMade << " ";
				fout << p[i].scores[j].pointsPossible << " ";
			}
			fout << endl;
		};
		cout << "'gradesout.txt' file written." << endl;
	};
	fout.close();
}

void displayMenu() {
	cout << "+------------------------------+" << endl;
	cout << "|        GRADE PRO PLUS        |" << endl;
	cout << "|        by Aiden Koknat       |" << endl;
	cout << "+------------------------------+" << endl;
	cout << "A - Add Student         D - Drop Student" << endl;
	cout << "V - View Student        P - Print class " << endl;
	cout << "S - Sort by Avg         N - Sort by name" << endl;
	cout << "E - Enter new scores    X - Exit" << endl;
	cout << "Enter menu option: ";
}

char getOption(string option) {
	char opt;
	if (cin.peek() == '\n') cin.ignore(); // discard any leading newline
	getline(cin, option); // get entire line of input, spaces & all
	opt = toupper(option[0]);
	string validOptions = "ADVPSNEX";
	validOptions.find(opt);
	int found = validOptions.find(opt);
	int notOption = -1;
	if (found == notOption) {
		cout << "Invalid option. Choose one of ADVPSNEX" << endl;
	};
	return opt;
}

int search(student p[], int inputStudentID) {
	for (int i = 0; i < MAX_STUDENTS; i++) {
		if (inputStudentID == p[i].studentID) {
			int foundStudentIndex = i;
			return foundStudentIndex;
		}
		if ((i == MAX_STUDENTS - 1) && (inputStudentID != p[i].studentID)) {
			cout << "Student ID: " << inputStudentID << " not found!" << endl;
			return -1;
		}
	}
}

int findStudent(student p[]) {
	int inputStudentID;
	cout << "Input student ID: ";
	cin >> inputStudentID;
	return search(p, inputStudentID);
}

float getAvg(score scores[], int numScore) {
	float sumScore = 0;
	float sumPoss = 0;
	float average;
	if (numScore == 0)
		average = 0;
	else {
		for (int j = 0; j < numScore; j++) {
			sumScore = sumScore + scores[j].pointsMade;
		}
		for (int j = 0; j < numScore; j++) {
			sumPoss = sumPoss + scores[j].pointsPossible;
		}
		average = (sumScore / sumPoss) * 100;
	}
	return average;
}

char getGrade(float average) {
	char grade;
	if (average >= 90)
		grade = 'A';
	if ((average >= 80) && (average < 90))
		grade = 'B';
	if ((average >= 70) && (average < 80))
		grade = 'C';
	if ((average >= 60) && (average < 70))
		grade = 'D';
	if (average < 60)
		grade = 'F';
	return grade;
}

void viewStudent(student p[]) {
	int m = findStudent(p);
	if (m >= 0) {
		cout << "ID: " << p[m].studentID << "    " << "Name:  " << p[m].lastName << ", " << p[m].firstName << endl;

		float average = getAvg(p[m].scores, p[m].numScore);
		cout << "Avg: " << fixed << setprecision(1) << average << "  Grade:  ";
		cout << setprecision(0);
		cout << getGrade(average);
		cout << endl;
		cout << "Number of scores:  " << p[m].numScore << endl;
		cout << "Scores:           ";
		for (int j = 0; j < p[m].numScore; j++) {
			cout << setw(3) << right << p[m].scores[j].pointsMade << "/" << setw(3) << right << p[m].scores[j].pointsPossible << " ";
		}
	}
}

void printReport(student p[], int& studentNum) {
	cout << " ID   Name                   Avg  Grd Scores" << endl;
	cout << "----  --------------------- ----- --- ---------------------------------------" << endl;
	for (int i = 0; i < studentNum; i++) {
		cout << setw(4) << left << p[i].studentID << "  " << setw(22) << left << p[i].firstName + ", " + p[i].lastName;
		cout << setw(5) << right << fixed << setprecision(1) << setw(5) << getAvg(p[i].scores, p[i].numScore);

		cout << setprecision(0);
		cout << setw(3) << right << getGrade(getAvg(p[i].scores, p[i].numScore)) << " ";

		for (int j = 0; j < p[i].numScore; j++) {
			cout << setw(3) << right << p[i].scores[j].pointsMade << "/" << setw(3) << right << p[i].scores[j].pointsPossible << " ";
		}
		cout << endl;
	}
}

void addStudent(student p[], int& studentNum) {
	if (studentNum >= MAX_STUDENTS)
		cout << "No more students may be added.";
	else {
		cout << "Enter student ID number: ";
		cin >> p[studentNum].studentID;
		cout << "Enter first and last name: ";
		cin >> p[studentNum].firstName;
		cin >> p[studentNum].lastName;
		cout << "Enter number of scores: ";
		cin >> p[studentNum].numScore;
		do {	
			if ((p[studentNum].numScore > MAX_SCORES) || (p[studentNum].numScore < 0)) {
				cout << "Invalid number of scores." << endl;
				cout << "Enter number of scores: ";
				cin >> p[studentNum].numScore;
			}
		} while ((p[studentNum].numScore > MAX_SCORES) || (p[studentNum].numScore < 0));

		for (int j = 0; j < p[studentNum].numScore; j++) {
			cout << "Enter score " << j + 1 << " (Points Made | Maximum Possible): ";
			cin >> p[studentNum].scores[j].pointsMade >> p[studentNum].scores[j].pointsPossible;
		}
		cout << "New student added.";
		studentNum = studentNum + 1;
	}
}

student removeStudent(student p[], int i, int& studentNum) {
	if (i >= 0 && i < studentNum) {
		student deleted = p[i];
		studentNum--;
		for (int j = i; j < studentNum; j++)
			p[j] = p[j + 1];
		return deleted;
		studentNum = studentNum - 1;
	}
}

student dropStudent(student p[], int& studentNum) {
	int o = findStudent(p);
	student deleted = removeStudent(p, o, studentNum);
	cout << deleted.firstName << " " << deleted.lastName << " dropped.";
	return deleted;
}

void swap(student p[], int a, int b) {
	student temp = p[a];
	p[a] = p[b];
	p[b] = temp;
}

// Okay, please don't look at this and gawk and say "Boy howdy! This guy doesn't know what the heck he's doing!" This does work. I needed an extra
// function to make it run properly, but only so it doesn't diplay "Class sorted by Name." over and over again.
// The function sortByName works by swapping functions over and over until it is perfectly aligned and no more swaps are necessary. It repeats the
// function whenever it senses a swap has been made. That is why I wrote one with NoCout that was used for repeats, and one generic one.
// It's a different type of sorting algorithm but it is easy to code and makes sense to me.
// I did the same thing with sortByAvg.

void sortByNameNoCout(student p[], int& studentNum) {
	for (int i = 0; i < studentNum; ++i) {
		if (i < studentNum - 1) {
			if (p[i].lastName + p[i].firstName > p[i + 1].lastName + p[i + 1].firstName) {
				swap(p, i, i + 1);
				sortByNameNoCout(p, studentNum);
			}
		}
	}
}

void sortByName(student p[], int& studentNum) {
	for (int i = 0; i < studentNum; ++i) {
		if (i < studentNum - 1) {
			if (p[i].lastName + p[i].firstName > p[i + 1].lastName + p[i + 1].firstName) {
				swap(p, i, i + 1);
				sortByNameNoCout(p, studentNum);
			}
		}
	}
	cout << "Class sorted by Name.";
}

void sortByAvgNoCout(student p[], int& studentNum) {
	for (int i = 0; i < studentNum; ++i) {
		if (i < studentNum - 1) {
			if (getAvg(p[i].scores, p[i].numScore) < getAvg(p[i + 1].scores, p[i].numScore)) {
				swap(p, i, i + 1);
				sortByAvgNoCout(p, studentNum);
			}
		}
	}
}

void sortByAvg(student p[], int& studentNum) {
	for (int i = 0; i < studentNum; ++i) {
		if (i < studentNum - 1) {
			if (getAvg(p[i].scores, p[i].numScore) < getAvg(p[i + 1].scores, p[i].numScore)) {
				swap(p, i, i + 1);
				sortByAvgNoCout(p, studentNum);
			}
		}	
	}
	cout << "Class sorted by Average.";
}

void enterScores(student p[], int& studentNum) {
	sortByName(p, studentNum);
	cout << endl;
	cout << "Enter possible points for this assignment: ";
	int inputMaxTotal;
	cin >> inputMaxTotal;
	
	cout << "Enter points made for each student: " << endl;
	for (int i = 0; i < studentNum; i++) {
		if (p[i].numScore >= MAX_SCORES)
			cout << "Max scores exceeded!" << endl;
		else {
			p[i].scores[(p[i].numScore)].pointsPossible = inputMaxTotal;
			cout << setw(4) << left << p[i].studentID << " " << setw(25) << left << p[i].lastName + ", " + p[i].firstName + ":";
			cin >> p[i].scores[(p[i].numScore)].pointsMade;
			p[i].numScore = p[i].numScore + 1;
		}
	}
}

int main() {
	student p[MAX_STUDENTS]; // Partial Array of students: the array
	int scores[MAX_SCORES]; // Partial Array of : number (1-10)
	string option;
	int studentNum = 0;
	init(p, studentNum);
	load(p, studentNum);
	
	//getOption(oof);
	char opt;
	do {
		displayMenu();
		opt = getOption(option);
		switch (opt) {

			case 'A': // Adds a new student
				addStudent(p, studentNum);
				cout << endl;
				system("PAUSE");
				break;

			case 'E': // Enters a new test score for everyone in the class
				enterScores(p, studentNum);
				cout << endl;
				system("PAUSE");
				break;

			case 'D': // Drops a student from the class
				dropStudent(p, studentNum);
				cout << endl;
				system("PAUSE");
				break;

			case 'P': // Prints the report of students and their grades
				printReport(p, studentNum);
				cout << endl;
				system("PAUSE");
				break;

			case 'V': // Views a student
				viewStudent(p);
				cout << endl;
				system("PAUSE");
				break;

			case 'S': // search student
				sortByAvg(p, studentNum);
				cout << endl;
				system("PAUSE");
				break;

			case 'N': // Sorts by Name
				sortByName(p, studentNum);
				cout << endl;
				system("PAUSE");
				break;

			case 'X': // Exit Application
				break;
		}
		
	} while (opt != 'X');
	write(p, studentNum);
	cout << "Thank you for using Grade Pro Plus!" << endl;
	system("PAUSE");
	return 0;
}