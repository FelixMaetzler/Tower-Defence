#pragma once
#ifndef SPIELER_H
#define SPIELER_H

class Spieler {
private:
	//Geld des Spielers
	double geld = 0;
	//Leben des Spielers
	double leben = 0;
public:
	//setzt Geld
	void set_geld(const double);
	//gibt Geld zurück
	double get_geld(void)const;
	//setzt Leben, wenn diese allerdings nicht größer Null sind, dann ist Game Over (Muss erst noch implementiert werden)
	void set_leben(const double);
	//gibt Leben zurück
	double get_leben(void)const;
};

#endif // !SPIELER_H
