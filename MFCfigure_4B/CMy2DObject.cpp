#include "stdafx.h"
#include <ostream>
#include <iostream>
#include "CMy2DPoint.h"
#include "CMy2DObject.h"
#include <math.h>
#include <Windows.h>

#define M_PI 3.1415926535897932384626433832795

using namespace std;


// user's functions
double degtorad(double deg) {
	return (deg * M_PI / 180);
}

CMy2DPoint rotatedPoint(const CMy2DPoint &point, const CMy2DPoint &centerPoint, double dAngle) {
	//CMy2DPoint result(centerPoint.m_x + (point.m_x - centerPoint.m_x) * cos(180 * dAngle / M_PI) - (point.m_y - centerPoint.m_y) * sin(180 * dAngle / M_PI),
	//	centerPoint.m_y + (point.m_y - centerPoint.m_y) * cos(180 * dAngle / M_PI) + (point.m_x - centerPoint.m_x) * sin(180 * dAngle / M_PI));
	
	CMy2DPoint result(centerPoint.m_x + (point.m_x - centerPoint.m_x) * cos(degtorad(dAngle)) - (point.m_y - centerPoint.m_y) * sin(degtorad(dAngle)),
		centerPoint.m_y + (point.m_y - centerPoint.m_y) * cos(degtorad(dAngle)) + (point.m_x - centerPoint.m_x) * sin(degtorad(dAngle)));
	return result;
};

double distancePoints(const CMy2DPoint &point1, const CMy2DPoint &point2) {
	return pow(pow(point1.m_x - point2.m_x, 2) + pow(point1.m_y - point2.m_y, 2), 0.5);
};

// methods of class
CMy2DObject4B::CMy2DObject4B() :A(0), A1(0), A2(0), A3(0), m_dAngle(0) {};

CMy2DObject4B::CMy2DObject4B(double A, double A1, double A2, double A3, const CMy2DPoint& center, double dAngle) :A(A), A1(A1), A2(A2), A3(A3), m_center(center), m_dAngle(dAngle) {};

CMy2DObject4B::~CMy2DObject4B() {};

double CMy2DObject4B::getA(int number) const {
	switch (number) {
	case 0:
		return A;
		break;
	case 1:
		return A1;
		break;
	case 2:
		return A2;
		break;
	case 3:
		return A3;
		break;

	default:
		return -1;
		break;
	}
};

CMy2DPoint CMy2DObject4B::getCenter() const {
	return m_center;
};

double CMy2DObject4B::getAngle() const {
	return m_dAngle;
};

void CMy2DObject4B::printSettings() const {
	cout << "A: " << A << "\t" <<
		"A1: " << A1 << "\t" <<
		"A2: " << A2 << "\t" <<
		"A3: " << A3 << endl <<
		"m_center: " << m_center << "\t" <<
		"m_dAngle: " << m_dAngle << endl;
	cout << endl;
};

void CMy2DObject4B::set() {
	bool flag = true;
	double newA;
	double newA1;
	double newA2;
	double newA3;
	CMy2DPoint newCenter;
	double newAngle;

	do {
		cout << "New settings:" << endl;

		cout << "A: ";
		cin >> newA;

		cout << "A1: ";
		cin >> newA1;

		cout << "A2: ";
		cin >> newA2;

		cout << "A3: ";
		cin >> newA3;

		cout << endl;

		cout << "m_center: ";
		cin >> newCenter;

		cout << "m_dAngle: ";
		cin >> newAngle;

		//CMy2DPoint vector1(newA / 2 - newA1, newA1 / 2);
		//CMy2DPoint pointB;
		//pointB = m_center + vector1;

		//CMy2DPoint vector2(newA2 / 2 - newA1, -newA1 / 2);
		//CMy2DPoint pointC;
		//pointC = m_center + vector2;

		//CMy2DPoint vector3(-newA / 2, newA / 2);
		//CMy2DPoint pointLT;
		//pointLT = m_center + vector3;

		//CMy2DPoint vector4(newA / 2 - newA3, newA2 / 2 - newA3);
		//CMy2DPoint pointLB;
		//pointLB = m_center - vector4;

		//flag = !((newA > 0) & (newA1 > 0) & (newA2 > 0) & (newA3 > 0) &
		//	(newA1 < newA) & (newA2 < newA) & (newA3 < newA) & (newA3 + newA2 < newA) & // on self-intersection test
		//	(distancePoints(pointLT, pointB) > newA2) &
		//	(distancePoints(pointLB, pointC) > 0));

		flag = !testProperties(newA, newA1, newA2, newA3, newAngle, newCenter);

		if (flag) {
			HANDLE hConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsoleHandle, (WORD)12);
			cout << endl << "!!! WRONG NEW PARAMETERS !!!" << endl << endl;
			SetConsoleTextAttribute(hConsoleHandle, (WORD)7);

			cout << "Shape 1:" << endl;
			printSettings();
		}
		else {
			A = newA;
			A1 = newA1;
			A2 = newA2;
			A3 = newA3;
			m_center = newCenter;
			m_dAngle = newAngle;

			HANDLE hConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsoleHandle, (WORD)10);
			cout << endl << "Done" << endl << endl;
			SetConsoleTextAttribute(hConsoleHandle, (WORD)7);
		}
	} while (flag);
};

