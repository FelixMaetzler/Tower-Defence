#pragma once
#ifndef GEGNERINTERAKTION_H
#define GEGNERINTERAKTION_H
#include"Gegner.h"
#include"Figuren.h"
//jeder Turm checkt jeden Gegner und interagiert mit ihm (schiesst ihn ab)
void schiessen(vector<Gegner*>*, vector<Figuren*>*);
//Alle Gegner werden gezeichnet
void zeichnen(vector<Gegner*>*);
//alle Figuren werden gezeichnet
void zeichnen(vector<Figuren*>*);
//Alle Gegner bewegen sich
void bewegen(vector<Gegner*>*);
//?
void bewegen(Gegner*);
//Für jeden Gegner wird die Richtung berechnet
void wegpunkt(vector<Gegner*>*, vector<Kachel>);
#endif // !GEGNERINTERAKTION_H
