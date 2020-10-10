#pragma once
#ifndef ZWEITERGEGNER_H
#define ZWEITERGEGNER_H
#include "Gegner.h"
#include <Gosu/Gosu.hpp>
#include <Gosu/AutoLink.hpp>
class ZweiterGegner : public Gegner {
private:

public:
	//Konstruktoren

	//Standartkonstruktor
	ZweiterGegner(void);

	//Get/Set Methoden

	//andere Methoden

	//Virtuelle Methoden

	virtual Gegner* schwaecherenGegnerSpawnen(Vektoren, int) override;
};

#endif // !ZWEITERGEGNER_H

