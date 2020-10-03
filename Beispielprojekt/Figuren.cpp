#include "stdafx.h"
#include "Figuren.h"

//Konstruktoren

Figuren::Figuren(void) {};
Figuren::Figuren(double as, double d, int p) {
	this->attackspeed = as;
	this->damage = d;
	this->price = p;
};

//Methoden

void Figuren::set_attackspeed(double as) {
	this->attackspeed = as;
}
double Figuren::get_attackspeed(void) {
	return this->attackspeed;
}
void Figuren::set_damage(double d) {
	this->damage = d;
}
double Figuren::get_damage(void) {
	return this->damage;
}
void Figuren::set_price(int p) {
	this->price = p;
}
int Figuren::get_price(void) {
	return this->price;
}