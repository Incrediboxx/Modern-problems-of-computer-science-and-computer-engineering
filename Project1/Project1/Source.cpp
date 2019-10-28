#include <iostream>
#include <fstream>

using namespace std;

void main() {
	
	setlocale(LC_ALL, "Russian");

	ifstream inputFile("INPUT.txt");
	ofstream outputFile("OUTPUT.txt");

	int a, b;
	int counter = 0;

	inputFile >> a >> b;

	int* aa = new int[a,b];

	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			inputFile >> aa[i, j];
			cout << aa[i, j] << " ";
		}
		cout << endl;
	}

	for (int i = 0; i < a; i++) 
		for (int j = 1; j < b; j++)
			for (int k = 0; k < j; k++) {
				cout << "Текущий элемент массива" << aa[i, j] << " Сравниваемый" << aa[i, k] << endl;
				if (aa[i, k] < aa[i, j])
					counter++;
			}

				
			

	cout << counter;
}