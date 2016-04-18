#include "stdafx.h"
#include <ostream>
#include <iostream>
#include <fstream>
#include "CMy2DPoint.h"
#include <math.h>

using namespace std;

CMy2DPoint::CMy2DPoint() {
	m_x = 0.0;
	m_y = 0.0;
};

CMy2DPoint::CMy2DPoint(double var) :m_x(var), m_y(var) {}

CMy2DPoint::CMy2DPoint(double x, double y) :m_x(x), m_y(y) {}

CMy2DPoint::CMy2DPoint(const CMy2DPoint &src) :m_x(src.m_x), m_y(src.m_y) {}

CMy2DPoint CMy2DPoint::operator+ (const CMy2DPoint &point) const {
	return CMy2DPoint(m_x + point.m_x, m_y + point.m_y);
};

CMy2DPoint CMy2DPoint::operator- (const CMy2DPoint &point) const {
	return CMy2DPoint(m_x - point.m_x, m_y - point.m_y);
};

double CMy2DPoint::operator * (const CMy2DPoint &point) const {
	return m_x * point.m_x + m_y * point.m_y;
};

CMy2DPoint CMy2DPoint::operator * (double number) const {
	return CMy2DPoint(number * m_x, number * m_y);
};

CMy2DPoint CMy2DPoint::operator / (double number) const {
	return CMy2DPoint(m_x / number, m_y / number);
};

bool CMy2DPoint::operator== (const CMy2DPoint &point) const {
	return (m_x == point.m_x) && (m_y == point.m_y) ? true : false;
};

bool CMy2DPoint::operator!= (const CMy2DPoint &point) const {
	return (m_x != point.m_x) || (m_y != point.m_y) ? true : false;
};

CMy2DPoint operator * (double number, const CMy2DPoint &point) {
	return CMy2DPoint(number * point.m_x, number * point.m_y);
};

ostream& operator<< (ostream& out, const CMy2DPoint &point) {
	out << "<" << point.m_x << ", " << point.m_y << ">";
	return out;
};

istream& operator>> (istream& in, CMy2DPoint &point) {
	in >> point.m_x >> point.m_y;
	return in;

};

ofstream & operator<<(ofstream &ofs, const CMy2DPoint &point) {
	ofs << "<" << point.m_x << ", " << point.m_y << ">";
	return ofs;
};
