#include "stdafx.h"
#include "GegnerInteraktion.h"

void schiessen(vector<Gegner>* Gegnerliste, vector<Figuren>* Figurenliste)
{
	
	for (int i = 0; i < Gegnerliste->size(); i++)
	{
		for (int j = 0; j < Figurenliste->size(); j++)
		{
			Figurenliste->at(j).gegnerinrange(Gegnerliste);
			/*
			d = Gegnerliste->at(i).get_position() - Figurenliste->at(j).get_position();
			if (d.laenge() <= Figurenliste->at(j).get_range())
			{
				if (Gegnerliste->at(i).get_leben()>Figurenliste->at(j).get_damage())
				{
					Gegnerliste->at(i).lebenAbziehen(Figurenliste->at(j).get_damage());
				}
				else
				{
					//stirbt er
					//Spieler bekommt Geld
					//vllt in andere Funktion auslagern
					Gegnerliste->erase(Gegnerliste->begin() + i);
					i--;
				}
			}
			*/
		}
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

	for (int i = 0; i < liste_ptr->size(); i++)
	{
		Gegner& gegner = liste_ptr->at(i);
	
	

		int k = gegner.get_naechsterwegpunkt();

		Kachel a = wegliste.at(k);//nächste Kachel
		Vektoren d;

		d = a.get_position() - gegner.get_position();//Verbindungsvektor zwischen dem Gegner und der nächsten Kachel
		if (d.laenge() <= 3)//Wenn der Gegner nah genug an der Kachel ist, dann
		{
			
			
			if (k + 1 >= wegliste.size())
			{
				liste_ptr->erase(liste_ptr->begin() + i);
				i--;
				//Dem spieler müssen Leben abgezogen werden
				
				return;
			}
			
			gegner.set_naechsterwegpunkt(k + 1);//Dann ist der Wegpunkt erreicht und der nächste Wegpunkt wird gesetzt
			gegner.RichtungZuPunkt(wegliste.at(k + 1).get_position());
		}
		else
		{
			gegner.set_richtung(a.get_position() - gegner.get_position());
		}
	}
}