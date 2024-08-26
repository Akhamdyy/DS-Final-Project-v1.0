#include "RandGen.h"
#include <random>
#include"Game.h"
using namespace std;

RandGen::RandGen(EarthArmy* e, AlienArmy* a,inputformat i1):Earth(nullptr), Aliens(nullptr)
{
	input = i1;
	Earth = e;
	Aliens = a;
}
void RandGen::Generateunits(Game&g,inputformat i)
{

	int A = rand() % 100 + 1;
	/*cout << "A=" << A << endl;
	cout << "Prob =" << i.prob << endl;*/
	if (A <= i.prob)
	{
		for (int j = 0; j < i.N; j++)
		{
			int B = rand() % 100 + 1;
			if (B <= i.ESper)
			{
				int health = generaterange(i.minearthhealth, i.maxearthhealth);
				int power = generaterange(i.minearthpower, i.maxearthpower);
				int capacity = generaterange(i.minearthcapacity, i.maxearthcapacity);
				Earth->incrementnextID();
				int returnedid = Earth->getincrementedid();
				Earth->CreateES(returnedid, "ES",g.gettimestep(), health, power, capacity, 0, 0, health);
				Earth->incrementES_created();
				//Earth->incrementtotal();
				/*cout << "Created ES with ID: " << returnedid << "and original health of: " << health << endl;*/
			}
			else if (B > i.ESper && B <= i.ETper + i.ESper)
			{
				int health = generaterange(i.minearthhealth, i.maxearthhealth);
				int power = generaterange(i.minearthpower, i.maxearthpower);
				int capacity = generaterange(i.minearthcapacity, i.maxearthcapacity);
				Earth->incrementnextID();
				int returnedid = Earth->getincrementedid();
				Earth->CreateET(returnedid, "ET", g.gettimestep(), health, power, capacity,0,0,health);
				Earth->incrementET_created();
				//Earth->incrementtotal();
				/*cout << "Created ET with ID " << returnedid << "and orignial health of : " << health << endl;*/
			}
			else if ((B > i.ETper + i.ESper)&&(B<= i.ETper + i.ESper+i.EGper))
			{
				int health = generaterange(i.minearthhealth, i.maxearthhealth);
				int power = generaterange(i.minearthpower, i.maxearthpower);
				int capacity = generaterange(i.minearthcapacity, i.maxearthcapacity);
				Earth->incrementnextID();
				int returnedid = Earth->getincrementedid();
				Earth->CreateEG(returnedid, "EG", g.gettimestep(), health, power, capacity, 0, 0);
				Earth->incrementEG_created();
				//Earth->incrementtotal();
				/*cout << "Created EG with ID " << returnedid << "and orignial health of : " << health << endl;*/

			}
			else
			{
				int health = generaterange(i.minearthhealth, i.maxearthhealth);
				int power = generaterange(i.minearthpower, i.maxearthpower);
				int capacity = generaterange(i.minearthcapacity, i.maxearthcapacity);
				Earth->incrementnextID();
				int returnedid = Earth->getincrementedid();
				Earth->CreateHU(returnedid, "HU", g.gettimestep(), health, power, capacity, 0, 0);
				/*cout << "CreatedHU WITH ID: " << returnedid << endl;*/

			}
			int C = rand() % 100 + 1;
			if (C <= i.ASper)
			{
				int health = generaterange(i.minalienhealth, i.maxalienhealth);
				int power = generaterange(i.minalienpower, i.maxalienpower);
				int capacity = generaterange(i.minaliencapacity, i.maxaliencapacity);
				Aliens->incrementnextid();
				int returnedid = Aliens->getinceremntedid();
				Aliens->CreateAS(returnedid, "AS", g.gettimestep(), health, power, capacity,0,0);
				Aliens->incrementAS_created();
				/*cout << "Created AS with ID " << returnedid << "and orignial health of : " << health << endl;*/

			}
			else if (C > i.ASper && C <= (i.ASper + i.AMper))
			{
				int health = generaterange(i.minalienhealth, i.maxalienhealth);
				int power = generaterange(i.minalienpower, i.maxalienpower);
				int capacity = generaterange(i.minaliencapacity, i.maxaliencapacity);
				Aliens->incrementnextid();
				int returnedid = Aliens->getinceremntedid();
				Aliens->CreateAM(returnedid, "AM", g.gettimestep(), health, power, capacity,0,0);
				Aliens->incrementAM_created();
				/*cout << "Created AM with ID " << returnedid << "and orignial health of : " << health << endl;*/

			}
			else if (C > (i.ASper + i.AMper))
			{
				int health = generaterange(i.minalienhealth, i.maxalienhealth);
				int power = generaterange(i.minalienpower, i.maxalienpower);
				int capacity = generaterange(i.minaliencapacity, i.maxaliencapacity);
				Aliens->incrementnextid();
				int returnedid = Aliens->getinceremntedid();
				Aliens->CreateAD(returnedid, "AD", g.gettimestep(), health, power, capacity,0,0);
				Aliens->incrementAD_created();
				/*cout << "Created AD with ID " << returnedid << "and orignial health of : " << health << endl;*/

			}
		}
		
	}
}
int RandGen::generaterange(int min, int max)
{
	int c = max - min + 1;
	int range = rand() % c + min;
	return range;
}
void RandGen::setalienarmy(AlienArmy* a)
{
	if (a != nullptr)
		Aliens = a;
}
void RandGen::seteartharmy(EarthArmy* e)
{
	if (e != nullptr)
		Earth = e;
}
void RandGen::setinput(inputformat in)
{
	input = in;
}
RandGen::RandGen()
{

}