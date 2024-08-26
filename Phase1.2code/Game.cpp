#include "Game.h"
#include<iostream>
using namespace std;
Game* Game::instance = nullptr;
inputformat Game::ReadInput(string filename)
{
	inputformat i;
	int EArr[5] = { 0 };
	int AArr[4] = { 0 };
	int Erange[7] = { 0 };
	int Arange[7] = { 0 };
	ifstream inputfile(filename);
	if (inputfile.is_open())
	{
		string line;
		// first line//
		getline(inputfile, line);
		istringstream is1(line);
		is1 >> i.N;
		// second line//
		getline(inputfile, line);
		istringstream is2(line);
		int count = 0;
		while (is2)
		{
			int Eper;
			is2 >> Eper;
			EArr[count] = Eper;
			is2.ignore(1);
			count++;
		}
		i.ESper = EArr[0];
		i.ETper = EArr[1];
		i.EGper = EArr[2];
		i.HUper = EArr[3];
		count = 0;
		///third line//
		getline(inputfile, line);
		istringstream is3(line);
		while (is3)
		{
			int Aper;
			is3 >> Aper;
			AArr[count] = Aper;
			is3.ignore();
			count++;
		}
		i.ASper = AArr[0];
		i.AMper = AArr[1];
		i.ADper = AArr[2];
		//// fourth line//
		getline(inputfile, line);
		istringstream is4(line);
		is4 >> i.prob;
		//// next line is empty//
		getline(inputfile, line);
		/// fifth line//
		getline(inputfile, line);
		istringstream is5(line);
		count = 0;
		while (is5)
		{
			int x;
			is5 >> x;
			Erange[count] = x;
			count++;
			is5.ignore(1);
		}
		i.minearthpower = Erange[0];
		i.maxearthpower = Erange[1];
		i.minearthhealth = Erange[2];
		i.maxearthhealth = Erange[3];
		i.minearthcapacity = Erange[4];
		i.maxearthcapacity = Erange[5];
		/// reading sixth line//
		getline(inputfile, line);
		istringstream is6(line);
		count = 0;
		while (is6)
		{
			int x;
			is6 >> x;
			Arange[count] = x;
			count++;
			is6.ignore(1);
		}
		i.minalienpower = Arange[0];
		i.maxalienpower = Arange[1];
		i.minalienhealth = Arange[2];
		i.maxalienhealth = Arange[3];
		i.minaliencapacity = Arange[4];
		i.maxaliencapacity = Arange[5];
		inputfile.close();

	}
	else
	{
		cout << "Unable to open the file" << endl;
	}
	/*generator.setinput(i);*/
	input = i;
	return i;
}
Game& Game::getinstance(int t)
{
	if (instance == nullptr)
	{
		instance = new Game(1);
	}
	return*instance;
}
Game::Game(int t=1)
{
	timestep = t;
	generator.setalienarmy(AArmy);
	generator.seteartharmy(EArmy);
}
void Game::simulate()
{
	cout << "Please choose a file number to select a scenario to test: 0 to 6" << endl;
	/*cout << "File1: ";*/
	int file = 0;
	cout << "File 1: Weak Earth - Weak Aliens" << endl;
	cout << "File 2: Weak Earth - Moderate Aliens" << endl;
	cout << "File 3: Weak Earth - Strong Aliens" << endl;
	cout << "File 4: Strong Earth - Weak Aliens " << endl;
	cout << "File 5: Strong Earth- Moderate Aliens" << endl;
	cout << "File 6: Strong Earth - Strong Aliens" << endl;
	cin >> file;
	while (file < 1 || file>6)
	{
		cout << "Please enter a valid file name:";
		cin >> file;
	}
	
	string filename = "";
	string outputfilename = "";
	switch(file)
	{
	case(1):
		filename = "Input-1.txt";
		outputfilename = "Output-1.txt";
		break;
	case (2):
		filename = "Input-2.txt";
		outputfilename = "Output-2.txt";
		break;
	case(3):
		filename = "Input-3.txt";
		outputfilename = "Output-3.txt";
		break;
	case(4):
		filename = "Input-4.txt";
		outputfilename = "Output-4.txt";
		break;
	case(5):
		filename = "Input-5.txt";
		outputfilename = "Output-5.txt";
	case(6):
		filename = "Input-6.txt";
		outputfilename = "Output-7.txt";
		break;
	}
	input = ReadInput(filename);
	timestep = 1;
	cout << "Please enter a number to choose the desired mode: " << endl;
	cout << "0- Silent Run Mode " << endl;
	cout << "1- Interactive Run Mode" << endl;
	int mode;
	cin >> mode;
	while (mode < 0 || mode>1)
	{
		cout << "Please enter a valid mode number: " << endl;
	}
	cout << "Simulation Started..."<<endl;
	for(int j=1;j<500;j++)
	{
		timestep = j;
		generator.Generateunits(*this, input);
		attack();
		EArmy->Heal(*this);
		if (mode == 1)
		{
			printGame();

		}
		clearlists();
		incrementwait();
		if (j > 40)
		{
			if (EArmy->is_dead() == true || AArmy->is_dead() == true)
			{
				break;
			}
		}
		
	}
	if (EArmy->is_dead() == true)
	{
		if (mode == 1)
		{
			cout << "=======================SURRENDER THE ALIENS HAVE INVADED THE EARTH==================================" << endl;
			cout << "                                                                                                    " << endl;
			cout << "                                                                                                    " << endl;
			cout << "  " << endl;
		}
		                                                                                                  
		clearUML1();
		clearUML2();
		state = 1;
	}
	else if (AArmy->is_dead() == true)
	{
		if (mode == 1)
		{
			cout << "==========================YOU HAVE SAVED THE EARTH SUCCESSFULLY=====================================" << endl;
			cout << "                                                                                                    " << endl;
			cout << "                                                                                                    " << endl;
			cout << "                                                                                                    " << endl;
		}
		state = 2;
	}
	else
	{
		int earthalive = EArmy->getttoalalive();
		int alienalive = AArmy->gettotalalive();
		if (earthalive > alienalive)
		{
			state = 2;
		}
		else if (earthalive < alienalive)
		{
			state = 1;
		}
	}
	produceoutput(outputfilename);
	
}


