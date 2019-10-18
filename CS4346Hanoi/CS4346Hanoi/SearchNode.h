#pragma once
#include "GameState.h"

/*
SearchNode is the basic element for the search tree which the sarch AIs will use
*/

class SearchNode
{
private:
	GameState state;
	int g;
	int h;
public:
	SearchNode();
	~SearchNode();

	GameState getState();
	int getG();
	int getH();

	void setG(int n);
	void setH(int n);
};

