#include "GameState.h"

GameState::GameState()
{
	init(0);
}

GameState::GameState(short totalGameDiscs)
{
	this->init(totalGameDiscs);
}


GameState::~GameState()
{
}

void GameState::init(short totalDiscs)
{
	tA.setName("A");
	tB.setName("B");
	tC.setName("C");

	tA.init(totalDiscs);
}

Tower GameState::getTower(TowerSelection t)
{
	Tower tow;
	if (t == TOWER_A)
	{
		tow = tA;
	}
	else if (t == TOWER_B)
	{
		tow = tB;
	}
	else if (t == TOWER_C)
	{
		tow = tC;
	}
	return tow;
}

bool GameState::move(TowerSelection start, TowerSelection goal)
{
	bool flag = false;

	if (start != goal)
	{
		short disc = SHRT_MAX;
		Tower startTower;
		Tower goalTower;

		//parse selections
		switch (start)
		{
		case TOWER_A: startTower = tA; break;
		case TOWER_B: startTower = tB; break;
		case TOWER_C: startTower = tC; break;
		}

		switch (goal)
		{
		case TOWER_A: goalTower = tA; break;
		case TOWER_B: goalTower = tB; break;
		case TOWER_C: goalTower = tC; break;
		}

		//get top disc value from start tower
		disc = startTower.peek();

		//check if action would be valid on goal tower
		flag = goalTower.isValidAction(disc);

		if (flag == true) //take action if valid
		{
			disc = startTower.takeDisc();
			goalTower.addDisc(disc);

			//save changes
			switch (start)
			{
			case TOWER_A: tA = startTower; break;
			case TOWER_B: tB = startTower; break;
			case TOWER_C: tC = startTower; break;
			}
			switch (goal)
			{
			case TOWER_A: tA = goalTower; break;
			case TOWER_B: tB = goalTower; break;
			case TOWER_C: tC = goalTower; break;
			}
		}
	}

	return flag; //return whether the action was completed or not
}
