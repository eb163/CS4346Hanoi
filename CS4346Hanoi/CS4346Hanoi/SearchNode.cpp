#include "SearchNode.h"



SearchNode::SearchNode()
{
}


SearchNode::~SearchNode()
{
}

GameState SearchNode::getState()
{
	return state;
}

int SearchNode::getG()
{
	return g;
}

int SearchNode::getH()
{
	return h;
}

void SearchNode::setG(int n)
{
	if (n > -1)
	{
		g = n;
	}
}

void SearchNode::setH(int n)
{
	if (n > -1)
	{
		h = n;
	}
}
