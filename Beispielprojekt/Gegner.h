#pragma once
#ifndef GEGNER_H
#define GEGNER_H
#include "Vektoren.h"
#include "Grid.h"

//Das ist eine abstrakte Klasse. D.h. von dieser Klasse k�nnen keine Objekte erstellt werden

class Gegner {
private:
	//ist das Leben
	double leben;
	//ist die Geschwindigkeit
	double geschwindigkeit;
	//ist die Position (linke obere Ecke)
	Vektoren position;
	//ist der Geldwert des Gegners
	double geld;
	//ist die Richtung, in der sich der Gegner bewegt. Die L�nge entspicht der Geschwindigkeit
	Vektoren richtung;
	//ist eine Art Counter die den n�chsten Wegpunkt angibt. Sort f�r Ordentlich Performance Ersparnis
	int naechsterwegpunkt = 0;
	//ist das Bild des Gegners
	Gosu::Image image;
	

public:


	//Konstruktoren

	//Standartkonstruktor
	//Gegner(void);
	Gegner(void);

	//Konstruktor f�r Leben und Geschwindigkeit
	Gegner(int l, double g);
	
	

	//Destruktor
	~Gegner(void);

	//Get/Set Methoden:

	//gibt das Leben zur�ck
	double get_leben(void)const;
	//setzt das Leben
	void set_leben(const double);
	//gibt die Geschwindigkeit zur�ck
	double get_geschwindigkeit(void)const;
	//setzt dei Geschwindigkeit
	void set_geschwindigkeit(const double);
	//gibt den x Wert der Position zur�ck
	int get_x(void)const;
	//setzt den x Wert der Position
	void set_x(const int);
	//gibt den y Wert der Position zur�ck
	int get_y(void)const;
	//setzt den y Wert der Position
	void set_y(const int);
	//gibt die Richtung zurpck
	Vektoren get_richtung(void)const;
	//setzt die Richtung, als zweites Argument kann noch ein Skalierungsfaktor angegeben werden. Dieser wird f�r den Slow Turm ben�tigt
	void set_richtung(Vektoren, double = 1);
	//gibt die Position zur�ck
	Vektoren get_position(void)const;
	//setzt die Position
	void set_position(const Vektoren);
	//gibt den n�chsten Wegpunkt zur�ck
	int get_naechsterwegpunkt(void)const;
	//setzt den n�chsten Wegpunkt
	void set_naechsterwegpunkt(const int);
	//gibt das Bild zur�ck
	Gosu::Image get_image(void)const;
	//setzt das Bild
	void set_image(const string);
	//gibt den Geldwert zur�ck
	double get_geld(void)const;
	//setzt den Geldwert
	void set_geld(const double);


	//andere Methoden

	//setzt die Richtung des Gegners zu dem als Argument angegebenen Punkt
	void RichtungZuPunkt(const Vektoren);

	void Zeichnen(void)const;
	//Diese Funktion sorgt daf�r, dass der Gegner den richtigen Weg abf�hrt. Daf�r wird die Richtung gesetzt
	void wegpunkt(vector<Kachel>);
	//Zieht die Anzahl an Leben ab
	void lebenAbziehen(double);
	//Wenn der gegner das Ende des Paths erreicht hat
	void endeErreicht(void);

	//Virtuelle Methoden

	//!!!!!!!!!!!!!
	//Diese Methoden M�SSEN in den Kinderklassen �berschrieben werden, sonst fliegt uns alles um die Ohren bzw. ich denke es wird einfach nur ein Fehler rausgeboltzt

	//Spawnt den n�chst schw�cheren Gegner.ALs Argument bekommt er die Position und den n�chsten Wegpunkt vom gestorbenen Gegner. Diese MUSS in allen Kindklassen �berschrieben werden !!!
	virtual Gegner* schwaecherenGegnerSpawnen(Vektoren, int) = 0;
	
};


#endif // !GEGNER_H
