#pragma once
#include "Point.h"
#include <vector>
using namespace std;

class Triangle;

class Polygon :public Point
{
public:
	vector<Point>CoordinatePolygon;
public:
	~Polygon() {}
	void SetPolygonPoint(Point PolyPoint);
	vector<Point> GetCoordinatesPolygon() { return CoordinatePolygon; }
	void TriangleIntersectionContour(Polygon& PolygonPoints, Triangle Figure1, Triangle Figure2);//определение точек пересечения двух треугольников
	void PrintPolygonPoints();//вывод точек пересечения двух треугольников
};
