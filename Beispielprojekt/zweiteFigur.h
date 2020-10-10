#pragma once
#ifndef ZWEITEFIGUR_H
#define ZWEITEFIGUR_H
#include "Figuren.h"
#include "stdafx.h"
#include <Gosu/Gosu.hpp>
#include <Gosu/AutoLink.hpp>

class zweiteFigur : public Figuren {
private:
	//gibt die Slowrate des Turms an
	double slowrate;

public:
	//Konstruktoren
	
	//Standartkonstruktor
	zweiteFigur(void);
	
	//Get/Set Methoden
	
	//setzt die Slowrate
	void set_slowrate(const double);
	//gibt die Slowrate zurück
	double get_slowrate(void)const;

	//Andere Methoden

	//Virtuelle Methoden

	virtual void gegnerinrange(vector<Gegner*>*) override;
	virtual void Zeichnen(void) override;

};

#endif // !ZWEITEFIGUR_H
