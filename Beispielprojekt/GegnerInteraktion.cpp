#include "stdafx.h"
#include "GegnerInteraktion.h"

void inrange(vector<Gegner>* Gegnerliste, vector<Figuren>* Figurenliste)
{
	for each (Gegner gegner in *Gegnerliste)
	{
		int j = 0;
		for each (Figuren figur in *Figurenliste)
		{
			Vektoren d = gegner.get_position() - figur.get_position();
			if (d.laenge() <= figur.get_range())
			{
				gegner.lebenAbziehen(figur.get_damage());
				(*Gegnerliste).erase((*Gegnerliste).begin() + j);

			}
		}
		j++;
	}
}
void zeichnen(vector<Gegner>* Gegnerliste) {
	for (int i = 0; i < (*Gegnerliste).size(); i++)
	{
		Gegner& gegner = (*Gegnerliste).at(i);


		gegner.Zeichnen();
	}
}
void bewegen(vector<Gegner>* Gegnerliste) {
	for (int i = 0; i < (*Gegnerliste).size(); i++)
	{
		Gegner& gegner = (*Gegnerliste).at(i);
			   			
		gegner.set_position(gegner.get_position() + gegner.get_richtung());
	}
}
void bewegen(Gegner* x) {
	
	
		x->set_position(x->get_position() + x->get_richtung());
	
}
void wegpunkt(vector<Gegner>* liste_ptr, vector<Kachel> wegliste) {

	for (int i = 0; i < (*liste_ptr).size(); i++)
	{
		Gegner& gegner = (*liste_ptr).at(i);
	
	

		int k = gegner.get_naechsterwegpunkt();

		Kachel a = wegliste.at(k);//nächste Kachel
		Vektoren d;

		d = a.get_position() - gegner.get_position();//Verbindungsvektor zwischen dem Gegner und der nächsten Kachel
		if (d.laenge() <= 3)//Wenn der Gegner nah genug an der Kachel ist, dann
		{
			//das erkennt wenn der Gegner am Ende ist, allerdings macht endeErreicht() noch nicht das was es soll
			/*
			if (k + 1 >= liste.size())
			{
				this->endeErreicht();
				return;
			}
			*/
			gegner.set_naechsterwegpunkt(k + 1);//Dann ist der Wegpunkt erreicht und der nächste Wegpunkt wird gesetzt
			gegner.RichtungZuPunkt(wegliste.at(k + 1).get_position());
		}
		else
		{
			gegner.set_richtung(a.get_position() - gegner.get_position());
		}
	}
}