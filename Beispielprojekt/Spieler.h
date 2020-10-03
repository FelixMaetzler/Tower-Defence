#pragma once
#ifndef SPIELER_H
#define SPIELER_H

class Spieler {
private:
	int geld = 0;
	int leben = 0;
public:
	void set_geld(int);
	int get_geld(void);
	void set_leben(int);
	int get_leben(void);
};

#endif // !SPIELER_H
