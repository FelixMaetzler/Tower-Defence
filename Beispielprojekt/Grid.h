#pragma once
#ifndef GRID_H
#define GRID_H
#include "Zeichnen.h"
#include <Gosu/Gosu.hpp>
#include <Gosu/AutoLink.hpp>
#include "Vektoren.h"
using namespace std;

class Kachel {
private:
	//Farbe der Kachel
	Gosu::Color farbe = Schwarz;
	//Kantenl�nge der quadratischen Kachel
	int kachelgr��e;
	//Position (obere linke Ecke)
	Vektoren position;
	//schaut, ob die kachel schon geflippt wurde
	bool Check_if_changed = false;
	//ist gesetzt, wenn die Kachel ein Weg ist
	bool istWeg = false;
	//Bild
	Gosu::Image image;
	//ist gesetzt, wenn auf dem Feld ein Spieler ist
	bool besetzt = false;
	
public:
	//Konstruktoren
	
	//Standartkonstruktor
	Kachel();
	//Konstruktor mit Position der oberen linken Ecke, die Kantenl�nge und die Farbe
	Kachel(Vektoren, int, Gosu::Color);
	//Konstruktor mit Position der oberen linken Ecke, die Kantenl�nge der Farbe und ob sie geflippt wurde
	Kachel(Vektoren, int, Gosu::Color, bool);
	
	//Get/Set Methoden
	
	//gibt den x Wert der Position zur�ck
	int get_x(void)const;
	//setzt den x Wert der Position
	void set_x(const int);
	//gibt den y Wert der Position zur�ck
	int get_y(void)const;
	//setzt den y Wert der Position
	void set_y(const int);
	//gibt die KAchelgr��e zur�ck
	int get_kachelgr��e(void)const;
	//setzt die Kachelgr��e
	void set_kachelgr��e(const int);
	//gibt die Farbe zur�ck
	Gosu::Color get_farbe(void)const;
	//setzt die Farbe
	void set_farbe(const Gosu::Color);
	//gibt zur�ck, ob ob die Kachelgeflippt wurde
	bool get_change(void)const;
	//setzt den Flip
	void set_change(const bool);
	//gibt zur�ck, ob die Kachel eine Wegkachel ist
	bool get_istWeg(void)const;
	//setzt, ob es eine Wegkachel ist oder nicht
	void set_istWeg(const bool);
	//gibt die Position zur�ck
	Vektoren get_position(void)const;
	//setzt die Position
	void set_position(const Vektoren);
	//gibt das Bild zur�ck
	Gosu::Image get_image(void)const;
	//setzt das Bild
	void set_image(const string);
	//gibt zur�ck, ob die Kachel besetzt ist
	bool get_besetzt(void)const;
	//setzt die Kachel auf besetzt
	void set_besetzt(const bool);

	
	//andere Methoden

	//Zeichnet eine Kachel
	void zeichnen(void);
	//gibt den Mittelpunkt der Kachel zur�ck
	Vektoren Mittelpunkt(void);
};
//Funktionen

//gibt die Kachelmatrix zur�ck. Nur die Kacheln, also ohne Weg. Fensterbreite, Fensterh�he, Kachelgr��e und Abstand. 
void grid(int fensterbreite, int fensterh�he, int kachelgr��e, int abstand);
//nimmt die Mauskoordinaten (x|y) und die Kachelmatrix und gibt die getroffene Kachel als Vektor zur�ck. Darf nur aufgerufen  werden, wenn man wei�, das eine Kachel getroffen wurde
Vektoren MausZuKachel(int, int);
//nimmt die Mauskoordinaten (x|y) und die Kachelmatrix und gibt zur�ck, ob �berhaupt eine Kachel getroffen wurde
bool hatKachelgetroffen(int, int);
//Zeichnet die Kachelmatrix
void ArrayZeichnen(vector<vector<Kachel>>*);
//


#endif // !GRID_H


