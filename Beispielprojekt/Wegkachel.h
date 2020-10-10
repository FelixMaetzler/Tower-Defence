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
vector<vector<Kachel>> wegHorizontal(vector<vector<Kachel>>, int, int, int);
//Zeichnet einen vertikalen Weg von der Kachel mit der Stelle (x|y) mit einer L�nge von L�nge
vector<vector<Kachel>> wegVertikal(vector<vector<Kachel>>, int, int, int);
//ninmt das komplett leere Grid und gibt das Grid mit dem gelben Weg zur�ck
vector<vector<Kachel>> gridmitweg(vector<vector<Kachel>>);
//nimmt das Komplette Grid und gibt den Weg als Liste zur�ck. dabei sind die Kacheln in der richtigen Reihenfolge
vector<Kachel> wegalsListe(vector<vector<Kachel>>);


#endif // !WEGKACHEL_H
