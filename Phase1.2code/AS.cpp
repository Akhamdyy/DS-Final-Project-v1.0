#include "AS.h"
#include"Game.h"
using namespace std;
void AS::attack(Game&g)
{
	g.setASID(getid());
	//cout << "THIS IS ALIEN SOLDIERS ATTACKING EARTH SOLDIERS" << endl;
	//cout << "Power is: " << getpower() << endl;
	//cout << "Health is: " << gethealth() << endl;
	EarthArmy* Humans = g.getEarthArmy();
	//cout << "capacity is: " << getattackcap() << endl;
	LinkedQueue<ES*> Templist;
	LinkedQueue<ES*> UML1;
	if (getattackcap() > Humans->getEScount()) ////////if attack capacity more than elements in the list//////////////
	{
		LinkedQueue<ES> templist; 
			for (int i = 0; i < Humans->getEScount(); i++)
			{
				ES* EarthSoldier = Humans->removeES();
				if (EarthSoldier != nullptr)
				{
					if (EarthSoldier->getfirstattacked() == 0)///// if not attacked befor//////////
					{
						EarthSoldier->setfirstattacked(g.gettimestep());
					}
					//cout << "HEALTH BEFORE= " << EarthSoldier->gethealth() << endl;
					int damage = ceil((getpower() * gethealth() / 100) / sqrt(EarthSoldier->gethealth()));
					//cout << "damage is= " << damage << endl;
					if (damage >= EarthSoldier->gethealth())//////////if damage more than already health (to avoid negative value of health)//////////
					{
						EarthSoldier->sethealth(0);
					}
					else
					{
						EarthSoldier->sethealth(EarthSoldier->gethealth() - damage);
					}
					//cout << "ID: " << EarthSoldier->getid() << endl;
					//cout << "Health After =" << EarthSoldier->gethealth() << endl;
					g.addtoattackAS(EarthSoldier->getid());
					if (EarthSoldier->gethealth() == 0)
					{
						//cout << "Unit is killed" << endl;
						EarthSoldier->setdestructed(g.gettimestep());
						g.addtokilled(EarthSoldier);
						Humans->incrementES_destruct();
					}
					else
					{
						//cout << "Original health is: " << EarthSoldier->getoriginalhealth() << endl;
						if (EarthSoldier->gethealth() > 0 && EarthSoldier->gethealth() < (EarthSoldier->getoriginalhealth() * 0.2))
						{
							//cout << "Unit is in UML1";
							g.addtoUML1(EarthSoldier);
						}
						else
						{
							Templist.enqueue(EarthSoldier);
						}
					}
				}	
			}
	}
	else
	{
		for (int i = 0; i < getattackcap(); i++)
		{
			ES* EarthSoldier = Humans->removeES();
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
				//cout << "ID: " << EarthSoldier->getid() << endl;
				//cout << "Health After =" << EarthSoldier->gethealth() << endl;
				g.addtoattackAS(EarthSoldier->getid());
				if (EarthSoldier->gethealth() == 0)
				{
					//cout << "Unit is Killed";
					EarthSoldier->setdestructed(g.gettimestep());
					g.addtokilled(EarthSoldier);
					Humans->incrementES_destruct();
				}
				else
				{
					//cout << "Original health is: " << EarthSoldier->getoriginalhealth() << endl;

					if (EarthSoldier->gethealth() > 0 && EarthSoldier->gethealth() < (EarthSoldier->getoriginalhealth() * 0.2))
					{
						//cout << "Unit is in UML1";
						g.addtoUML1(EarthSoldier);
					}
					else
					{
						Templist.enqueue(EarthSoldier);
					}
				}
			}

		}
	}
	/*cout << "AS " << getid() << " Shot [";
	Templist.print();
	cout << " ]" << endl;*/
	ES* EarthSoldier = nullptr;
	while (Templist.dequeue(EarthSoldier))
	{
		Humans->CreateES(EarthSoldier->getid(), "ES",EarthSoldier->getjointime(), EarthSoldier->gethealth(), EarthSoldier->getpower(), EarthSoldier->getattackcap(), EarthSoldier->getdestructed(), EarthSoldier->getfirstattacked(), EarthSoldier->getoriginalhealth());

	}
}
ostream& operator <<(ostream& out, AS& e)
{
	out << e.getid();
	return out;
}
