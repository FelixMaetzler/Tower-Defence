#pragma once
#ifndef ERSTEFIGUR_H
#define ERSTEFIGUR_H
#include "Figuren.h"
#include "stdafx.h"
class ersteFigur : public Figuren {
private:


public:

	virtual void gegnerinrange(vector<Gegner>&) override;
};



#endif // !ERSTEFIGUR_H
