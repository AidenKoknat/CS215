#include <string>
#include <iostream>
#include <iomanip>
#include "statistics.h"
using namespace std;
void statistic::statistics() { // constructor
	pointsMade = 0;
	pointsPossible = 0;
} // statistics()

void statistic::setPointsMade(int s) {
	pointsMade = s;
}
float statistic::getPointsMade() {
	return pointsMade;
}

void statistic::setPointsPossible(int s) {
	pointsPossible = s;
}
float statistic::getPointsPossible() {
	return pointsPossible;
}

float statistic::getPercentage() {
	if (pointsPossible == 0) {
		int percentage = 0;
		return percentage;
	}
	else {
		int percentage = (pointsMade / pointsPossible) * 100;
		return percentage;
	}
} // getPercentage()

void statistic::printStatistic() {
	cout << right << setw(2) << pointsMade << "/" << setw(2) << pointsPossible << " (" <<setw(3) << getPercentage() << "%)";
}