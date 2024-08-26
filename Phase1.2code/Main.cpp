#include<iostream>
using namespace std;
#include"Game.h"
int main()
{
	srand((unsigned)time(0));
	Game& game = Game::getinstance(1);
	game.simulate();
	return 0;
}