#pragma once
#ifndef ERSTERGEGNER_H
#define ERSTERGEGNER_H
#include "Gegner.h"
#include <Gosu/Gosu.hpp>
#include <Gosu/AutoLink.hpp>
class ErsterGegner : public Gegner {
private:
	Gosu::Image image;
public:
	
	//Konstruktoren

	ErsterGegner(void);

	//Methoden
};

#endif // !ERSTERGEGNER_H

