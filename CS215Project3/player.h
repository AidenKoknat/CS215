#include <iostream>
#include <string>
#include "statistics.h"
using namespace std;
const int MAX_GAMES = 15;
//----------------------------------------
// class player
//----------------------------------------
// Implements a basketball player
//----------------------------------------
const int MAX_SHOTS = 100;
class player
{
private:
	string playerName;
	int jerseyNum;
	
	//int totalPoints[]; // necessary?
public:
	player(); // constructor
	int gamesPlayed;
	statistic threePointers[MAX_SHOTS];
	statistic twoPointers[MAX_SHOTS];
	statistic freeThrows[MAX_SHOTS];
	string getPlayerName();
	int getJerseyNum();
	int getGamesPlayed();
	void setPlayerName(string s);
	void setJerseyNum(int s);
	void printPlayer();
	void addGame(int madeone, int possone, int madetwo, int posstwo, int madethree, int possthree);
}; // end class player
#pragma once
