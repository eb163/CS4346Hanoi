#pragma once
#include "Tower.h"

/*

A class for containing all three Tower states for the game.

*/

enum TowerSelection {TOWER_A = 0, TOWER_B = 1, TOWER_C = 2};

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

	Tower getTower(TowerSelection tower); //returns a copy of the tower data structure

	bool move(TowerSelection start, TowerSelection goal); 
	//move the top disk from start to goal
	//return true if the operation was valid
	//or return false if the operation was invalid
};

