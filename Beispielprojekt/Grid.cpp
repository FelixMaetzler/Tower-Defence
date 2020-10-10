#include "stdafx.h"
#include "Grid.h"
#include "Zeichnen.h"
#include "list"
#include "Vektoren.h"
#include <Gosu/Gosu.hpp>
#include <Gosu/AutoLink.hpp>
#include "stdafx.h"

#include <Gosu/Gosu.hpp>
#include <Gosu/AutoLink.hpp>

#include <vector>
#include <string>
#include <iostream>

//#include "Vektor2d.h"
#include "Vektoren.h"
#include "Grid.h"
#include "Zeichnen.h"
#include "Spieler.h"
#include "Wegkachel.h"
#include "ErsterGegner.h"
using namespace std;

//Konstruktoren

Kachel::Kachel() {};
Kachel::Kachel(Vektoren p, int kachelgr��e, Gosu::Color farbe) {
	this->set_position(p);
	this->set_kachelgr��e(kachelgr��e);
	this->set_farbe(farbe);
}

Kachel::Kachel(Vektoren p, int kachelgr��e, Gosu::Color farbe, bool Check_if_Changed) {
	this->set_position(p);
	this->set_kachelgr��e(kachelgr��e);
	this->set_farbe(farbe);
	this->set_change(Check_if_Changed);
}

//Get/Set Methoden



