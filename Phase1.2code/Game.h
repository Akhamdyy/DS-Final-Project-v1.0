#pragma once
#include"RandGen.h"
#include<fstream>
#include<sstream>
#include<iostream>
class Game
{
private:
	RandGen generator;
	EarthArmy* EArmy= new EarthArmy;
	AlienArmy* AArmy = new AlienArmy;
	LinkedQueue<Unit*> Killedlist;
	inputformat input;
	int timestep=1;
	Game(int t);
	static Game* instance;
	LinkedQueue<ES*> UML1;
	priQueue<ET*>UML2;
	LinkedQueue<int>listattackES;
	LinkedQueue<int>listattackET;
	LinkedQueue<int>listattackEG;
	LinkedQueue<int>listattackAS;
	LinkedQueue<int>listattackAM;
	LinkedQueue<int>listattackAD;
	int ESID=0;
	int EGID=0;
	int ETID=0;
	int ASID=0;
	int AMID=0;
	int ADID1=0;
	int ADID2 = 0;
	int state = 0;
public:
	inputformat ReadInput(string filename);
	static Game& getinstance(int t);
	Game(const Game&) = delete;
	Game& operator=(const Game&) = delete;
	void simulate();
	void printGame();
	int gettimestep();
	EarthArmy* getEarthArmy();
	AlienArmy* getalienarmy();
	void addtokilled(Unit*  u);
	void attack();
	void incrementwait();
	void addtoattackES(int n);
	void addtoattackET(int n);
	void addtoattackEG(int n);
	void addtoattackAS(int n);
	void addtoattackAM(int n);
	void addtoattackAD(int n);
	void clearlists();
	void setESID(int n);
	void setETID(int n);
	void setEGID(int n);
	void setASID(int n);
	void setAMID(int n);
	LinkedQueue<ES*> getUML1();
	priQueue<ET*>getUML2();
	void addtoUML1(ES* soldier);
	void addtoUML2(ET* tank,int pri);
	void produceoutput(string filename);
	ES* removefromUML1();
	ET* removefromUML2(int &x);
	int getUML1count();
	int getUML2count();
	void clearUML1();
	void clearUML2();
};