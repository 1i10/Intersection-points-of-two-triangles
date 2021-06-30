#include "Point.h"

Point::Point(float x, float y)
{
	this->x = x;
	this->y = y;
}

bool operator==(const Point& Point1, const Point& Point2)
{
	return (Point1.x == Point2.x && Point1.y == Point2.y);
}

std::ostream& operator<<(std::ostream& Out, const Point& Point)
{
	Out << "Point(" << Point.x << ", " << Point.y << ")";

	return Out;
}

Point InputPoint()
{
	Point P;
	std::cin >> P.x >> P.y;
	while (!std::cin || P.x > 300.0f || P.x < -300.0f || P.y > 300.0f || P.y < -300.0f)
	{
		std::cout << "Неверный ввод!Введите два числа (x y) в диапазоне от -300 до 300: ";
		std::cin.clear();
		std::cin.ignore(1251, '\n');
		std::cin >> P.x >> P.y;
	}
	std::cin.ignore(std::cin.rdbuf()->in_avail());

	return P;
}
