#pragma once
#include <vector>
#include "SearchNode.h"
#include "GameState.h"

/*
SearchResult is a class used for returning results of a search.
A search can either be successful or a failure (ResultType)
If a SearchResult is a success, it also holds: 
The inital SearchNode (located at Path[0]) *
The goal SearchNode (located at Path[size - 1]) *

*Note: Need to decide how the vector holding the path will be organized. Will it be inital at front, goal at back, or goal at front, initial at back?

the path from an inital SearchNode to a goal SearchNode
all SearchNodes are copies from the SearchAI's heap. this is so that Searchresult instances can remain valid after the SearchAI has deallocated all SearchNodes.
the size of the path
the total cost of the path (an accumulation of F scores)
*/

enum ResultType {RESULT_FAILURE = 0, RESULT_SUCCESS = 1};

class SearchResult
{
private:
	ResultType rtype;
	vector<SearchNode> nodes;

public:
	SearchResult(ResultType type);
	~SearchResult();
	ResultType getType();
	bool isSuccess();
	bool isFailure();
	int getSize();	//return how many nodes are in the path (this is equivalent to moveCount + 1, since initialNode is included)
	SearchNode getInitialNode();
	SearchNode getGoalNode();
	SearchNode getNode(int index);

	bool addNode(SearchNode* nptr); //creates a copy of nptr's SearchNode and pushes it to the back of the nodes vector
};

