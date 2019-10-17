#pragma once
#include "Tower.h"

/*

A class for containing all three Tower states for the game.

*/

class GameState
{
private:
	Tower tA;
	Tower tB;
	Tower tC;
public:
	GameState();
	GameState(short totalGameDiscs);
	~GameState();

	void init(short totalDiscs);
};

