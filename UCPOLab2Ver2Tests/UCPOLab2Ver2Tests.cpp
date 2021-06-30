#include "pch.h"
#include "CppUnitTest.h"
#include "..\UCPOLab2Ver2\Point.h"
#include "..\UCPOLab2Ver2\Triangle.h"
#include "..\UCPOLab2Ver2\LineEquation.h"
#include "..\UCPOLab2Ver2\Polygon.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UCPOLab2Ver2Tests
{
	TEST_CLASS(TestingBlackBox)
	{
	public:
		
		TEST_METHOD(NoIntersectionPoints)
		{
			Polygon PolygonPoints;
			Triangle Triangle1, Triangle2;

			Point Tr1Point1(110, -170);
			Point Tr1Point2(60, -30);
			Point Tr1Point3(170, -30);

			Point Tr2Point1(20, 190);
			Point Tr2Point2(-120, 170);
			Point Tr2Point3(-65, -20);

			Triangle1.SetTriangleVertices(Tr1Point1, Tr1Point2, Tr1Point3);
			Triangle2.SetTriangleVertices(Tr2Point1, Tr2Point2, Tr2Point3);

			PolygonPoints.TriangleIntersectionContour(PolygonPoints, Triangle1, Triangle2);
			int PolygonSize = PolygonPoints.GetCoordinatesPolygon().size();
			Assert::AreEqual(0, PolygonSize);
		}
		TEST_METHOD(OneIntersectionPoint)
		{
			Polygon PolygonPoints;
			Triangle Triangle1, Triangle2;

			Point Tr1Point1(-30, -30);
			Point Tr1Point2(-80, 110);
			Point Tr1Point3(30, 110);

			Point Tr2Point1(-30, -170);
			Point Tr2Point2(-80, -30);
			Point Tr2Point3(30, -30);

			Triangle1.SetTriangleVertices(Tr1Point1, Tr1Point2, Tr1Point3);
			Triangle2.SetTriangleVertices(Tr2Point1, Tr2Point2, Tr2Point3);

			PolygonPoints.TriangleIntersectionContour(PolygonPoints, Triangle1, Triangle2);
			int PolygonSize = PolygonPoints.GetCoordinatesPolygon().size();
			Assert::AreEqual(1, PolygonSize);
		}
		TEST_METHOD(TwoIntersectionPoints)
		{
			Polygon PolygonPoints;
			Triangle Triangle1, Triangle2;

			Point Tr1Point1(-30, -30);
			Point Tr1Point2(-80, 110);
			Point Tr1Point3(30, 110);

			Point Tr2Point1(-30, 250);
			Point Tr2Point2(-80, 110);
			Point Tr2Point3(30, 110);

			Triangle1.SetTriangleVertices(Tr1Point1, Tr1Point2, Tr1Point3);
			Triangle2.SetTriangleVertices(Tr2Point1, Tr2Point2, Tr2Point3);

			PolygonPoints.TriangleIntersectionContour(PolygonPoints, Triangle1, Triangle2);
			int PolygonSize = PolygonPoints.GetCoordinatesPolygon().size();
			Assert::AreEqual(2, PolygonSize);
		}
		TEST_METHOD(ThreeIntersectionPoints)
		{
			Polygon PolygonPoints;
			Triangle Triangle1, Triangle2;

			Point Tr1Point1(10, 90);
			Point Tr1Point2(-60, -50);
			Point Tr1Point3(70, -50);

			Point Tr2Point1(10, -90);
			Point Tr2Point2(70, 50);
			Point Tr2Point3(150, -150);

			Triangle1.SetTriangleVertices(Tr1Point1, Tr1Point2, Tr1Point3);
			Triangle2.SetTriangleVertices(Tr2Point1, Tr2Point2, Tr2Point3);

			PolygonPoints.TriangleIntersectionContour(PolygonPoints, Triangle1, Triangle2);
			int PolygonSize = PolygonPoints.GetCoordinatesPolygon().size();
			Assert::AreEqual(3, PolygonSize);
		}
		TEST_METHOD(FourIntersectionPoints)
		{
			Polygon PolygonPoints;
			Triangle Triangle1, Triangle2;

			Point Tr1Point1(10, -90);
			Point Tr1Point2(-60, 50);
			Point Tr1Point3(70, 50);

			Point Tr2Point1(50, -90);
			Point Tr2Point2(0, 30);
			Point Tr2Point3(100, 100);

			Triangle1.SetTriangleVertices(Tr1Point1, Tr1Point2, Tr1Point3);
			Triangle2.SetTriangleVertices(Tr2Point1, Tr2Point2, Tr2Point3);

			PolygonPoints.TriangleIntersectionContour(PolygonPoints, Triangle1, Triangle2);
			int PolygonSize = PolygonPoints.GetCoordinatesPolygon().size();
			Assert::AreEqual(4, PolygonSize);
		}
		TEST_METHOD(FiveIntersectionPoints)
		{
			Polygon PolygonPoints;
			Triangle Triangle1, Triangle2;

			Point Tr1Point1(150, 0);
			Point Tr1Point2(0, 150);
			Point Tr1Point3(0, 0);

			Point Tr2Point1(130, 130);
			Point Tr2Point2(0, -100);
			Point Tr2Point3(-70, 100);

			Triangle1.SetTriangleVertices(Tr1Point1, Tr1Point2, Tr1Point3);
			Triangle2.SetTriangleVertices(Tr2Point1, Tr2Point2, Tr2Point3);

			PolygonPoints.TriangleIntersectionContour(PolygonPoints, Triangle1, Triangle2);
			int PolygonSize = PolygonPoints.GetCoordinatesPolygon().size();
			Assert::AreEqual(5, PolygonSize);
		}
		TEST_METHOD(SixIntersectionPoints)
		{
			Polygon PolygonPoints;
			Triangle Triangle1, Triangle2;

			Point Tr1Point1(10, 90);
			Point Tr1Point2(-60, -50);
			Point Tr1Point3(70, -50);

			Point Tr2Point1(10, -90);
			Point Tr2Point2(-60, 50);
			Point Tr2Point3(70, 50);

			Triangle1.SetTriangleVertices(Tr1Point1, Tr1Point2, Tr1Point3);
			Triangle2.SetTriangleVertices(Tr2Point1, Tr2Point2, Tr2Point3);

			PolygonPoints.TriangleIntersectionContour(PolygonPoints, Triangle1, Triangle2);
			int PolygonSize = PolygonPoints.GetCoordinatesPolygon().size();
			Assert::AreEqual(6, PolygonSize);
		}
		TEST_METHOD(PermutationOfTriangleVertices)
		{
			Polygon PolygonPoints, PolygonPoints1, PolygonPoints2, PolygonPoints3;
			Triangle Triangle1, Triangle2;

			Point Tr1Point1(10, 90);
			Point Tr1Point2(-60, -50);
			Point Tr1Point3(70, -50);

			Point Tr2Point1(10, -90);
			Point Tr2Point2(70, 50);
			Point Tr2Point3(150, -150);
			//без перестановки
			Triangle1.SetTriangleVertices(Tr1Point1, Tr1Point2, Tr1Point3);
			Triangle2.SetTriangleVertices(Tr2Point1, Tr2Point2, Tr2Point3);

			PolygonPoints.TriangleIntersectionContour(PolygonPoints, Triangle1, Triangle2);
			int PolygonSize = PolygonPoints.GetCoordinatesPolygon().size();
			Assert::AreEqual(3, PolygonSize);

			//перестановка порядка вершин треугольника1
			//1
			Triangle1.SetTriangleVertices(Tr1Point2, Tr1Point1, Tr1Point3);
			PolygonPoints.TriangleIntersectionContour(PolygonPoints1, Triangle1, Triangle2);
			PolygonSize = PolygonPoints1.GetCoordinatesPolygon().size();
			Assert::AreEqual(3, PolygonSize);
			//2
			Triangle1.SetTriangleVertices(Tr1Point3, Tr1Point1, Tr1Point2);
			PolygonPoints.TriangleIntersectionContour(PolygonPoints2, Triangle1, Triangle2);
			PolygonSize = PolygonPoints2.GetCoordinatesPolygon().size();
			Assert::AreEqual(3, PolygonSize);
			//3
			Triangle1.SetTriangleVertices(Tr1Point1, Tr1Point3, Tr1Point2);
			PolygonPoints.TriangleIntersectionContour(PolygonPoints3, Triangle1, Triangle2);
			PolygonSize = PolygonPoints3.GetCoordinatesPolygon().size();
			Assert::AreEqual(3, PolygonSize);
		}
		TEST_METHOD(CoordinatesAtOnePoint)
		{
			Polygon PolygonPoints;
			Triangle Triangle1, Triangle2;

			Point Tr1Point1(0, 0);
			Point Tr1Point2(0, 0);
			Point Tr1Point3(0, 0);

			Point Tr2Point1(0, 0);
			Point Tr2Point2(0, 0);
			Point Tr2Point3(0, 0);

			Triangle1.SetTriangleVertices(Tr1Point1, Tr1Point2, Tr1Point3);
			Triangle2.SetTriangleVertices(Tr2Point1, Tr2Point2, Tr2Point3);

			PolygonPoints.TriangleIntersectionContour(PolygonPoints, Triangle1, Triangle2);
			int PolygonSize = PolygonPoints.GetCoordinatesPolygon().size();
			Assert::AreEqual(0, PolygonSize);
		}
		TEST_METHOD(ThreePointLine)
		{
			Polygon PolygonPoints;
			Triangle Triangle1, Triangle2;

			Point Tr1Point1(-30, -30);
			Point Tr1Point2(-80, 110);
			Point Tr1Point3(30, 110);
			//следующие точки образуют линию
			Point Tr2Point1(-40, 30);
			Point Tr2Point2(10, 30);
			Point Tr2Point3(30, 30);

			Triangle1.SetTriangleVertices(Tr1Point1, Tr1Point2, Tr1Point3);
			Triangle2.SetTriangleVertices(Tr2Point1, Tr2Point2, Tr2Point3);

			int PolygonSize;
			if (!Triangle1.IsTriangle() || !Triangle2.IsTriangle())
			{
				PolygonSize = PolygonPoints.GetCoordinatesPolygon().size();
			}
			else
			{
				PolygonPoints.TriangleIntersectionContour(PolygonPoints, Triangle1, Triangle2);
				PolygonSize = PolygonPoints.GetCoordinatesPolygon().size();
			}
			Assert::AreEqual(0, PolygonSize);
		}
		TEST_METHOD(VerticalSideTriangles)
		{
			Polygon PolygonPoints;
			Triangle Triangle1, Triangle2;

			Point Tr1Point1(10, 10);
			Point Tr1Point2(10, 200);
			Point Tr1Point3(-30, 30);

			Point Tr2Point1(20, 50);
			Point Tr2Point2(-60, 90);
			Point Tr2Point3(30, 30);
			//вертикальная линия у треугольника 1
			Triangle1.SetTriangleVertices(Tr1Point1, Tr1Point2, Tr1Point3);
			Triangle2.SetTriangleVertices(Tr2Point1, Tr2Point2, Tr2Point3);

			PolygonPoints.TriangleIntersectionContour(PolygonPoints, Triangle1, Triangle2);
			int PolygonSize = PolygonPoints.GetCoordinatesPolygon().size();
			Assert::AreEqual(4, PolygonSize);
			//вертикальная линия у треугольника 2
			Triangle1.SetTriangleVertices(Tr2Point1, Tr2Point2, Tr2Point3);
			Triangle2.SetTriangleVertices(Tr1Point1, Tr1Point2, Tr1Point3);
			Polygon PolygonPoints2;
			PolygonPoints2.TriangleIntersectionContour(PolygonPoints2, Triangle1, Triangle2);
			PolygonSize = PolygonPoints2.GetCoordinatesPolygon().size();
			Assert::AreEqual(4, PolygonSize);
		}
	};
}
