#include "Polygon.h"
#include "Triangle.h"
#include "LineEquation.h"

bool IsInside = false;

void Polygon::SetPolygonPoint(Point PolyPoint)
{
	CoordinatePolygon.push_back(PolyPoint);
}

void Polygon::TriangleIntersectionContour(Polygon& PolygonPoints, Triangle Figure1, Triangle Figure2)
{
	LineEquation Lines;
	vector<LineEquation>LinesFigure1, LinesFigure2;

	Lines.LinesTriangle(LinesFigure1, Figure1);
	Lines.LinesTriangle(LinesFigure2, Figure2);

	//проверка на точки внутри треугольника
	Lines.SearchPointInTriangle(PolygonPoints, LinesFigure1, Figure2);
	if (PolygonPoints.CoordinatePolygon.size() == 3)
	{
		IsInside = true;
		return;// второй треугольник в первом
	}

	if (PolygonPoints.CoordinatePolygon.size() == 0)//от предыдущего поиска нет точек
	{
		Lines.SearchPointInTriangle(PolygonPoints, LinesFigure2, Figure1);
		if (PolygonPoints.CoordinatePolygon.size() == 3)
		{
			IsInside = true;
			return;//первый треугольник во втором
		}
	}
	else
	{
		Lines.SearchPointInTriangle(PolygonPoints, LinesFigure2, Figure1);
	}

	for (unsigned int i = 0; i < LinesFigure1.size(); i++)
	{
		for (unsigned int j = 0; j < LinesFigure2.size(); j++)
		{
			Lines.IntersectionOfLines(PolygonPoints, LinesFigure1[i], LinesFigure2[j]);
		}
	}
}

void Polygon::PrintPolygonPoints()
{
	for (unsigned int i = 0; i < this->CoordinatePolygon.size(); i++)
	{
		cout << this->CoordinatePolygon[i] << endl;
	}
}
