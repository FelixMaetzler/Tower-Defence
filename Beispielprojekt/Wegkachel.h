#pragma once
#ifndef WEGKACHEL_H
#define WEGKACHEL_H
#include "Grid.h"
#include "Vektoren.h"

class Wegkachel : public Kachel {
private:

public:


};

vector<vector<Kachel>> wegHorizontal(vector<vector<Kachel>>, int, int, int);
vector<vector<Kachel>> wegVertikal(vector<vector<Kachel>>, int, int, int);
vector<vector<Kachel>> weg(vector<vector<Kachel>>);
vector<Kachel> wegalsVektor(vector<vector<Kachel>>);


#endif // !WEGKACHEL_H
