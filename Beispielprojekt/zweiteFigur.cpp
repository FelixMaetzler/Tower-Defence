#include "stdafx.h"
#include "zweiteFigur.h"

//Konstruktoren

zweiteFigur::zweiteFigur(void) {
	this->set_attackspeed(0);
	this->set_damage(0);
	this->set_image("Eisberg.png");
	this->set_price(100);
	this->set_range(200);
	this->set_slowrate(0.5);
	this->set_audio("Eisberg.wav");

}

//Get/Set Methoden

void zweiteFigur::set_slowrate(const double sl) {
	this->slowrate = sl;
}
double zweiteFigur::get_slowrate(void) const {
	return this->slowrate;
}

//andere Methoden

//Virtuelle Methoden

void zweiteFigur::gegnerinrange(vector<Gegner*>* liste_ptr) {
	//Verbindugsvektor
	Vektoren d;
	//ermittelt die Zeit, seitdem das letzte mal der Sound abgespielt wurde
	auto t = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - this->get_zeitstempel()).count();
	for (int i = 0; i < liste_ptr->size(); i++)
	{
		//ermittelt den Verbindungsvektor
		d = liste_ptr->at(i)->get_position() - this->get_position();
		//Wenn der Gegnre in Reichweite ist dann
		if (d.laenge() <= this->get_range())
		{
			//Wird die Geschwindigkeit des Gegners mit der Slowrate multipliziert
			liste_ptr->at(i)->set_richtung(liste_ptr->at(i)->get_richtung(), this->get_slowrate());
			//und wenn der Sound noch nicht so lange her ist dann
			if (t > 4000/1.3)
			{
				//wird er nochmals abgespielt
				this->get_audio().play(1, 1.3);
				this->set_zeitstempel(std::chrono::steady_clock::now());
			}

		}
	}
}
void zweiteFigur::Zeichnen(void) {
	//this->get_image().draw_rot(this->get_x(), this->get_y(), 50, 0, 0.5, 0.5);
	this->get_image().draw(this->get_x(), this->get_y(), 50);
}