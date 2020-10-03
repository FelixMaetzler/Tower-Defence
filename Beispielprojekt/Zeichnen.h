#pragma once
#ifndef ZEICHNEN_H
#define ZEICHNEN_H


const Gosu::Color Hellblau = Gosu::Color::AQUA;
const Gosu::Color Schwarz = Gosu::Color::BLACK;
const Gosu::Color Blau = Gosu::Color::BLUE;
const Gosu::Color Cyan = Gosu::Color::CYAN;
const Gosu::Color Lila = Gosu::Color::FUCHSIA;
const Gosu::Color Grau = Gosu::Color::GRAY;
const Gosu::Color Gruen = Gosu::Color::GREEN;
const Gosu::Color Rot = Gosu::Color::RED;
const Gosu::Color Weiss = Gosu::Color::WHITE;
const Gosu::Color Gelb = Gosu::Color::YELLOW;

//Hier müssen zwei sich gegenüberliegende Punkte angegeben werden
void rechteck_2Ecken(double x1, double y1, double x2, double y2, Gosu::Color farbe, Gosu::ZPos zpos);
void rechteck_Mittelpunkt(double mx, double my, double laenge, double hoehe, Gosu::Color farbe, Gosu::ZPos zpos);
//Die Linie wird von (x|y) um die angegebene Länge nach rechts gezeichnet
void waagerechteLinie(double x, double y, double laenge, Gosu::Color farbe, Gosu::ZPos zpos);
//Die Linie wird von (x|y) um die angegebene Länge nach unten gezeichnet
void senkrechteLinie(double x, double y, double laenge, Gosu::Color farbe, Gosu::ZPos zpos);
//Der Punkt besteht aus 3x3 Pixel, wobei (x|y) der Mittelpunkt ist
void punkt(double x, double y, Gosu::Color farbe, Gosu::ZPos zpos);
//bild ist das Bild des Mauszeigers und (x|y) die Position
void mauszeiger(Gosu::Image bild, double x, double y);
#endif // !ZEICHNEN_H
