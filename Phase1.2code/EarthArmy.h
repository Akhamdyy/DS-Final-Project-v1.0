#pragma once
#include"ArrayStack.h"
#include"LinkedQueue.h"
#include"priNode.h"
#include"priQueue.h"
#include"ES.h"
#include"EG.h"
#include"ET.h"
#include"HU.h";
class EarthArmy
{
private:
	LinkedQueue<ES*> ESlist;
	ArrayStack<ET*> ETlist;
	priQueue<EG*> EGlist;
	LinkedQueue<HU*>HUlist;
	int EScount;
	int ETcount;
	int EGcount;
	int HUcount;
	int EStotal;
	int ETtotal;
	int EGtotal;
	int EarthTotal=0;
	int ES_destruct=0;
	int ET_destruct=0;
	int EG_destruct=0;
	int totaldestruct=0;
	int totalhealed = 0;
	static int id;
public:
	EarthArmy()
	{
		id = 1;
		EScount = 0;
		ETcount = 0;
		EGcount = 0;
		HUcount = 0;
		EStotal = 0;
		ETtotal = 0;
		EGtotal = 0;
		EarthTotal = 0;
		ES_destruct = 0;
		EG_destruct = 0;
		ET_destruct = 0;
		totaldestruct = 0;
		totalhealed = 0;
	}
	void CreateES(int i, string t, int tj, int hp, int pwr, int ac, int firstattack, int destruct,int original);
	void CreateET(int i, string t, int tj, int hp, int pwr, int ac, int firstattack, int destruct,int original);
	void CreateEG(int i, string t, int tj, int hp, int pwr, int ac, int firstattack, int destruct);
	void CreateHU(int i, string t, int tj, int hp, int pwr, int ac, int firstattack, int destruct);
	void incrementnextID();
	void print();
	int getincrementedid();
	ES* removeES();
	EG* removeEG();
	ET* removeET();
	int getEScount();
	int getETcount();
	int getEGcount();
	void attack(Game&g);
	void Heal(Game&g);
	bool is_dead();
	void incrementES_destruct();
	void incrementET_destruct();
	void incrementEG_destruct();
	void incrementES_created();
	void incrementEG_created();
	void incrementET_created();
	int gettotal();
	int gettotaldestructed();
	int getES_destruct();
	int getET_destruct();
	int getEG_destruct();
	int getES_total();
	int getET_total();
	int getEG_total();
	int getttoalalive();
	void incrementhealed();
	int gettotalhealed();
};