#include "stdafx.h"
#include "Spieler.h"


void Spieler::set_geld(int g) {

	this->geld = g;

}
int Spieler::get_geld(void) {
	return this->geld;
}
void Spieler::set_leben(int l) {
	if (l < 1)
	{
		// Game Over
	}
	else
	{
		this->leben = l;
	}
}
int Spieler::get_leben(void) {
	return this->leben;
}
