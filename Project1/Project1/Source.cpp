#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <vector>
#include <ctime>
#include "figures.h"

using namespace std;

void main() {
	
	setlocale(LC_ALL, "Russian");

	srand((unsigned int)time(NULL));
	const int nFigures = 10;
	std::vector<Figure*> figures(nFigures);
	for (size_t i = 0; i < nFigures; i++)
	{
		if (rand() % 2 == 0) {
			figures[i] = new Circle(Figure::Point(rand() % 100, rand() % 100), rand() % 100 + 1, rand() % 100);
		}
		else {
			figures[i] = new Triangle(Figure::Point(rand() % 100, rand() % 100), Figure::Point(rand() % 100, rand() % 100),
				Figure::Point(rand() % 100, rand() % 100), rand() % 100);
		}
	}

	double	sumPlace = 0.0;

	for (size_t i = 0; i < nFigures; i++)
	{
		sumPlace += figures[i]->place();
	}

	std::cout << std::fixed << std::setprecision(6) << "Sum place = " << sumPlace << std::endl;

	for (size_t i = 0; i < nFigures; i++)
	{
		delete figures[i];
	}
	
}