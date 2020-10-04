#pragma once
#ifndef WEGKACHEL_H
#define WEGKACHEL_H
#include "Grid.h"

class Wegkachel : public Kachel {
private:

public:


};

vector<vector<Kachel>> wegHorizontal(vector<vector<Kachel>>, int, int, int);
vector<vector<Kachel>> wegVertikal(vector<vector<Kachel>>, int, int, int);
vector<vector<Kachel>> weg(vector<vector<Kachel>>, int);



#endif // !WEGKACHEL_H
