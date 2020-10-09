#pragma once
#ifndef ZWEITEFIGUR_H
#define ZWEITEFIGUR_H
#include "Figuren.h"
#include "stdafx.h"
#include <Gosu/Gosu.hpp>
#include <Gosu/AutoLink.hpp>

class zweiteFigur : public Figuren {
private:
	double slowrate;
public:
	zweiteFigur(void);

	void set_slowrate(const double);
	double get_slowrate(void)const;

	virtual void gegnerinrange(vector<Gegner*>*) override;
	virtual void Zeichnen(void) override;

};

#endif // !ZWEITEFIGUR_H
