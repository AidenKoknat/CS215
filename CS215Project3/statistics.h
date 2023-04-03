#include <iostream>
#include <string>
using namespace std;
//----------------------------------------
// class statistic
//----------------------------------------
// Records the points attempted and made
//----------------------------------------
class statistic
{
private:
	float pointsMade;
	float pointsPossible;
public:
	void statistics(); // constructor
	void setPointsMade(int s); 
	void setPointsPossible(int s);
	float getPointsMade();
	float getPointsPossible();
	void printStatistic();
	float getPercentage(); 
}; // end class statistic
#pragma once
