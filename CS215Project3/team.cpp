#include <string>
#include <iostream>
#include <iomanip>
#include "team.h"
#include <fstream>
using namespace std;

team::team() { // constructor 
	numGames = 0;
	numPlayers = 0;
} // team()

void team::setNumGames(int s) {
	numGames = s;
}
int team::getNumGames() {
	return numGames;
}

void team::setNumPlayers(int s) {
	numPlayers = s;
}
int team::getNumPlayers() {
	return numPlayers;
}

void team::read() {
	int tempJerseyNum;
	string firstName;
	string lastName;
	ifstream fin;
	fin.open("bballin.txt");
	if (fin.fail())
		cout << "Failed to open text file 'bballing.txt'";
	else {
		fin >> numPlayers;
		fin >> numGames;
		for (int i = 0; i < numPlayers; i++) {
			players[i].gamesPlayed = numGames;
			fin >> tempJerseyNum;
			players[i].setJerseyNum(tempJerseyNum);
			fin >> lastName;
			fin >> firstName;
			players[i].setPlayerName(lastName + " " + firstName);
			int made;
			int poss;
			for (int j = 0; j < numGames; j++) {
				fin >> made;
				fin >> poss;
				players[i].threePointers[j].setPointsMade(made);
				players[i].threePointers[j].setPointsPossible(poss);
				fin >> made;
				fin >> poss;
				players[i].twoPointers[j].setPointsMade(made);
				players[i].twoPointers[j].setPointsPossible(poss);
				fin >> made;
				fin >> poss;
				players[i].freeThrows[j].setPointsMade(made);
				players[i].freeThrows[j].setPointsPossible(poss);
			}
		}
	}
	fin.close();
} // read()

void team::printTeam() {
	for (int i = 0; i < numPlayers; i++) {
		players[i].printPlayer();
		cout << endl;
	}
} // printTeam()

void team::addGame() {
	if (numGames + 1 >= MAX_GAMES)
		cout << "Maximum amount of games played reached." << endl;
	else {
		for (int i = 0; i < numPlayers; i++) {
			int a;
			int b;
			int c;
			int d;
			int e;
			int f;
			cout << "Enter Made Three Pointers for " << players[i].getPlayerName() << ": ";
			cin >> a;
			cout << "Enter Attempted Three Pointers for " << players[i].getPlayerName() << ": ";
			cin >> b;
			cout << "Enter Made Two Pointers for " << players[i].getPlayerName() << ": ";
			cin >> c;
			cout << "Enter Attempted Two Pointers for " << players[i].getPlayerName() << ": ";
			cin >> d;
			cout << "Enter Made Free Throws for " << players[i].getPlayerName() << ": ";
			cin >> e;
			cout << "Enter Attempted Free Throws for " << players[i].getPlayerName() << ": ";
			cin >> f;
			players[i].player::addGame(a, b, c, d, e, f);
		}
		numGames = numGames + 1;
	}
} // addGame()

int team::searchPlayer() {
	int temp;
	cout << "Enter Jersey Number of Player: ";
	cin >> temp;
	for (int i = 0; i < numPlayers; i++) {
		if (temp == players[i].getJerseyNum())
			return i;
		if ((i == numPlayers - 1) && (temp != players[i].getJerseyNum())) {
				return -1;
		}
	}
} // searchPlayer()

void team::displayPlayer() {
	int i;
	i = searchPlayer();
	if (i == -1)
		cout << "Player not found.";
	else
		players[i].printPlayer();
} // displayPlayer()

void team::removePlayer() {
	int i;
	i = searchPlayer();
	if (i == -1)
		cout << "Player not found.";
	else {
		player deleted = players[i];
		numPlayers--;
		for (int j = i; j < numPlayers; j++)
			players[j] = players[j + 1];
		cout << "Player removed.";
	}
} // removePlayer()

void team::sortByName() {
	for (int i = 0; i < numPlayers; ++i) {
		if (i < numPlayers - 1) {
			player temp;
			if (players[i].getPlayerName() > players[i + 1].getPlayerName()) {
				temp = players[i];
				players[i] = players[i+1];
				players[i + 1] = temp;
				sortByName();
			}
		}
	}
} // sortByName()

void team::sortByJersey() {
	for (int i = 0; i < numPlayers; ++i) {
		if (i < numPlayers - 1) {
			player temp;
			if (players[i].getJerseyNum() > players[i + 1].getJerseyNum()) {
				temp = players[i];
				players[i] = players[i + 1];
				players[i + 1] = temp;
				sortByJersey();
			}
		}
	}
} // sortByJersey()

void team::write() {
	ofstream fout;
	fout.open("bballout.txt");
	if (fout.fail()) {
		cout << "Failed to write 'bballout.txt' file.";
	}
	else {
		fout << numPlayers << " " << numGames << endl;
		for (int i = 0; i < numPlayers; i++) {
			fout << players[i].getJerseyNum() << " " << players[i].getPlayerName() << endl;
			for (int j = 0; j < numGames; j++) {
				fout << players[i].threePointers[j].getPointsMade();
				fout << "  ";
				fout << players[i].threePointers[j].getPointsPossible();
				fout << "  ";
				fout << players[i].twoPointers[j].getPointsMade();
				fout << "  ";
				fout << players[i].twoPointers[j].getPointsPossible();
				fout << "  ";
				fout << players[i].freeThrows[j].getPointsMade();
				fout << "  ";
				fout << players[i].freeThrows[j].getPointsPossible();
				fout << endl;
			}
		}
		
	}
} // write()