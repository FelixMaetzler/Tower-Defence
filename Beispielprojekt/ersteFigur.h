#pragma once
#ifndef ERSTEFIGUR_H
#define ERSTEFIGUR_H
#include "Figuren.h"
#include "stdafx.h"
#include <Gosu/Gosu.hpp>
#include <Gosu/AutoLink.hpp>

class ersteFigur : public Figuren {

private:

	//Sniper

public:

	virtual void gegnerinrange(vector<Gegner*> *gegnerliste_ptr) override;
};



#endif // !ERSTEFIGUR_H
