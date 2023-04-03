#include <iostream>
#include "player.h"
const int MAX_PLAYERS = 10;
//----------------------------------------
// class team
//----------------------------------------
// Implements a team of basketball players
//----------------------------------------
class team
{
private:
	int numGames;
	int numPlayers;
	player players[MAX_PLAYERS]; // sets up an array of players
public:
	team(); // constructor
	void read();
	void setNumGames(int s);
	void setNumPlayers(int s);
	int getNumGames();
	int getNumPlayers();
	void addGame();
	int searchPlayer();
	void printTeam();
	void displayPlayer();
	void removePlayer();
	void sortByName();
	void sortByJersey();
	void write();
}; // end class team
#pragma once