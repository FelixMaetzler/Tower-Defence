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
void Maustaste_Losgelassen(int x_maus, int y_maus)
{

	double iterator_ze = 1;
	double iterator_sp = 1;

	for (iterator_ze = 1; iterator_ze < arrayKachel->size() + 1; iterator_ze++)
	{
		for (iterator_sp = 1; iterator_sp < arrayKachel->at(0).size() + 1; iterator_sp++)
		{
			(*arrayKachel)[(iterator_ze - 1)][int(iterator_sp - 1)].set_change(false);
		}
	}
	
}

void Maustaste_Gedrückt( int x_maus, int y_maus)
{
	if (hatKachelgetroffen(x_maus, y_maus))//Wenn man eine Kachel geklickt hat
	{
		//Dann soll eine Funktion ausgeführt werden, die die Kachelposition als Vektor zurückgibt
		Vektoren a = MausZuKachel(x_maus, y_maus);

		//a.print();
		Kachel z = (*arrayKachel)[a.get_x()][a.get_y()];

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


			if (spieler.get_geld() >= x->get_price() && !z.get_besetzt())//wenn der Spieler Genug Geld hat und die Kachel nicht besetzt ist
			{
				spieler.geld_abziehen(x->get_price());//Dann wird dem Spieler Geld abgezogen

				x->set_position(z.get_position());//Die Position der Figur wird auf die angeklickte Kachel gesetzt
				figurenliste_ptr->push_back(x);//und die Figur wird zur Liste hinzugefügt
				arrayKachel->at(a.get_x()).at(a.get_y()).set_besetzt(true);
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
	
}
