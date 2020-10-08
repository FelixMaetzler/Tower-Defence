#pragma once
#ifndef GEGNER_H
#define GEGNER_H
#include "Vektoren.h"
#include "Grid.h"

class Gegner {
private:
	double leben;
	double geschwindigkeit;
	Vektoren position;//linke obere Ecke
	Vektoren richtung;
	int naechsterwegpunkt = 0;
	Gosu::Image image;

public:
	
	//Konstruktoren

	//Standartkonstruktor
	//Gegner(void);
	Gegner(void)
		
	{
		
	};
	//Konstruktor für Leben und Geschwindigkeit
	Gegner(int l, double g)
		//:image("tomato.png")
	{
		this->set_leben(l);
		this->set_Geschwindigkeit(g);	
	};

	//Destruktor
	~Gegner(void);

	//Get/Set Methoden:

	double get_leben(void)const;
	void set_leben(const double);
	double get_geschwindigkeit(void)const;
	void set_Geschwindigkeit(const double);
	int get_x(void)const;
	void set_x(const int);
	int get_y(void)const;
	void set_y(const int);
	Vektoren get_richtung(void)const;
	void set_richtung(Vektoren);
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
	//Zieht die Anzahl an Leben ab
	void lebenAbziehen(double);
	//Wenn der gegner das Ende des Paths erreicht hat
	void endeErreicht(void);

};


#endif // !GEGNER_H
