#include "stdafx.h"
#include "Figuren.h"
#include "Vektoren.h"
#include "ErsterGegner.h"

//Konstruktoren

Figuren::Figuren(void) {};
Figuren::Figuren(double as, double d, int p) {
	this->set_attackspeed(as);
	this->set_damage(d);
	this->set_price(p);
};

//Get/Set Methoden

void Figuren::set_attackspeed(const double as) {
	this->attackspeed = as;
}
double Figuren::get_attackspeed(void) const {
	return this->attackspeed;
}
void Figuren::set_damage(const double d) {
	this->damage = d;
}
double Figuren::get_damage(void) const {
	return this->damage;
}
void Figuren::set_price(const int p) {
	this->price = p;
}
int Figuren::get_price(void) const {
	return this->price;
}
void Figuren::set_position(const Vektoren p) {
	this->position = p;
}
Vektoren Figuren::get_position(void) const {
	return this->position;
}
void Figuren::set_range(const double r) {
	this->range = r;
}
double Figuren::get_range(void) const {
	return this->range;
}

void Figuren::set_zeitstempel(const std::chrono::steady_clock::time_point z)
{
	this->zeitstempel = z;
}

std::chrono::steady_clock::time_point Figuren::get_zeitstempel(void) const
{
	return this->zeitstempel;
}
Gosu::Image Figuren::get_image(void) const {
	return this->image;
}
void Figuren::set_image(const string dateipfad) {
	this->image = Gosu::Image(dateipfad);
}
int Figuren::get_x(void) const {
	return this->get_position().get_x();
}
void Figuren::set_x(const int x) {
	this->position.set_x(x);
}
int Figuren::get_y(void) const {
	return this->get_position().get_y();
}
void Figuren::set_y(const int y) {
	this->position.set_y(y);
}
Gosu::Sample Figuren::get_audio(void) const {
	return this->audio;
}
void Figuren::set_audio(const string s) {
	this->audio = Gosu::Sample(s);
}

//andere Methoden
