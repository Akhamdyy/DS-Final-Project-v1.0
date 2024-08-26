#pragma once
#include<iostream>
using namespace std;
class Game;
class Unit
{
private:
	int Id;
	string type;
	int jointime;
	int health;
	int power;
	int attackcap;
	int destructedtime;
	int firstattackedtime;
public:
	Unit(int id=0, string t="", int tj=0, int h=0, int p=0, int ac=0, int dt=0, int FA=0) :Id(id), type(t), jointime(tj), health(h), power(p), attackcap(ac), destructedtime(dt), firstattackedtime(FA) {};
	void setid(int n);
	void settype(string x);
	void setjointime(int t);
	void sethealth(int n);
	void setpower(int n);
	void setattackcap(int n);
	virtual void attack(Game& g) = 0;
	int getid() const;
	string gettype();
	int getjointime();
	int gethealth();
	int getpower();
	int getattackcap();
	int getdestructed();
	void setdestructed(int value);
	int getfirstattacked();
	void setfirstattacked(int value);
};

