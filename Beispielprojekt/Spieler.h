#pragma once
#ifndef SPIELER_H
#define SPIELER_H
#include"stdafx.h"
#include <Gosu/Gosu.hpp>
#include <Gosu/AutoLink.hpp>

using namespace std;

class Spieler {
private:
	//Geld des Spielers
	double geld = 0;
	//Leben des Spielers
	double leben = 0;
	//Lebensanzeige
	Gosu::Font lebensanzeige;
	//Geldanzeige
	Gosu::Font geldanzeige;
public:
	//Konstruktoren

	//Standartkonstruktor
	Spieler(void);
	
	
	//Get/Set Methoden
	
	//setzt Geld
	void set_geld(const double);
	//gibt Geld zurück
	double get_geld(void)const;
	//setzt Leben, wenn diese allerdings nicht größer Null sind, dann ist Game Over (Muss erst noch implementiert werden)
	void set_leben(const double);
	//gibt Leben zurück
	double get_leben(void)const;
	
	//setzt Lebensanzeige
	void set_lebensanzeige(const int);
	
	//gibt Lebensanzeige zurück
	Gosu::Font get_lebensanzeige(void)const;

	//setzt Geldanzeige
	void set_geldanzeige(const int);

	//gibt Geldanzeige zurück
	Gosu::Font get_geldanzeige(void)const;
	
	//andere Methoden

	void Zeichnen(void);

};

#endif // !SPIELER_H