void Game::printGame()
{
	cout << "Current Timestep " << timestep << endl;
	cout << "===============================================Earth Army Alive Units=================================================" << endl;
	EArmy->print();
	cout << "                                                                                                                      " << endl;
	cout << "                                                                                                                      " << endl;

	cout << "===============================================Alien Army Alive Units=================================================" << endl;
	AArmy->print();
	cout << "                                                                                                                      " << endl;
	cout << "                                                                                                                      " << endl;
	cout << "===========================================Units fighting at current timestep=========================================" << endl;
	cout << "ES " << ESID << " shot [ ";
	listattackES.killprint();
	cout << "] " << endl;
	cout << "ET " << ETID << " shot [ ";
	listattackET.killprint();
	cout << "] " << endl;
	cout << "EG " << EGID << " shot [ ";
	listattackEG.killprint();
	cout << "] " << endl;
	cout << "AS " << ASID << " shot [ ";
	listattackAS.killprint();
	cout << "] " << endl;
	cout << "AM " << AMID << " shot [ ";
	listattackAM.killprint();
	cout << "] " << endl;
	ADID1 = AArmy->getAD1id();
	ADID2 = AArmy->getAD2id();
	cout << "AD " << ADID1<<" & "<<ADID2<< " shot [ ";
	listattackAD.killprint();
	cout << "] " << endl;
	cout << "                                                                                                                      " << endl;
	cout << "                                                                                                                      " << endl;
	cout << "===========================================Unit Maintainance lists====================================================" << endl;
	cout << "UML1 For soldiers: [";
	UML1.print();
	cout << "] " << endl;
	cout << "UML2 For tanks: [";
	UML2.print();
	cout << "] " << endl;
	cout << "=========================================Killed/Destructed Units======================================================" << endl;
	cout << Killedlist.getcount() << " units";
	cout << "[ ";
	Killedlist.print();
	cout << "]";
	cout << "                                                                                                                     " << endl;
	cout << "                                                                                                                     " << endl;
	cout << "Press Any Key to move to next timestep" << endl;
	//cin.get();
}

int Game::gettimestep()
{
	return timestep;
}

EarthArmy* Game::getEarthArmy()
{
	return EArmy;
}

AlienArmy* Game::getalienarmy()
{
	return AArmy;
}

void Game::addtokilled(Unit* u)
{
	Killedlist.enqueue(u);
}

void Game::attack()
{
	EArmy->attack(*this);
	AArmy->attack(*this);
}