void CMy2DObject4B::setA(double newA) {
	A = newA;
}

void CMy2DObject4B::setA1(double newA1) {
	A1 = newA1;
}

void CMy2DObject4B::setA2(double newA2) {
	A2 = newA2;
}

void CMy2DObject4B::setA3(double newA3) {
	A3 = newA3;
}

void CMy2DObject4B::setAngle(double newAngle) {
	m_dAngle = newAngle;
}

void CMy2DObject4B::setCenter(CMy2DPoint newCenter) {
	m_center = newCenter;
}

bool testProperties(double newA, double newA1, double newA2, double newA3, double newAngle, CMy2DPoint center) {
	bool flag = true;

	CMy2DPoint vector1(newA / 2 - newA1, newA1 / 2);
	CMy2DPoint pointB;
	pointB = center + vector1;

	CMy2DPoint vector2(newA2 / 2 - newA1, -newA1 / 2);
	CMy2DPoint pointC;
	pointC = center + vector2;

	CMy2DPoint vector3(-newA / 2, newA / 2);
	CMy2DPoint pointLT;
	pointLT = center + vector3;

	CMy2DPoint vector4(newA / 2 - newA3, newA2 / 2 - newA3);
	CMy2DPoint pointLB;
	pointLB = center - vector4;

	flag = !((newA > 0) & (newA1 > 0) & (newA2 > 0) & (newA3 > 0) &
		(newA1 <= newA) & (newA2 <= newA) & (newA3 <= newA) & (newA3 + newA2 <= newA) & // on self-intersection test
		(distancePoints(pointLT, pointB) >= newA2) &
		(distancePoints(pointLB, pointC) >= 0));

	return (!flag);
}

void CMy2DObject4B::move(const CMy2DPoint &delta, double dAngle) {
	m_dAngle += dAngle;
	m_center = m_center + delta;
};

void CMy2DObject4B::move(double dX, double dY, double dAngle) {
	CMy2DPoint delta(dX, dY);
	move(delta, dAngle);
};

void CMy2DObject4B::rotate(double dAngle) {
	m_dAngle += dAngle;
	while (m_dAngle > 360) {
		m_dAngle -= 360;
	}
	while (m_dAngle < 0) {
		m_dAngle += 360;
	}
};

