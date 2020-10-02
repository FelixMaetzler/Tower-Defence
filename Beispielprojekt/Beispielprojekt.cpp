#include "stdafx.h"

#include <Gosu/Gosu.hpp>
#include <Gosu/AutoLink.hpp>

#include <vector>
#include <string>
#include <iostream>

#include "Vektor2d.h"


// Simulationsgeschwindigkeit
const double DT = 100.0;
void rechteck_2Ecken(double x1, double y1, double x2, double y2, Gosu::Color farbe, Gosu::ZPos zpos);
void rechteck_Mittelpunkt(double mx, double my, double laenge, double hoehe, Gosu::Color farbe, Gosu::ZPos zpos);
double x = 0;
double y = 0;

class GameWindow : public Gosu::Window
{
public:
	Gosu::Image bild;
	GameWindow()
		: Window(800, 600)
		, bild("mauscursor.png")
	{
		set_caption("Gosu Tutorial mit Git");
	}

	// wird bis zu 60x pro Sekunde aufgerufen.
	// Wenn die Grafikkarte oder der Prozessor nicht mehr hinterherkommen,
	// dann werden `draw` Aufrufe ausgelassen und die Framerate sinkt
	void draw() override
	{
		bild.draw_rot(x + 5, y + 5, 10, 0, 0.5, 0.5, 0.011, 0.011);//Mauszeiger
		rechteck_2Ecken(0, 0, 800, 600, Gosu::Color::WHITE, 0);//Hintergrund
	}

	// Wird 60x pro Sekunde aufgerufen
	void update() override
	{
		x = input().mouse_x();
		y = input().mouse_y();
	}
};

// C++ Hauptprogramm
int main()
{
	GameWindow window;
	window.show();
}
void rechteck_2Ecken(double x1, double y1, double x2, double y2, Gosu::Color farbe, Gosu::ZPos zpos) {
	//(x1|y1) definieren eine Ecke und (x2|y2) definieren die gegenüberliegende Ecke.
	Gosu::Graphics::draw_quad(
		x1, y1, farbe,
		x2, y1, farbe,
		x1, y2, farbe,
		x2, y2, farbe,
		zpos);
}
void rechteck_Mittelpunkt(double mx, double my, double laenge, double hoehe, Gosu::Color farbe, Gosu::ZPos zpos) {
	//(mx|my) ist der Mittelpunkt
	//diese Funktion muss noch getestet werden
	rechteck_2Ecken(
		mx - laenge / 2, my - hoehe / 2,
		mx + laenge / 2, my + hoehe / 2,
		farbe, zpos);
}
