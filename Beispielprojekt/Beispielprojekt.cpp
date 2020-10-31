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
#include "ZweiterGegner.h"
#include "ButtonHandler.h"
#include "Figuren.h"
#include "GegnerInteraktion.h"
#include "ersteFigur.h"
#include "zweiteFigur.h"
#include "interneKonstanten.h"
#include "math.h"
using namespace std;


// Simulationsgeschwindigkeit
const double DT = 100.0;

int x_maus = 0;//X-Position der Maus
int y_maus = 0;//Y-Position der Maus
int fensterbreite = 1920;
int fensterhöhe = 1080;
int kachelgröße = 50;
int abstand = 0;
//Gosu::Color blck(255, 0, 0, 0);
//Gosu::Color rd(255, 255, 0, 0);



vector<vector<Kachel>> arrayKachel;
vector<vector<Kachel>>* arrayKachel_ptr = &arrayKachel;//Pointer auf das Kachelarray


//ErsterGegner* test_ptr = &test;

vector<Gegner*> gegnerliste(0);
vector<Figuren*> figurenliste(0);
vector<Gegner*>* gegnerliste_ptr = &gegnerliste;
vector<Figuren*>* figurenliste_ptr = &figurenliste;

Spieler spieler;
double lautstaerke = 0.2;
bool rundenstart = false;
bool SniperAusgewählt = false;
bool EisbergAusgewählt = false;

class GameWindow : public Gosu::Window
{
public:
	Gosu::Image Mauszeiger;
	Gosu::Image Tomate;
	GameWindow()
		:
		Mauszeiger("mauscursor_bearbeitet.png"),
		Window(fensterbreite, fensterhöhe, false)
	{
		set_caption("Gosu Tutorial mit Git");
	}

	// wird bis zu 60x pro Sekunde aufgerufen.
	// Wenn die Grafikkarte oder der Prozessor nicht mehr hinterherkommen,
	// dann werden `draw` Aufrufe ausgelassen und die Framerate sinkt
	void draw() override
	{
		mauszeiger(Mauszeiger, x_maus, y_maus);


		rechteck_2Ecken(0, 0, fensterbreite, fensterhöhe, Weiss, Z_Hintergrund);//Hintergrund

		ArrayZeichnen(*arrayKachel_ptr);
		if (rundenstart)
		{
			zeichnen(gegnerliste_ptr);
		}



		zeichnen(figurenliste_ptr);
		//Tomate.draw_rot(500, 500, 500,0,0.5,0.5, 1, 1);

		spieler.Zeichnen();
	}

	// Wird 60x pro Sekunde aufgerufen
	void update() override
	{

		x_maus = input().mouse_x();
		y_maus = input().mouse_y();
		if (rundenstart)//erst wenn die Runde gestartet wurde
		{




			if (gegnerliste_ptr->size() == 0)//alle Gegner sind weg
			{
				if (spieler.get_runde() != 0)
				{
					rundenstart = false; //Spiel wird pausiert. Ausser beim ersten Mal
				}

				spieler.runde_inkrementieren();
				//neue Gegner müssen gespawnt werden
				int x;
				x = spieler.get_runde();
				for (int i = 0; i < x; i++)
				{
					Gegner* gegner = new ZweiterGegner();
					gegner->set_position({ i * 50,0 });
					gegnerliste_ptr->push_back(gegner);
				}
			}
			bewegen(gegnerliste_ptr);//Bewegen muss IMMER vor Wegpunkt uffgerufe werden, weil sonst das Slowen von zweiteFigur nicht funzt
			wegpunkt(gegnerliste_ptr, wegalsListe(arrayKachel));//Bewegen muss IMMER vor Wegpunkt uffgerufe werden, weil sonst das Slowen von zweiteFigur nicht funzt


			schiessen(gegnerliste_ptr, figurenliste_ptr);
		}
		
	
		
	}

	void button_down(Gosu::Button button) override
	{


		if (button == Gosu::MS_LEFT) {

			arrayKachel = Maustaste_Gedrückt(*arrayKachel_ptr, x_maus, y_maus, figurenliste_ptr);
		}

		else {
			Window::button_down(button);
		}

		if (button == Gosu::KB_P)//P für Play wurde gedrückt
		{
			rundenstart = true;
		}
		if (button == Gosu::KB_S)//Shortcut Sniper
		{
			SniperAusgewählt = true;
			//alle anderen auf false
			EisbergAusgewählt = false;
		}
		if (button == Gosu::KB_E)//Shortcut Eisberg
		{
			EisbergAusgewählt = true;
			//alle anderen auf false
			SniperAusgewählt = false;
		}
	}
	void button_up(Gosu::Button button)override {
		if (button == Gosu::MS_LEFT) {
			arrayKachel = Maustaste_Losgelassen(arrayKachel, x_maus, y_maus);
		}
	}
};

class Hauptmenu : public Gosu::Window {
private:

public:
	Gosu::Image Mauszeiger;
	Hauptmenu() :
		Window(fensterbreite, fensterhöhe, false),
		Mauszeiger("mauscursor_bearbeitet.png")
	{
		set_caption("Hauptmenu");
	}

	void draw() override {
		rechteck_2Ecken(0, 0, fensterbreite, fensterhöhe, Weiss, Z_Hintergrund);//Hintergrund
		mauszeiger(Mauszeiger, x_maus, y_maus);
	}

	void update() override {
		x_maus = input().mouse_x();
		y_maus = input().mouse_y();
	}
};

// C++ Hauptprogramm
int main()
{

	auto qwertz = grid(fensterbreite, fensterhöhe, kachelgröße, abstand);
	arrayKachel = gridmitweg(qwertz);



	ZweiterGegner* test = new ZweiterGegner();
	ZweiterGegner* test2 = new ZweiterGegner();
	ZweiterGegner* test3 = new ZweiterGegner();
	ersteFigur figur;
	zweiteFigur figur2;

	/*

	//test.set_Geschwindigkeit(5);
	//test.set_leben(10);
	//test.set_position(arrayKachel.at(0).at(0).get_position());
	test->set_position(Vektoren(0, 100));
	gegnerliste_ptr->push_back(test);

	//test2.set_Geschwindigkeit(3);
	//test2.set_leben(100);
	//test.set_position(arrayKachel.at(0).at(0).get_position());
	test2->set_position(Vektoren(200, 0));
	gegnerliste_ptr->push_back(test2);

	test3->set_position(Vektoren(0, 0));
	gegnerliste_ptr->push_back(test3);

	*/


	arrayKachel.back().back().set_farbe(Gosu::Color::Color(254, 0, 0));
	arrayKachel.at(0).at(0).set_farbe(Gosu::Color::Color(0, 255, 0));
	/*
	figur.set_attackspeed(10);
	figur.set_damage(0.5);
	figur.set_range(5000);
	*/

	/*

	figur.set_position(arrayKachel[3][3].get_position());// Sitzt auf der 4. kachel von rechts und der 4. von oben
	figurenliste_ptr->push_back(&figur);
	figur2.set_position(arrayKachel[11][2].get_position());
	figurenliste_ptr->push_back(&figur2);

	*/

	Hauptmenu hm;
	GameWindow Fenster;
	//hm.show();

	Fenster.show();



}


