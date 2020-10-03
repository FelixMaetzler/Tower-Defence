#pragma once
#ifndef FIGUREN_H
#define FIGUREN_H

class Figuren {
private:
	double attackspeed;
	double damage;
	int price;
public:
	//Konstruktoren
	
	//Standartkonstruktor
	Figuren(void);
	//Konstruktor für Attackspeed, Damage und Price
	Figuren(double, double, int);

	//Methoden
	
	void set_attackspeed(const double);
	double get_attackspeed(void)const;
	void set_damage(const double);
	double get_damage(void)const;
	void set_price(const int);
	int get_price(void)const;
};

#endif // !FIGUREN_H

