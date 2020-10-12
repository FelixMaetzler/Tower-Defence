#include "stdafx.h"
#include "ersteFigur.h"
#include "Gegner.h"
#include <chrono>
#include <iostream>
#include "interneKonstanten.h"


//Konstruktoren

ersteFigur::ersteFigur(void) {
	this->set_attackspeed(1);
	this->set_damage(10);
	this->set_image("Sniper.png");
	this->set_price(100);
	this->set_range(750);
	this->set_audio("Sniper.wav");
}

//Get/Set Methoden

void ersteFigur::set_richtungzumgegner(const Vektoren a) {
	this->richtungzumgegner = a;
}
Vektoren ersteFigur::get_richtungzumgegner(void) const {
	return this->richtungzumgegner;
}

//andere Methoden

void ersteFigur::gegnerinrange(vector<Gegner*>* liste_ptr) {

	//Zeit in ms nach dem letzen Schuss
	auto d = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - this->get_zeitstempel()).count();
	if (d >= (1 / (this->get_attackspeed()) * 1000))//Wenn diese Zahl größer gleich dem atckspeed des Turmes ist, dann darf er wieder feuern
	{
		//std::cout << d << std::endl;

		Vektoren abstand;
		int j = 0;//Setzt den Spitzenreiter auf den Listenplatz 0
		for (int i = 0; i < liste_ptr->size(); i++)//Hier wird durch die Gegnerliste iteriert
		{
			abstand = (liste_ptr->at(i))->get_position() - this->get_position();//berechnet den Abstand des Turms zum Gegner

			if (abstand.laenge() <= this->get_range())//Wenn dieser kleiner gleich der Range des Turmers ist, also in Reichweite
			{
				if ((liste_ptr->at(j))->get_leben() < (liste_ptr->at(i))->get_leben())// dann wird überprüft ob der aktuelle Spitzenreiter j weniger Leben hat wie der aktuelle
				{
					j = i;// Wenn ja wird der aktuelle der neue Spitzenreiter
				}
			}
		}
		//Jetzt beiinhaltet j den Listenplatz des Gegners mit den meisten Leben der in Range ist
		//wenn aber gar keiner in Range ist, dann wäre es automatisch an der Stelle 0

		if (((liste_ptr->at(j))->get_position() - this->get_position()).laenge() <= this->get_range())//Deswegen wird hier nochmal geprüft ob der Spitzenreiter j wirklich in range ist
		{
			//auf das Element das in der Liste auf j liegt wird jetzt geschossen
			this->get_audio().play(lautstaerke, 1);//Audio wird abgespielt
			this->set_zeitstempel(std::chrono::steady_clock::now());//und der Zeitstempel des letzten Schusses auf jetzt gesetzt

			if ((liste_ptr->at(j))->get_leben() > this->get_damage())//Wenn der Gegner mehr Leben hat als der Turm Schaden macht
			{
				(liste_ptr->at(j))->lebenAbziehen(this->get_damage());//Dann wird ihm der Schaden an Leben abgezogen
				this->set_richtungzumgegner((liste_ptr->at(j))->get_position() - this->get_position());//und die Richtung zu dem Gegner gesetzt
			}
			else//Wenn er nicht mehr genug leben hat
			{
				//Dann wird hier ein Gegner erstellt der einen Tier unter dem aktuellen ist
				//Dieser bekommt Position des sterbenden Gegners
				Gegner* a = (liste_ptr->at(j))->schwaecherenGegnerSpawnen((liste_ptr->at(j))->get_position(), (liste_ptr->at(j))->get_naechsterwegpunkt());
				this->set_richtungzumgegner((liste_ptr->at(j))->get_position() - this->get_position());//Richtung wird gesetzt
				spieler.set_geld(spieler.get_geld() + liste_ptr->at(j)->get_geld());//gibt dem Spieler Geld wenn der gegner stirbt
				//liste_ptr->at(j)->~Gegner();//Keine Ahnung ob des funzt
				//cout << a << endl;
				//free(liste_ptr->at(j));
				//cout << a << endl;
				delete liste_ptr->at(j);//Und der Gegner der stirbt wird vom Speicher gelöscht

				if (a != NULL)// Wenn der gestorbene Gegner schon der niedrigste war, dann ist der pointer auf den neuenn Gegner null
				{
					//Wenn nicht dann wird der neue Gegner da in die liste eingesetzt wo vorher der alte war
					liste_ptr->at(j) = a;
				}
				else
				{
					//wenn es aber schon der niedrigste war, dann wird der Listenplatz gelöscht
					liste_ptr->erase(liste_ptr->begin() + j);
				}


			}
		}
	}
}
void ersteFigur::Zeichnen(void) {
	double angle = 0;// ist der Winkel zum Gegner; Wird benötigt um den SNiper richtig zu drehen
	angle = winkelingosuwinkel(double(this->get_richtungzumgegner().winkel()));
	/*
	 if (angle != 0)
	{
		cout << angle << endl;
	}
	*/
	//Zeichnet den Sniper
	this->get_image().draw_rot(this->get_x(), this->get_y(), Z_Figur, angle);
}