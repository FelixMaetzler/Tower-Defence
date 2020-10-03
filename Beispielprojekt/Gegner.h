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
	//Konstruktor für Leben und Geschwindigkeit
	Gegner(int, double);

	//Methoden:

	int get_leben(void)const;
	void set_leben(const int);
	double get_geschwindigkeit(void)const;
	void set_Geschwindigkeit(const double);
};


#endif // !GEGNER_H
