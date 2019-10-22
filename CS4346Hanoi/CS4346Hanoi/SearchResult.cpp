#include "SearchResult.h"

SearchResult::SearchResult(ResultType type)
{
	rtype = type;
}

SearchResult::~SearchResult()
{
}

ResultType SearchResult::getType()
{
	return rtype;
}

bool SearchResult::isSuccess()
{
	return (rtype == ResultType::RESULT_SUCCESS);
}

bool SearchResult::isFailure()
{
	return (rtype == ResultType::RESULT_FAILURE);
}

int SearchResult::getSize()
{
	return nodes.size();
}

SearchNode SearchResult::getNode(int index)
{
	return nodes.at(index);
}

bool SearchResult::addNode(SearchNode * nptr)
{
	bool flag = false;
	if (nptr != nullptr)
	{
		SearchNode n = *(nptr);
		nodes.push_back(n);
		flag = true;
	}
	return flag;
}
