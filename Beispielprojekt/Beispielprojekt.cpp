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

vector<Gegner> gegnerliste(0);
vector<Figuren> figurenliste(0);
vector<Gegner>* gegnerliste_ptr = &gegnerliste;
vector<Figuren>* figurenliste_ptr = &figurenliste;

ErsterGegner test;
Figuren figur;

//Check ob die Maus bereits im vorherigen Zyklus losgelassen wurde, wenn ja, dann muss nicht die ganze Liste gechanged werden.


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

		ArrayZeichnen(arrayKachel);
		//arrayKachel[2][2].set_farbe(Gosu::Color::Color(255,255,0,0));
		test.Zeichnen();


	}

	// Wird 60x pro Sekunde aufgerufen
	void update() override
	{



		//if (!input().down(Gosu::Button::Button(Gosu::ButtonName::MS_LEFT)) {


		//	int iterator_ze = 1;
		//	int iterator_sp = 1;

		//	for (int iterator_ze = 1; iterator_ze < arrayKachel.size(); iterator_ze++)
		//	{
		//		for (int iterator_sp = 1; iterator_sp < arrayKachel.at(0).size(); iterator_sp++)
		//		{
		//			arrayKachel[iterator_ze][iterator_sp].set_change(false);
		//		}
		//	}
		//	Matrix_Change_Sauber = true;
		//}
		x_maus = input().mouse_x();
		y_maus = input().mouse_y();
		//if (input().down(Gosu::Button::Button(Gosu::ButtonName::MS_LEFT)))
		//{

		//	Matrix_Change_Sauber = false;
		//	if (hatKachelgetroffen(x_maus, y_maus, arrayKachel))//Wenn man eine Kachel geklickt hat
		//	{
		//		//Dann soll eine Funktion ausgeführt werden, die die Kachelposition als Vektor zurückgibt
		//		Vektoren a = MausZuKachel(x_maus, y_maus, arrayKachel);
		//		
		//		//a.print();
		//		Kachel z = arrayKachel[a.get_x()][a.get_y()];
		//		
		//		if (z.get_farbe() == Schwarz&& z.get_change()==false)
		//		{
		//			z.set_change(true);
		//			//cout << "Schwarz wurde erkannt" << endl;
		//			z.set_farbe(Rot);
		//		}
		//		else if (z.get_farbe() == Rot && z.get_change() == false)
		//		{
		//			z.set_change(true);
		//			z.set_farbe(Schwarz);
		//			//cout << "Rot wurde erkannt" << endl;
		//		}

		//		arrayKachel[a.get_x()][a.get_y()] = z;

		//	}
		//}
		test.wegpunkt(wegalsListe(arrayKachel));
		test.set_position(test.get_position() + test.get_richtung());


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
	/*Gosu::Color a(255, 255, 0, 0);
	cout << a.gl() << endl;
	a = Gosu::Color::Color(4278190080);
	cout << a.gl() << endl;*/



	test.set_Geschwindigkeit(5);
	test.set_leben(10);
	//test.set_position(arrayKachel.at(0).at(0).get_position());
	test.set_position(Vektoren(0, 0));
	
	arrayKachel.back().back().set_farbe(Gosu::Color::Color(120, 120, 120));

	figur.set_attackspeed(1);
	figur.set_damage(1);
	figur.set_position(arrayKachel[3][3].get_position());// Sitzt auf der 4. kachel von rechts und der 4. von oben

	
	GameWindow Fenster;

	Fenster.show();


	//system("pause");
}

//TODO: ENUM für Z-Ebene implementieren

enum Zpos {
	Z_Hintergrund,
	Z_Kacheln,
	Z_Gegner,
};