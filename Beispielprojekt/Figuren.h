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
	Gosu::Image image;
	Gosu::Sample audio;

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
	Gosu::Image get_image(void)const;
	void set_image(const string);
	void set_x(const int);
	int get_x(void)const;
	void set_y(const int);
	int get_y(void)const;
	Gosu::Sample get_audio(void)const;
	void set_audio(const string);

	//andere Methoden
	virtual void Zeichnen(void) { return; };
	virtual void gegnerinrange(vector<Gegner*>* gegnerliste_ptr) = 0;
};

#endif // !FIGUREN_H

