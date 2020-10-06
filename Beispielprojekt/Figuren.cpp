#include "stdafx.h"
#include "Figuren.h"
#include "Vektoren.h"
#include "ErsterGegner.h"

//Konstruktoren

Figuren::Figuren(void) {};
Figuren::Figuren(double as, double d, int p) {
	this->set_attackspeed(as);
	this->set_damage(d);
	this->set_price(p);
};

//Methoden

void Figuren::set_attackspeed(const double as) {
	this->attackspeed = as;
}
double Figuren::get_attackspeed(void) const {
	return this->attackspeed;
}
void Figuren::set_damage(const double d) {
	this->damage = d;
}
double Figuren::get_damage(void) const {
	return this->damage;
}
void Figuren::set_price(const int p) {
	this->price = p;
}
int Figuren::get_price(void) const {
	return this->price;
}
void Figuren::set_position(const Vektoren p) {
	this->position = p;
}
Vektoren Figuren::get_position(void) const {
	return this->position;
}
void Figuren::set_range(const double r) {
	this->range = r;
}
double Figuren::get_range(void) const {
	return this->range;
}
