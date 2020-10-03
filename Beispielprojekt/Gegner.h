#pragma once
#ifndef GEGNER_H
#define GEGNER_H

class Gegner {
private:
	int leben;
	double geschwindigkeit;

public:
	//Konstruktoren
	
	//Standartkonstruktor
	Gegner(void);
	//Leben, Geschwindigkeit
	Gegner(int, double);

	//Methoden:

	int get_leben(void);
	void set_leben(int);
	double get_geschwindigkeit(void);
	void set_Geschwindigkeit(double);
};


#endif // !GEGNER_H
