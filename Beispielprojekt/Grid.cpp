#include "stdafx.h"
#include "Grid.h"
#include "Zeichnen.h"
#include "list"
using namespace std;

Kachel::Kachel() {};
Kachel::Kachel(int x, int y, int kachelgröße, Gosu::Color farbe) {
	this->x = x;
	this->y = y;
	this->kachelgröße = kachelgröße;
	this->farbe = farbe;
}

Kachel::Kachel(int x, int y, int kachelgröße, Gosu::Color farbe, bool Check_if_Changed) {
	this->x = x;
	this->y = y;
	this->kachelgröße = kachelgröße;
	this->farbe = farbe;
	this->Check_if_changed = false;
}



vector<vector<Kachel>> gridZeichnen(int fensterbreite, int fensterhöhe, int kachelgröße, int abstand) {
	int AnzahlKachelnZeile = fensterbreite / (kachelgröße + abstand);
	int AnzahlKachelnSpalte = fensterhöhe / (kachelgröße + abstand);

	if ((fensterhöhe - ((AnzahlKachelnSpalte + 1) * kachelgröße + AnzahlKachelnSpalte * abstand)) >= 0)
	{
		AnzahlKachelnSpalte++;
	}
	if ((fensterbreite - ((AnzahlKachelnZeile + 1) * kachelgröße + AnzahlKachelnZeile * abstand)) >= 0)
	{
		AnzahlKachelnZeile++;
	}
	vector<vector<Kachel>> Kachelarray(AnzahlKachelnSpalte, vector<Kachel>(AnzahlKachelnZeile));
	for (int i = 0; i < AnzahlKachelnSpalte; i++)
	{
		for (int j = 0; j < AnzahlKachelnZeile; j++)
		{
			int x1, x2, y1, y2;
			x1 = j * (kachelgröße + abstand);
			y1 = i * (kachelgröße + abstand);
			x2 = x1 + kachelgröße;
			y2 = y1 + kachelgröße;
			//rechteck_2Ecken(x1, y1, x2, y2, Gosu::Color::BLACK, 5);

			Kachel a(x1, y1, kachelgröße, Gosu::Color::Color(255, 0, 0, 0),false);
			Kachelarray[i][j] = a;
			//Kachelarray[j][i].set_farbe(Gosu::Color::Color(255, 0, 0, 0));

			//Kachelarray[j][i] = Kachel(x1, y1, kachelgröße, Schwarz);
			
		}
	}
	return Kachelarray;
};
void Kachel::zeichnen(void) {
	rechteck_2Ecken(this->x, this->y, this->x + this->kachelgröße, this->y + this->kachelgröße, this->farbe, 5);
}
void Kachel::set_farbe(Gosu::Color f) {
	this->farbe = f;
}

void ArrayZeichnen(vector<vector<Kachel>> Kachelarray) {
	for each (auto x in Kachelarray)
	{
		for each (Kachel y in x)
		{
			y.zeichnen();
		}
	}
}
Vektoren MausZuKachel(int x, int y, vector<vector<Kachel>> Kachelarray)  {
	int Koordinate_Zeile;
	int Koordinate_Spalte;
	for (Koordinate_Zeile = 0; Koordinate_Zeile < Kachelarray.size(); Koordinate_Zeile++)
	{
		Kachel a = Kachelarray[Koordinate_Zeile][0];
		if (a.get_y() <= y && y <= (a.get_y() + a.get_kachelgröße())) {
			break;
		}
	}
	for (Koordinate_Spalte = 0; Koordinate_Spalte < Kachelarray.at(0).size(); Koordinate_Spalte++)
	{
		Kachel a = Kachelarray[0][Koordinate_Spalte];
		if (a.get_x() <= x && x <= (a.get_x() + a.get_kachelgröße())) {
			break;
		}
	}
	return Vektoren(Koordinate_Zeile, Koordinate_Spalte);
}
bool hatKachelgetroffen(int x, int y, vector<vector<Kachel>> Kachelarray) {

	//[i][0] iterieren wir über die erste Spalte -> Hier muss die Höhe geprüft werden
	//if Mauspos-Höhe ein Wert der einer Kachel zugewiesen werden kann: 
	//[0][j] iterieren wir über die erste Zeile -> Hier muss die Breite geprüft werden
	
	bool g = false;
	bool h = false;
	for (int i = 0; i < Kachelarray.size(); i++)
	{
		Kachel a = Kachelarray[i][0];
		if (a.get_y() <= y && y <= (a.get_y() + a.get_kachelgröße()) ){
			g = true;
			break;
		}
	}
	for (int j = 0; j < Kachelarray.at(0).size(); j++)
	{
		Kachel a = Kachelarray[0][j];
		if (a.get_x() <= x && x <= (a.get_x() + a.get_kachelgröße())) {
			h = true;
			break;
		}
	}
	if (g && h)
	{
		return true;
	}
	else
	{
		return false;
	}
	
		
}
int Kachel::get_x(void) const {
	return this->x;
}
int Kachel::get_y(void) const {
	return this->y;
}
int Kachel::get_kachelgröße(void) const {
	return this->kachelgröße;
}
Gosu::Color Kachel::get_farbe(void) const {
	return this->farbe;
}
void Kachel::set_x(const int a) {
	this->x = a;
}
void Kachel::set_y(const int a) {
	this->y = a;
}
void Kachel::set_kachelgröße(const int a) {
	this->kachelgröße = a;
}
bool Kachel::get_change(void) const
{
	return this->Check_if_changed;
}
void Kachel::set_change(const bool changer)
{
	this->Check_if_changed = changer;
}
bool Kachel::get_istWeg(void)const {
	return this->istWeg;
}
void Kachel::set_istWeg(const bool b) {
	this->istWeg = b;
}
Vektoren Kachel::Mittelpunkt(void)  {
	Vektoren a;
	a.set_x(this->x + this->kachelgröße / 2);
	a.set_y(this->y + this->kachelgröße / 2);
	return a;
}
