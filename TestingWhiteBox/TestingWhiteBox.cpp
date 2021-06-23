#include "pch.h"
#include "CppUnitTest.h"
#include "..\UCPOLab2Ver2\Point.h"
#include "..\UCPOLab2Ver2\Triangle.h"
#include "..\UCPOLab2Ver2\LineEquation.h"
#include "..\UCPOLab2Ver2\Polygon.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestingWhiteBox
{
	TEST_CLASS(TestingWhiteBox)
	{
	public:
		
		TEST_METHOD(Triangle2INTriangle1)
		{
			Polygon PolygonPoints;
			Triangle Triangle1, Triangle2;

			Point Tr1Point1(110, -170);
			Point Tr1Point2(60, -30);
			Point Tr1Point3(170, -30);

			Point Tr2Point1(110, -140);
			Point Tr2Point2(90, -60);
			Point Tr2Point3(140, -60);

			Triangle1.SetTriangleVertices(Tr1Point1, Tr1Point2, Tr1Point3);
			Triangle2.SetTriangleVertices(Tr2Point1, Tr2Point2, Tr2Point3);

			PolygonPoints.TriangleIntersectionContour(PolygonPoints, Triangle1, Triangle2);
			int PolygonSize = PolygonPoints.GetCoordinatesPolygon().size();
			Assert::AreEqual(3, PolygonSize);
		}
		TEST_METHOD(PointsInTwoTriangles)
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
		TEST_METHOD(Triangle1INTriangle2)
		{
			Polygon PolygonPoints;
			Triangle Triangle1, Triangle2;

			Point Tr1Point1(110, -140);
			Point Tr1Point2(90, -60);
			Point Tr1Point3(140, -60);

			Point Tr2Point1(110, -170);
			Point Tr2Point2(60, -30);
			Point Tr2Point3(170, -30);

			Triangle1.SetTriangleVertices(Tr1Point1, Tr1Point2, Tr1Point3);
			Triangle2.SetTriangleVertices(Tr2Point1, Tr2Point2, Tr2Point3);

			PolygonPoints.TriangleIntersectionContour(PolygonPoints, Triangle1, Triangle2);
			int PolygonSize = PolygonPoints.GetCoordinatesPolygon().size();
			Assert::AreEqual(3, PolygonSize);
		}
		TEST_METHOD(NotPointsInTriangle1AndHavePointsInTriangle2)
		{
			Polygon PolygonPoints;
			Triangle Triangle1, Triangle2;

			Point Tr1Point1(110, -170);
			Point Tr1Point2(60, -30);
			Point Tr1Point3(170, -30);

			Point Tr2Point1(80, -190);
			Point Tr2Point2(220, -170);
			Point Tr2Point3(165, 20);

			Triangle1.SetTriangleVertices(Tr1Point1, Tr1Point2, Tr1Point3);
			Triangle2.SetTriangleVertices(Tr2Point1, Tr2Point2, Tr2Point3);

			PolygonPoints.TriangleIntersectionContour(PolygonPoints, Triangle1, Triangle2);
			int PolygonSize = PolygonPoints.GetCoordinatesPolygon().size();
			Assert::AreEqual(4, PolygonSize);
		}
		TEST_METHOD(PointsInTriangle)
		{
			Polygon PolygonPoints;
			Triangle Triangle1;
			LineEquation Lines;
			vector<LineEquation>LinesTr1;

			Point Tr1Point1(130, 130);
			Point Tr1Point2(0, -100);
			Point Tr1Point3(-70, 100);

			Point Tr2Point1(150, 0);
			Point Tr2Point2(0, 80);
			Point Tr2Point3(0, 0);

			Triangle1.SetTriangleVertices(Tr1Point1, Tr1Point2, Tr1Point3);
			Lines.LinesTriangle(LinesTr1, Triangle1);
			Triangle Triangle2(Tr2Point1, Tr2Point2, Tr2Point3);

			Lines.SearchPointInTriangle(PolygonPoints, LinesTr1, Triangle2);//поиск в первом треугольнике точек из второго
			
			int PolygonSize = PolygonPoints.GetCoordinatesPolygon().size();
			Assert::AreEqual(2, PolygonSize);
		}

		TEST_METHOD(LinesDontIntersect)
		{
			Polygon PolygonPoints;
			LineEquation Lines;

			Point Tr1Point1(30, 110);
			Point Tr1Point2(-80, 110);

			Point Tr2Point1(-50, 110);
			Point Tr2Point2(60, 110);

			LineEquation Line1(Tr1Point1, Tr1Point2);
			LineEquation Line2(Tr2Point1, Tr2Point2);

			Lines.IntersectionOfLines(PolygonPoints, Line1, Line2);

			int PolygonSize = PolygonPoints.GetCoordinatesPolygon().size();
			Assert::AreEqual(0, PolygonSize);
		}
		TEST_METHOD(PointOfIntersectionBehindTheTrianglesRelativeToTheX_axis)
		{
			Polygon PolygonPoints;
			LineEquation Lines;

			Point Tr1Point1(0, 150);
			Point Tr1Point2(150, 0);

			Point Tr2Point1(0, -100);
			Point Tr2Point2(-70, 100);

			LineEquation Line1(Tr1Point1, Tr1Point2);
			LineEquation Line2(Tr2Point1, Tr2Point2);

			Lines.IntersectionOfLines(PolygonPoints, Line1, Line2);

			int PolygonSize = PolygonPoints.GetCoordinatesPolygon().size();
			Assert::AreEqual(0, PolygonSize);
		}
		TEST_METHOD(IntersectionWithVerticalLine1IsOutsideOfTheY_axis)
		{
			Polygon PolygonPoints;
			LineEquation Lines;

			Point Tr1Point1(0, 150);
			Point Tr1Point2(0, 0);

			Point Tr2Point1(0, -100);
			Point Tr2Point2(-70, 100);

			LineEquation Line1(Tr1Point1, Tr1Point2);
			LineEquation Line2(Tr2Point1, Tr2Point2);

			Lines.IntersectionOfLines(PolygonPoints, Line1, Line2);

			int PolygonSize = PolygonPoints.GetCoordinatesPolygon().size();
			Assert::AreEqual(0, PolygonSize);
		}
		TEST_METHOD(IntersectionWithVerticalLine2IsOutsideOfTheY_axis)
		{
			Polygon PolygonPoints;
			LineEquation Lines;

			Point Tr1Point1(0, -100);
			Point Tr1Point2(-70, 100);

			Point Tr2Point1(0, 0);
			Point Tr2Point2(0, 150);

			LineEquation Line1(Tr1Point1, Tr1Point2);
			LineEquation Line2(Tr2Point1, Tr2Point2);

			Lines.IntersectionOfLines(PolygonPoints, Line1, Line2);

			int PolygonSize = PolygonPoints.GetCoordinatesPolygon().size();
			Assert::AreEqual(0, PolygonSize);
		}
		TEST_METHOD(TwoLineSegmentsTouching)
		{
			Polygon PolygonPoints;
			LineEquation Lines;

			Point Tr1Point1(-80, -30);
			Point Tr1Point2(30, -30);

			Point Tr2Point1(-30, -30);
			Point Tr2Point2(-80, 110);

			LineEquation Line1(Tr1Point1, Tr1Point2);
			LineEquation Line2(Tr2Point1, Tr2Point2);

			Lines.IntersectionOfLines(PolygonPoints, Line1, Line2);

			int PolygonSize = PolygonPoints.GetCoordinatesPolygon().size();
			Assert::AreEqual(1, PolygonSize);
		}
		TEST_METHOD(SectionsOfTwoLinesHaveACommonStartOrEndPoint)
		{
			Polygon PolygonPoints;
			LineEquation Lines;

			Point Tr1Point1(-80, 110);
			Point Tr1Point2(30, 110);

			Point Tr2Point1(30, 110);
			Point Tr2Point2(-30, 250);

			LineEquation Line1(Tr1Point1, Tr1Point2);
			LineEquation Line2(Tr2Point1, Tr2Point2);

			Lines.IntersectionOfLines(PolygonPoints, Line1, Line2);

			int PolygonSize = PolygonPoints.GetCoordinatesPolygon().size();
			Assert::AreEqual(1, PolygonSize);
		}
		TEST_METHOD(SectionsOfTwoLinesHaveACommonStartOrEndPoint_TryingToSaveAgain)
		{
			Polygon PolygonPoints;
			LineEquation Lines;

			Point Tr1Point1(-80, 110);
			Point Tr1Point2(30, 110);

			Point Tr2Point1(30, 110);
			Point Tr2Point2(-30, 250);

			PolygonPoints.SetPolygonPoint(Tr1Point2);

			LineEquation Line1(Tr1Point1, Tr1Point2);
			LineEquation Line2(Tr2Point1, Tr2Point2);

			Lines.IntersectionOfLines(PolygonPoints, Line1, Line2);

			int PolygonSize = PolygonPoints.GetCoordinatesPolygon().size();
			Assert::AreEqual(1, PolygonSize);
		}
		TEST_METHOD(IdenticalTriangles)
		{
			Triangle Triangle1, Triangle2;

			Point Tr1Point1(110, -170);
			Point Tr1Point2(60, -30);
			Point Tr1Point3(170, -30);

			Point Tr2Point1(110, -170);
			Point Tr2Point2(60, -30);
			Point Tr2Point3(170, -30);

			Triangle1.SetTriangleVertices(Tr1Point1, Tr1Point2, Tr1Point3);
			Triangle2.SetTriangleVertices(Tr2Point1, Tr2Point2, Tr2Point3);

			Assert::IsTrue(Triangle1.IsIdenticalTriangles(Triangle1, Triangle2));
		}
		TEST_METHOD(NotIdenticalTriangles)
		{
			Triangle Triangle1, Triangle2;

			Point Tr1Point1(-30, -30);
			Point Tr1Point2(-80, 110);
			Point Tr1Point3(30, 110);

			Point Tr2Point1(-30, 250);
			Point Tr2Point2(-80, 110);
			Point Tr2Point3(30, 110);

			Triangle1.SetTriangleVertices(Tr1Point1, Tr1Point2, Tr1Point3);
			Triangle2.SetTriangleVertices(Tr2Point1, Tr2Point2, Tr2Point3);

			Assert::IsFalse(Triangle1.IsIdenticalTriangles(Triangle1, Triangle2));
		}
	};
}
