#pragma once

#include <vector>

#ifndef __FIGURES_H		
#define __FIGURES_H	

class Figure {
	int color;
public:
	Figure(int color) : color(color) {};

	virtual double place() const = 0;
	virtual double perimetr() const = 0;

	struct Point {
		int x, y;
		Point(int x, int y) : x(x), y(y) {};
		Point() {};
	};

	//friend std::ostream& operator<< (std::ostream& out, const Figure& figure);
};

class Circle : public Figure {
	Point center;
	int rad;
public:
	Circle(Point center, int rad, int color);
	virtual double place() const;
	virtual double perimetr() const;

	friend std::ostream& operator<< (std::ostream &out, const Circle &circle);
};

class Triangle : public Figure {
	Point	p1, p2, p3;
public:	
	Triangle(Point p1, Point p2, Point p3, int color);
	virtual double place() const;
	virtual double perimetr() const;
};

class Polygon : public Figure {
	std::vector<Point> pVector;
public:
	Polygon(int pArray[],int n, int color);
	virtual double place() const;
	virtual double perimetr() const;
};

#endif
