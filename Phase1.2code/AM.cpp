#include "AM.h"
#include"Game.h";
void AM::attack(Game&g)
{
	g.setAMID(getid());
	/*cout << "This is attack for alien monsters " << endl;
	cout << "Power is: " << getpower() << endl;
	cout << "Health is: " << gethealth() << endl;*/
	EarthArmy* Army = g.getEarthArmy();
	//cout << "capacity is: " << getattackcap() << endl;
	LinkedQueue<ES*>Templist1; //EarthSoldiers temp list
	LinkedQueue<ET*>Templist2; //EarthTanks temp list
	LinkedQueue<ES*> UML1;
	priQueue<ET*>UML2;
	int count = getattackcap();
	int c1 = ceil(count / 2);  //ES counter
	int c2 = count - c1;       //ET counter
	int y = 0;
	int f = 0;
	if (c1 >= Army->getEScount())
	{
		y = Army->getEScount();
		c2 = c2 + (c1 - y);
	}
	else
	{
		y = c1;
	}
	if (c2 >= Army->getETcount())
	{
		f = Army->getETcount();
	}
	else
	{
		f = c2;
	}
	for (int i = 0; i < y; i++)
	{
		ES* EarthSoldier = Army->removeES();
		if (EarthSoldier != nullptr)
		{
			if (EarthSoldier->getfirstattacked() == 0)///// if not attacked befor//////////
			{
				EarthSoldier->setfirstattacked(g.gettimestep());
			}
			//cout << "Health Before= " << EarthSoldier->gethealth() << endl;
			int damage = ceil((getpower() * gethealth() / 100) / sqrt(EarthSoldier->gethealth()));
			//cout << "Damage is=" << damage << endl;
			if (damage >= EarthSoldier->gethealth())//////////if damage more than already health (to avoid negative value of health)//////////
			{
				EarthSoldier->sethealth(0);
			}
			else
			{
				EarthSoldier->sethealth(EarthSoldier->gethealth() - damage);

			}
			//cout << "Health After =" << EarthSoldier->gethealth() << endl;
			g.addtoattackAM(EarthSoldier->getid());
			if (EarthSoldier->gethealth() == 0)
			{
				//cout << "Unit is Killed" << endl;
				EarthSoldier->setdestructed(g.gettimestep());
				g.addtokilled(EarthSoldier);
				Army->incrementES_destruct();
			}
			else
			{
				if (EarthSoldier->gethealth() > 0 && EarthSoldier->gethealth() < (EarthSoldier->getoriginalhealth() * 0.2))
				{
					//cout << "Unit is in UML1";
					g.addtoUML1(EarthSoldier);
				}
				else
				{
					Templist1.enqueue(EarthSoldier);
				}
			}
		}


	}
	/*cout << "AM " << getid() << " Shot [";
	Templist1.print();
	cout << " ]" << endl;*/
	ES* EarthSoldier = nullptr;
	while (Templist1.dequeue(EarthSoldier))
	{
		Army->CreateES(EarthSoldier->getid(), "ES",EarthSoldier->getjointime(), EarthSoldier->gethealth(), EarthSoldier->getpower(), EarthSoldier->getattackcap(), EarthSoldier->getdestructed(), EarthSoldier->getfirstattacked(), EarthSoldier->getoriginalhealth());

	}
	for (int i = 0; i < f; i++)
	{
		ET* EarthTanks = Army->removeET();
		if (EarthTanks != nullptr)
		{
			if (EarthTanks->getfirstattacked() == 0)///// if not attacked befor//////////
			{
				EarthTanks->setfirstattacked(g.gettimestep());
			}
			//cout << "Health Before= " << EarthTanks->gethealth() << endl;
			int damage = ceil((getpower() * gethealth() / 100) / sqrt(EarthTanks->gethealth()));
			//cout << "Damage is=" << damage << endl;
			if (damage >= EarthTanks->gethealth())//////////if damage more than already health (to avoid negative value of health)//////////
			{
				EarthTanks->sethealth(0);
			}
			else
			{
				EarthTanks->sethealth(EarthTanks->gethealth() - damage);

			}
			//cout << "Health After =" << EarthTanks->gethealth() << endl;
			g.addtoattackAM(EarthTanks->getid());
			if (EarthTanks->gethealth() == 0)
			{
				//cout << "Unit is Killed" << endl;
				EarthTanks->setdestructed(g.gettimestep());
				g.addtokilled(EarthTanks);
				Army->incrementET_destruct();

			}
			else
			{
				if (EarthTanks->gethealth() > 0 && EarthTanks->gethealth() < (EarthTanks->getoriginalhealth() * 0.2))
				{
					//cout << "Unit is in UML2";
					g.addtoUML2(EarthTanks,(100-EarthTanks->gethealth()));
				}
				else
				{
					Templist2.enqueue(EarthTanks);
				}
			}
		}
	}
	ET* EarthTanks = nullptr;
	while (Templist2.dequeue(EarthTanks))
	{
		Army->CreateET(EarthTanks->getid(), "ET", EarthTanks->getjointime(), EarthTanks->gethealth(), EarthTanks->getpower(), EarthTanks->getattackcap(), EarthTanks->getdestructed(), EarthTanks->getfirstattacked(), EarthTanks->getoriginalhealth());

	}
}

ostream& operator <<(ostream& out, AM& e)
{
	out << e.getid();
	return out;
}


