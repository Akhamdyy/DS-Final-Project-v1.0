#include "Unit.h"
#include"Game.h"
void Unit::setid(int n)
{
	Id = n;
}
int Unit::getid() const
{
	return Id;
}
void Unit::settype(string x)
{
	type = x;
}
string Unit::gettype()
{
	return type;
}
void Unit::setjointime(int n)
{
	jointime = n;
}
int Unit::getjointime()
{
	return jointime;
}
void Unit::sethealth(int n)
{
	health = n;
}
int Unit::gethealth()
{
	return health;
}
void Unit::setpower(int n)
{
	power = n;
}
int Unit::getpower()
{
	return power;
}
void Unit::setattackcap(int n)
{
	attackcap = n;
}
int Unit::getattackcap()
{
	return attackcap;
}

int Unit::getdestructed()
{
	return destructedtime;
}
int Unit::getfirstattacked()
{
	return firstattackedtime;
}
void Unit::setfirstattacked(int value)
{
	firstattackedtime = value;
}
void Unit::setdestructed(int value)
{
	destructedtime = value;
}