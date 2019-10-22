#pragma once
#include "SearchNode.h"
#include "GameState.h"
#include "PriorityQueue.h"
#include "SearchResult.h"
#include "scoreFunctions.h"
#include <vector>
#include <queue>

/*
SearchAI is a generic base class to be used to define an interface which both the A* search and the RBF search strategies will inherit and use.
*/

using std::vector;
using std::priority_queue;

class SearchAI
{
private:
	PriorityQueue openNodes;
	vector<SearchNode*> closedNodes;
	SearchNode goalNode;
	//GameState goalState;

protected:
/*
	bool isOpen(SearchNode n); //searches openNodes for a Node that matches n
	bool isClosed(SearchNode n); //searches closedNodes for a Node that matches n
	bool compareNode(SearchNode n1, SearchNode n2); //returns true if n1 and n2 are exactly the same
	vector<SearchNode> generateMoves(SearchNode curr); //generate a set of SearchNodes based on the state of the passed SearchNode
*/

	void clearOpenNodes();
	void clearClosedNodes();

public:
	SearchAI();
	~SearchAI();

	virtual SearchResult search(GameState initialState, GameState goalState); //pass the starting state and goal state for starting the search

	bool isOpen(SearchNode* n); //searches openNodes for a Node that matches n
	bool isClosed(SearchNode* n); //searches closedNodes for a Node that matches n
	bool compareNode(SearchNode* n1, SearchNode* n2); //returns true if n1 and n2 are exactly the same
	vector<SearchNode*> generateMoves(SearchNode* curr); //generate a set of SearchNodes based on the state of the passed SearchNode

	void addNodeToOpen(SearchNode* n); //add a node to open (primarily for testing isOpen)
	void addNodeToClosed(SearchNode* n); //add a Node to closed (priarily for testing isClosed)

	void clear(); //for clearing heap without calling a new search
};

