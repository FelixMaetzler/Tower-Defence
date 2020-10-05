#include "stdafx.h"
#include"Gegner.h"
#include "Vektoren.h"
#include "Zeichnen.h"

//Konstruktoren

Gegner::Gegner(void) {};
Gegner::Gegner(int l, double g) {
	this->set_leben(l);
	this->set_Geschwindigkeit(g);
};

//Get/Set Methoden

int Gegner::get_leben(void) const {
	return this->leben;
}
void Gegner::set_leben(const int l) {
	this->leben = l;
}
double Gegner::get_geschwindigkeit(void) const {
	return this->geschwindigkeit;
}
void Gegner::set_Geschwindigkeit(const double gesch) {
	this->geschwindigkeit = gesch;
}
int Gegner::get_x(void) const {
	return this->get_position().get_x();
}
void Gegner::set_x(const int x) {
	this->position.set_x(x);
}
int Gegner::get_y(void) const {
	return this->get_position().get_y();
}
void Gegner::set_y(const int y) {
	this->position.set_y(y);
}
Vektoren Gegner::get_richtung(void) const {
	return this->richtung;
}
void Gegner::set_richtung(const Vektoren a) {
	a.normieren();
	this->richtung = a * this->get_geschwindigkeit();
}
void Gegner::set_position(const Vektoren a) {
	this->position = a;
}
Vektoren Gegner::get_position(void) const {
	return this->position;
}
int Gegner::get_naechsterwegpunkt(void)const {
	return this->naechsterwegpunkt;
}
void Gegner::set_naechsterwegpunkt(const int w) {
	this->naechsterwegpunkt = w;
}

//andere Methoden

//setzt die Richtung des Gegners zu dem als Argument angegebenen Punkrt
void Gegner::RichtungZuPunkt(const Vektoren a) {
	this->set_richtung(a - this->get_position());
}

void Gegner::Zeichnen(void) const {
	int b = 20;//Kantenl�nge des quadratischen Gegners
	int a = 50;//Kachelgr��e. Gegebenfalls als Variable neiboltzten

	rechteck_Mittelpunkt(this->get_x() + a / 2, this->get_y() + a / 2, b, b, Gosu::Color::Color(255, 0, 0, 255), 30);
}
//Diese Funktion sorgt daf�r, dass der Gegner den richtigen Weg abf�hrt. Daf�r wird ggf. die Richtung gesetzt
void Gegner::wegpunkt(vector<Kachel> liste) {

	//Hier muss noch was hin, wenn das Ende erreicht worden ist

	int k = this->get_naechsterwegpunkt();
	Kachel a = liste.at(k);//n�chste Kachel
	Vektoren d;

	d = a.get_position() - this->get_position();//Verbindungsvektor zwischen dem Gegner und der n�chsten Kachel
	if (d.laenge() <= 3)//Wenn der Gegner nah genug an der Kachel ist, dann
	{
		this->set_naechsterwegpunkt(k + 1);//Dann ist der Wegpunkt erreicht und der n�chste Wegpunkt wird gesetzt
		this->set_richtung(liste.at(k + 1).get_position() - this->get_position());//Dann wird die neueRcihtung gesetzt
	}


}