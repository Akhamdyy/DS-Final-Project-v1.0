#pragma once
#include"EarthArmy.h"
#include"AlienArmy.h"
#include<ctime>
#include<cstdlib>
#ifndef RANDGEN_H
#define RANDGEN_H

using namespace std;
struct inputformat
	{
		int N=0, ESper=0, ETper=0, EGper=0, ASper=0, AMper=0, ADper=0, prob=0,HUper=0;
		int minearthpower=0, maxearthpower=0, minearthhealth=0, maxearthhealth=0, minearthcapacity=0, maxearthcapacity=0;
		int minalienpower=0, maxalienpower=0, minalienhealth=0, maxalienhealth=0, minaliencapacity=0, maxaliencapacity=0;
	};
class RandGen
{
private:
	EarthArmy* Earth;
	AlienArmy* Aliens;
	inputformat input;
public:
	RandGen(EarthArmy* e, AlienArmy* a, inputformat i1);
	RandGen();
	void seteartharmy(EarthArmy* e);
	void setalienarmy(AlienArmy* a);
	void Generateunits(Game& g,inputformat i);
	int generaterange(int min,int max);
	void setinput(inputformat in);
};

#endif