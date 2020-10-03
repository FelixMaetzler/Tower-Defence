#include "stdafx.h"
#include "Vektoren.h"

#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>


//Konstruktoren

Vektoren::Vektoren(void) {};
Vektoren::Vektoren(const double x,const double y) {
	this->x = x;
	this->y = y;
}

//Methoden

double Vektoren::get_x(void) {
	return this->x;
}
void Vektoren::set_x(double x) {
	this->x = x;
}
double Vektoren::get_y(void) {
	return this->y;
}
void Vektoren::set_y(double y) {
	this->y = y;
}
Vektoren Vektoren::operator+(const Vektoren a) const {
	return Vektoren(this->x + a.x, this->y + a.y);
}
Vektoren Vektoren::operator+=(const Vektoren a) const {
	return Vektoren(this->x + a.x, this->y + a.y);
}
Vektoren Vektoren::operator-(const Vektoren a) const {
	return Vektoren(this->x - a.x, this->y - a.y);
}
Vektoren Vektoren::operator-=(const Vektoren a) const {
	return Vektoren(this->x - a.x, this->y - a.y);
}
double Vektoren::operator*(const Vektoren a) const {
	return (a.x * this->x + a.y * this->y);
}
Vektoren Vektoren::operator*(const double a) const {
	return Vektoren(this->x * a, this->y * a);
}
Vektoren Vektoren::operator*=(const double a) const {
	return Vektoren(this->x * a, this->y * a);
}
Vektoren Vektoren::operator/(const double a) const {
	return Vektoren(this->x / a, this->y / a);
}
Vektoren Vektoren::operator/=(const double a) const {
	return Vektoren(this->x / a, this->y / a);
}
double Vektoren::laenge(void) const {
	double d = 0;
	d += this->x * this->x;
	d += this->y * this->y;
	d = pow(d, 0.5);
	return d;
}
double Vektoren::winkel(void) const {
	double w;
	double r = 0;//Um alles um einen bestimmen Winkel im Gradmaß gegen den Uhrzeigersinn zu drehen

	w = -radiantToDegree(atan2(this->y, this->x));
	w = winkelNormalisieren(w + r);
	return w;

}
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
double Vektoren::winkelZwischen2Vektoren(const Vektoren a) const {
	double w;
	w = a.winkel() - this->winkel();
	return winkelNormalisieren(w);
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
Vektoren Vektoren::normieren(void) const {
	return (*this / this->laenge());
}
void Vektoren::print(void) const {
	std::cout << "(" << this->x << "|" << this->y << ")" << std::endl;
}
double Vektoren::skalarprodukt(Vektoren a) const {
	return *this * a;
}