bool CMy2DObject4B::isInside(const CMy2DPoint &customPoint) const {
	bool result = false;
	//CMy2DPoint newCustomPoint;

	//newCustomPoint = rotatedPoint(customPoint, m_center, - m_dAngle); // rotate custom point to -Angle
	CMy2DPoint newPoint = rotatedPoint(customPoint, m_center, -m_dAngle); // rotate custom point to -Angle;

	result = (newPoint.m_x < m_center.m_x + A / 2) & (newPoint.m_x > m_center.m_x - A / 2);
	result = result & (newPoint.m_y > m_center.m_y - A / 2) & (newPoint.m_y < m_center.m_y + A / 2);
	
	CMy2DPoint TL(m_center.m_x - A / 2, m_center.m_y - A / 2);
	result = result & (distancePoints(newPoint, TL) > A2);

	CMy2DPoint BL(m_center.m_x - A / 2, m_center.m_y + A / 2);
	result = result & ((newPoint.m_x > BL.m_x + A3) || (newPoint.m_y < BL.m_y - A3));
	result = result & ((newPoint.m_x < m_center.m_x + A / 2 - A1) || (newPoint.m_y < m_center.m_y - A1 / 2) || (newPoint.m_y > m_center.m_y + A1 / 2));
	//result = (newCustomPoint.m_x < m_center.m_x + A / 2 - A1) ||
	//	((newCustomPoint.m_y < m_center.m_y + A / 2) & (newCustomPoint.m_y > m_center.m_y + A1 / 2)) ||
	//	((newCustomPoint.m_y > m_center.m_y - A / 2) & (newCustomPoint.m_y < m_center.m_y - A1 / 2)); // right middle test

	//CMy2DPoint pointLT(m_center.m_x - A / 2, m_center.m_y + A / 2);
	//result = result & (distancePoints(newCustomPoint, pointLT) > A2); // left top test

	//CMy2DPoint pointLB(m_center.m_x - A / 2, m_center.m_y - A / 2);
	//result = result & ((newCustomPoint.m_x - pointLB.m_x > A3) || (newCustomPoint.m_y - pointLB.m_y > A3)); // left bottom test

	//result = result &
	//	((newCustomPoint.m_x < m_center.m_x + A / 2) || (newCustomPoint.m_x >m_center.m_x - A / 2)) &
	//	((newCustomPoint.m_y < m_center.m_y + A / 2) || (newCustomPoint.m_y >m_center.m_y - A / 2));

	return result;
};

bool CMy2DObject4B::isInside(double x, double y) const {
	CMy2DPoint point(x, y);
	return isInside(point);
};


void CMy2DObject4B::draw(CDC &dc) {
	CMy2DPoint TL(m_center.m_x - A / 2, m_center.m_y - A / 2);
	TL = rotatedPoint(TL, m_center, m_dAngle);
	CMy2DPoint TLs(m_center.m_x - A / 2 + A2, m_center.m_y - A / 2);
	TLs = rotatedPoint(TLs, m_center, m_dAngle);
	CMy2DPoint BL1(m_center.m_x - A / 2, m_center.m_y + A / 2 - A3);
	BL1 = rotatedPoint(BL1, m_center, m_dAngle);
	CMy2DPoint BL2(m_center.m_x - A / 2 + A3, m_center.m_y + A / 2 - A3);
	BL2 = rotatedPoint(BL2, m_center, m_dAngle);
	CMy2DPoint BL3(m_center.m_x - A / 2 + A3, m_center.m_y + A / 2);
	BL3 = rotatedPoint(BL3, m_center, m_dAngle);
	CMy2DPoint BR(m_center.m_x + A / 2, m_center.m_y + A / 2);
	BR = rotatedPoint(BR, m_center, m_dAngle);
	CMy2DPoint P4(m_center.m_x + A / 2, m_center.m_y + A1 / 2);
	P4 = rotatedPoint(P4, m_center, m_dAngle);
	CMy2DPoint P3(m_center.m_x + A / 2 - A1, m_center.m_y + A1 / 2);
	P3 = rotatedPoint(P3, m_center, m_dAngle);
	CMy2DPoint P2(m_center.m_x + A / 2 - A1, m_center.m_y - A1 / 2);
	P2 = rotatedPoint(P2, m_center, m_dAngle);
	CMy2DPoint P1(m_center.m_x + A / 2, m_center.m_y - A1 / 2);
	P1 = rotatedPoint(P1, m_center, m_dAngle);
	CMy2DPoint TB(m_center.m_x + A / 2, m_center.m_y - A / 2);
	TB = rotatedPoint(TB, m_center, m_dAngle);

	dc.MoveTo(BL1.m_x, BL1.m_y);
	dc.LineTo(BL2.m_x, BL2.m_y);
	dc.LineTo(BL3.m_x, BL3.m_y);
	dc.LineTo(BR.m_x, BR.m_y);
	dc.LineTo(P4.m_x, P4.m_y);
	dc.LineTo(P3.m_x, P3.m_y);
	dc.LineTo(P2.m_x, P2.m_y);
	dc.LineTo(P1.m_x, P1.m_y);
	dc.LineTo(TB.m_x, TB.m_y);
	dc.LineTo(TLs.m_x, TLs.m_y);
	dc.AngleArc(TL.m_x, TL.m_y, A2, - m_dAngle, - 90);
	dc.LineTo(BL1.m_x, BL1.m_y);
}