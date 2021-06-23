#include "LineEquation.h"
#include "Triangle.h"
#include "Polygon.h"

LineEquation::LineEquation()
{
	this->a = this->b = this->c = 0.0f;
	FirstPoint.SetX(0.0f);
	FirstPoint.SetY(0.0f);
	SecondPoint.SetX(0.0f);
	SecondPoint.SetY(0.0f);
}

LineEquation::LineEquation(Point FirstPoint, Point SecondPoint)
{
	this->a = FirstPoint.GetY() - SecondPoint.GetY();
	this->b = SecondPoint.GetX() - FirstPoint.GetX();
	this->c = FirstPoint.GetX() * SecondPoint.GetY() - SecondPoint.GetX() * FirstPoint.GetY();

	if (FirstPoint.GetX() < SecondPoint.GetX())//��������, ����� ���������� ������/������ �� X
	{
		this->FirstPoint = FirstPoint;
		this->SecondPoint = SecondPoint;
	}
	else if (FirstPoint.GetX() == SecondPoint.GetX())//����� ������������� ����������� � ����� ������� �� Y
	{
		if (FirstPoint.GetY() < SecondPoint.GetY())//��������, ����� ���������� ������/������ �� Y
		{
			this->FirstPoint = FirstPoint;
			this->SecondPoint = SecondPoint;
		}
		else
		{
			this->FirstPoint = SecondPoint;
			this->SecondPoint = FirstPoint;
		}
	}
	else
	{
		this->FirstPoint = SecondPoint;
		this->SecondPoint = FirstPoint;
	}
}

void LineEquation::LinesTriangle(vector<LineEquation>& LinesFigure, Triangle Figure)
{
	LineEquation Line1Figure(Figure.GetCoordinatesTriangle()[0], Figure.GetCoordinatesTriangle()[1]);
	LineEquation Line2Figure(Figure.GetCoordinatesTriangle()[1], Figure.GetCoordinatesTriangle()[2]);
	LineEquation Line3Figure(Figure.GetCoordinatesTriangle()[2], Figure.GetCoordinatesTriangle()[0]);

	LinesFigure.push_back(Line1Figure);
	LinesFigure.push_back(Line2Figure);
	LinesFigure.push_back(Line3Figure);
}

void LineEquation::SearchPointInTriangle(Polygon& PolygonPoints, vector<LineEquation> LinesFigure1, Triangle Figure2)
{
	for (unsigned int i = 0; i < Figure2.GetCoordinatesTriangle().size(); i++)
	{
		float First = LinesFigure1[0].GetA() * Figure2.GetCoordinatesTriangle()[i].GetX() + LinesFigure1[0].GetB() * Figure2.GetCoordinatesTriangle()[i].GetY() + LinesFigure1[0].GetC();
		float Second = LinesFigure1[1].GetA() * Figure2.GetCoordinatesTriangle()[i].GetX() + LinesFigure1[1].GetB() * Figure2.GetCoordinatesTriangle()[i].GetY() + LinesFigure1[1].GetC();
		float Third = LinesFigure1[2].GetA() * Figure2.GetCoordinatesTriangle()[i].GetX() + LinesFigure1[2].GetB() * Figure2.GetCoordinatesTriangle()[i].GetY() + LinesFigure1[2].GetC();
		if ((First < 0.0f && Second < 0.0f && Third < 0.0f) || (First > 0.0f && Second > 0.0f && Third > 0.0f))
		{
			PolygonPoints.CoordinatePolygon.push_back(Figure2.GetCoordinatesTriangle()[i]);
		}
	}
}

float LineEquation::DeterminantMatrix2x2(float A11, float A12, float A21, float A22)
{
	return A11 * A22 - A12 * A21;
}

void LineEquation::IntersectionOfLines(Polygon& PolygonPoints, LineEquation Eq1, LineEquation Eq2)
{
	//����� �������
	LineEquation Det;
	float Determinant = Det.DeterminantMatrix2x2(Eq1.GetA(), Eq1.GetB(), Eq2.GetA(), Eq2.GetB());
	if (Determinant == 0.0f)//����� �� ������������
	{
		return;
	}

	float DeterminantX = DeterminantMatrix2x2(-Eq1.c, Eq1.b, -Eq2.c, Eq2.b);

	float DeterminantY = DeterminantMatrix2x2(Eq1.a, -Eq1.c, Eq2.a, -Eq2.c);

	Point PointIntersection;

	PointIntersection.SetX(DeterminantX / Determinant);
	PointIntersection.SetY(DeterminantY / Determinant);

	//�������� ������������ ��������� �����(������� ����������� ������) ������������ �������� �������������
	if ((PointIntersection.GetX() < Eq1.FirstPoint.GetX() || PointIntersection.GetX() > Eq1.SecondPoint.GetX()) || (PointIntersection.GetX() < Eq2.FirstPoint.GetX() || PointIntersection.GetX() > Eq2.SecondPoint.GetX()))
	{
		return;//����� ������������� ����� ��� ������� ��������
	}
	if (PointIntersection.GetX() == Eq1.FirstPoint.GetX() && PointIntersection.GetX() == Eq1.SecondPoint.GetX())//��� ����� ������������ 1
	{
		if (PointIntersection.GetY() < Eq1.FirstPoint.GetY() || PointIntersection.GetY() > Eq1.SecondPoint.GetY())
		{
			return;//������������ �����, ����� ������������ ���� ��� ���� �������
		}
	}
	else if (PointIntersection.GetX() == Eq2.FirstPoint.GetX() && PointIntersection.GetX() == Eq2.SecondPoint.GetX())//��� ����� ������������ 2
	{
		if (PointIntersection.GetY() < Eq2.FirstPoint.GetY() || PointIntersection.GetY() > Eq2.SecondPoint.GetY())
		{
			return;//������������ �����, ����� ������������ ���� ��� ���� �������
		}
	}
	//���� ����� ����� ����� �� ������
	if (PointIntersection == Eq1.FirstPoint || PointIntersection == Eq1.SecondPoint)
	{
		//��������� ���� �� ��� ��� ���������
		for (unsigned int i = 0; i < PolygonPoints.GetCoordinatesPolygon().size(); i++)
		{
			if (PolygonPoints.GetCoordinatesPolygon()[i] == PointIntersection)
			{
				return;//������ ����� ��� ���� ���������
			}
		}
	}
	PolygonPoints.SetPolygonPoint(PointIntersection);
}
