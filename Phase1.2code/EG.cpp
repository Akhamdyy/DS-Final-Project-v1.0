#include"EG.h";                                                                                                                                                                                                                             #include "EG.h"
#include"Game.h"
#include<iostream>;
using namespace std;
ostream& operator <<(ostream& out, EG& e)
{
	out << e.getid();
	return out;
}

void EG::attack(Game& g)
{
	g.setEGID(getid());
	//cout << "----THIS IS EARTH GUNNERY ATTACK-------" << endl;
	//cout << "Power is: " << getpower() << endl;
	//cout << "Health is: " << gethealth() << endl;
	AlienArmy* aliens = g.getalienarmy();
	//cout << "Capacity is: " << getattackcap() << endl;
	LinkedQueue<AM*> templistmonsters;
	int totalcap = getattackcap();
	int cap1 = ceil(totalcap / 2);// for monsters///
	int cap2 = totalcap - cap1;/// for drones///
	//// attacing monsters part////
	int x = 0;
	int amcount = aliens->getAMcount();
	if (cap1 >= aliens->getAMcount())
	{
		x = aliens->getAMcount();
		cap2 = cap2 + (cap1 - x);// to match full attack capacity///
	}
	else
	{
		x = cap1;
	}
	for (int i = 0; i < x; i++)
	{
		//cout << "attacking monsters part";
		AM* monster = aliens->removeAM();
		if (monster != nullptr)
		{
			if (monster->getfirstattacked() == 0)
			{
				monster->setfirstattacked(g.gettimestep());
			}
			//cout << "HEALTH BEFORE " <<monster->gethealth()<< endl;
			int damage = ceil((getpower() * gethealth() / 100) / sqrt(monster->gethealth()));
			//cout << "damage is= " << damage << endl;
			if (damage >= monster->gethealth())
			{
				monster->sethealth(0);
			}
			else
			{
				monster->sethealth(monster->gethealth() - damage);
			}
			//cout << "Health after= " << monster->gethealth() << endl;
			//cout << "ID of monster attacked" << monster->getid() << endl;
			g.addtoattackEG(monster->getid());
			if (monster->gethealth() == 0)
			{
				//cout << "unit is killed" << endl;
				monster->setdestructed(g.gettimestep());
				g.addtokilled(monster);
				aliens->incrementAM_destruct();
			}
			else
			{
				templistmonsters.enqueue(monster);
			}
		}
	}
	//// attacking drones part///
	//cout << "NOW ATTACKING DRONES" << endl;
	int z = 0;
	LinkedQueue<AD*> templistdrone;
	int adcount = aliens->getADcount();
	if (cap2 > aliens->getADcount())
	{
		z = aliens->getADcount();
	}
	else
	{
		z = cap2;
	}
	for (int i = 0; i < z; i++)
	{
		AD* drone1 = nullptr;
		AD* drone2 = nullptr;
		aliens->removeAD(drone1, drone2);
		if (drone1 != nullptr && drone2 != nullptr)
		{
			if (drone1 == drone2)/// this means there is only one drone in the list availble to attack//
			{
				if (drone1->getfirstattacked() == 0)
				{
					drone1->setfirstattacked(g.gettimestep());
				}
				//cout << "HEALTH BEFORE" << drone1->gethealth() <<endl;
				int damage1 = ceil((getpower() * gethealth() / 100) / sqrt(drone1->gethealth()));
				//cout << "damage is: " <<damage1<<endl;
				if (damage1 >= drone1->gethealth())
				{
					drone1->sethealth(0);
				}
				else
				{
					drone1->sethealth(drone1->gethealth() - damage1);
				}
				//cout << "HEALTH AFTER" << drone1->gethealth() << endl;
				g.addtoattackEG(drone1->getid());
				if (drone1->gethealth() == 0)
				{
					//cout << "drone is killed" << endl;
					drone1->setdestructed(g.gettimestep());
					g.addtokilled(drone1);
					aliens->incrementAD_destruct();
				}
				else
				{
					templistdrone.enqueue(drone1);
				}

			}
			else if(drone1!=drone2)
			{
				// drone 1//
				if (drone1->getfirstattacked() == 0)
				{
					drone1->setfirstattacked(g.gettimestep());
				}
				//cout << "Drone 1:HEALTH BEFORE"<< drone1->gethealth() << endl;
				int damage1 = ceil((getpower() * gethealth() / 100) / sqrt(drone1->gethealth()));
				//cout << "damage is: " << damage1 << endl;
				if (damage1 >= drone1->gethealth())
				{
					drone1->sethealth(0);

				}
				else
				{
					drone1->sethealth(drone1->gethealth() - damage1);
				}
				//cout << "drone 1: HEALTH AFTER" <<drone1->gethealth()<< endl;
				g.addtoattackEG(drone1->getid());
				if (drone1->gethealth() == 0)
				{
					//cout << "drone1 is killed" << endl;
					drone1->setdestructed(g.gettimestep());
					g.addtokilled(drone1);
					aliens->incrementAD_destruct();
				}
				else
				{
					templistdrone.enqueue(drone1);
				}
				// drone2///
				if (drone2->getfirstattacked() == 0)
				{
					drone2->setfirstattacked(g.gettimestep());
				}
				//cout << "drone 2: HEALTH BEFORE" << drone2->gethealth()<< endl;
				int damage2 = ceil((getpower() * gethealth() / 100) / sqrt(drone2->gethealth()));
				//cout << "damage is: " << damage1 << endl;
				if (damage2 >= drone2->gethealth())
				{
					drone2->sethealth(0);
				}
				else
				{
					drone2->sethealth(drone2->gethealth() - damage2);
				}
				//cout << "drone2: HEALTH AFTER" <<drone2->gethealth()<< endl;
				g.addtoattackEG(drone2->getid());
				if (drone2->gethealth() == 0)
				{
					//cout << "drone 2 is killed" << endl;
					drone2->setdestructed(g.gettimestep());
					g.addtokilled(drone2);
					aliens->incrementAD_destruct();
				}
				else
				{
					templistdrone.enqueue(drone2);
				}
			}
		}

	}
	/*cout << "EG " << getid() << "SHOT [  ";
	templistmonsters.print();
	templistdrone.print();
	cout << " ]" << endl;*/
	AM* monster1 = nullptr;
	AD* drones = nullptr;
	while (templistmonsters.dequeue(monster1))
	{
		aliens->CreateAM(monster1->getid(), "AM", monster1->getjointime(), monster1->gethealth(), monster1->getpower(), monster1->getattackcap(), monster1->getdestructed(), monster1->getfirstattacked());

	}
	while (templistdrone.dequeue(drones))
	{
		aliens->CreateAD(drones->getid(), "AM", drones->getjointime(), drones->gethealth(), drones->getpower(), drones->getattackcap(), drones->getdestructed(), drones->getfirstattacked());

	}

}

