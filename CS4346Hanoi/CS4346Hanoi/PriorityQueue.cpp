#include "PriorityQueue.h"

SearchNode* PriorityQueue::peek()
{
	return contents.front();
}

SearchNode* PriorityQueue::peekAt(int index)
{
	if (index < contents.size())
	{
		SearchNode* result;
		list<SearchNode*>::iterator i = contents.begin();
		for (int num = 0; num < index; ++num) { ++i; /*increment iterator*/ }
		result = *i;
		return result;
	}
	else
	{
		//throw an exception
		//TODO
	}
}

SearchNode* PriorityQueue::pop()
{
	SearchNode* front = contents.front();
	contents.pop_front();
	return front;
}

void PriorityQueue::add(SearchNode* n)
{
	int fScore = n->getF();
	if (isEmpty() == false)
	{
		list<SearchNode*>::iterator index = contents.begin();
		bool hitEnd = false;
		bool inserted = false;
		do
		{
			int currFScore = (*index)->getF();
			if (currFScore > fScore)
			{
				contents.insert(index, n); 
				//inserts SearchNode n in the list just BEFORE the current element pointed to by index
				inserted = true;
			}
			++index; //incr iterator
			hitEnd = (index == contents.end());
		} while (hitEnd == false && inserted == false);
		if (hitEnd == true && inserted == false)
		{//if the end of list is reached and no position was found, put n at back of list
			contents.push_back(n);
		}
	}
	else
	{//if list is empty, just add n to list
		contents.push_front(n);
	}
}

void PriorityQueue::clear()
{
	if (contents.empty() == false)
	{
		for (int i = 0; i < contents.size(); ++i)
		{
			SearchNode* currptr = this->peekAt(i);
			if (currptr != nullptr) { delete currptr; }
		}
		//after deleting any SearchNodes pointed to by pointers remaining in the Queue, clear the Queue of hanging pointers
		contents.clear();
	}
}

int PriorityQueue::getSize()
{
	return contents.size();
}

bool PriorityQueue::isEmpty()
{
	return contents.empty();
}

PriorityQueue::PriorityQueue()
{

}


PriorityQueue::~PriorityQueue()
{

}
