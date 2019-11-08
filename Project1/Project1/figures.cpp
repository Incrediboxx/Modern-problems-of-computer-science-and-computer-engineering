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

Triangle::Triangle(Point p1, Point p2, Point p3, int color) : Figure(color), p1(p1), p2(p2), p3(p3) {}
double Triangle::place() const {
#ifdef _DEBUG	
	std::cerr << "In Triangle::place() \n";
#endif
	double ans = 0.5 * ((p1.x - p3.x) * (p2.y - p3.y) - (p2.x - p3.x) * (p1.y - p3.y));
	return abs(ans);
}

Polygon::Polygon(std::vector<Point> pVector, int color): Figure(color), pVector(pVector) {}
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
