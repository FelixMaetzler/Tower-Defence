#pragma once
#ifndef SPIELER_H
#define SPIELER_H

class Spieler {
private:
	int geld = 0;
	int leben = 0;
public:
	void set_geld(const int);
	int get_geld(void)const;
	void set_leben(const int);
	int get_leben(void)const;
};

#endif // !SPIELER_H
