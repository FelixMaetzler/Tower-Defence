#include "stdafx.h"

#include <Gosu/Gosu.hpp>
#include <Gosu/AutoLink.hpp>

#include <vector>
#include <string>
#include <iostream>

//#include "Vektor2d.h"
#include "Vektoren.h"
#include "Grid.h"
#include "Zeichnen.h"
#include "Spieler.h"

using namespace std;


// Simulationsgeschwindigkeit
const double DT = 100.0;

double x_maus = 0;//X-Position der Maus
double y_maus = 0;//Y-Position der Maus
int fensterbreite = 1920;
int fensterhöhe = 1080;
int kachelgröße = 50;
int abstand = 2;
auto arrayKachel = gridZeichnen(fensterbreite, fensterhöhe, kachelgröße, abstand);
class GameWindow : public Gosu::Window
{
public:
	Gosu::Image bild;
	GameWindow()
		: Window(fensterbreite, fensterhöhe, false)
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


		rechteck_2Ecken(0, 0, fensterbreite, fensterhöhe, Weiss, 0);//Hintergrund
		
		arrayKachel[3][4].set_farbe(Schwarz);
		ArrayZeichnen(arrayKachel);
		arrayKachel[3][5].set_farbe(Blau);
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


	//system("pause");
}

