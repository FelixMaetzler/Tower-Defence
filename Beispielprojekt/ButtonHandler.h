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

void Maustaste_Losgelassen(int,int);
void Maustaste_Gedrückt( int,int);
#endif // !BUTTONHANDLER_H
