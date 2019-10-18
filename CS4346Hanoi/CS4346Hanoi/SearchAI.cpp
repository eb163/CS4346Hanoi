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
	//set up the goalState for comparison
	//call the search function
}

void SearchAI::search(GameState initialState, GameState goalState)
{
	//psuedocode of the search process
	//intialize the open nodes container (frontier)
	//initialize the closed nodes container
	
	//while open is not empty

	//get the next node in the open container

	//compare if the current node matches the goal node

	//else generate moves from this node

	//for each generated move
	//check if this move is in the open or closed trees
	//if the current move is not in open or closed
	//expand this node
}
