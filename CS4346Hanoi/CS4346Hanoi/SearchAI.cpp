#include "SearchAI.h"



SearchAI::SearchAI()
{
}


SearchAI::~SearchAI()
{
}

void SearchAI::startSearch(GameState initialState, GameState goalState)
{
	//setup the initialNode in the tree
	SearchNode rootNode;
	rootNode.setState(initialState);
	rootNode.setG(0);
	rootNode.setH(scoreGameState(initialState));

	//set up the goalState for comparison
	this->goalState = goalState;

	//intialize the open nodes container
	if (openNodes.empty() == false)
	{
		openNodes.clear();
	}

	//initialize the closed nodes container
	if (closedNodes.empty() == false)
	{
		closedNodes.clear();
	}

	//add the root node to open
	openNodes.push_back(rootNode);

	//run search loop
	do
	{
		SearchNode currN = openNodes.front();
	} while (openNodes.empty() == false);
}

void SearchAI::search(GameState initialState, GameState goalState)
{
	//psuedocode of the search process
	
	//while open is not empty

	//get the next node in the open container

	//compare if the current node matches the goal node

	//else generate moves from this node

	//for each generated move
	//check if this move is in the open or closed trees
	//if the current move is not in open or closed
	//expand this node
}
