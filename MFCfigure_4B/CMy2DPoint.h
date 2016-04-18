#pragma once
#include <iostream>

class CMy2DPoint {
public:
	double m_x;
	double m_y;

	CMy2DPoint();

	CMy2DPoint(double var);
	CMy2DPoint(double x, double y);
	CMy2DPoint(const CMy2DPoint &src);
	~CMy2DPoint() {};

	CMy2DPoint operator+ (const CMy2DPoint &point) const;
	CMy2DPoint operator- (const CMy2DPoint &point) const;
	double operator * (const CMy2DPoint &point) const;
	CMy2DPoint operator * (double number) const;
	CMy2DPoint operator / (double number) const;
	bool operator== (const CMy2DPoint &point) const;
	bool operator!= (const CMy2DPoint &point) const;

	friend CMy2DPoint operator * (double number, const CMy2DPoint &point);

	friend std::ostream & operator<<(std::ostream & os, const CMy2DPoint & output);
	friend std::istream & operator>>(std::istream & is, CMy2DPoint & input);
	friend std::ofstream & operator<<(std::ofstream &ofs, const CMy2DPoint &output);
};