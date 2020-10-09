#pragma once
#ifndef ERSTEFIGUR_H
#define ERSTEFIGUR_H
#include "Figuren.h"
#include "stdafx.h"
#include <Gosu/Gosu.hpp>
#include <Gosu/AutoLink.hpp>

class ersteFigur : public Figuren {
	Vektoren richtungzumgegner;
private:

	//Sniper
	

public:
	ersteFigur(void);
	
	void set_richtungzumgegner(const Vektoren);
	Vektoren get_richtungzumgegner(void)const;
	virtual void gegnerinrange(vector<Gegner*>*) override;
	virtual void Zeichnen(void) override;
};



#endif // !ERSTEFIGUR_H
