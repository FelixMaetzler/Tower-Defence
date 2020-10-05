#include "stdafx.h"
#include "Vektoren.h"

#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>


//Konstruktoren

Vektoren::Vektoren(void) {};
Vektoren::Vektoren(const double x, const double y) {
	this->set_x(x);
	this->set_y(y);
}
Vektoren::Vektoren(const int x, const int y) {
	this->set_x(x);
	this->set_y(y);
}


//Methoden

double Vektoren::get_x(void) const {
	return this->x;
}
void Vektoren::set_x(const double x) {
	this->x = x;
}
double Vektoren::get_y(void) const {
	return this->y;
}
void Vektoren::set_y(const double y) {
	this->y = y;
}
Vektoren Vektoren::operator+(const Vektoren a) const {
	return Vektoren(this->get_x() + a.get_x(), this->get_y() + a.get_y());
}
Vektoren Vektoren::operator+=(const Vektoren a) const {
	return Vektoren(this->get_x() + a.get_x(), this->get_y() + a.get_y());
}
Vektoren Vektoren::operator-(const Vektoren a) const {
	return Vektoren(this->get_x() - a.get_x(), this->get_y() - a.get_y());
}
Vektoren Vektoren::operator-=(const Vektoren a) const {
	return Vektoren(this->get_x() - a.get_x(), this->get_y() - a.get_y());
}
double Vektoren::operator*(const Vektoren a) const {
	return (a.get_x() * this->get_x() + a.get_y() * this->get_y());
}
Vektoren Vektoren::operator*(const double a) const {
	return Vektoren(this->get_x() * a, this->get_y() * a);
}
Vektoren Vektoren::operator*=(const double a) const {
	return Vektoren(this->get_x() * a, this->get_y() * a);
}
Vektoren Vektoren::operator/(const double a) const {
	return Vektoren(this->get_x() / a, this->get_y() / a);
}
Vektoren Vektoren::operator/=(const double a) const {
	return Vektoren(this->get_x() / a, this->get_y() / a);
}
double Vektoren::laenge(void) const {
	double d = 0;
	d += this->get_x() * this->get_x();
	d += this->get_y() * this->get_y();
	d = pow(d, 0.5);
	return d;
}
double Vektoren::winkel(void) const {
	double w;
	double r = 0;//Um alles um einen bestimmen Winkel im Gradmaß gegen den Uhrzeigersinn zu drehen

	w = -radiantToDegree(atan2(this->get_y(), this->get_x()));
	w = winkelNormalisieren(w + r);
	return w;

}
double Vektoren::winkelZwischen2Vektoren(const Vektoren a) const {
	double w;
	w = a.winkel() - this->winkel();
	return w;
}
void Vektoren::normieren(void)  {
	double d = this->laenge();
	this->set_x(this->get_x() / d);
	this->set_y(this->get_y() / d);
}
void Vektoren::print(void) const {
	std::cout << "(" << this->get_x() << "|" << this->get_y() << ")" << std::endl;
}
double Vektoren::skalarprodukt(Vektoren a) const {
	return *this * a;
}

//Funktionen

double radiantToDegree(const double r) {
	double d = r * 360;
	d = d / (2 * M_PI);
	return d;
}
double DegreeToRadiant(double d) {
	double r = d * 2 * M_PI;
	r = r / 360;
	return r;
}

double winkelNormalisieren(double w) {

	int i = (int)(w / 360);
	w = (w - double(i) * 360);
	if (w < 0)
	{
		return w + 360;
	}
	else
	{
		return w;
	}
}

