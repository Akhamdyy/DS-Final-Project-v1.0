#include "EarthArmy.h"
#include"Game.h"
int EarthArmy::id = 1;
void EarthArmy::CreateES(int i,string t, int tj, int hp, int pwr, int ac,int firstattack,int destruct,int original)
{
	if (i != 0)
	{
		ES* eu1 = nullptr;
		eu1 = new ES(i, "ES", tj, hp, pwr, ac, destruct, firstattack, 0, original);
		ESlist.enqueue(eu1);
		EScount++;

	}
	else
	{
		i = id;
		ES* eu1 = nullptr;
		eu1 = new ES(i, t, tj, hp, pwr, ac,0,0);
		ESlist.enqueue(eu1);
		EScount++;
	}
	
}
void EarthArmy::CreateET(int i, string t, int tj, int hp, int pwr, int ac, int firstattack, int destruct,int original)
{
	if (i != 0)/// 
	{
		ET* eu2 = new ET(i, t, tj, hp, pwr, ac,destruct,firstattack,0,original);
		ETlist.push(eu2);
		ETcount++;

	}
	else
	{
		i = id;
		ET* eu2 = new ET(i, t, tj, hp, pwr, ac,destruct,firstattack);
		ETlist.push(eu2);
		ETcount++;
	}
	
}
void EarthArmy::CreateEG(int i, string t, int tj, int hp, int pwr, int ac, int firstattack, int destruct)
{
	if (i != 0)
	{
		double dpri = sqrt(hp * pwr);
		int pri = int(dpri);
		EG* eu3 = new EG(i, t, tj, hp, pwr, ac,destruct,firstattack);
		EGlist.enqueue(eu3, pri);
		EGcount++;

	}
	else
	{
		i = id;
		double dpri = sqrt(hp * pwr);
		int pri = int(dpri);
		EG* eu3 = new EG(i, t, tj, hp, pwr, ac,destruct,firstattack);
		EGlist.enqueue(eu3, pri);
		EGcount++;
	}
		
}
void EarthArmy::CreateHU(int i, string t, int tj, int hp, int pwr, int ac, int firstattack, int destruct)
{
	i = id;
	HU* healedunit = new HU(i, "HU", tj, hp, pwr, ac, destruct, firstattack);
	HUlist.enqueue(healedunit);
	HUcount++;
}
ES* EarthArmy::removeES()
{
	ES* eu4 = nullptr;
	if (!ESlist.isEmpty())
	{
		ESlist.dequeue(eu4);
		EScount--;
	}
	
	return eu4;
}
EG* EarthArmy::removeEG()
{
	EG* eu5 = nullptr;
	int pri;
	if (!EGlist.isEmpty())
	{
		EGlist.dequeue(eu5, pri);
		EGcount--;
	}
	return eu5;
}
ET* EarthArmy::removeET()
{
	ET* eu6 = nullptr;
	if (!ETlist.isEmpty())
	{
		ETlist.pop(eu6);
		ETcount--;
	}
	return eu6;
}
int EarthArmy::getEScount()
{
	return EScount;
}
int EarthArmy::getEGcount()
{
	return EGcount;
}
int EarthArmy::getETcount()
{
	return ETcount;
}
void EarthArmy::attack(Game&g)
{
	/// ES ATTACK////
	ES* EarthSoldier = removeES();
	if (EarthSoldier != nullptr)
	{
		EarthSoldier->attack(g);
		CreateES(EarthSoldier->getid(), "ES", EarthSoldier->getjointime(), EarthSoldier->gethealth(), EarthSoldier->getpower(), EarthSoldier->getattackcap(),EarthSoldier->getdestructed(),EarthSoldier->getfirstattacked(),EarthSoldier->getoriginalhealth());
	}
	else
	{
		return;
	}
	/// ET ATTACK ///
	ET* EarthTank = removeET();
	if (EarthTank != nullptr)
	{
		EarthTank->attack(g);
		CreateET(EarthTank->getid(), "ET", EarthTank->getjointime(), EarthTank->gethealth(), EarthTank->getpower(), EarthTank->getattackcap(), EarthTank->getdestructed(), EarthTank->getfirstattacked(),EarthTank->getoriginalhealth());
	}
	else
	{
		return;
	}
	/// EG ATTACK///
	EG* Egun = removeEG();
	if (Egun != nullptr)
	{
		Egun->attack(g);
		CreateEG(Egun->getid(), "EG", Egun->getjointime(), Egun->gethealth(), Egun->getpower(), Egun->getattackcap(), Egun->getfirstattacked(), Egun->getdestructed());
	}

}
void EarthArmy::Heal(Game& g)
{
	HU* HealUnit = nullptr;
	HUlist.dequeue(HealUnit);
	if (HealUnit != nullptr) {
		HealUnit->attack(g);
		g.addtokilled(HealUnit);
		HealUnit->setdestructed(g.gettimestep());
		HUcount--;
	}
}
bool EarthArmy::is_dead()
{
	if (ETlist.isEmpty() == true && ESlist.isEmpty() == true && EGlist.isEmpty() == true)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void EarthArmy::incrementET_destruct()
{
	ET_destruct++;
	totaldestruct++;
}
void EarthArmy::incrementES_destruct()
{
	ES_destruct++;
	totaldestruct++;
}
void EarthArmy::incrementEG_destruct()
{
	EG_destruct++;
	totaldestruct++;
}
void EarthArmy::incrementEG_created()
{
	EGtotal++;
	EarthTotal++;
}
void EarthArmy::incrementES_created()
{
	EStotal++;
	EarthTotal++;
}
void EarthArmy::incrementET_created()
{
	ETtotal++;
	EarthTotal++;
}
int EarthArmy::gettotal()
{
	return EarthTotal;
}
int EarthArmy::gettotaldestructed()
{
	return totaldestruct;
}
int EarthArmy::getES_destruct()
{
	return ES_destruct;
}
int EarthArmy::getEG_destruct()
{
	return EG_destruct;
}
int EarthArmy::getET_destruct()
{
	return ET_destruct;
}
int EarthArmy::getEG_total()
{
	return EGtotal;
}
int EarthArmy::getttoalalive()
{
	return EScount + ETcount + EGcount;
}
void EarthArmy::incrementhealed()
{
	totalhealed++;
}
int EarthArmy::gettotalhealed()
{
	return totalhealed;
}
int EarthArmy::getET_total()
{
	return ETtotal;
}
int EarthArmy::getES_total()
{
	return EStotal;
}
void EarthArmy::print()
{
	cout << EScount<< " ES [ ";
	ESlist.print();
	cout << " ]" << endl;
	cout << ETcount<< " ET [ ";
	ETlist.print();
	cout << " ]" << endl;
	cout <<EGcount<< " EG [ ";
	EGlist.print();
	cout << " ]" << endl;
	cout << HUcount << " HU [";
	HUlist.print();
	cout << "] " << endl;
}
int EarthArmy::getincrementedid()
{
	return id;
}
void EarthArmy::incrementnextID()
{
	id++;
}