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
