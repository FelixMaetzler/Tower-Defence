#include "stdafx.h"
#include"ZweiterGegner.h"
#include "Gegner.h"
#include "ErsterGegner.h"

ZweiterGegner::ZweiterGegner(void) {
	this->set_leben(20);
	this->set_Geschwindigkeit(5);
	this->set_image("Gurke.png");
}
Gegner* ZweiterGegner::schwaecherenGegnerSpawnen(Vektoren pos, int wegpunkt) {
	Gegner* gegner = new ErsterGegner();
	gegner->set_position(pos);
	gegner->set_naechsterwegpunkt(wegpunkt);

	return gegner;
}