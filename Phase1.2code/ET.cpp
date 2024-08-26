#include "ET.h"
#include "Game.h"
using namespace std;
void ET::attack(Game& g)
{
	g.setETID(getid());
	/*cout << "-----------------THIS IS ATTACK OF TANKS--------------" << endl;
	cout << "Power is: " << getpower() << endl;
	cout << "Health is: " << gethealth() << endl;
	cout << "capacity is: " << getattackcap() << endl;*/
	EarthArmy* Earth = g.getEarthArmy();
	AlienArmy* Aliens = g.getalienarmy();
	LinkedQueue<AS*> Templist;
	LinkedQueue<AM*> Templist2;
	/*cout << "ES:" << Earth->getEScount() << endl;
	cout << "AS:" << Aliens->getAScount() << endl;*/
	if (Earth->getEScount() < 0.3 * Aliens->getAScount()) {
		//cout << "Attack Monsters & Soldiers" << endl;
		int ac1 = ceil(getattackcap() / 2); ///Attack Cap for AS///
		int ac2 = getattackcap() - ac1; ///Attack Cap for AM///
		while (Earth->getEScount() != 0.8 * Aliens->getAScount()) {
			if (ac1 > Aliens->getAScount()) {
				ac2 = ac2 + (ac1 - Aliens->getAScount());
				for (int i = 0; i < Aliens->getAScount(); i++) {
					AS* AlienSoldier = Aliens->removeAS();
					if (AlienSoldier != nullptr) {
						if (AlienSoldier->getfirstattacked() == 0)///// if not attacked befor//////////
						{
							AlienSoldier->setfirstattacked(g.gettimestep());
						}
						//cout << "HEALTH BEFORE= " << AlienSoldier->gethealth() << endl;
						int damage = ceil((getpower() * gethealth() / 100) / sqrt(AlienSoldier->gethealth()));
						//cout << "damage is= " << damage << endl;
						if (damage >= AlienSoldier->gethealth())//////////if damage more than already health (to avoid negative value of health)//////////
						{
							AlienSoldier->sethealth(0);
						}
						else
						{
							AlienSoldier->sethealth(AlienSoldier->gethealth() - damage);
						}
					/*	cout << "Health After =" << AlienSoldier->gethealth() << endl;
						cout << "Power of tank" << AlienSoldier->getpower();*/
						g.addtoattackET(AlienSoldier->getid());
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
				if (ac2 > Aliens->getAMcount()) {
					for (int i = 0; i < Aliens->getAMcount(); i++) {
						AM* AlienMonster = Aliens->removeAM();
						if (AlienMonster != nullptr) {
							if (AlienMonster->getfirstattacked() == 0)///// if not attacked befor//////////
							{
								AlienMonster->setfirstattacked(g.gettimestep());
							}
							//cout << "HEALTH BEFORE= " << AlienMonster->gethealth() << endl;
							int damage = ceil((getpower() * gethealth() / 100) / sqrt(AlienMonster->gethealth()));
							//cout << "damage is= " << damage << endl;

							if (damage >= AlienMonster->gethealth())//////////if damage more than already health (to avoid negative value of health)//////////
							{
								AlienMonster->sethealth(0);
							}
							else
							{
								AlienMonster->sethealth(AlienMonster->gethealth() - damage);
							}
						/*	cout << "Health After =" << AlienMonster->gethealth() << endl;
							cout << "Power of tank" << AlienMonster->getpower() << endl;*/

							g.addtoattackET(AlienMonster->getid());
							if (AlienMonster->gethealth() == 0)
							{
								//cout << "Unit is killed" << endl;
								AlienMonster->setdestructed(g.gettimestep());
								g.addtokilled(AlienMonster);
								Aliens->incrementAM_destruct();
							}
							else
							{
								Templist2.enqueue(AlienMonster);
							}
						}
					}
				}
				else {
					for (int i = 0; i < ac2; i++) {
						AM* AlienMonster = Aliens->removeAM();
						if (AlienMonster != nullptr) {
							if (AlienMonster->getfirstattacked() == 0)///// if not attacked befor//////////
							{
								AlienMonster->setfirstattacked(g.gettimestep());
							}
							//cout << "HEALTH BEFORE= " << AlienMonster->gethealth() << endl;
							int damage = ceil((getpower() * gethealth() / 100) / sqrt(AlienMonster->gethealth()));
							//cout << "damage is= " << damage << endl;
							if (damage >= AlienMonster->gethealth())//////////if damage more than already health (to avoid negative value of health)//////////
							{
								AlienMonster->sethealth(0);
							}
							else
							{
								AlienMonster->sethealth(AlienMonster->gethealth() - damage);
							}
							/*cout << "Health After =" << AlienMonster->gethealth() << endl;
							cout << "Power of tank" << AlienMonster->getpower() << endl;*/

							g.addtoattackET(AlienMonster->getid());
							if (AlienMonster->gethealth() == 0)
							{
								//cout << "Unit is killed" << endl;
								AlienMonster->setdestructed(g.gettimestep());
								g.addtokilled(AlienMonster);
								Aliens->incrementAM_destruct();
							}
							else
							{
								Templist2.enqueue(AlienMonster);
							}
						}
					}
				}
			}
			else {
				for (int i = 0; i < ac1; i++) {
					AS* AlienSoldier = Aliens->removeAS();
					if (AlienSoldier != nullptr) {
						if (AlienSoldier->getfirstattacked() == 0)///// if not attacked befor//////////
						{
							AlienSoldier->setfirstattacked(g.gettimestep());
						}
						//cout << "HEALTH BEFORE= " << AlienSoldier->gethealth() << endl;
						int damage = ceil((getpower() * gethealth() / 100) / sqrt(AlienSoldier->gethealth()));
						//cout << "damage is= " << damage << endl;
						if (damage >= AlienSoldier->gethealth())//////////if damage more than already health (to avoid negative value of health)//////////
						{
							AlienSoldier->sethealth(0);
						}
						else
						{
							AlienSoldier->sethealth(AlienSoldier->gethealth() - damage);
						}
						//cout << "Health After =" << AlienSoldier->gethealth() << endl;
						g.addtoattackET(AlienSoldier->getid());
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
				if (ac2 > Aliens->getAMcount()) {
					for (int i = 0; i < Aliens->getAMcount(); i++) {
						AM* AlienMonster = Aliens->removeAM();
						if (AlienMonster != nullptr) {
							if (AlienMonster->getfirstattacked() == 0)///// if not attacked befor//////////
							{
								AlienMonster->setfirstattacked(g.gettimestep());
							}
							//cout << "HEALTH BEFORE= " << AlienMonster->gethealth() << endl;
							int damage = ceil((getpower() * gethealth() / 100) / sqrt(AlienMonster->gethealth()));
							//cout << "damage is= " << damage << endl;
							if (damage >= AlienMonster->gethealth())//////////if damage more than already health (to avoid negative value of health)//////////
							{
								AlienMonster->sethealth(0);
							}
							else
							{
								AlienMonster->sethealth(AlienMonster->gethealth() - damage);
							}
						/*	cout << "Health After =" << AlienMonster->gethealth() << endl;
							cout << "Power of tank" << AlienMonster->getpower() << endl;*/

							g.addtoattackET(AlienMonster->getid());
							if (AlienMonster->gethealth() == 0)
							{
								//cout << "Unit is killed" << endl;
								AlienMonster->setdestructed(g.gettimestep());
								g.addtokilled(AlienMonster);
								Aliens->incrementAM_destruct();
							}
							else
							{
								Templist2.enqueue(AlienMonster);
							}
						}
					}
				}
				else {
					for (int i = 0; i < ac2; i++) {
						AM* AlienMonster = Aliens->removeAM();
						if (AlienMonster != nullptr) {
							if (AlienMonster->getfirstattacked() == 0)///// if not attacked befor//////////
							{
								AlienMonster->setfirstattacked(g.gettimestep());
							}
							//cout << "HEALTH BEFORE= " << AlienMonster->gethealth() << endl;
							int damage = ceil((getpower() * gethealth() / 100) / sqrt(AlienMonster->gethealth()));
							//cout << "damage is= " << damage << endl;
							if (damage >= AlienMonster->gethealth())//////////if damage more than already health (to avoid negative value of health)//////////
							{
								AlienMonster->sethealth(0);
							}
							else
							{
								AlienMonster->sethealth(AlienMonster->gethealth() - damage);
							}
							//cout << "Health After =" << AlienMonster->gethealth() << endl;
							g.addtoattackET(AlienMonster->getid());
							if (AlienMonster->gethealth() == 0)
							{
								//cout << "Unit is killed" << endl;
								AlienMonster->setdestructed(g.gettimestep());
								g.addtokilled(AlienMonster);
								Aliens->incrementAM_destruct();
							}
							else
							{
								Templist2.enqueue(AlienMonster);
							}
						}
					}
				}
			}
			break;
		}
		/*cout << "ET " << getid() << " Shot [";
		Templist.print();
		cout << " ]" << endl;
		cout << "ET " << getid() << " Shot [";
		Templist2.print();
		cout << " ]" << endl;*/
		AM* AlienMonster = nullptr;
		while (Templist2.dequeue(AlienMonster))
		{
			Aliens->CreateAM(AlienMonster->getid(), "AM", AlienMonster->getjointime(), AlienMonster->gethealth(), AlienMonster->getpower(), AlienMonster->getattackcap(), AlienMonster->getdestructed(), AlienMonster->getfirstattacked());

		}
		AS* AlienSoldier = nullptr;
		while (Templist.dequeue(AlienSoldier))
		{
			Aliens->CreateAS(AlienSoldier->getid(), "AS",AlienSoldier->getjointime(), AlienSoldier->gethealth(), AlienSoldier->getpower(), AlienSoldier->getattackcap(), AlienSoldier->getdestructed(), AlienSoldier->getfirstattacked());

		}
	}
	else {
		//cout << "Attack Monsters Only" << endl;
		if (getattackcap() > Aliens->getAMcount()) {
			//cout << "attacking less than attak capacity" << endl;
			for (int i = 0; i < Aliens->getAMcount(); i++) {
				AM* AlienMonster = Aliens->removeAM();
				if (AlienMonster != nullptr) {
					if (AlienMonster->getfirstattacked() == 0)///// if not attacked befor//////////
					{
						AlienMonster->setfirstattacked(g.gettimestep());
					}
					/*cout << "ID of monster attacked" << AlienMonster->getid() << endl;
					cout << "HEALTH BEFORE= " << AlienMonster->gethealth() << endl;*/
					int damage = ceil((getpower() * gethealth() / 100) / sqrt(AlienMonster->gethealth()));
					//cout << "damage is= " << damage << endl;
					if (damage >= AlienMonster->gethealth())//////////if damage more than already health (to avoid negative value of health)//////////
					{
						AlienMonster->sethealth(0);
					}
					else
					{
						AlienMonster->sethealth(AlienMonster->gethealth() - damage);
					}
					//cout << "Health After =" << AlienMonster->gethealth() << endl;
					g.addtoattackET(AlienMonster->getid());
					if (AlienMonster->gethealth() == 0)
					{
						//cout << "Unit is killed" << endl;
						AlienMonster->setdestructed(g.gettimestep());
						g.addtokilled(AlienMonster);
						Aliens->incrementAM_destruct();
					}
					else
					{
						Templist2.enqueue(AlienMonster);
					}
				}
			}
		}
		else {
			for (int i = 0; i < getattackcap(); i++) {
				//cout << "attacking with full attack capacity" << endl;
				AM* AlienMonster = Aliens->removeAM();
				if (AlienMonster != nullptr) {
					if (AlienMonster->getfirstattacked() == 0)///// if not attacked befor//////////
					{
						AlienMonster->setfirstattacked(g.gettimestep());
					}
					/*cout << "ID of monster attacked" << AlienMonster->getid() << endl;
					cout << "HEALTH BEFORE= " << AlienMonster->gethealth() << endl;*/
					int damage = ceil((getpower() * gethealth() / 100) / sqrt(AlienMonster->gethealth()));
					//cout << "damage is= " << damage << endl;
					if (damage >= AlienMonster->gethealth())//////////if damage more than already health (to avoid negative value of health)//////////
					{
						AlienMonster->sethealth(0);
					}
					else
					{
						AlienMonster->sethealth(AlienMonster->gethealth() - damage);
					}
					//cout << "Health After =" << AlienMonster->gethealth() << endl;
					g.addtoattackET(AlienMonster->getid());
					if (AlienMonster->gethealth() == 0)
					{
						//cout << "Unit is killed" << endl;
						AlienMonster->setdestructed(g.gettimestep());
						g.addtokilled(AlienMonster);
						Aliens->incrementAM_destruct();
					}
					else
					{
						Templist2.enqueue(AlienMonster);
					}
				}
			}
		}
		/*cout << "ET " << getid() << " Shot [";
		Templist2.print();
		cout << " ]" << endl;*/
		AM* AlienMonster = nullptr;
		while (Templist2.dequeue(AlienMonster))
		{
			Aliens->CreateAM(AlienMonster->getid(), "AM", AlienMonster->getjointime(), AlienMonster->gethealth(), AlienMonster->getpower(), AlienMonster->getattackcap(), AlienMonster->getdestructed(), AlienMonster->getfirstattacked());

		}
	}
}

void ET::incrementwaittime()
{
	waittime++;
}

int ET::getwaittime()
{
	return waittime;
}
int ET::getoriginalhealth()
{
	return originalhealth;
}
