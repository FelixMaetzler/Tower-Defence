#include "stdafx.h"
#include "Spieler.h"


void Spieler::set_geld(const double g) {

	this->geld = g;

}
double Spieler::get_geld(void) const {
	return this->geld;
}
void Spieler::set_leben(const double l) {
	if (l < 1)
	{
		// Game Over
	}
	else
	{
		this->leben = l;
	}
}
double Spieler::get_leben(void) const {
	return this->leben;
}
