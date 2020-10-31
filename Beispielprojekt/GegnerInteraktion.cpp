#include "stdafx.h"
#include "GegnerInteraktion.h"
#include "interneKonstanten.h"

void schiessen(vector<Gegner*>* Gegnerliste, vector<Figuren*>* Figurenliste)
{
	//iteriert über alle Gegner
	//for (int i = 0; i < Gegnerliste->size(); i++)
	//{
		//iteriert über alle Figuren
	if (Gegnerliste->size() != 0)
	{


		for (int j = 0; j < Figurenliste->size(); j++)
		{

			(Figurenliste->at(j))->gegnerinrange(Gegnerliste);
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
	//}
}
void zeichnen(vector<Gegner*>* Gegnerliste) {
	for (int i = 0; i < (*Gegnerliste).size(); i++)
	{
		(Gegnerliste->at(i))->Zeichnen();
	}
}
void zeichnen(vector<Figuren*>* Figurenliste) {
	for (int i = 0; i < (*Figurenliste).size(); i++)
	{
		(Figurenliste->at(i))->Zeichnen();
	}
}

void bewegen(vector<Gegner*>* Gegnerliste) {
	for (int i = 0; i < (*Gegnerliste).size(); i++)
	{
		Gegner& gegner = *((*Gegnerliste).at(i));
		
		
		gegner.set_position(gegner.get_position() + gegner.get_richtung());
		
	}
}
void bewegen(Gegner* x) {


	x->set_position(x->get_position() + x->get_richtung());

}
void wegpunkt(vector<Gegner*>* liste_ptr, vector<Kachel> wegliste) {

	for (int i = 0; i < liste_ptr->size(); i++)
	{
		Gegner& gegner = *(liste_ptr->at(i));



		int k = gegner.get_naechsterwegpunkt();

		Kachel a = wegliste.at(k);//nächste Kachel
		Vektoren d;

		d = a.get_position() - gegner.get_position();//Verbindungsvektor zwischen dem Gegner und der nächsten Kachel
		if (d.laenge() <= 3)//Wenn der Gegner nah genug an der Kachel ist, dann
		{

			//Wenn er den letzten Wegpunkt erreicht hat oder aus iwelchen gründen weiter ist, dann wird er aus der Liste gelöscht
			if (double(k) + 1 >= wegliste.size() || wegliste.back().get_x() > fensterbreite ||wegliste.back().get_y() > fensterhöhe)
			{
				//Dem Spieler werden Leben abgezogen
				spieler.set_leben(spieler.get_leben() - liste_ptr->at(i)->get_leben());
				if (liste_ptr->size() != 0)//Vllt ist schon Game Over
				{


					delete liste_ptr->at(i);
					liste_ptr->erase(liste_ptr->begin() + i);
					i--;
				}

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