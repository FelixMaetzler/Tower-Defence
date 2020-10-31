#include "stdafx.h"
#include"Wegkachel.h"
#include "interneKonstanten.h"
#include <iostream>
Gosu::Color rd = Gosu::Color::Color(255, 255, 0, 0);

void wegHorizontal(int x, int y, int länge) {

	for (int i = 0; i < länge; i++)
	{
		Kachel a = (*arrayKachel)[x][double(y + i)];
		a.set_istWeg(true);
		a.set_farbe(Gosu::Color::Color(255, 255, 255, 0));
		a.set_image("Weg.png");
		(*arrayKachel)[x][double(y + i)] = a;
	}
	
}
void wegVertikal(int x, int y, int länge) {

	for (int i = 0; i < länge; i++)
	{
		Kachel a = (*arrayKachel)[double(x + i)][y];
		a.set_istWeg(true);
		a.set_farbe(Gosu::Color::Color(255, 255, 255, 0));
		a.set_image("Weg.png");
		(*arrayKachel)[double(x + i)][y] = a;
	}

}
void gridmitweg(void) {
	int Zeilenzahl = arrayKachel->size();
	int Spaltenzahl = arrayKachel->at(0).size();

	wegHorizontal(0, 0, Spaltenzahl);
	wegHorizontal(Zeilenzahl / 2, 0, Spaltenzahl);
	wegHorizontal(Zeilenzahl - 1, 0, Spaltenzahl);
	wegVertikal(0, Spaltenzahl - 1, Zeilenzahl / 2);
	wegVertikal(Zeilenzahl / 2, 0, Zeilenzahl / 2);

	
}
vector<Kachel> wegalsListe(void) {
	vector<Kachel> liste(0);
	int Zeilenzahl = arrayKachel->size();
	int Spaltenzahl = arrayKachel->at(0).size();
	for (int i = 0; i < Spaltenzahl; i++)
	{
		liste.push_back((*arrayKachel)[0][i]);
	}
	int i = 0;
	for (i = 1; i < Zeilenzahl; i++)
	{
		if ((*arrayKachel)[i][double(Spaltenzahl - 1)].get_istWeg() == false)
		{
			break;
		}
		else
		{
			liste.push_back((*arrayKachel)[i][double(Spaltenzahl - 1)]);
		}

	}
	for (int j = Spaltenzahl - 2; j >= 0; j--)
	{
		liste.push_back((*arrayKachel)[double(i - 1)][j]);
	}
	for (int j = i; j < Zeilenzahl; j++)
	{
		liste.push_back((*arrayKachel)[j][0]);
	}
	for (int j = 1; j < Spaltenzahl; j++)
	{
		liste.push_back((*arrayKachel)[double(Zeilenzahl - 1)][j]);
	}

	return liste;
}