#include "stdafx.h"

#include <Gosu/Gosu.hpp>
#include <Gosu/AutoLink.hpp>

#include <vector>
#include <string>
#include <iostream>

#include "Vektor2d.h"

#include "Zeichnen.h"
#include "Spieler.h"


// Simulationsgeschwindigkeit
const double DT = 100.0;

double x_maus = 0;//X-Position der Maus
double y_maus = 0;//Y-Position der Maus

class GameWindow : public Gosu::Window
{
public:
	Gosu::Image bild;
	GameWindow()
		: Window(800, 600)
		, bild("mauscursor_bearbeitet.png")
	{
		set_caption("Gosu Tutorial mit Git");
	}

	// wird bis zu 60x pro Sekunde aufgerufen.
	// Wenn die Grafikkarte oder der Prozessor nicht mehr hinterherkommen,
	// dann werden `draw` Aufrufe ausgelassen und die Framerate sinkt
	void draw() override
	{
		mauszeiger(bild, x_maus, y_maus);
		rechteck_2Ecken(0, 0, 800, 600, Weiss, 0);//Hintergrund
		punkt(200, 200, Schwarz, 100);
		rechteck_Mittelpunkt(200, 200, 200, 300, Blau, 50);
		
	}

	// Wird 60x pro Sekunde aufgerufen
	void update() override
	{
		x_maus = input().mouse_x();
		y_maus = input().mouse_y();
	}
};

// C++ Hauptprogramm
int main()
{
	GameWindow window;
	window.show();
}

