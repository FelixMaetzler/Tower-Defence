#include "stdafx.h"
#include"ErsterGegner.h"
#include "Gegner.h"

//Konstruktoren


ErsterGegner::ErsterGegner(void) {
	
	this->set_leben(10);
	this->set_geschwindigkeit(1);
	this->set_image("tomato.png");
}



//Methoden

Gegner* ErsterGegner::schwaecherenGegnerSpawnen(Vektoren pos, int wegpunkt) {
	Gegner* gegner = NULL; 

	return gegner;//es wird ein NULL pointer zurückgegeben, da er schon der schwächste Gegner ist
}