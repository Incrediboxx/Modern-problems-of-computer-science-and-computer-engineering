#define _USE_MATH_DEFINES
#include <math.h>
#include "figures.h"	
#include <iostream>

Circle::Circle(Point center, int rad, int color) : Figure(color), center(center), rad(rad) {}
double Circle::place() const {
#ifdef _DEBUG
	std::cerr << "In Circle::place() \n";
#endif
	return M_PI * rad * rad;
}
double Circle::perimetr() const {
	return 2 * M_PI * rad;
}
std::ostream& operator<<(std::ostream &out, const Circle &circle) {
	out << "<Circle: x=" << circle.center.x << " ,y=" << circle.center.y << " ,r=" << circle.rad << " ,color =" << circle.color;
	return out;
}


Triangle::Triangle(Point p1, Point p2, Point p3, int color) : Figure(color), p1(p1), p2(p2), p3(p3) {}
double Triangle::place() const {
#ifdef _DEBUG	
	std::cerr << "In Triangle::place() \n";
#endif
	double ans = 0.5 * ((p1.x - p3.x) * (p2.y - p3.y) - (p2.x - p3.x) * (p1.y - p3.y));
	return abs(ans);
}
double Triangle::perimetr() const {
	return sqrt(pow((p1.x - p2.x), 2) + pow((p1.y - p2.y), 2)) + sqrt(pow((p2.x - p3.x), 2) + pow((p2.y - p3.y), 2))
		+ sqrt(pow((p3.x - p1.x), 2) + pow((p3.y - p1.y), 2));
}

// ѕо отладке на бумаге выходит что последни€ точка не 
// ну попробуйте так тода

Polygon::Polygon(int pArray[],int n, int color): Figure(color) {
	for (size_t i = 0; i < n-1; i+=2)
	{
		//std::cout << "n: " << n << "; i: " << i << std::endl;
		pVector.emplace_back(pArray[i], pArray[i + 1]);
	}
}
double Polygon::place() const {
#ifdef _DEBUG	
	std::cerr << "In Polygon::place() \n";
#endif	

	double res = 0;
	for (unsigned i = 0; i < pVector.size(); i++)
	{
		Point
			p1 = i ? pVector[i - 1] : pVector.back(),
			p2 = pVector[i];
		res += (p1.x - p2.x) * (p1.y + p2.y);
	}
	return fabs(res) / 2;
}

double Polygon::perimetr() const {
	double ans = 0;
	Point nextPoint;
	for (size_t i = 0; i < pVector.size(); i++)
	{
		if (i != pVector.size() - 1)
			 nextPoint = pVector[i + 1];
		else
			 nextPoint = pVector[0];

		ans += sqrt(pow((pVector[i].x - nextPoint.x), 2) + pow((pVector[i].y - nextPoint.y), 2));
	}

	return ans;
}
