#pragma once
#include <iostream>

class Point
{
protected:
	float x;
	float y;
public:
	Point() :x(0.0f), y(0.0f) {}
	Point(float x, float y);
	~Point() {}
	void SetX(float x) { this->x = x; }
	void SetY(float y) { this->y = y; }
	float GetX() { return x; }
	float GetY() { return y; }
	friend bool operator==(const Point& Point1, const Point& Point2);
	friend std::ostream& operator<< (std::ostream& Out, const Point& Point);
	friend Point InputPoint();//ввод координат точки
};

Point InputPoint();
