#pragma once
#include "GameState.h"
/*
SearchAI is a generic base class to be used to define an interface which both the A* search and the RBF search strategies will inherit and use.
*/

class SearchAI
{
private:

public:
	SearchAI();
	~SearchAI();

	virtual void startSearch(GameState initialState, GameState goalState); //pass the starting state and goal state for starting the search
	virtual void search(GameState initialState, GameState goalState);
};