void Game::incrementwait()
{
	///incrementing wait time for soldiers//
	ES* soldier1 = nullptr;
	LinkedQueue<ES*> temp1;
	while (UML1.dequeue(soldier1))
	{
		soldier1->incrementwaittime();
		temp1.enqueue(soldier1);
	}
	while (temp1.dequeue(soldier1))
	{
		UML1.enqueue(soldier1);
	}
	/// incrementing waittime for tanks///
	priQueue<ET*>temp;
	ET* tank = nullptr;
	int pri = 0;
	while (UML2.dequeue(tank, pri))
	{
		tank->incrementwaittime();
		temp.enqueue(tank, pri);
	}
	ET* tank2 = nullptr;
	int pri2 = 0;
	while (temp.dequeue(tank2, pri2))
	{
		UML2.enqueue(tank2, pri2);
	}
}
void Game::addtoattackES(int n)
{
	listattackES.enqueue(n);
}
void Game::addtoattackET(int n)
{
	listattackET.enqueue(n);
}
void Game::addtoattackEG(int n)
{
	listattackEG.enqueue(n);
}
void Game::addtoattackAS(int n)
{
	listattackAS.enqueue(n);
}
void Game::addtoattackAM(int n)
{
	listattackAM.enqueue(n);
}
void Game::addtoattackAD(int n)
{
	listattackAD.enqueue(n);
}

void Game::clearlists()
{
	int x;
	while (listattackES.dequeue(x))
	{
		x = 1;
	}
	while (listattackEG.dequeue(x))
	{
		x = 1;
	}
	while (listattackET.dequeue(x))
	{
		x = 1;
	}
	while (listattackAS.dequeue(x))
	{
		x = 1;
	}
	while (listattackAM.dequeue(x))
	{
		x = 1;
	}
	while (listattackAD.dequeue(x))
	{
		x = 1;
	}
	ESID = 0;
	ASID = 0;
	EGID = 0;
	ETID = 0;
	ADID1 = 0;
	ADID2 = 0;
	AMID = 0;

}

void Game::setESID(int n)
{
	ESID = n;
}
void Game::setETID(int n)
{
	ETID = n;
}void Game::setEGID(int n)
{
	EGID = n;
}void Game::setASID(int n)
{
	ASID = n;
}void Game::setAMID(int n)
{
	AMID = n;
}

LinkedQueue<ES*> Game::getUML1()
{
	return UML1;
}

priQueue<ET*> Game::getUML2()
{
	return UML2;
}

void Game::addtoUML1(ES* soldier)
{
	UML1.enqueue(soldier);
}
void Game::addtoUML2(ET* tank,int pri)
{
	UML2.enqueue(tank,pri);
}

