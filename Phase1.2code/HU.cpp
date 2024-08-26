#include "HU.h"
#include"Game.h"
void HU::attack(Game& g)
{
	LinkedQueue<ES*> tempEs;
	priQueue<ET*> tempET;
	EarthArmy* EArmy = g.getEarthArmy();
	int healcapacity = getattackcap();
	/*cout << "HEALTH: " << gethealth() << endl;
	cout << "CAPACITY: " << healcapacity << endl;
	cout << "Power: " << getpower() << endl;*/
	int healsoldierscount=0;
	int healtankscount=0;
	if (getattackcap() > g.getUML1count())
	{
		healsoldierscount = g.getUML1count();/// first fulfil all soldiers//
		healtankscount = healcapacity - healsoldierscount;/// then the rest for tanks///
	}
	else if (getattackcap() < g.getUML1count())
	{
		healsoldierscount = getattackcap();
		healtankscount = 0;
	}
	if (g.getUML2count() == 0)
	{
		healtankscount = healcapacity;
	}
	// first we heal the soldiers///
	if (g.getUML1count() != 0)
	{
		for (int i = 0; i < healsoldierscount; i++)
		{
			ES* soldier = g.removefromUML1();
			if (soldier != nullptr)
			{
				if (soldier->getwaittime() >= 10)
				{
					/*cout << "unit spent too much in UML so killed" << endl;*/
					soldier->setdestructed(g.gettimestep());
					g.addtokilled(soldier);
					EArmy->incrementES_destruct();
				}
				else
				{
					/*cout << "HEALTH BEFORE HEALING: "<<soldier->gethealth() << endl;*/
					int healimprovement = ceil((getpower() * gethealth() / 100) / sqrt(soldier->gethealth()));
					/*cout << " HEALTH IMPROVEMENT: " << healimprovement << endl;*/
					soldier->sethealth(soldier->gethealth() + healimprovement);
					/*cout << "HEALTH AFTER " << soldier->gethealth() << endl;*/
					if (soldier->gethealth() > (0.2 * soldier->getoriginalhealth()))
					{
						/*cout << "soldier is healed and sent back to battle" << endl;*/
						EArmy->incrementhealed();
						EArmy->CreateES(soldier->getid(), "ES", soldier->getjointime(), soldier->gethealth(), soldier->getpower(), soldier->getattackcap(), soldier->getfirstattacked(), soldier->getdestructed(),soldier->getoriginalhealth());
					}
					else
					{
						tempEs.enqueue(soldier);
					}
				}
			}
		}
		ES* sol = nullptr;
		while (tempEs.dequeue(sol))
		{
			g.addtoUML1(sol);
		}
	}
	if (g.getUML2count() != 0)
	{
		for (int i = 0; i < healtankscount; i++)
		{
			ET* tank = nullptr;
			int pri=0;
			tank=g.removefromUML2(pri);
			if (tank != nullptr)
			{
				if (tank->getwaittime() >= 10)
				{
					tank->setdestructed(g.gettimestep());
					g.addtokilled(tank);
					EArmy->incrementET_destruct();
				}
				else
				{
					/*cout << "HEALTH BEFORE TANK HEALING" << tank->gethealth() << endl;*/
					int healimprovement = ceil((getpower() * gethealth() / 100) / sqrt(tank->gethealth()));
					tank->sethealth(tank->gethealth() + healimprovement);
					/*cout << "HEALTH AFTER TANK HEALING" << tank->gethealth() << endl;*/
					if (tank->gethealth() > (0.2 * tank->getoriginalhealth()))
					{
						EArmy->incrementhealed();
						/*cout << "tank is healed and sent back to battle " << endl;*/
						EArmy->CreateET(tank->getid(), "ET", tank->getjointime(), tank->gethealth(), tank->getpower(), tank->getattackcap(), tank->getfirstattacked(), tank->getdestructed(), tank->getoriginalhealth());
					}
					else
					{

						tempET.enqueue(tank,100-gethealth());
					}

				}
			}
		}
		ET* tank = nullptr;
		int pri = 0;
		while (tempET.dequeue(tank,pri))
		{
			g.addtoUML2(tank, pri);
		}
	}

}