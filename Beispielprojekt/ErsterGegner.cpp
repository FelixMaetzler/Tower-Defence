#include "stdafx.h"
#include"ErsterGegner.h"
//Konstruktoren

ErsterGegner::ErsterGegner(void ) 
	:image("tomato.png")
{
	//Gegner(10, 1);
	this->set_leben(10);
	this->set_Geschwindigkeit(1);
}

//Methoden