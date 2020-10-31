#pragma once
#ifndef INTERNEKONSTANTEN_H
#define INTERNEKONSTANTEN_H

#include "Spieler.h"
#include "Figuren.h"
#include "Gegner.h"
//In dieser Datei werden Dinge definirt, die man �berall im Programm braucht und aber nicht ge�ndert werden m�ssen. Bzw. nur sehr sehr selten
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

extern int fensterbreite;
extern int fensterh�he;
extern int kachelgr��e;
extern int abstand;


extern double lautstaerke;
extern Spieler spieler;
extern bool rundenstart;
extern bool SniperAusgew�hlt;
extern bool EisbergAusgew�hlt;
extern vector<Gegner*>* gegnerliste_ptr;
extern vector<Figuren*>* figurenliste_ptr;

extern vector<vector<Kachel>>* arrayKachel_ptr;
#endif // !INTERNEKONSTANTEN_H

