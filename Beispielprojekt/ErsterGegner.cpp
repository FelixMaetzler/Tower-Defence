#include "stdafx.h"
#include"ErsterGegner.h"
#include "Gegner.h"

//Konstruktoren


ErsterGegner::ErsterGegner(void) {

	this->set_leben(10);
	this->set_Geschwindigkeit(1);
	this->set_image("tomato.png");
}

//Methoden