#pragma once
#ifndef SPIELER_H
#define SPIELER_H

class Spieler {
private:
	int geld = 0;
	int leben = 0;
public:
	void set_geld(int g);
	int get_geld(void);
};

#endif // !SPIELER_H
