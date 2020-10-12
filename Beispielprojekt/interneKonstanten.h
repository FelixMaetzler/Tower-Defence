#pragma once
#ifndef INTERNEKONSTANTEN_H
#define INTERNEKONSTANTEN_H

#include "Spieler.h"

//In dieser Datei werden Dinge definirt, die man überall im Programm braucht und aber nicht geändert werden müssen. Bzw. nur sehr sehr selten
//Wie z.B. der Spieler. davon gibt es nur einen. Oder die Enumeration der Zpos

enum Zpos {
	Z_Hintergrund,
	Z_Kacheln,
	Z_Gegner,
	Z_Figur,
	Z_Spieleranzeige,
	Z_GUI,
	Z_Mauszeiger,
	
};
extern double lautstaerke;
extern Spieler spieler;

#endif // !INTERNEKONSTANTEN_H

