#pragma once
#ifndef ERSTEFIGUR_H
#define ERSTEFIGUR_H
#include "Figuren.h"
#include "stdafx.h"
#include <Gosu/Gosu.hpp>
#include <Gosu/AutoLink.hpp>

class ersteFigur : public Figuren {
	Vektoren richtungzumgegner;//gibt die Richtung zum Gegner an. Wird benötigt um den Sniper richtig zu drehen
private:

	//Sniper
	

public:
	//Konstruktoren

	//Standartkonstruktor
	ersteFigur(void);
	
	//Get/Set Methoden

	//setzt die Richtung zum Gegner. Als Argument wird die Position des Gegners erwartet
	void set_richtungzumgegner(const Vektoren);
	//Gibt die Richtung zum Gegner zurück
	Vektoren get_richtungzumgegner(void)const;

	//andere Methoden

	virtual void gegnerinrange(vector<Gegner*>*) override;
	virtual void Zeichnen(void) override;
};



#endif // !ERSTEFIGUR_H
