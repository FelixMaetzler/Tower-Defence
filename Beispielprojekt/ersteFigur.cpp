#include "stdafx.h"
#include "ersteFigur.h"
#include "Gegner.h"
#include <chrono>
#include <iostream>




ersteFigur::ersteFigur(void) {
	this->set_attackspeed(1);
	this->set_damage(10);
	this->set_image("Sniper.png");
	this->set_price(100);
	this->set_range(750);
	this->set_audio("Sniper.wav");
}

void ersteFigur::set_richtungzumgegner(const Vektoren a) {
	this->richtungzumgegner = a;
}
Vektoren ersteFigur::get_richtungzumgegner(void) const {
	return this->richtungzumgegner;
}

void ersteFigur::gegnerinrange(vector<Gegner*>* liste_ptr) {
	auto d = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - this->get_zeitstempel()).count();
	if (d >= (1 / (this->get_attackspeed()) * 1000))
	{
		//std::cout << d << std::endl;
		this->set_zeitstempel(std::chrono::steady_clock::now());
		Vektoren abstand;
		int j = 0;
		for (int i = 0; i < liste_ptr->size(); i++)
		{
			abstand = (liste_ptr->at(i))->get_position() - this->get_position();

			if (abstand.laenge() <= this->get_range())
			{
				if ((liste_ptr->at(j))->get_leben() < (liste_ptr->at(i))->get_leben())
				{
					j = i;
				}
			}
		}
		if (((liste_ptr->at(j))->get_position() - this->get_position()).laenge() <= this->get_range())
		{
			this->get_audio().play(1,1);
			// auf das Element das in der Liste auf j liegt wird geschossen
			if ((liste_ptr->at(j))->get_leben() > this->get_damage())
			{
				(liste_ptr->at(j))->lebenAbziehen(this->get_damage());
				this->set_richtungzumgegner((liste_ptr->at(j))->get_position() - this->get_position());
			}
			else
			{
				Gegner* a = (liste_ptr->at(j))->schwaecherenGegnerSpawnen((liste_ptr->at(j))->get_position(), (liste_ptr->at(j))->get_naechsterwegpunkt());
				this->set_richtungzumgegner((liste_ptr->at(j))->get_position() - this->get_position());
				//liste_ptr->at(j)->~Gegner();//Keine Ahnung ob des funzt
				//cout << a << endl;
				//free(liste_ptr->at(j));
				//cout << a << endl;
				delete liste_ptr->at(j);
				
				if (a != NULL)
				{
					liste_ptr->at(j) = a;
				}
				else
				{
					
					liste_ptr->erase(liste_ptr->begin() + j);
				}
				

			}
		}
	}
}
void ersteFigur::Zeichnen(void) {
	double angle = 0;
	angle = winkelingosuwinkel(double(this->get_richtungzumgegner().winkel()));
	/*
	 if (angle != 0)
	{
		cout << angle << endl;
	}
	*/
	this->get_image().draw_rot(this->get_x(), this->get_y(), 50, angle);
}