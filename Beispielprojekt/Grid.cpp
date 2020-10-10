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
Kachel::Kachel(Vektoren p, int kachelgröße, Gosu::Color farbe) {
	this->set_position(p);
	this->set_kachelgröße(kachelgröße);
	this->set_farbe(farbe);
}

Kachel::Kachel(Vektoren p, int kachelgröße, Gosu::Color farbe, bool Check_if_Changed) {
	this->set_position(p);
	this->set_kachelgröße(kachelgröße);
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
int Kachel::get_kachelgröße(void) const {
	return this->kachelgröße;
}
void Kachel::set_kachelgröße(const int a) {
	this->kachelgröße = a;
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
	a.set_x(double(this->get_x() + this->get_kachelgröße() / 2));
	a.set_y(double(this->get_y() + this->get_kachelgröße() / 2));
	return a;
}

void Kachel::zeichnen(void) {
	rechteck_2Ecken(this->get_x(), this->get_y(),
		double(this->get_x() + this->get_kachelgröße()), double(this->get_y() + this->get_kachelgröße()),
		this->get_farbe(), 5);
}

//Funktionen


vector<vector<Kachel>> grid(int fensterbreite, int fensterhöhe, int kachelgröße, int abstand) {
	//berechnet, wieviel ganze Kacheln in eine Zeile passen
	int AnzahlKachelnZeile = fensterbreite / (kachelgröße + abstand);
	//berechnet, wieviel ganze Kacheln in eine Spalte passen
	int AnzahlKachelnSpalte = fensterhöhe / (kachelgröße + abstand);

	//Hier wird gecheckt, ob vielleicht noch eine  Kachel mehr geht, wenn man keinen Abstand zum Rand haben muss
	if ((fensterhöhe - ((AnzahlKachelnSpalte + 1) * kachelgröße + AnzahlKachelnSpalte * abstand)) >= 0)
	{
		AnzahlKachelnSpalte++;
	}
	//Hier wird gecheckt, ob vielleicht noch eine  Kachel mehr geht, wenn man keinen Abstand zum Rand haben muss
	if ((fensterbreite - ((AnzahlKachelnZeile + 1) * kachelgröße + AnzahlKachelnZeile * abstand)) >= 0)
	{
		AnzahlKachelnZeile++;
	}
	//DAs Speichert ide einzelnen Kacheln
	vector<vector<Kachel>> Kachelarray(AnzahlKachelnSpalte, vector<Kachel>(AnzahlKachelnZeile));
	//iteriert über alle Zeilen
	for (int i = 0; i < AnzahlKachelnSpalte; i++)
	{
		//iteriert über alle Saplten
		for (int j = 0; j < AnzahlKachelnZeile; j++)
		{
			int x1, x2, y1, y2;
			//x Wert der linken obere Ecke
			x1 = j * (kachelgröße + abstand);
			//y Wert der linken obere Ecke
			y1 = i * (kachelgröße + abstand);
			//x Wert der rechten unteren Ecke
			x2 = x1 + kachelgröße;
			//y Wert der rechten unten Ecke
			y2 = y1 + kachelgröße;
			//rechteck_2Ecken(x1, y1, x2, y2, Gosu::Color::BLACK, 5);

			//wandelt den linken oberen Punkt in einen Vektor um
			Vektoren p(x1, y1);
			//erstellt eine Kachel mit den ganzen Werten
			Kachel a(p, kachelgröße, Gosu::Color::Color(255, 0, 0, 0), false);
			//Boltzt diese Kachel ins Array rein
			Kachelarray[i][j] = a;
			//Kachelarray[j][i].set_farbe(Gosu::Color::Color(255, 0, 0, 0));

			//Kachelarray[j][i] = Kachel(x1, y1, kachelgröße, Schwarz);

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
	//diese Funktion darf nur uffgerufe werden, wenn man weiß das eine Kachel getroffen wurde. Ansonsten wird (0|0) zurückgeboltzt
	//Merker für die Zeile
	int Koordinate_Zeile;
	//Merker für die Spalte
	int Koordinate_Spalte;
	//hier wird über alle Zeilen iteriert
	for (Koordinate_Zeile = 0; Koordinate_Zeile < Kachelarray.size(); Koordinate_Zeile++)
	{
		//Zwischenspeicher für eine Kachel. Da alle Kacheln in einer Reihe die gleichen y Koordinanten haben, wird der aus der 1. Spalte genommen 
		Kachel a = Kachelarray[Koordinate_Zeile][0];
		//wenn der y wert der Maus zwischen den beiden y Werten der Kachel liegt, dann wurde die richtige Zeile gefunden 
		if (a.get_y() <= y && y <= (a.get_y() + a.get_kachelgröße()))
		{
			//und die Schleife wird beendet
			break;
		}
	}
	for (Koordinate_Spalte = 0; Koordinate_Spalte < Kachelarray.at(0).size(); Koordinate_Spalte++)
	{
		//Zwischenspeicher für eine Kachel. Da alle Kacheln in einer Zeile die gleichen x Koordinanten haben, wird der aus der 1. Zeile genommen
		Kachel a = Kachelarray[0][Koordinate_Spalte];
		if (a.get_x() <= x && x <= (a.get_x() + a.get_kachelgröße()))
		{
			//wenn der x wert der Maus zwischen den beiden x Werten der Kachel liegt, dann wurde die richtige Spalte gefunden 
			break;
		}
	}
	//Das ergibt dann die Position der getroffenen Kachel
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
		//Zwischenspeicher für eine Kachel. Da alle Kacheln in einer Reihe die gleichen y Koordinanten haben, wird der aus der 1. Spalte genommen 
		Kachel a = Kachelarray[i][0];
		
		if (a.get_y() <= y && y <= (a.get_y() + a.get_kachelgröße()))
		{
			//wenn der y wert der Maus zwischen den beiden y Werten der Kachel liegt, dann wurde eine Zeile gefunden
			//und g wird auf true gesetzt und die Schleife wird verlassen
			g = true;
			break;
		}
	}
	for (int j = 0; j < Kachelarray.at(0).size(); j++)
	{
		//Zwischenspeicher für eine Kachel. Da alle Kacheln in einer Zeile die gleichen x Koordinanten haben, wird der aus der 1. Zeile genommen
		Kachel a = Kachelarray[0][j];
		if (a.get_x() <= x && x <= (a.get_x() + a.get_kachelgröße()))
		{
			//wenn der x wert der Maus zwischen den beiden x Werten der Kachel liegt, dann wurde eine Spalte gefunden
			//und h wird auf true gesetzt und die Schleife wird verlassen
			h = true;
			break;
		}
	}
	if (g && h)
	{
		//Wenn sowohl eine zulässige Spalte als auch Zeile gefunden wurde, dann wurde auch eine zulässige Kachel gefunden
		//Dan gibt "hatKachelgetroffen" ein true zurück
		return true;
	}
	else
	{
		//Wenn das nicht der Fall ist, wird ein false zurückgegeben
		return false;
	}


}
/*
vector<vector<Kachel>> Maustaste_Losgelassen(bool Matrix_Change_Sauber, vector<vector<Kachel>> arrayKachel)
{
	
	return vector<vector<Kachel>>();
}

vector<vector<Kachel>> Maustaste_Gedrückt(bool Matrix_Change_Sauber, vector<vector<Kachel>> arrayKachel)
{
	if (input().down(Gosu::Button::Button(Gosu::ButtonName::MS_LEFT)))
	{
		Matrix_Change_Sauber = false;
		if (hatKachelgetroffen(x_maus, y_maus, arrayKachel))//Wenn man eine Kachel geklickt hat
		{
			//Dann soll eine Funktion ausgeführt werden, die die Kachelposition als Vektor zurückgibt
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