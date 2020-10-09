#pragma once
#ifndef FIGUREN_H
#define FIGUREN_H

#include"stdafx.h"
#include "Gegner.h"
#include "Vektoren.h"
#include <ctime>
#include <chrono>
using namespace std;

//Diese Klasse ist eine abstrakte Klasse; D.h. es können keine Objekte dieser Klasse erzeugt werden
class Figuren {
private:
	//ist die Angriffsgeschwindigkeit eines Turms
	double attackspeed;
	//ist der Schaden eines Turms
	double damage;
	//ist der Preis eines Turms
	int price;
	//ist die Position eines Turms (linke obere Ecke)
	Vektoren position;
	//ist die Angriffsreichweite eines Turms
	double range;
	//Ist der Zeitstempel an dem der Turm zum letzten mal angegriffen hat. Wird auf jetzt Initialisiert
	std::chrono::steady_clock::time_point zeitstempel = std::chrono::steady_clock::now();
	//ist das Bild des Turms
	Gosu::Image image;
	//ist das Geräusch was der Turm macht
	Gosu::Sample audio;

public:
	//Konstruktoren

	//Standartkonstruktor
	Figuren(void);
	//Konstruktor für Attackspeed, Damage und Price
	Figuren(double, double, int);

	//Get/Set Methoden

	//Setzt die Angriffsgeschwindigkeit
	void set_attackspeed(const double);
	//gibt die Angriffsgeschwindigkeit zurück
	double get_attackspeed(void)const;
	//setzt den Schaden
	void set_damage(const double);
	//Gibt den Schaden zurück
	double get_damage(void)const;
	//setzt den Preis
	void set_price(const int);
	//gibt den Preis zurück
	int get_price(void)const;
	//setzt die Position
	void set_position(const Vektoren);
	//gibt die Position zurück
	Vektoren get_position(void)const;
	//setzt die Range
	void set_range(const double);
	//gibt die Range zurück
	double get_range(void)const;
	//setzt den Zeitstempel
	void set_zeitstempel(const std::chrono::steady_clock::time_point);
	//gibt den Zeitstempel zurück
	std::chrono::steady_clock::time_point get_zeitstempel(void)const;
	//setzt das Bild auf den Dateipfad, der als Argument angegeben wird
	void set_image(const string);
	//gibt ein Bild zurück
	Gosu::Image get_image(void)const;
	//Setzt den x Wert der Position
	void set_x(const int);
	//gibt den x Wert der Position zurück
	int get_x(void)const;
	//Setzt den y Wert der Position
	void set_y(const int);
	//gibt den y Wert der Position zurück
	int get_y(void)const;
	//Setzt die Audio auf den Dateipfad, der als Argument angegeben ist
	void set_audio(const string);
	//Gibt die Audio zurück
	Gosu::Sample get_audio(void)const;
	

	//andere Methoden

	//rein Virtuelle Methoden

	//!!!!!!!!!!!!!
	//Diese Methoden MÜSSEN in den Kinderklassen überschrieben werden, sonst fliegt uns alles um die Ohren bzw. ich denke es wird einfach nur ein Fehler rausgeboltzt

	//Zeichnet einen Turm. Diese MUSS in allen Kindklassen überschrieben werden !!!
	virtual void Zeichnen(void) = 0;
	//Checkt ob Gegner in Range sind und interagiert auch direkt mit denen. Diese MUSS in allen Kindklassen überschrieben werden !!!
	virtual void gegnerinrange(vector<Gegner*>* gegnerliste_ptr) = 0;
};

#endif // !FIGUREN_H

