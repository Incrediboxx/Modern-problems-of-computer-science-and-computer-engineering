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
		int var = rand() % 1;
		switch (var) {
		case 0:
			figures[i] = new Circle(Figure::Point(rand() % 100, rand() % 100), rand() % 100 + 1, rand() % 100);
		case 1:
			figures[i] = new Triangle(Figure::Point(rand() % 100, rand() % 100), Figure::Point(rand() % 100, rand() % 100),
				Figure::Point(rand() % 100, rand() % 100), rand() % 100);
		case 2:
		{
			int n = rand() % 6 + 3;
			int* arr = new int[n * 2];
			for (size_t i = 0; i < n * 2; i++)
			{
				arr[i] = rand() % 100;
			}

			figures[i] = new Polygon(arr, n, rand() % 100);
		}
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