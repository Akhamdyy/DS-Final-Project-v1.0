#pragma once
#include"ArrayStack.h"
#include"LinkedQueue.h"
#include"DoubleQueue.h"
#include"priNode.h"
#include"priQueue.h"
#include"DoubleListQueue.h"
#include"AM.h"
#include"AS.h"
#include"AD.h"
class AlienArmy
{
private:
	LinkedQueue<AS*> ASlist;
	DoubleListQueue<AD*> ADlist;
	AM* arr[1000];
	int actualcount;
	int ADcount;
	int AScount;
	static int id;
	int AS_total;
	int AM_total;
	int AD_total;
	int Alientotal;
	int AS_destruct;
	int AM_destruct;
	int AD_destruct;
	int totalaliendestruct;
	int ADattacker1=0;
	int ADattacker2=0;

public:
	AlienArmy()
	{

		id = 2000;
		actualcount = 0;
		ADcount = 0;
		AScount = 0;
		AS_total=0;
		AM_total=0;
		AD_total=0;
		Alientotal=0;
		AS_destruct=0;
		AM_destruct=0;
		AD_destruct=0;
		totalaliendestruct=0;
	}
	void attack(Game& g);
	void CreateAS(int i,string t, int tj, int hp, int pwr, int ac,int destruct,int firstattack);
	void CreateAD(int i,string t, int tj, int hp, int pwr, int ac,int destruct,int firstattack);
	void CreateAM(int i,string t, int tj, int hp, int pwr, int ac,int destruct,int firstattack);
	void print();
	void incrementnextid();
	int getdronecount();
	AS* removeAS();
	int getAMcount();
	int getAScount();
	int getADcount();
	int getinceremntedid();
	void removeAD(AD *&e,AD*& f);
	AM* removeAM();
	void printarr();
	bool is_dead();
	void incrementAS_destruct();
	void incrementAM_destruct();
	void incrementAD_destruct();
	void incrementAS_created();
	void incrementAM_created();
	void incrementAD_created();
	int gettotal();
	int getotaldestruct();
	int getAS_destruct();
	int getAM_destruct();
	int getAD_destruct();
	int getAS_total();
	int getAM_total();
	int getAD_total();
	int gettotalalive();
	int getAD1id();
	int getAD2id();
};

