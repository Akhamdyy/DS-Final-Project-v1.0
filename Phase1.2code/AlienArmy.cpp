#include "AlienArmy.h"
int AlienArmy::id = 2000;
void AlienArmy::attack(Game& g)
{
	/// AS ATTACK///
	AS* aliensoldier = removeAS();
	if (aliensoldier != nullptr)
	{
		aliensoldier->attack(g);
		CreateAS(aliensoldier->getid(), "AS", aliensoldier->getjointime(), aliensoldier->gethealth(), aliensoldier->getpower(), aliensoldier->getattackcap(), aliensoldier->getdestructed(), aliensoldier->getfirstattacked());
	}
	/// AM ATTACK///
	AM* alienmonster = removeAM();
	if (alienmonster != nullptr)
	{
		alienmonster->attack(g);
		CreateAM(alienmonster->getid(), "AM", alienmonster->getjointime(), alienmonster->gethealth(), alienmonster->getpower(), alienmonster->getattackcap(), alienmonster->getdestructed(), alienmonster->getfirstattacked());
	}
	/// AD attack//
	AD* drone1 = nullptr;
	AD* drone2 = nullptr;
	removeAD(drone1, drone2);
	if (drone1 != nullptr && drone2 != nullptr)
	{
		drone1->attack(g);
		drone2->attack(g);
		ADattacker1 = drone1->getid();
		ADattacker2 = drone2->getid();
		CreateAD(drone1->getid(), "AD", drone1->getjointime(), drone1->gethealth(), drone1->getpower(), drone1->getattackcap(), drone1->getdestructed(), drone1->getfirstattacked());
		CreateAD(drone2->getid(), "AD", drone2->getjointime(), drone2->gethealth(), drone2->getpower(), drone2->getattackcap(), drone2->getdestructed(), drone2->getfirstattacked());
	}



}
void AlienArmy::CreateAS(int i,string t, int tj, int hp, int pwr, int ac,int destruct,int firstattack)
{
	if (i != 0)
	{
		AS* unit4 = new AS(i, t, tj, hp, pwr, ac,destruct,firstattack);
		ASlist.enqueue(unit4);
		AScount++;
	}
	else
	{
		i = id;
		AS* unit4 = new AS(i, t, tj, hp, pwr, ac, destruct, firstattack);
		ASlist.enqueue(unit4);
		AScount++;
	}	
}

void AlienArmy::CreateAD(int i,string t, int tj, int hp, int pwr, int ac,int destruct,int firstattack)
{
	if (i != 0)
	{
		int id3 = i;
		AD* unit5 = new AD(i, t, tj, hp, pwr, ac, destruct, firstattack);
		ADlist.enqueue(unit5);
		ADcount++;
	}
	else
	{
		i = id;
		AD* unit5 = new AD(i, t, tj, hp, pwr, ac);
		ADlist.enqueue(unit5);
		ADcount++;
	}
	
}

void AlienArmy::CreateAM(int i,string t, int tj, int hp, int pwr, int ac,int destruct,int firstattack)
{
	if (i != 0)
	{
		AM* unit1 = new AM(i, t, tj, hp, pwr, ac, destruct, firstattack);
		arr[actualcount] = unit1;
		actualcount++;
	}
	else
	{
		i = id;
		AM* unit1 = new AM(i, t, tj, hp, pwr, ac, destruct, firstattack);
		arr[actualcount] = unit1;
		actualcount++;

	}
	
	
}
AS* AlienArmy::removeAS()
{
	AS* unit2 = nullptr;
	if (!ASlist.isEmpty())
	{
		ASlist.dequeue(unit2);
		AScount--;
	}
	return unit2;
	
}
int AlienArmy::getAMcount()
{
	return actualcount;
}
int AlienArmy::getAScount()
{
	return AScount;
}
int AlienArmy::getADcount()
{
	return ADcount;
}
int AlienArmy::getinceremntedid()
{
	return id;
}
void AlienArmy::removeAD(AD*& e,AD*& f)
{
	ADlist.dequeueback(e);
	ADlist.dequeue(f);
	if (e != nullptr && f != nullptr)
	{
		ADcount--;
		ADcount--;
	}
	else if (e == nullptr && f != nullptr)
	{
		e = f;
		ADcount--;
	}
	else if (e !=  nullptr && f == nullptr)
	{
		f = e;
		ADcount--;
		//incrementAD_created();
	}
	else
	{
		return;
	}
}
AM* AlienArmy::removeAM()
{
	AM* unit3;
	int x = 0;
	if (arr == nullptr)
	{
			return nullptr;
	}
	else if (actualcount == 0)
	{
		return nullptr;
	}
	else if (actualcount == 1)
	{
		x = 0;
	}
	else
	{
		x= rand() % actualcount + 1;
	}
	if (arr[x] == nullptr)
	{
		return nullptr;
	}
	unit3 = arr[x];
	arr[x] = arr[actualcount - 1];
	actualcount--;
	return unit3;
	
}

void AlienArmy::printarr() 
{
	if (arr == NULL)
	{
		cout << " ";
	}
	else
	{
		for (int i = 0; i < actualcount; i++)
		{
			if (arr[i]!=nullptr)
			{
				int id = arr[i]->getid();
				cout << id << ", ";
			}
		}
	}
}
bool AlienArmy::is_dead()
{
	if (ASlist.isEmpty() == true && ADlist.isEmpty() && actualcount == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void AlienArmy::incrementAS_destruct()
{
	AS_destruct++;
	totalaliendestruct++;
}
void AlienArmy::incrementAM_destruct()
{
	AM_destruct++;
	totalaliendestruct++;
}
void AlienArmy::incrementAD_destruct()
{
	AD_destruct++;
	totalaliendestruct++;
}
void AlienArmy::incrementAS_created()
{
	AS_total++;
	Alientotal++;
}
void AlienArmy::incrementAM_created()
{
	AM_total++;
	Alientotal++;
}
void AlienArmy::incrementAD_created()
{
	AD_total++;
	Alientotal++;
}
int AlienArmy::gettotal()
{
	return Alientotal;
}
int AlienArmy::getotaldestruct()
{
	return totalaliendestruct;
}
int AlienArmy::getAS_destruct()
{
	return AS_destruct;
}
int AlienArmy::getAM_destruct()
{
	return AM_destruct;
}
int AlienArmy::getAD_destruct()
{
	return AD_destruct;
}
int AlienArmy::getAS_total()
{
	return AS_total;
}
int AlienArmy::getAM_total()
{
	return AM_total;
}
int AlienArmy::getAD_total()
{
	return AD_total;
}
int AlienArmy::gettotalalive()
{
	return AScount + ADcount + actualcount;
}
int AlienArmy::getAD1id()
{
	return ADattacker1;
}
int AlienArmy::getAD2id()
{
	return ADattacker2;
}

void AlienArmy::print()
{
	cout << AScount << " AS [ ";
	ASlist.print();
	cout << " ]" << endl;
	cout << ADcount<< " AD [ ";
	ADlist.print();
	cout << " ]" << endl;
	cout << actualcount<< " AM [ ";
	printarr();
	cout << " ]" << endl;
}

void AlienArmy::incrementnextid()
{
	id++;
}

int AlienArmy::getdronecount()
{
	return ADlist.getcount();
}
