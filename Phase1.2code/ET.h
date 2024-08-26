#pragma once
#include<iostream>
#include"Unit.h"
using namespace std;
class Game;
class ET :public Unit
{
private:
	int waittime;
	int originalhealth;
public:
	ET(int id = 0, string t = "", int tj = 0, int hp = 100, int pwr = 0, int ac = 0, int dt = 0, int fa = 0, int wait=0, int original=0) :Unit(id, t, tj, hp, pwr, ac, dt, fa) 
	{
		waittime = wait;
		originalhealth = original;
	}
	void attack(Game& g) override;
	void incrementwaittime();
	int getwaittime();
	int getoriginalhealth();
};
inline ostream& operator << (ostream& out,const ET& e)
{
	out << e.getid();
	return out;
}

