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
	//Attackspeed, Damage, Price
	Figuren(double, double, int);

	//Methoden
	
	void set_attackspeed(double);
	double get_attackspeed(void);
	void set_damage(double);
	double get_damage(void);
	void set_price(int);
	int get_price(void);
};

#endif // !FIGUREN_H

