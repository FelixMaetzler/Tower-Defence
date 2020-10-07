#pragma once
#ifndef SPIELER_H
#define SPIELER_H

class Spieler {
private:
	double geld = 0;
	double leben = 0;
public:
	void set_geld(const double);
	double get_geld(void)const;
	void set_leben(const double);
	double get_leben(void)const;
};

#endif // !SPIELER_H
