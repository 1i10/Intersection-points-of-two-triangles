#pragma once
#include "Point.h"
#include <vector>
using namespace std;

class Triangle :public Point
{
private:
	vector<Point>CoordinateTriangle;
public:
	Triangle();
	Triangle(Point Ver1, Point Ver2, Point  Ver3);
	~Triangle() {}
	void SetTriangleVertices(Point Ver1, Point Ver2, Point  Ver3);
	vector<Point> GetCoordinatesTriangle() { return CoordinateTriangle; }
	bool IsIdenticalTriangles(Triangle Figure1, Triangle Figure2);//проверка на идентичность треугольников
	bool IsTriangle();//проверка на то, что введенная фигура - треугольник
};
