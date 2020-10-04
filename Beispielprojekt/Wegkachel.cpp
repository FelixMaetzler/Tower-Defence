#include "stdafx.h"
#include"Wegkachel.h"
#include <iostream>
Gosu::Color rd = Gosu::Color::Color(255, 255, 0, 0);

vector<vector<Kachel>> wegHorizontal(vector<vector<Kachel>> Kachelmatrix, int x, int y, int länge) {

	for (int i = 0; i < länge; i++)
	{
		Kachel a = Kachelmatrix[x][y + i];
		a.set_istWeg(true);
		a.set_farbe(Gosu::Color::Color(255, 255, 255, 0));
		Kachelmatrix[x][y + i] = a;
	}
	return Kachelmatrix;
}
vector<vector<Kachel>> wegVertikal(vector<vector<Kachel>> Kachelmatrix, int x, int y, int länge) {

	for (int i = 0; i < länge; i++)
	{
		Kachel a = Kachelmatrix[x + i][y];
		a.set_istWeg(true);
		a.set_farbe(Gosu::Color::Color(255, 255, 255, 0));
		Kachelmatrix[x + i][y] = a;
	}
	return Kachelmatrix;
}
vector<vector<Kachel>> weg(vector<vector<Kachel>> Kachelmatrix, int abstand) {
	int Zeilenzahl = Kachelmatrix.size();
	int Spaltenzahl = Kachelmatrix.at(0).size();

	return Kachelmatrix;
}