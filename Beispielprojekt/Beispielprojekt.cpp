#include "stdafx.h"

#include <Gosu/Gosu.hpp>
#include <Gosu/AutoLink.hpp>

#include <vector>
#include <string>
#include <iostream>
//Pfeife
#include "Vektor2d.h"

// Simulationsgeschwindigkeit
const double DT = 100.0;

class GameWindow : public Gosu::Window
{
public:
	Gosu::Image bild;
	GameWindow()
		: Window(800, 600)
	{
		set_caption("Gosu Tutorial Game mit Git zum testen geändert");
		//Pfeife
	}

	// wird bis zu 60x pro Sekunde aufgerufen.
	// Wenn die Grafikkarte oder der Prozessor nicht mehr hinterherkommen,
	// dann werden `draw` Aufrufe ausgelassen und die Framerate sinkt
	void draw() override
	{
		//hajonet
		//Pfeife
		//Pfeife2
	}

	// Wird 60x pro Sekunde aufgerufen
	void update() override
	{
		//oiuveno
	}
};

// C++ Hauptprogramm
int main()
{
	GameWindow window;
	window.show();
}
