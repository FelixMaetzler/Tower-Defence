#include "stdafx.h"
#include"Gegner.h"

//Konstruktoren

Gegner::Gegner(void) {};
Gegner::Gegner(int l, double g) {
	this->leben = l;
	this->geschwindigkeit = g;
};

//Methoden

int Gegner::get_leben(void) {
	return this->leben;
}
void Gegner::set_leben(int l) {
	this->leben = l;
}
double Gegner::get_geschwindigkeit(void) {
	return this->geschwindigkeit;
}
void Gegner::set_Geschwindigkeit(double gesch) {
	this->geschwindigkeit = gesch;
}