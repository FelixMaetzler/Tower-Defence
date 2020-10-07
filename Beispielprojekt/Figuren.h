#pragma once
#ifndef FIGUREN_H
#define FIGUREN_H

#include"stdafx.h"
#include "Gegner.h"
#include "Vektoren.h"
#include <ctime>
#include <chrono>
using namespace std;


class Figuren {
private:
	double attackspeed;
	double damage;
	int price;
	Vektoren position;
	double range;
	std::chrono::steady_clock::time_point zeitstempel = std::chrono::steady_clock::now();
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
	void set_zeitstempel(const std::chrono::steady_clock::time_point);
	std::chrono::steady_clock::time_point get_zeitstempel(void)const;
	//andere Methoden

	virtual void gegnerinrange(vector<Gegner*>* gegnerliste_ptr) { return; };
};

#endif // !FIGUREN_H

