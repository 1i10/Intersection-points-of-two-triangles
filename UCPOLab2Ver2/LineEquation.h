#pragma once
#include "Point.h"
#include <vector>
using namespace std;

class Triangle;
class Polygon;

class LineEquation :public Point
{
private:
	float a;
	float b;
	float c;
	Point FirstPoint;//������ �������
	Point SecondPoint;//����� �������
public:
	LineEquation();
	LineEquation(Point FirstPoint, Point SecondPoint);
	float GetA() { return a; }
	float GetB() { return b; }
	float GetC() { return c; }
	void LinesTriangle(vector<LineEquation>& LinesFigure, Triangle Figure);//��������� �����, ������� �������� �����������
	void SearchPointInTriangle(Polygon& PolygonPoints, vector<LineEquation> LinesFigure1, Triangle Figure2);//����� ����� ������ ������������
	float DeterminantMatrix2x2(float A11, float A12, float A21, float A22);//������������ ������� 2�2
	void IntersectionOfLines(Polygon& PolygonPoints, LineEquation Eq1, LineEquation Eq2);//����������� ����� ���������� ���� �����
};

