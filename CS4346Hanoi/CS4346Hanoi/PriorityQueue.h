#pragma once
#include "GameState.h"
#include "SearchNode.h"
#include <list> //used for the constant time insertion and deletion operations

/*
The PriorityQueue is a container for holding SearchNodes. 
The PriorityQueue uses the F values of Nodes as a key to order by.
The SearchNode with the lowest F value is located at the front.
*/

using std::list;

class PriorityQueue
{
private:
	list<SearchNode> contents;
protected:

public:
	SearchNode peek();
	SearchNode peekAt(int index);
	SearchNode pop();
	void add(SearchNode n);
	void clear(); //whipe contents of PriorityQueue
	int getSize();
	bool isEmpty();
	PriorityQueue();
	~PriorityQueue();
};

