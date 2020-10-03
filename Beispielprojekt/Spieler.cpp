#include "stdafx.h"
#include "Spieler.h"


void Spieler::set_geld(const int g) {

	this->geld = g;

}
int Spieler::get_geld(void) const {
	return this->geld;
}
void Spieler::set_leben(const int l) {
	if (l < 1)
	{
		// Game Over
	}
	else
	{
		this->leben = l;
	}
}
int Spieler::get_leben(void) const {
	return this->leben;
}
