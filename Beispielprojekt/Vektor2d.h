#pragma once

#include <iostream>

class Vektor2d
{
	double x = 0.0;
	double y = 0.0;
public:
	Vektor2d();
	Vektor2d(double, double);
	~Vektor2d();

	double get_x() const;
	double get_y() const;

	Vektor2d operator+(const Vektor2d&) const;
	Vektor2d& operator+=(const Vektor2d&);
	Vektor2d operator-(const Vektor2d&) const;
	Vektor2d& operator-=(const Vektor2d&);
	Vektor2d operator*(const double&) const;
	Vektor2d& operator*=(const double&);
	Vektor2d operator/(const double&) const;
	Vektor2d& operator/=(const double&);

	double length_squared() const;
	double angle(const Vektor2d&) const;

	Vektor2d log() const;

	static Vektor2d from_angle(double angle, double speed = 1.0);
};

