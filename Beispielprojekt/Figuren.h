#pragma once
#ifndef FIGUREN_H
#define FIGUREN_H

#include"stdafx.h"
#include "Gegner.h"
#include "Vektoren.h"
using namespace std;


class Figuren {
private:
	double attackspeed;
	double damage;
	int price;
	Vektoren position;
	double range;
public:
	//Konstruktoren
	
	//Standartkonstruktor
	Figuren(void);
	//Konstruktor für Attackspeed, Damage und Price
	Figuren(double, double, int);

	//Get/Set Methoden
	
	void set_attackspeed(const double);
	double get_attackspeed(void)const;
	void set_damage(const double);
	double get_damage(void)const;
	void set_price(const int);
	int get_price(void)const;
	void set_position(const Vektoren);
	Vektoren get_position(void)const;
	void set_range(const double);
	double get_range(void)const;

	//andere Methoden

	virtual void gegnerinrange(vector<Gegner>&) {};
};

#endif // !FIGUREN_H

