#include "Triangle.h"
#include "LineEquation.h"

Triangle::Triangle()
{
	Point NullCoordinates;

	for (unsigned int i = 0; i < 3; i++)
	{
		CoordinateTriangle.push_back(NullCoordinates);
	}
}

Triangle::Triangle(Point Ver1, Point Ver2, Point Ver3)
{
	CoordinateTriangle.push_back(Ver1);
	CoordinateTriangle.push_back(Ver2);
	CoordinateTriangle.push_back(Ver3);
}

void Triangle::SetTriangleVertices(Point Ver1, Point Ver2, Point Ver3)
{
	CoordinateTriangle[0] = Ver1;
	CoordinateTriangle[1] = Ver2;
	CoordinateTriangle[2] = Ver3;
}

bool Triangle::IsIdenticalTriangles(Triangle Figure1, Triangle Figure2)
{
	for (unsigned int i = 0; i < Figure1.CoordinateTriangle.size(); i++)
	{
		unsigned int j = 0;
		for (; j < Figure2.CoordinateTriangle.size(); j++)
		{
			if (Figure1.CoordinateTriangle[i] == Figure2.CoordinateTriangle[j])
			{
				//��� ������� ���������
				break;
			}
		}
		if (j == Figure2.CoordinateTriangle.size())//����� �� ���� ������� ��� �������
		{
			//������������ �� ���������
			return false;
		}
	}
	//������������ ���������
	return true;
}

bool Triangle::IsTriangle()
{
	//��������� ��������� ������ �� ���� ������
	//���� ������ ����� ����������� ���� ����� (��������� = 0), �� ����� �������� ������ ��� ��� ��� � ����� �����
	LineEquation SideTriangle(this->CoordinateTriangle[0], this->CoordinateTriangle[1]);

	float Equation = SideTriangle.GetA() * this->CoordinateTriangle[2].GetX() + SideTriangle.GetB() * this->CoordinateTriangle[2].GetY() + SideTriangle.GetC();
	if (Equation == 0.0f)
	{
		return false;
	}

	return true;
}
