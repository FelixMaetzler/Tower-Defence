#include "stdafx.h"
#include"Gegner.h"
#include "Vektoren.h"
#include "Zeichnen.h"

//Konstruktoren

Gegner::Gegner(void) {};
Gegner::Gegner(int l, double g) {
	this->leben = l;
	this->geschwindigkeit = g;
};

//Methoden

int Gegner::get_leben(void) const {
	return this->leben;
}
void Gegner::set_leben(const int l) {
	this->leben = l;
}
double Gegner::get_geschwindigkeit(void) const {
	return this->geschwindigkeit;
}
void Gegner::set_Geschwindigkeit(const double gesch) {
	this->geschwindigkeit = gesch;
}
int Gegner::get_x(void) const {
	return this->get_position().get_x();
}
void Gegner::set_x(const int x) {
	this->position.set_x(x);
}
int Gegner::get_y(void) const {
	return this->get_position().get_y();
}
void Gegner::set_y(const int y) {
	this->position.set_y(y);
}
Vektoren Gegner::get_richtung(void) const {
	return this->richtung;
}
void Gegner::set_richtung(const Vektoren a) {
	a.normieren();
	this->richtung = a * this->geschwindigkeit;
}
void Gegner::RichtungZuPunkt(const Vektoren a) {
	this->set_richtung(a - this->position);
}
void Gegner::set_position(const Vektoren a) {
	this->position = a;
}
Vektoren Gegner::get_position(void) const {
	return this->position;
}
void Gegner::Zeichnen(void) const {
	int b = 20;
	//rechteck_2Ecken(this->get_x(), this->get_y(), this->get_x() + b, this->get_y() + b, Gosu::Color::Color(255, 0, 0, 255), 30);
	rechteck_Mittelpunkt(this->get_x(), this->get_y(), b, b, Gosu::Color::Color(255, 0, 0, 255), 30);
}