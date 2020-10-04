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
#include "Wegkachel.h"

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

auto arrayKacheln = gridZeichnen(fensterbreite, fensterhöhe, kachelgröße, abstand);
auto arrayKachel = weg(arrayKacheln, 3);


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

	}
	
	// Wird 60x pro Sekunde aufgerufen
	void update() override
	{
		x_maus = input().mouse_x();
		y_maus = input().mouse_y();
		
		if (input().down(Gosu::Button::Button(Gosu::ButtonName::MS_LEFT)) )
		{
			
			if (hatKachelgetroffen(x_maus, y_maus, arrayKachel))//Wenn man eine Kachel geklickt hat
			{
				//Dann soll eine Funktion ausgeführt werden, die die Kachelposition als Vektor zurückgibt
				Vektoren a = MausZuKachel(x_maus, y_maus, arrayKachel);
				
				//a.print();
				Kachel z = arrayKachel[a.get_x()][a.get_y()];
				
				if (z.get_farbe() == Schwarz&& z.get_change()==false)
				{
					z.set_change(true);
					//cout << "Schwarz wurde erkannt" << endl;
					z.set_farbe(Rot);
				}
				else if (z.get_farbe() == Rot && z.get_change() == false)
				{
					z.set_change(true);
					z.set_farbe(Schwarz);
					//cout << "Rot wurde erkannt" << endl;
				}

				arrayKachel[a.get_x()][a.get_y()] = z;

			}
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
	GameWindow window;
	window.show();


	//system("pause");
}

