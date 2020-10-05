#pragma once
#ifndef WEGKACHEL_H
#define WEGKACHEL_H
#include "Grid.h"
#include "Vektoren.h"

class Wegkachel : public Kachel {
private:

public:


};

//Funktionen

//Zeichnet einen horizontalen Weg von der Kachel mit der Stelle (x|y) mit einer Länge von Länge
vector<vector<Kachel>> wegHorizontal(vector<vector<Kachel>>, int, int, int);
//Zeichnet einen vertikalen Weg von der Kachel mit der Stelle (x|y) mit einer Länge von Länge
vector<vector<Kachel>> wegVertikal(vector<vector<Kachel>>, int, int, int);
//ninmt das komplett leere Grid und gibt das Grid mit dem gelben Weg zurück
vector<vector<Kachel>> gridmitweg(vector<vector<Kachel>>);
//nimmt das Komplette Grid und gibt den Weg als Liste zurück
vector<Kachel> wegalsListe(vector<vector<Kachel>>);


#endif // !WEGKACHEL_H
