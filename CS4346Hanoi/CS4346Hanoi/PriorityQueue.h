#pragma once
#include "GameState.h"
#include "SearchNode.h"
#include <list> //used for the constant time insertion and deletion operations

/*
The PriorityQueue is a container for holding SearchNode pointers. 
The PriorityQueue uses the F values of Nodes as a key to order the list.
The SearchNode pointer with the lowest F value is located at the front.
*/

using std::list;

class PriorityQueue
{
private:
	list<SearchNode*> contents;
protected:

public:
	SearchNode* peek();
	SearchNode* peekAt(int index);
	SearchNode* pop();
	void add(SearchNode* n);
	void clear(); //whipe contents of PriorityQueue
	int getSize();
	bool isEmpty();
	PriorityQueue();
	~PriorityQueue();
};

