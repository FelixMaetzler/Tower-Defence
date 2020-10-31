#include "stdafx.h"
#include"Wegkachel.h"
#include <iostream>
Gosu::Color rd = Gosu::Color::Color(255, 255, 0, 0);

vector<vector<Kachel>> wegHorizontal(vector<vector<Kachel>> Kachelmatrix, int x, int y, int länge) {

	for (int i = 0; i < länge; i++)
	{
		Kachel a = Kachelmatrix[x][double(y + i)];
		a.set_istWeg(true);
		a.set_farbe(Gosu::Color::Color(255, 255, 255, 0));
		a.set_image("Weg.png");
		Kachelmatrix[x][double(y + i)] = a;
	}
	return Kachelmatrix;
}
vector<vector<Kachel>> wegVertikal(vector<vector<Kachel>> Kachelmatrix, int x, int y, int länge) {

	for (int i = 0; i < länge; i++)
	{
		Kachel a = Kachelmatrix[double(x + i)][y];
		a.set_istWeg(true);
		a.set_farbe(Gosu::Color::Color(255, 255, 255, 0));
		a.set_image("Weg.png");
		Kachelmatrix[double(x + i)][y] = a;
	}
	return Kachelmatrix;
}
vector<vector<Kachel>> gridmitweg(vector<vector<Kachel>> Kachelmatrix) {
	int Zeilenzahl = Kachelmatrix.size();
	int Spaltenzahl = Kachelmatrix.at(0).size();

	Kachelmatrix = wegHorizontal(Kachelmatrix, 0, 0, Spaltenzahl);
	Kachelmatrix = wegHorizontal(Kachelmatrix, Zeilenzahl / 2, 0, Spaltenzahl);
	Kachelmatrix = wegHorizontal(Kachelmatrix, Zeilenzahl - 1, 0, Spaltenzahl);
	Kachelmatrix = wegVertikal(Kachelmatrix, 0, Spaltenzahl - 1, Zeilenzahl / 2);
	Kachelmatrix = wegVertikal(Kachelmatrix, Zeilenzahl / 2, 0, Zeilenzahl / 2);

	return Kachelmatrix;
}
vector<Kachel> wegalsListe(vector<vector<Kachel>> Kachelmatrix) {
	vector<Kachel> liste(0);
	int Zeilenzahl = Kachelmatrix.size();
	int Spaltenzahl = Kachelmatrix.at(0).size();
	for (int i = 0; i < Spaltenzahl; i++)
	{
		liste.push_back(Kachelmatrix[0][i]);
	}
	int i = 0;
	for (i = 1; i < Zeilenzahl; i++)
	{
		if (Kachelmatrix[i][double(Spaltenzahl - 1)].get_istWeg() == false)
		{
			break;
		}
		else
		{
			liste.push_back(Kachelmatrix[i][double(Spaltenzahl - 1)]);
		}

	}
	for (int j = Spaltenzahl - 2; j >= 0; j--)
	{
		liste.push_back(Kachelmatrix[double(i - 1)][j]);
	}
	for (int j = i; j < Zeilenzahl; j++)
	{
		liste.push_back(Kachelmatrix[j][0]);
	}
	for (int j = 1; j < Spaltenzahl; j++)
	{
		liste.push_back(Kachelmatrix[double(Zeilenzahl - 1)][j]);
	}

	return liste;
}