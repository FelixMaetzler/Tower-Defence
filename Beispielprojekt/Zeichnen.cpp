

#include "stdafx.h"
#include <Gosu/Gosu.hpp>
#include <Gosu/AutoLink.hpp>
#include "Zeichnen.h"

void rechteck_2Ecken(double x1, double y1, double x2, double y2, Gosu::Color farbe, Gosu::ZPos zpos)  {

	Gosu::Graphics::draw_quad(
		x1, y1, farbe,
		x2, y1, farbe,
		x1, y2, farbe,
		x2, y2, farbe,
		zpos);
}
void rechteck_Mittelpunkt(double mx, double my, double laenge, double hoehe, Gosu::Color farbe, Gosu::ZPos zpos) {

	rechteck_2Ecken(
		mx - laenge / 2, my - hoehe / 2,
		mx + laenge / 2, my + hoehe / 2,
		farbe, zpos);
}
void waagerechteLinie(double x, double y, double laenge, Gosu::Color farbe, Gosu::ZPos zpos) {
	Gosu::Graphics::draw_line(x, y, farbe, x + laenge, y, farbe, zpos);
}
void senkrechteLinie(double x, double y, double laenge, Gosu::Color farbe, Gosu::ZPos zpos) {
	Gosu::Graphics::draw_line(x, y, farbe, x, y + laenge, farbe, zpos);
}
void punkt(double x, double y, Gosu::Color farbe, Gosu::ZPos zpos) {
	rechteck_2Ecken(x - 1, y - 1, x + 1, y + 1, farbe, zpos);
}
void mauszeiger(Gosu::Image bild, double x, double y){
	bild.draw_rot(x + 5, y + 5, 3147483647, 0, 0.3, 0.15, 0.011, 0.011);//Mauszeiger
};