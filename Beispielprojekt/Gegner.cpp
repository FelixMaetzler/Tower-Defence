#include "stdafx.h"
#include"Gegner.h"

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