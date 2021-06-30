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

	cout << "Введите координаты точек для треугольника 1:" << endl;
	cout << "Точка 1 :";
	Point Figure1Ver1 = InputPoint();
	cout << "Точка 2 :";
	Point Figure1Ver2 = InputPoint();
	cout << "Точка 3 :";
	Point Figure1Ver3 = InputPoint();

	TriangleFigure1.SetTriangleVertices(Figure1Ver1, Figure1Ver2, Figure1Ver3);
	cout << "Точки треугольника 1: " << Figure1Ver1 << ", " << Figure1Ver2 << ", " << Figure1Ver3 << endl;

	cout << "Введите координаты точек для треугольника 2:" << endl;
	cout << "Точка 1 :";
	Point Figure2Ver1 = InputPoint();
	cout << "Точка 2 :";
	Point Figure2Ver2 = InputPoint();
	cout << "Точка 3 :";
	Point Figure2Ver3 = InputPoint();

	TriangleFigure2.SetTriangleVertices(Figure2Ver1, Figure2Ver2, Figure2Ver3);
	cout << "Точки треугольника 2: " << Figure2Ver1 << ", " << Figure2Ver2 << ", " << Figure2Ver3 << endl;

	if (!TriangleFigure1.IsTriangle() || !TriangleFigure2.IsTriangle())
	{
		cout << "Заданы координаты, которые не образуют треугольник. Поиск пересечений невозможен!" << endl;
	}
	//проверка на совпадение треугольников
	else if (TriangleFigure1.IsIdenticalTriangles(TriangleFigure1, TriangleFigure2))
	{
		cout << "Треугольники совпадают по координатам" << endl;
	}
	else
	{
		PolygonIntersection.TriangleIntersectionContour(PolygonIntersection, TriangleFigure1, TriangleFigure2);

		if (PolygonIntersection.GetCoordinatesPolygon().size() == 0)
		{
			cout << "Треугольники не пересекаются" << endl;
		}
		else if (PolygonIntersection.GetCoordinatesPolygon().size() == 1 || PolygonIntersection.GetCoordinatesPolygon().size() == 2)
		{
			cout << "Треугольники соприкасаются в точке/точках: " << endl;
		}
		else if (IsInside)
		{
			cout << "Один треугольник вложен в другой. Внутри треугольник, содержащий точки: " << endl;
		}
		else
		{
			cout << "Треугольники пересекаются в точках: " << endl;
		}
		PolygonIntersection.PrintPolygonPoints();
	}

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(900, 100);
	glutCreateWindow("Определение контура пересечения треугольников");
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
	glColor3f(0.0f, 0.5f, 0.0f);//зеленый

	CreateTriangle(TriangleFigure1);

	glColor3f(0.0f, 0.5f, 1.0f);//синий
	CreateTriangle(TriangleFigure2);

	//контур треугольников
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glLineWidth(2);
	glColor3f(0.0f, 0.0f, 0.0f);//черный

	CreateTriangle(TriangleFigure1);

	CreateTriangle(TriangleFigure2);

	glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
	glPointSize(5);
	glColor3f(1.0f, 0.0f, 0.0f);//красный
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
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);//фон белый
	glClearDepth(1.0f);//значение буфера глубины по умолчанию
	//glEnable(GL_DEPTH_TEST);//Вкл. тест глубины

	glTranslatef(300.0f, 300.0f, 0.0f);//сдвиг начала системы координат

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0f, 599.0f, 0.0f, 599.0f);
}