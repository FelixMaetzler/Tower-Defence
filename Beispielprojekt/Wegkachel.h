#pragma once
#ifndef WEGKACHEL_H
#define WEGKACHEL_H
#include "Grid.h"
#include "Vektoren.h"

//ist nur dazu da, um den Weg einmalig zu zeichnen

class Wegkachel : public Kachel {
private:

public:


};

//Funktionen

//Zeichnet einen horizontalen Weg von der Kachel mit der Stelle (x|y) mit einer L�nge von L�nge
void wegHorizontal(int, int, int);
//Zeichnet einen vertikalen Weg von der Kachel mit der Stelle (x|y) mit einer L�nge von L�nge
void wegVertikal(int, int, int);
//ninmt das komplett leere Grid und gibt das Grid mit dem gelben Weg zur�ck
void gridmitweg(void);
//nimmt das Komplette Grid und gibt den Weg als Liste zur�ck. dabei sind die Kacheln in der richtigen Reihenfolge
vector<Kachel> wegalsListe(void);


#endif // !WEGKACHEL_H
