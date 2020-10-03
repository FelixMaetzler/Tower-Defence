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
	vector<vector<Kachel>> Kachelarray(AnzahlKachelnZeile, vector<Kachel>(AnzahlKachelnSpalte));
	for (int i = 0; i < AnzahlKachelnSpalte; i++)
	{
		for (int j = 0; j < AnzahlKachelnZeile; j++)
		{
			int x1, x2, y1, y2;
			x1 = j * (kachelgröße + abstand);
			y1 = i * (kachelgröße + abstand);
			x2 = x1 + kachelgröße;
			y2 = y1 + kachelgröße;
			rechteck_2Ecken(x1, y1, x2, y2, Gosu::Color::BLACK, 5);


			Kachelarray[j][i] = Kachel(x1, y1, kachelgröße, Schwarz);
			
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
