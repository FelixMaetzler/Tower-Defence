#include "stdafx.h"
#include "Spieler.h"
#include "interneKonstanten.h"

//Konstruktoren

Spieler::Spieler(void)
	:lebensanzeige(20),//gibt die Schriftgröße an
	geldanzeige(20)//gibt die Schriftgröße an
{
	this->set_geld(300);
	this->set_leben(50);
	//this->set_geldanzeige(20);
	//this->set_lebensanzeige(20);

}

//Get/Set Methoden

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

void Spieler::set_lebensanzeige(const int i) {
	this->lebensanzeige = Gosu::Font(i);
}

Gosu::Font Spieler::get_lebensanzeige(void) const {
	return this->lebensanzeige;
}

void Spieler::set_geldanzeige(const int i) {
	this->geldanzeige = Gosu::Font(i);
}

Gosu::Font Spieler::get_geldanzeige(void) const {
	return this->geldanzeige;
}

void Spieler::set_runde(const int i) {
	this->runde = i;
}

int Spieler::get_runde(void) const {
	return this->runde;
}

//andere Methoden

void Spieler::Zeichnen(void) {
	string text_geld;
	string text_leben;
	text_leben = "Leben: ";
	text_leben += std::to_string((int)this->get_leben());
	text_geld = "";
	text_geld += std::to_string((int)this->get_geld());
	text_geld += " Euro";
	this->get_geldanzeige().draw(text_geld, 1600, 70, Z_Spieleranzeige, 1, 1, Gosu::Color::Color(0, 255, 0));
	this->get_lebensanzeige().draw(text_leben, 1710, 70, Z_Spieleranzeige, 1, 1, Gosu::Color::Color(0, 255, 0));
}

void Spieler::geld_abziehen(const double geld) {
	this->set_geld(this->get_geld() - geld);
}

void Spieler::runde_inkrementieren(void) {
	this->set_runde(this->get_runde() + 1);
}