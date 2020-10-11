#include "stdafx.h"
#include"ZweiterGegner.h"
#include "Gegner.h"
#include "ErsterGegner.h"

ZweiterGegner::ZweiterGegner(void) {
	this->set_leben(30);
	this->set_geschwindigkeit(5);
	this->set_image("Gurke.png");
	this->set_geld(10);
}
Gegner* ZweiterGegner::schwaecherenGegnerSpawnen(Vektoren pos, int wegpunkt) {
	Gegner* gegner = new ErsterGegner();
	gegner->set_position(pos);
	gegner->set_naechsterwegpunkt(wegpunkt);

	return gegner;
}