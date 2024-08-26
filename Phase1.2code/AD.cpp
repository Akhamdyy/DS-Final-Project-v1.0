#include "AD.h"
#include "AS.h"
#include "Game.h"
#include<iostream>
using namespace std;
void AD::attack(Game& g)
{
	/*cout << "------------THIS IS TESTING FOR ALIEN DRONES ATTACK" << endl;
	cout << "Health: " << gethealth() << endl;
	cout << "Power: " << getpower() << endl;*/
	LinkedQueue<ET*> Templist;
	LinkedQueue<EG*> Templist2;
	EarthArmy* Earth = g.getEarthArmy();
	AlienArmy* Aliens = g.getalienarmy();
	if (Aliens->getADcount() == 1) {
		return;
	}
	int ac1 = ceil(getattackcap() / 2); ///Attack Cap for ET///
	int ac2 = getattackcap() - ac1; ///Attack Cap for EG///
	if (ac1 > Earth->getETcount()) {
		ac2 = ac2 + (ac1 - Earth->getETcount());
		for (int i = 0; i < Earth->getETcount(); i++) {
			ET* EarthTank = Earth->removeET();
			if (EarthTank != nullptr) {
				if (EarthTank->getfirstattacked() == 0)///// if not attacked befor//////////
				{
					EarthTank->setfirstattacked(g.gettimestep());
				}
				//cout << "HEALTH BEFORE= " << EarthTank->gethealth() << endl;
				int damage = ceil((getpower() * gethealth() / 100) / sqrt(EarthTank->gethealth()));
				//cout << "damage is= " << damage << endl;
				if (damage >= EarthTank->gethealth())//////////if damage more than already health (to avoid negative value of health)//////////
				{
					EarthTank->sethealth(0);
				}
				else
				{
					EarthTank->sethealth(EarthTank->gethealth() - damage);
				}
				//cout << "Health After =" << EarthTank->gethealth() << endl;
				g.addtoattackAD(EarthTank->getid());
				if (EarthTank->gethealth() == 0)
				{
					//cout << "Unit is killed" << endl;
					EarthTank->setdestructed(g.gettimestep());
					g.addtokilled(EarthTank);
					Earth->incrementET_destruct();
				}
				else
				{
					if (EarthTank->gethealth() > 0 && EarthTank->gethealth() < (EarthTank->getoriginalhealth() * 0.2))
					{
						//cout << "Unit is in UML2";
						g.addtoUML2(EarthTank,(100-EarthTank->gethealth()));
					}
					else
					{
						Templist.enqueue(EarthTank);
					}
				}
			}

		}
		if (ac2 > Earth->getEGcount()) {
			for (int i = 0; i < Earth->getEGcount(); i++) {
				EG* EarthGunnary = Earth->removeEG();
				if (EarthGunnary != nullptr) {
					if (EarthGunnary->getfirstattacked() == 0)///// if not attacked befor//////////
					{
						EarthGunnary->setfirstattacked(g.gettimestep());
					}
					//cout << "HEALTH BEFORE= " << EarthGunnary->gethealth() << endl;
					int damage = ceil((getpower() * gethealth() / 100) / sqrt(EarthGunnary->gethealth()));
					//cout << "damage is= " << damage << endl;
					if (damage >= EarthGunnary->gethealth())//////////if damage more than already health (to avoid negative value of health)//////////
					{
						EarthGunnary->sethealth(0);
					}
					else
					{
						EarthGunnary->sethealth(EarthGunnary->gethealth() - damage);
					}
					//cout << "Health After =" << EarthGunnary->gethealth() << endl;
					g.addtoattackAD(EarthGunnary->getid());
					if (EarthGunnary->gethealth() == 0)
					{
						//cout << "Unit is killed" << endl;
						EarthGunnary->setdestructed(g.gettimestep());
						g.addtokilled(EarthGunnary);
						Earth->incrementEG_destruct();

					}
					else
					{
						Templist2.enqueue(EarthGunnary);
					}
				}
			}
		}
		else {
			for (int i = 0; i < ac2; i++) {
				EG* EarthGunnary = Earth->removeEG();
				if (EarthGunnary != nullptr) {
					if (EarthGunnary->getfirstattacked() == 0)///// if not attacked befor//////////
					{
						EarthGunnary->setfirstattacked(g.gettimestep());
					}
					//cout << "HEALTH BEFORE= " << EarthGunnary->gethealth() << endl;
					int damage = ceil((getpower() * gethealth() / 100) / sqrt(EarthGunnary->gethealth()));
					//cout << "damage is= " << damage << endl;
					if (damage >= EarthGunnary->gethealth())//////////if damage more than already health (to avoid negative value of health)//////////
					{
						EarthGunnary->sethealth(0);
					}
					else
					{
						EarthGunnary->sethealth(EarthGunnary->gethealth() - damage);
					}
					//cout << "Health After =" << EarthGunnary->gethealth() << endl;
					g.addtoattackAD(EarthGunnary->getid());
					if (EarthGunnary->gethealth() == 0)
					{
						//cout << "Unit is killed" << endl;
						EarthGunnary->setdestructed(g.gettimestep());
						g.addtokilled(EarthGunnary);
						Earth->incrementEG_destruct();

					}
					else
					{
						Templist2.enqueue(EarthGunnary);
					}
				}
			}
		}
	}
	else {
		for (int i = 0; i < ac1; i++) {
			ET* EarthTank = Earth->removeET();
			if (EarthTank != nullptr) {
				if (EarthTank->getfirstattacked() == 0)///// if not attacked befor//////////
				{
					EarthTank->setfirstattacked(g.gettimestep());
				}
				//cout << "HEALTH BEFORE= " << EarthTank->gethealth() << endl;
				int damage = ceil((getpower() * gethealth() / 100) / sqrt(EarthTank->gethealth()));
				//cout << "damage is= " << damage << endl;
				if (damage >= EarthTank->gethealth())//////////if damage more than already health (to avoid negative value of health)//////////
				{
					EarthTank->sethealth(0);
				}
				else
				{
					EarthTank->sethealth(EarthTank->gethealth() - damage);
				}
				//cout << "Health After =" << EarthTank->gethealth() << endl;
				g.addtoattackAD(EarthTank->getid());
				if (EarthTank->gethealth() == 0)
				{
					//cout << "Unit is killed" << endl;
					EarthTank->setdestructed(g.gettimestep());
					g.addtokilled(EarthTank);
					Earth->incrementET_destruct();

				}
				else
				{
					if (EarthTank->gethealth() > 0 && EarthTank->gethealth() < (EarthTank->getoriginalhealth() * 0.2))
					{
						//cout << "Unit is in UML2";
						g.addtoUML2(EarthTank, (100 - EarthTank->gethealth()));
					}
					else
					{
						Templist.enqueue(EarthTank);
					}
				}
			}
		}
		if (ac2 > Earth->getEGcount()) {
			for (int i = 0; i < Earth->getEGcount(); i++) {
				EG* EarthGunnary = Earth->removeEG();
				if (EarthGunnary != nullptr) {
					if (EarthGunnary->getfirstattacked() == 0)///// if not attacked befor//////////
					{
						EarthGunnary->setfirstattacked(g.gettimestep());
					}
					//cout << "HEALTH BEFORE= " << EarthGunnary->gethealth() << endl;
					int damage = ceil((getpower() * gethealth() / 100) / sqrt(EarthGunnary->gethealth()));
					//cout << "damage is= " << damage << endl;
					if (damage >= EarthGunnary->gethealth())//////////if damage more than already health (to avoid negative value of health)//////////
					{
						EarthGunnary->sethealth(0);
					}
					else
					{
						EarthGunnary->sethealth(EarthGunnary->gethealth() - damage);
					}
					//cout << "Health After =" << EarthGunnary->gethealth() << endl;
					g.addtoattackAD(EarthGunnary->getid());
					if (EarthGunnary->gethealth() == 0)
					{
						//cout << "Unit is killed" << endl;
						EarthGunnary->setdestructed(g.gettimestep());
						g.addtokilled(EarthGunnary);
						Earth->incrementEG_destruct();

					}
					else
					{
						Templist2.enqueue(EarthGunnary);
					}
				}
			}
		}
		else {
			for (int i = 0; i < ac2; i++) {
				EG* EarthGunnary = Earth->removeEG();
				if (EarthGunnary != nullptr) {
					if (EarthGunnary->getfirstattacked() == 0)///// if not attacked befor//////////
					{
						EarthGunnary->setfirstattacked(g.gettimestep());
					}
					//cout << "HEALTH BEFORE= " << EarthGunnary->gethealth() << endl;
					int damage = ceil((getpower() * gethealth() / 100) / sqrt(EarthGunnary->gethealth()));
					//cout << "damage is= " << damage << endl;
					if (damage >= EarthGunnary->gethealth())//////////if damage more than already health (to avoid negative value of health)//////////
					{
						EarthGunnary->sethealth(0);
					}
					else
					{
						EarthGunnary->sethealth(EarthGunnary->gethealth() - damage);
					}
					//cout << "Health After =" << EarthGunnary->gethealth() << endl;
					g.addtoattackAD(EarthGunnary->getid());
					if (EarthGunnary->gethealth() == 0)
					{
						//cout << "Unit is killed" << endl;
						EarthGunnary->setdestructed(g.gettimestep());
						g.addtokilled(EarthGunnary);
						Earth->incrementEG_destruct();
					}
					else
					{
						Templist2.enqueue(EarthGunnary);
					}
				}
			}
		}
	}
	/*cout << "AD " << getid() << " Shot [";
	Templist.print();
	cout << " ]" << endl;
	cout << "AD " << getid() << " Shot [";
	Templist2.print();
	cout << " ]" << endl;*/
	ET* EarthTank = nullptr;
	while (Templist.dequeue(EarthTank))
	{
		Earth->CreateET(EarthTank->getid(), "AS", EarthTank->getjointime(), EarthTank->gethealth(), EarthTank->getpower(), EarthTank->getattackcap(), EarthTank->getdestructed(), EarthTank->getfirstattacked(), EarthTank->getoriginalhealth());

	}
	EG* EarthGunnary = nullptr;
	while (Templist2.dequeue(EarthGunnary))
	{
		Earth->CreateEG(EarthGunnary->getid(), "AM",EarthGunnary->getjointime(), EarthGunnary->gethealth(), EarthGunnary->getpower(), EarthGunnary->getattackcap(), EarthGunnary->getdestructed(), EarthGunnary->getfirstattacked());

	}

}
ostream& operator <<(ostream& out, AD& e)
{
	out << e.getid();
	return out;
}