void Kachel::set_farbe(Gosu::Color f) {
	this->farbe = f;
}
Gosu::Color Kachel::get_farbe(void) const {
	return this->farbe;
}
int Kachel::get_x(void) const {
	return this->get_position().get_x();
}
int Kachel::get_y(void) const {
	return this->get_position().get_y();
}
int Kachel::get_kachelgr��e(void) const {
	return this->kachelgr��e;
}
void Kachel::set_kachelgr��e(const int a) {
	this->kachelgr��e = a;
}
void Kachel::set_x(const int a) {
	this->position.set_x(a);
}
void Kachel::set_y(const int a) {
	this->position.set_x(a);
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

Vektoren Kachel::get_position(void) const {
	return this->position;
}
void Kachel::set_position(const Vektoren a) {
	this->position = a;
}


//andere Methoden

Vektoren Kachel::Mittelpunkt(void) {
	Vektoren a;
	a.set_x(double(this->get_x() + this->get_kachelgr��e() / 2));
	a.set_y(double(this->get_y() + this->get_kachelgr��e() / 2));
	return a;
}

void Kachel::zeichnen(void) {
	rechteck_2Ecken(this->get_x(), this->get_y(),
		double(this->get_x() + this->get_kachelgr��e()), double(this->get_y() + this->get_kachelgr��e()),
		this->get_farbe(), 5);
}

//Funktionen


vector<vector<Kachel>> grid(int fensterbreite, int fensterh�he, int kachelgr��e, int abstand) {
	//berechnet, wieviel ganze Kacheln in eine Zeile passen
	int AnzahlKachelnZeile = fensterbreite / (kachelgr��e + abstand);
	//berechnet, wieviel ganze Kacheln in eine Spalte passen
	int AnzahlKachelnSpalte = fensterh�he / (kachelgr��e + abstand);

	//Hier wird gecheckt, ob vielleicht noch eine  Kachel mehr geht, wenn man keinen Abstand zum Rand haben muss
	if ((fensterh�he - ((AnzahlKachelnSpalte + 1) * kachelgr��e + AnzahlKachelnSpalte * abstand)) >= 0)
	{
		AnzahlKachelnSpalte++;
	}
	//Hier wird gecheckt, ob vielleicht noch eine  Kachel mehr geht, wenn man keinen Abstand zum Rand haben muss
	if ((fensterbreite - ((AnzahlKachelnZeile + 1) * kachelgr��e + AnzahlKachelnZeile * abstand)) >= 0)
	{
		AnzahlKachelnZeile++;
	}
	//DAs Speichert ide einzelnen Kacheln
	vector<vector<Kachel>> Kachelarray(AnzahlKachelnSpalte, vector<Kachel>(AnzahlKachelnZeile));
	//iteriert �ber alle Zeilen
	for (int i = 0; i < AnzahlKachelnSpalte; i++)
	{
		//iteriert �ber alle Saplten
		for (int j = 0; j < AnzahlKachelnZeile; j++)
		{
			int x1, x2, y1, y2;
			//x Wert der linken obere Ecke
			x1 = j * (kachelgr��e + abstand);
			//y Wert der linken obere Ecke
			y1 = i * (kachelgr��e + abstand);
			//x Wert der rechten unteren Ecke
			x2 = x1 + kachelgr��e;
			//y Wert der rechten unten Ecke
			y2 = y1 + kachelgr��e;
			//rechteck_2Ecken(x1, y1, x2, y2, Gosu::Color::BLACK, 5);

			//wandelt den linken oberen Punkt in einen Vektor um
			Vektoren p(x1, y1);
			//erstellt eine Kachel mit den ganzen Werten
			Kachel a(p, kachelgr��e, Gosu::Color::Color(255, 0, 0, 0), false);
			//Boltzt diese Kachel ins Array rein
			Kachelarray[i][j] = a;
			//Kachelarray[j][i].set_farbe(Gosu::Color::Color(255, 0, 0, 0));

			//Kachelarray[j][i] = Kachel(x1, y1, kachelgr��e, Schwarz);

		}
	}
	return Kachelarray;
};


void ArrayZeichnen(vector<vector<Kachel>> Kachelarray) {
	for each (auto x in Kachelarray)
	{
		for each (Kachel y in x)
		{
			y.zeichnen();
		}
	}
}



Vektoren MausZuKachel(int x, int y, vector<vector<Kachel>> Kachelarray) {
	//diese Funktion darf nur uffgerufe werden, wenn man wei� das eine Kachel getroffen wurde. Ansonsten wird (0|0) zur�ckgeboltzt
	//Merker f�r die Zeile
	int Koordinate_Zeile;
	//Merker f�r die Spalte
	int Koordinate_Spalte;
	//hier wird �ber alle Zeilen iteriert
	for (Koordinate_Zeile = 0; Koordinate_Zeile < Kachelarray.size(); Koordinate_Zeile++)
	{
		//Zwischenspeicher f�r eine Kachel. Da alle Kacheln in einer Reihe die gleichen y Koordinanten haben, wird der aus der 1. Spalte genommen 
		Kachel a = Kachelarray[Koordinate_Zeile][0];
		//wenn der y wert der Maus zwischen den beiden y Werten der Kachel liegt, dann wurde die richtige Zeile gefunden 
		if (a.get_y() <= y && y <= (a.get_y() + a.get_kachelgr��e()))
		{
			//und die Schleife wird beendet
			break;
		}
	}
	for (Koordinate_Spalte = 0; Koordinate_Spalte < Kachelarray.at(0).size(); Koordinate_Spalte++)
	{
		//Zwischenspeicher f�r eine Kachel. Da alle Kacheln in einer Zeile die gleichen x Koordinanten haben, wird der aus der 1. Zeile genommen
		Kachel a = Kachelarray[0][Koordinate_Spalte];
		if (a.get_x() <= x && x <= (a.get_x() + a.get_kachelgr��e()))
		{
			//wenn der x wert der Maus zwischen den beiden x Werten der Kachel liegt, dann wurde die richtige Spalte gefunden 
			break;
		}
	}
	//Das ergibt dann die Position der getroffenen Kachel
	return Vektoren(Koordinate_Zeile, Koordinate_Spalte);
}

bool hatKachelgetroffen(int x, int y, vector<vector<Kachel>> Kachelarray) {

	//[i][0] iterieren wir �ber die erste Spalte -> Hier muss die H�he gepr�ft werden
	//if Mauspos-H�he ein Wert der einer Kachel zugewiesen werden kann: 
	//[0][j] iterieren wir �ber die erste Zeile -> Hier muss die Breite gepr�ft werden

	bool g = false;
	bool h = false;
	for (int i = 0; i < Kachelarray.size(); i++)
	{
		//Zwischenspeicher f�r eine Kachel. Da alle Kacheln in einer Reihe die gleichen y Koordinanten haben, wird der aus der 1. Spalte genommen 
		Kachel a = Kachelarray[i][0];
		
		if (a.get_y() <= y && y <= (a.get_y() + a.get_kachelgr��e()))
		{
			//wenn der y wert der Maus zwischen den beiden y Werten der Kachel liegt, dann wurde eine Zeile gefunden
			//und g wird auf true gesetzt und die Schleife wird verlassen
			g = true;
			break;
		}
	}
	for (int j = 0; j < Kachelarray.at(0).size(); j++)
	{
		//Zwischenspeicher f�r eine Kachel. Da alle Kacheln in einer Zeile die gleichen x Koordinanten haben, wird der aus der 1. Zeile genommen
		Kachel a = Kachelarray[0][j];
		if (a.get_x() <= x && x <= (a.get_x() + a.get_kachelgr��e()))
		{
			//wenn der x wert der Maus zwischen den beiden x Werten der Kachel liegt, dann wurde eine Spalte gefunden
			//und h wird auf true gesetzt und die Schleife wird verlassen
			h = true;
			break;
		}
	}
	if (g && h)
	{
		//Wenn sowohl eine zul�ssige Spalte als auch Zeile gefunden wurde, dann wurde auch eine zul�ssige Kachel gefunden
		//Dan gibt "hatKachelgetroffen" ein true zur�ck
		return true;
	}
	else
	{
		//Wenn das nicht der Fall ist, wird ein false zur�ckgegeben
		return false;
	}


}
/*
vector<vector<Kachel>> Maustaste_Losgelassen(bool Matrix_Change_Sauber, vector<vector<Kachel>> arrayKachel)
{
	
	return vector<vector<Kachel>>();
}

vector<vector<Kachel>> Maustaste_Gedr�ckt(bool Matrix_Change_Sauber, vector<vector<Kachel>> arrayKachel)
{
	if (input().down(Gosu::Button::Button(Gosu::ButtonName::MS_LEFT)))
	{
		Matrix_Change_Sauber = false;
		if (hatKachelgetroffen(x_maus, y_maus, arrayKachel))//Wenn man eine Kachel geklickt hat
		{
			//Dann soll eine Funktion ausgef�hrt werden, die die Kachelposition als Vektor zur�ckgibt
			Vektoren a = MausZuKachel(x_maus, y_maus, arrayKachel);

			//a.print();
			Kachel z = arrayKachel[a.get_x()][a.get_y()];

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

		}
	}
	return vector<vector<Kachel>>();
}
*/