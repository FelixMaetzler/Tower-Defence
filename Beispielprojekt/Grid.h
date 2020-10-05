#pragma once
#ifndef GRID_H
#define GRID_H
#include "Zeichnen.h"
#include <Gosu/Gosu.hpp>
#include <Gosu/AutoLink.hpp>
#include "Vektoren.h"
using namespace std;
//Test
class Kachel {
private:
	Gosu::Color farbe = Schwarz;
	int kachelgröße;
	Vektoren position;
	bool Check_if_changed;
	bool istWeg = false;
	
public:
	//Konstruktoren
	
	//Standartkonstruktor
	Kachel();
	//Konstruktor mit Position der oberen linken Ecke, die Kantenlänge und die Farbe
	Kachel(Vektoren, int, Gosu::Color);
	Kachel(Vektoren, int, Gosu::Color, bool);
	
	//Methoden
	
	
	int get_x(void)const;
	void set_x(const int);
	int get_y(void)const;
	void set_y(const int);
	int get_kachelgröße(void)const;
	void set_kachelgröße(const int);
	Gosu::Color get_farbe(void)const;
	void set_farbe(const Gosu::Color);
	bool get_change(void)const;
	void set_change(const bool);
	bool get_istWeg(void)const;
	void set_istWeg(const bool);
	Vektoren Mittelpunkt(void);
	Vektoren get_position(void)const;
	void set_position(const Vektoren);
	
	
	//Zeichnet eine Kachel
	void zeichnen(void);
};
//Funktionen

//gibt die Kachelmatrix zurück. Nur die Kacheln, also ohne Weg. Fensterbreite, Fensterhöhe, Kachelgröße und Abstand. 
vector<vector<Kachel>> grid(int fensterbreite, int fensterhöhe, int kachelgröße, int abstand);
//nimmt die Mauskoordinaten (x|y) und die Kachelmatrix und gibt die getroffene Kachel als Vektor zurück
Vektoren MausZuKachel(int, int, vector<vector<Kachel>>);
//nimmt die Mauskoordinaten (x|y) und die Kachelmatrix und gibt zurück, ob überhaupt eine Kachel getroffen wurde
bool hatKachelgetroffen(int, int, vector<vector<Kachel>>);
//Zeichnet die Kachelmatrix
void ArrayZeichnen(vector<vector<Kachel>>);
#endif // !GRID_H


