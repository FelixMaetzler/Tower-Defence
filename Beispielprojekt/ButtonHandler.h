#pragma once
#ifndef BUTTONHANDLER_H
#define BUTTONHANDLER_H
#include "stdafx.h"
#include "Zeichnen.h"
#include <Gosu/Gosu.hpp>
#include <Gosu/AutoLink.hpp>
#include "Vektoren.h"
#include <iostream>
#include "Grid.h"
using namespace std;

vector<vector<Kachel>> Maustaste_Losgelassen(vector<vector<Kachel>>  arrayKachel,int,int);
vector<vector<Kachel>> Maustaste_Gedrückt(vector<vector<Kachel>> arrayKachel, int,int);
#endif // !BUTTONHANDLER_H
