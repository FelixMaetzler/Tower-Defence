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

//Zeichnet einen horizontalen Weg von der Kachel mit der Stelle (x|y) mit einer Länge von Länge
void wegHorizontal(int, int, int);
//Zeichnet einen vertikalen Weg von der Kachel mit der Stelle (x|y) mit einer Länge von Länge
void wegVertikal(int, int, int);
//ninmt das komplett leere Grid und gibt das Grid mit dem gelben Weg zurück
void gridmitweg(void);
//nimmt das Komplette Grid und gibt den Weg als Liste zurück. dabei sind die Kacheln in der richtigen Reihenfolge
vector<Kachel> wegalsListe(void);


#endif // !WEGKACHEL_H
