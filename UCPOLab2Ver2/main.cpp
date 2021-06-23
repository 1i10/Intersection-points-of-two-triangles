#include <iostream>
#include <gl/glut.h>
#include "Triangle.h"
#include "LineEquation.h"
#include "Polygon.h"
using namespace std;

Triangle TriangleFigure1, TriangleFigure2;
Polygon PolygonIntersection;
extern bool IsInside;

void CreateTriangle(Triangle Figure);
void Draw2DAxis();
void Display();
void MyInit();

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "rus");

	cout << "������� ���������� ����� ��� ������������ 1:" << endl;
	cout << "����� 1 :";
	Point Figure1Ver1 = InputPoint();
	cout << "����� 2 :";
	Point Figure1Ver2 = InputPoint();
	cout << "����� 3 :";
	Point Figure1Ver3 = InputPoint();

	TriangleFigure1.SetTriangleVertices(Figure1Ver1, Figure1Ver2, Figure1Ver3);
	cout << "����� ������������ 1: " << Figure1Ver1 << ", " << Figure1Ver2 << ", " << Figure1Ver3 << endl;

	cout << "������� ���������� ����� ��� ������������ 2:" << endl;
	cout << "����� 1 :";
	Point Figure2Ver1 = InputPoint();
	cout << "����� 2 :";
	Point Figure2Ver2 = InputPoint();
	cout << "����� 3 :";
	Point Figure2Ver3 = InputPoint();

	TriangleFigure2.SetTriangleVertices(Figure2Ver1, Figure2Ver2, Figure2Ver3);
	cout << "����� ������������ 2: " << Figure2Ver1 << ", " << Figure2Ver2 << ", " << Figure2Ver3 << endl;

	if (!TriangleFigure1.IsTriangle() || !TriangleFigure2.IsTriangle())
	{
		cout << "������ ����������, ������� �� �������� �����������. ����� ����������� ����������!" << endl;
	}
	//�������� �� ���������� �������������
	else if (TriangleFigure1.IsIdenticalTriangles(TriangleFigure1, TriangleFigure2))
	{
		cout << "������������ ��������� �� �����������" << endl;
	}
	else
	{
		PolygonIntersection.TriangleIntersectionContour(PolygonIntersection, TriangleFigure1, TriangleFigure2);

		if (PolygonIntersection.GetCoordinatesPolygon().size() == 0)
		{
			cout << "������������ �� ������������" << endl;
		}
		else if (PolygonIntersection.GetCoordinatesPolygon().size() == 1 || PolygonIntersection.GetCoordinatesPolygon().size() == 2)
		{
			cout << "������������ ������������� � �����/������: " << endl;
		}
		else if (IsInside)
		{
			cout << "���� ����������� ������ � ������. ������ �����������, ���������� �����: " << endl;
		}
		else
		{
			cout << "������������ ������������ � ������: " << endl;
		}
		PolygonIntersection.PrintPolygonPoints();
	}

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(900, 100);
	glutCreateWindow("����������� ������� ����������� �������������");
	glutDisplayFunc(Display);
	MyInit();
	glutMainLoop();

	return 0;
}

void CreateTriangle(Triangle Figure)
{
	glBegin(GL_TRIANGLES);
	for (unsigned int i = 0; i < Figure.GetCoordinatesTriangle().size(); i++)
	{
		glVertex2f(Figure.GetCoordinatesTriangle()[i].GetX(), Figure.GetCoordinatesTriangle()[i].GetY());
	}
	glEnd();
}

void Draw2DAxis()
{
	glColor3f(1.0f, 0.0f, 1.0f);

	glBegin(GL_LINES);
	glVertex2f(0.0f, -300.0f);
	glVertex2f(0.0f, 300.0f);
	glVertex2f(-300.0f, 0.0f);
	glVertex2f(300.0f, 0.0f);
	glEnd();

	glBegin(GL_POINTS);
	glVertex2f(0.0f, 0.0f);
	glEnd();
}

void Display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	Draw2DAxis();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(0.0f, 0.5f, 0.0f);//�������

	CreateTriangle(TriangleFigure1);

	glColor3f(0.0f, 0.5f, 1.0f);//�����
	CreateTriangle(TriangleFigure2);

	//������ �������������
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glLineWidth(2);
	glColor3f(0.0f, 0.0f, 0.0f);//������

	CreateTriangle(TriangleFigure1);

	CreateTriangle(TriangleFigure2);

	glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
	glPointSize(5);
	glColor3f(1.0f, 0.0f, 0.0f);//�������
	glBegin(GL_POINTS);
	for (unsigned int i = 0; i < PolygonIntersection.GetCoordinatesPolygon().size(); i++)
	{
		glVertex2f(PolygonIntersection.GetCoordinatesPolygon()[i].GetX(), PolygonIntersection.GetCoordinatesPolygon()[i].GetY());
	}
	glEnd();

	glutSwapBuffers();
}

void MyInit()
{
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);//��� �����
	glClearDepth(1.0f);//�������� ������ ������� �� ���������
	//glEnable(GL_DEPTH_TEST);//���. ���� �������

	glTranslatef(300.0f, 300.0f, 0.0f);//����� ������ ������� ���������

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0f, 599.0f, 0.0f, 599.0f);
}