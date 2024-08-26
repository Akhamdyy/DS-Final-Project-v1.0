#pragma once
#include<iostream>
#include"Unit.h"
//#include"Game.h"
using namespace std;
class ES:public Unit
{
private:
	int waittime;
	int originalhealth;
public:
	ES(int id = 0, string t = "", int tj = 0, int hp = 100, int pwr = 0, int ac = 0,int dt=0,int fa=0,int wait=0,int original=0) :Unit(id, t, tj, hp, pwr, ac,dt,fa){
		waittime = wait;
		originalhealth = original;
	}
	void attack(Game& g);
	friend ostream& operator <<(ostream& out, ES& e);
	int getwaittime();
	int getoriginalhealth();
	void incrementwaittime();
};