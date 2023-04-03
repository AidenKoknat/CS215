#include <string>
#include <iostream>
#include <iomanip>
#include "player.h"
using namespace std;

player::player() { // constructor
	playerName = "NONE";
	jerseyNum = 0;
	gamesPlayed = 0;
} // player()

void player::setPlayerName(string s) {
	playerName = s;
}
string player::getPlayerName() {
	return playerName;
}

void player::setJerseyNum(int s) {
	jerseyNum = s;
}
int player::getJerseyNum() {
	return jerseyNum;
}

int player::getGamesPlayed() {
	return gamesPlayed;
}

void player::addGame(int madeone, int possone, int madetwo, int posstwo, int madethree, int possthree) {
	if (gamesPlayed + 1 >= MAX_GAMES)
		cout << "Maximum amount of games played reached." << endl;
	else {
		freeThrows[gamesPlayed].setPointsMade(madeone);
		freeThrows[gamesPlayed].setPointsPossible(possone);
		twoPointers[gamesPlayed].setPointsMade(madetwo);
		twoPointers[gamesPlayed].setPointsPossible(posstwo);
		threePointers[gamesPlayed].setPointsMade(madethree);
		threePointers[gamesPlayed].setPointsPossible(possthree);
		gamesPlayed++;
	}
} // addGame()

void player::printPlayer() {
	cout << playerName << "  [" << jerseyNum << "] \n";
	cout << right; // right-justify all numbers in the report
	cout << "Game  3-Point FGs   2-Point FGs   Free Throws   Total\n";
	cout << "----  ------------  ------------  ------------  -----\n";
	float sumThreePointersMade = 0;
	float sumThreePointersPossible = 0;
	float sumTwoPointersMade = 0;
	float sumTwoPointersPossible = 0;
	float sumFreeThrowsMade = 0;
	float sumFreeThrowsPossible = 0;
	float sumTotal = 0;
	for (int i = 0; i < gamesPlayed; i++) {
		int total = (threePointers[i].getPointsMade() * 3) + (twoPointers[i].getPointsMade() * 2) + (freeThrows[i].getPointsMade());
		cout << right << "  " << setw(2) << i << "  ";
		threePointers[i].printStatistic();
		cout << "  ";
		twoPointers[i].printStatistic();
		cout << "  ";
		freeThrows[i].printStatistic();
		cout << "  " << setw(5) << total << "\n";
		
		sumThreePointersMade = threePointers[i].getPointsMade() + sumThreePointersMade;
		sumThreePointersPossible = threePointers[i].getPointsPossible() + sumThreePointersPossible;
		sumTwoPointersMade = twoPointers[i].getPointsMade() + sumTwoPointersMade;
		sumTwoPointersPossible = twoPointers[i].getPointsPossible() + sumTwoPointersPossible;
		sumFreeThrowsMade = freeThrows[i].getPointsMade() + sumFreeThrowsMade;
		sumFreeThrowsPossible = freeThrows[i].getPointsPossible() + sumFreeThrowsPossible;
		sumTotal = total + sumTotal;
	} 
	cout << right << setprecision(0) << setw(3) << " ALL  " << setw(2) << sumThreePointersMade << "/" << setw(2) << sumThreePointersPossible << " (" << setw(3) << int(sumThreePointersMade / sumThreePointersPossible *100) << "%)";
	cout << "  " << setprecision(0) << setw(2) << sumTwoPointersMade << "/" << setw(2) << sumTwoPointersPossible << " (" << setw(3) << int(sumTwoPointersMade / sumTwoPointersPossible * 100) << "%)";
	cout << "  " << setprecision(0) << setw(2) << sumFreeThrowsMade << "/" << setw(2) << sumFreeThrowsPossible << " (" << setw(3) << int(sumFreeThrowsMade / sumFreeThrowsPossible * 100) << "%)";
	cout << "    " << setw(3) << sumTotal << "\n\n";
} // printPlayer()
