#pragma once

#ifndef __FIGURES_H		
#define __FIGURES_H	

class Figure {
	int color;
public:
	Figure(int color) : color(color) {};

	virtual double place() const = 0;

	struct Point {
		int x, y;
		Point(int x, int y) : x(x), y(y) {};
	};
};

class Circle : public Figure {
	Point center;
	int rad;
public:
	Circle(Point center, int rad, int color);
	virtual double place() const;
};

class Triangle : public Figure {
	Point	p1, p2, p3;
public:	
	Triangle(Point p1, Point p2, Point p3, int color);
	virtual double place() const;
};

#endif