void Game::produceoutput(string filename)
{
	int sumearthdf=0, sumearthDd=0, sumearthDb=0;
	int sumaliendf = 0, sumalienDd = 0, sumalienDb = 0;
	int earthcount = 1;
	int aliencount = 1;
	int killedcount = Killedlist.getcount();
	ofstream outputfile(filename);
	if (outputfile.is_open())
	{
		outputfile << "Td    ID    Tj      Ta    Df    Dd    Db\n";
		Unit* killedunit = nullptr;
		while (Killedlist.dequeue(killedunit))
		{
			int Df = killedunit->getfirstattacked() - killedunit->getjointime();
			int Dd = killedunit->getdestructed() - killedunit->getfirstattacked();
			int Db = Df + Dd;
			if (killedunit->getid() > 2000)
			{
				sumaliendf = sumaliendf + Df;
				sumalienDd = sumalienDd + Dd;
				sumalienDb = sumalienDb + Db;
				aliencount++;
			}
			else if(killedunit->getid()<2000)
			{
				sumearthdf = sumearthdf + Df;
				sumearthDd = sumearthDd + Dd;
				sumearthDb = sumearthDb + Db;
				earthcount++;
			}
			
			outputfile << killedunit->getdestructed() << "    " << killedunit->getid() << "    " << killedunit->getjointime() << "    " << killedunit->getfirstattacked() << "    " << Df << "    " << Dd << "    " << Db << "\n";
		}
		outputfile << "Battle Result: ";
		if (state == 2)
		{
			outputfile << "WIN\n";
		}
		else if (state == 1)
		{
			outputfile << "LOSS\n";
		}
		else if (state == 3)
		{
			outputfile << "Drawn\n";
		}
		double averageearthDf = sumearthdf / earthcount;
		double averageearthDd = sumearthDd / earthcount;
		double averageearthDb = sumearthDb / earthcount;
		int x = EArmy->getES_destruct();
		int y = EArmy->getES_total();
		float z = (x*100) / y;
		/*int egdestruct = EArmy->getEG_destruct();
		int egtotal = EArmy->getEG_total();*/
		float w = (EArmy->getEG_destruct()*100) / EArmy->getEG_total();
		
		float m = (EArmy->getET_destruct()*100) / EArmy->getET_total();
		int totaldestructed = EArmy->gettotaldestructed();
		int total = EArmy->gettotal();
		float tdt = (totaldestructed*100) / total;
		outputfile << "Earth Army Stats:\n";
		outputfile << "Total ES Units: " << EArmy->getES_total() << "\n";
		outputfile << "Total EG units: " << EArmy->getEG_total() << "\n";
		outputfile << "Total ET units: " << EArmy->getET_total() << "\n";
		outputfile << "Percentage of destructed ES = " << z<< " %\n";
		outputfile << "Percentage of destructed EG = " << w<< " %\n";
		outputfile << "Percentage of destructed ET = " << m<< " %\n";
		double healedper = (EArmy->gettotalhealed() * 100) / EArmy->gettotal();
		outputfile << "Percentage of Healed = " << healedper << "% \n";
		outputfile << "Percentage of Total destructed = " << tdt<< "%\n";
		outputfile << "Average of Df: " << averageearthDf << "\n";
		outputfile << "Average of Dd: " << averageearthDd<< "\n";
		outputfile << "Average of Db: " << averageearthDb << "\n";
		double q = averageearthDf / averageearthDb;
		outputfile << "Df/Db = " << q*100<< "% \n";
		double q2 = averageearthDd / averageearthDb;
		outputfile << "Dd/Db =" << q2*100 <<"%" << "\n";
		outputfile << "                                                                    \n";
		outputfile << "\nAlien Army Stats: \n";
		outputfile << "Total AS units: " << AArmy->getAS_total() << "\n";
		outputfile << "Total AM units: " << AArmy->getAM_total() << "\n";
		outputfile << "Total AD units: " << AArmy->getAD_total() << "\n";
		int asdes = AArmy->getAS_destruct();
		int astot = AArmy->getAS_total();
		double ASdestructpercent = (AArmy->getAS_destruct() * 100) / AArmy->getAS_total();
		outputfile << "Percentage of destructed AS = " << ASdestructpercent << "% \n";
		int amdes = AArmy->getAM_destruct();
		int amtot = AArmy->getAM_total();
		double AMdestructpercent= (AArmy->getAM_destruct()*100)/ AArmy->getAM_total();
		outputfile << "Percentage of destructed AM = " << AMdestructpercent << "% \n";
		int ad_des = AArmy->getAD_destruct();
		int adx = AArmy->getADcount();
		int adtot = AArmy->getAD_total();
		if (adx == 0)
		{
			ad_des = adtot;
		}
		else if (ad_des > adtot)
		{
			ad_des = adtot;
		}
		double ADdestructpercent= ad_des*100/adtot;
		outputfile << "Percentage of destructed AD = " << ADdestructpercent << "%\n";
		double averagealiendf = sumaliendf / aliencount;
		double averagealiendd = sumalienDd / aliencount;
		double averagealiendb = sumalienDb / aliencount;
		outputfile << "Average of Df: " << averagealiendf << "\n";
		outputfile << "Average of Dd: " << averagealiendd << "\n";
		outputfile << "Average of Db: " << averagealiendb << "\n";
		double av1= averagealiendf / averagealiendb;
		double av2 = averagealiendd / averagealiendb;
		outputfile << "Df/Db = " << av1* 100<<"%\n";
		if (av2 < 0)
		{
			av2 = 0;
		}
		outputfile << "Dd/Db = " << av2* 100<<"%\n";
		outputfile.close();
		cout << "Simulation Ended \nOutputfile is Produced Successfully" << endl;
	}
}

ES* Game::removefromUML1()
{
	ES* sol = nullptr;
	UML1.dequeue(sol);
	if (sol != nullptr)
	{
		return sol;
	}
	else
	{
		return nullptr;
	}
}

ET* Game::removefromUML2(int& x)
{
	ET* tank = nullptr;
	UML2.dequeue(tank, x);
	if (tank != nullptr)
	{
		return tank;
	}
}

int Game::getUML1count()
{
	return UML1.getcount();
}int Game::getUML2count()
{
	return UML2.getcount();
}

void Game::clearUML1()
{
	ES* sol = nullptr;
	while (UML1.dequeue(sol))
	{
		sol->setdestructed(timestep);
		addtokilled(sol);
		EArmy->incrementES_destruct();
	}
}

void Game::clearUML2()
{
	ET* tank = nullptr;
	int p = 0;
	while (UML2.dequeue(tank, p))
	{
		EArmy->incrementET_destruct();
		tank->setdestructed(timestep);
		addtokilled(tank);

	}
}







