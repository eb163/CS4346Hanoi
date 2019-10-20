#pragma once
#include "SearchNode.h"
#include "GameState.h"
#include "PriorityQueue.h"
#include "scoreFunctions.h"
#include <vector>
#include <queue> //for priority_queue

/*
SearchAI is a generic base class to be used to define an interface which both the A* search and the RBF search strategies will inherit and use.
*/

using std::vector;
using std::priority_queue;

class SearchAI
{
private:
	PriorityQueue openNodes;
	vector<SearchNode> closedNodes;
	GameState goalState;

protected:
	bool isOpen(SearchNode n); //searches openNodes for a Node that matches n
	bool isClosed(SearchNode n); //searches closedNodes for a Node that matches n
	void compareNodes(SearchNode n1, SearchNode n2);

public:
	SearchAI();
	~SearchAI();

	virtual void startSearch(GameState initialState, GameState goalState); //pass the starting state and goal state for starting the search
	virtual void search(GameState initialState, GameState goalState);
};

