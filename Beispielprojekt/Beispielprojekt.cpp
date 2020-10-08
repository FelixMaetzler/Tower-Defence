#include "stdafx.h"
#include <Gosu/Gosu.hpp>
#include <Gosu/AutoLink.hpp>
#include <vector>
#include <string>
#include <iostream>
#include "Vektoren.h"
#include "Grid.h"
#include "Zeichnen.h"
#include "Spieler.h"
#include "Wegkachel.h"
#include "ErsterGegner.h"
#include "ButtonHandler.h"
#include "Figuren.h"
#include "GegnerInteraktion.h"
#include "ersteFigur.h"
using namespace std;


// Simulationsgeschwindigkeit
const double DT = 100.0;

int x_maus = 0;//X-Position der Maus
int y_maus = 0;//Y-Position der Maus
int fensterbreite = 1920;
int fensterhöhe = 1080;
int kachelgröße = 50;
int abstand = 5;
//Gosu::Color blck(255, 0, 0, 0);
//Gosu::Color rd(255, 255, 0, 0);

auto qwertz = grid(fensterbreite, fensterhöhe, kachelgröße, abstand);
auto arrayKachel = gridmitweg(qwertz);




//ErsterGegner* test_ptr = &test;

vector<Gegner*> gegnerliste(0);
vector<Figuren*> figurenliste(0);
vector<Gegner*>* gegnerliste_ptr = &gegnerliste;
vector<Figuren*>* figurenliste_ptr = &figurenliste;



class GameWindow : public Gosu::Window
{
public:
	Gosu::Image Mauszeiger;
	Gosu::Image Tomate;
	GameWindow()
		: 
		 Mauszeiger("mauscursor_bearbeitet.png"),
		Window(fensterbreite, fensterhöhe, false),
		Tomate("tomato.png")


	{
		set_caption("Gosu Tutorial mit Git");
	}

	// wird bis zu 60x pro Sekunde aufgerufen.
	// Wenn die Grafikkarte oder der Prozessor nicht mehr hinterherkommen,
	// dann werden `draw` Aufrufe ausgelassen und die Framerate sinkt
	void draw() override
	{
		mauszeiger(Mauszeiger, x_maus, y_maus);


		rechteck_2Ecken(0, 0, fensterbreite, fensterhöhe, Weiss, 0);//Hintergrund

		ArrayZeichnen(arrayKachel);

		zeichnen(gegnerliste_ptr);
		zeichnen(figurenliste_ptr);
		//Tomate.draw_rot(500, 500, 500,0,0.5,0.5, 1, 1);

	}

	// Wird 60x pro Sekunde aufgerufen
	void update() override
	{
		
		x_maus = input().mouse_x();
		y_maus = input().mouse_y();

		wegpunkt(gegnerliste_ptr, wegalsListe(arrayKachel));
		bewegen(gegnerliste_ptr);

		schiessen(gegnerliste_ptr, figurenliste_ptr);
		
	}

	void button_down(Gosu::Button button) override
	{


		if (button == Gosu::MS_LEFT) {

			arrayKachel = Maustaste_Gedrückt(arrayKachel, x_maus, y_maus);
		}

		else {
			Window::button_down(button);
		}
	}
	void button_up(Gosu::Button button)override {
		if (button == Gosu::MS_LEFT) {
			arrayKachel = Maustaste_Losgelassen(arrayKachel, x_maus, y_maus);
		}
	}
};

// C++ Hauptprogramm
int main()
{

	ErsterGegner test;
	ErsterGegner test2;
	ersteFigur figur;

	//test.set_Geschwindigkeit(5);
	//test.set_leben(10);
	//test.set_position(arrayKachel.at(0).at(0).get_position());
	test.set_position(Vektoren(0, 0));
	gegnerliste_ptr->push_back(&test);

	test2.set_Geschwindigkeit(3);
	test2.set_leben(100);
	//test.set_position(arrayKachel.at(0).at(0).get_position());
	test2.set_position(Vektoren(0, 0));
	gegnerliste_ptr->push_back(&test2);
	
	arrayKachel.back().back().set_farbe(Gosu::Color::Color(120, 120, 120));
	/*
	figur.set_attackspeed(10);
	figur.set_damage(0.5);
	figur.set_range(5000);
	*/
	figur.set_position(arrayKachel[3][3].get_position());// Sitzt auf der 4. kachel von rechts und der 4. von oben
	figurenliste_ptr->push_back(&figur);
	
	

	GameWindow Fenster;


	Fenster.show();



}

//TODO: ENUM für Z-Ebene implementieren

enum Zpos {
	Z_Hintergrund,
	Z_Kacheln,
	Z_Gegner,
};