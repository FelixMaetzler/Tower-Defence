#pragma once
#ifndef ERSTERGEGNER_H
#define ERSTERGEGNER_H
#include "Gegner.h"
#include <Gosu/Gosu.hpp>
#include <Gosu/AutoLink.hpp>
class ErsterGegner : public Gegner {
private:
	
public:
	
	//Konstruktoren

	ErsterGegner(void);
	

	//Methoden

virtual Gegner* schwaecherenGegnerSpawnen(Vektoren, int) override;
};

#endif // !ERSTERGEGNER_H

