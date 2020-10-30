#pragma once
#ifndef BUTTONHANDLER_H
#define BUTTONHANDLER_H
#include "stdafx.h"
#include "Zeichnen.h"
#include <Gosu/Gosu.hpp>
#include <Gosu/AutoLink.hpp>
#include "Vektoren.h"
#include "Figuren.h"
#include <iostream>
#include "Grid.h"

using namespace std;

vector<vector<Kachel>> Maustaste_Losgelassen(vector<vector<Kachel>>  arrayKachel,int,int);
vector<vector<Kachel>> Maustaste_Gedr�ckt(vector<vector<Kachel>> arrayKachel, int,int, vector<Figuren*>*);
#endif // !BUTTONHANDLER_H
