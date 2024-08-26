#pragma once
#include<iostream>
#include"Unit.h"
using namespace std;
class Game;
class AD :public Unit
{
public:
	AD(int id = 0, string t = "", int tj = 0, int hp = 100, int pwr = 0, int ac = 0, int dt = 0, int fa=0) :Unit(id, t, tj, hp, pwr, ac, dt, fa) {}
	void attack(Game& g) override;
	friend ostream& operator <<(ostream& out, AD& e);
};

