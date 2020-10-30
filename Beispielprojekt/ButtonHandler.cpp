#include "stdafx.h"
#include "ButtonHandler.h"
#include "Vektoren.h"
#include <vector>
#include "Grid.h"
#include "interneKonstanten.h"
#include <iostream>
#include "ersteFigur.h"
#include "zweiteFigur.h"
using namespace std;
vector<vector<Kachel>> Maustaste_Losgelassen(vector<vector<Kachel>> arrayKachel, int x_maus, int y_maus)
{

	double iterator_ze = 1;
	double iterator_sp = 1;

	for (iterator_ze = 1; iterator_ze < arrayKachel.size() + 1; iterator_ze++)
	{
		for (iterator_sp = 1; iterator_sp < arrayKachel.at(0).size() + 1; iterator_sp++)
		{
			arrayKachel[(iterator_ze - 1)][int(iterator_sp - 1)].set_change(false);
		}
	}
	return arrayKachel;
}

vector<vector<Kachel>> Maustaste_Gedrückt(vector<vector<Kachel>> arrayKachel, int x_maus, int y_maus, vector<Figuren*>* Figurenliste)
{
	if (hatKachelgetroffen(x_maus, y_maus, arrayKachel))//Wenn man eine Kachel geklickt hat
	{
		//Dann soll eine Funktion ausgeführt werden, die die Kachelposition als Vektor zurückgibt
		Vektoren a = MausZuKachel(x_maus, y_maus, arrayKachel);

		//a.print();
		Kachel z = arrayKachel[a.get_x()][a.get_y()];

		/*
		if (z.get_farbe() == Schwarz && z.get_change() == false)
		{
			z.set_change(true);
			//cout << "Schwarz wurde erkannt" << endl;
			z.set_farbe(Rot);
		}
		else if (z.get_farbe() == Rot && z.get_change() == false)
		{
			z.set_change(true);
			z.set_farbe(Schwarz);
			//cout << "Rot wurde erkannt" << endl;
		}

		arrayKachel[a.get_x()][a.get_y()] = z;
		*/

		//Wenn ein Shortcut gedrückt wurde

		Figuren* x = NULL;//ein leerer Zeiger wird erstellt

		if (SniperAusgewählt)
		{
			x = new ersteFigur();

		}
		if (EisbergAusgewählt)
		{
			x = new zweiteFigur();

		}
		if (x != NULL)//wenn er überschrieben wurde
		{


			if (spieler.get_geld() >= x->get_price())//wenn der Spieler Genug Geld hat
			{
				spieler.geld_abziehen(x->get_price());//Dann wird dem Spieler Geld abgezogen

				x->set_position(z.get_position());//Die Position der Figur wird auf die angeklickte Kachel gesetzt
				Figurenliste->push_back(x);//und die Figur wird zur Liste hinzugefügt
			}
			else//Wenn nicht genug Geld da ist
			{
				delete x;//Dann wird die Figur gelöscht
			}
		}

		//alle Shortcuts zurücksetzen
		SniperAusgewählt = false;
		EisbergAusgewählt = false;
	}
	return arrayKachel;
}
