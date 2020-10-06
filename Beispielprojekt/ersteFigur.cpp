#include "stdafx.h"
#include "ersteFigur.h"
#include "Gegner.h"

void ersteFigur::gegnerinrange(vector<Gegner>& liste_ptr)  {
	for each (Gegner a in liste_ptr)
	{
		Vektoren d = a.get_position() - this->get_position();
		if (d.laenge() <= this->get_range())
		{
			a.lebenAbziehen(this->get_damage());
		}
	}
}