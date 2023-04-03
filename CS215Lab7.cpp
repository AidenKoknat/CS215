// CS215-003 -- Lab 7 -- 4/3/20
// Aiden Koknat
//-----------------------------

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;
const int MAX_ITEMS = 5;
//prod p[MAX_ITEMS];

struct prod {
	string name;
	float price;
	int inStock;
};

//--------------------------------
//         readInventory
//--------------------------------
int readInventory(prod p[]) {
	ifstream fin;
	fin.open("inventory.txt");
	if (fin.fail()) {
		cout << "Unable to open input file.";
		int productNum = 0;
		return productNum;
	}
	else {
		for (int i = 0; i < MAX_ITEMS; i++) {
			float m;
			fin >> m;
			if (m != -1) {
				p[i].price = m;
				fin >> p[i].inStock;
				fin >> p[i].name;
			}
			else {
				cout << "Inventory read!" << endl;
				fin.close();
				int productNum = i;
				return productNum;
			}
		}	
	}
	
}

//------------------------------
//         totalValue
//------------------------------
float totalValue(prod p[], int& productNum) {
	float sum = 0;
	for (int i = 0; i < productNum; i++) {
		sum = sum + p[i].price * p[i].inStock;
	}
	return sum;
}

//------------------------------
//           sort
//------------------------------
void sort(prod p[], int& productNum) {
	 for (int i = 0; i < productNum; ++i) {
		 if (i < productNum - 1) {
			 if (p[i].name > p[i + 1].name) {
				 prod temp = p[i];
				 p[i] = p[i + 1];
				 p[i + 1] = temp;
				 sort(p, productNum);
			 }
		 }
		 else;

	 }
} 

//-----------------------------
//        writeReport 
//-----------------------------
void writeReport(prod p[], int& productNum) {
	ofstream fout;
	fout.open("report.txt");
	if (fout.fail())
		cout << "Unable to open output file.";
	else {
			fout << "+------------------------------+" << endl;
			fout << "|       Current Inventory      |" << endl;
			fout << "+------------------------------+" << endl;
			fout << "NAME                  PRICE   # " << endl;
			fout << "-------------------- ------- ---" << endl;
			for (int i = 0; i < productNum; i++) {
				fout << left << setw(21) << p[i].name << "$ " << right << setw(5) << fixed << setprecision(2) << p[i].price << "  " << p[i].inStock << endl;
			}
			fout << "+------------------------------+" << endl;
			fout << "Number of products:" << "    " << productNum << endl;
			fout << "Inventory total value: $" << totalValue(p, productNum);
			cout << "Report written to file." << endl;
	}
	fout.close();
}
int main() {
	prod p[MAX_ITEMS];
	int productNum = readInventory(p);
	sort(p, productNum);
	writeReport(p, productNum);
	system("PAUSE");
	return 0;
}