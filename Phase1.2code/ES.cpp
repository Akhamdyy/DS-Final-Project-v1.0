#include "ES.h"
#include"Game.h"
using namespace std;
void ES::attack(Game& g)
{
		g.setESID(getid());
		/*cout << "---- THIS IS FOR TESTING EARTH SOLDIERS ATTACKING ALIEN SOLDIERS----" << endl;
		cout << "Power is: " << getpower() << endl;
		cout << "Health is: " << gethealth() << endl;*/
		AlienArmy* Aliens = g.getalienarmy();
		/*cout << "capacity is: " << getattackcap() << endl;*/
		LinkedQueue<AS*> Templist;
		int counter = 0;
		if (getattackcap() >= Aliens->getAScount())
		{
			counter = Aliens->getAScount();
		}
		else
		{
			counter = getattackcap();
		}
		for (int i = 0; i < counter; i++)
		{
			AS* AlienSoldier = Aliens->removeAS();
			if (AlienSoldier != nullptr)
			{
				if (AlienSoldier->getfirstattacked() == 0)///// if not attacked before/////////
				{
					AlienSoldier->setfirstattacked(g.gettimestep());
				}
				/*cout << "HEALTH BEFORE= " << AlienSoldier->gethealth() << endl;*/
				double damage = ceil((getpower() * gethealth() / 100) / sqrt(AlienSoldier->gethealth()));
				/*cout << "damage is= " << damage << endl;*/
				if (damage >= AlienSoldier->gethealth())////////if damage more than already health (to avoid negative value of health)//////////
				{
					AlienSoldier->sethealth(0);
				}
				else
				{
					AlienSoldier->sethealth(AlienSoldier->gethealth() - damage);

				}
				//cout << "Health After =" << AlienSoldier->gethealth() << endl;
				g.addtoattackES(AlienSoldier->getid());
				if (AlienSoldier->gethealth() == 0)
				{
					//cout << "Unit is killed" << endl;
					AlienSoldier->setdestructed(g.gettimestep());
					g.addtokilled(AlienSoldier);
					Aliens->incrementAS_destruct();
				}
				else
				{
					Templist.enqueue(AlienSoldier);
				}
			}
		}
		/*cout << "ES " << getid() << " Shot [";
		Templist.print();
		cout << " ]" << endl;*/
		AS* AlienSoldier = nullptr;
		while (Templist.dequeue(AlienSoldier))
		{
			Aliens->CreateAS(AlienSoldier->getid(), "AS", AlienSoldier->getjointime(), AlienSoldier->gethealth(), AlienSoldier->getpower(), AlienSoldier->getattackcap(), AlienSoldier->getdestructed(), AlienSoldier->getfirstattacked());

		}

}
int ES::getwaittime()
{
	return waittime;
}
int ES::getoriginalhealth()
{
	return originalhealth;
}
void ES::incrementwaittime()
{
	waittime++;
}
//void ES::attack()
//{
//
//}
ostream& operator <<(ostream& out, ES& e)
{
	out << e.getid();
	return out;
}