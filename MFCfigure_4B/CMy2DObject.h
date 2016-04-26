#pragma once

#include "stdafx.h"
#include <math.h>
#include <iostream>
#include <ostream>
#include "CMy2DPoint.h"

class CMy2DObject4B {
public:
	double A;
	double A1;
	double A2;
	double A3;
	CMy2DPoint m_center;
	double m_dAngle;

	CMy2DObject4B();
	CMy2DObject4B(double A, double A1, double A2, double A3, const CMy2DPoint& center, double dAngle);
	~CMy2DObject4B();

	double getA(int number) const;
	CMy2DPoint getCenter() const;
	double getAngle() const;
	void printSettings() const;
	void set();
	void setA(double dValue);
	void setA1(double dValue);
	void setA2(double dValue);
	void setA3(double dValue);
	void setAngle(double dValue);
	void setCenter(CMy2DPoint center);
	void move(const CMy2DPoint &delta, double dAngle);
	void move(double dX, double dY, double dAngle);
	void rotate(double dAngle);
	void draw(CDC &dc);

	bool isInside(const CMy2DPoint &customPoint) const;
	bool isInside(double x, double y) const;
};

CMy2DPoint rotatedPoint(const CMy2DPoint &point, const CMy2DPoint &centerPoint, double dAngle);
bool testProperties(double dA, double dA1, double dA2, double dA3, double dAngle, CMy2DPoint center);
