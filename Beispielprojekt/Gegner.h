#pragma once
#ifndef GEGNER_H
#define GEGNER_H
#include "Vektoren.h"
#include "Grid.h"

class Gegner {
private:
	int leben;
	double geschwindigkeit;
	Vektoren position;//linke obere Ecke
	Vektoren richtung;
	int naechsterwegpunkt = 0;

public:
	//Konstruktoren
	
	//Standartkonstruktor
	Gegner(void);
	//Konstruktor für Leben und Geschwindigkeit
	Gegner(int, double);

	//Get/Set Methoden:

	int get_leben(void)const;
	void set_leben(const int);
	double get_geschwindigkeit(void)const;
	void set_Geschwindigkeit(const double);
	int get_x(void)const;
	void set_x(const int);
	int get_y(void)const;
	void set_y(const int);
	Vektoren get_richtung(void)const;
	void set_richtung( Vektoren);
	Vektoren get_position(void)const;
	void set_position(const Vektoren);
	int get_naechsterwegpunkt(void)const;
	void set_naechsterwegpunkt(const int);

	//andere Methoden

	//setzt die Richtung des Gegners zu dem als Argument angegebenen Punkrt
	void RichtungZuPunkt(const Vektoren);

	void Zeichnen(void)const;
	//Diese Funktion sorgt dafür, dass der Gegner den richtigen Weg abfährt. Dafür wird die Richtung gesetzt
	void wegpunkt(vector<Kachel>);

};


#endif // !GEGNER_H
