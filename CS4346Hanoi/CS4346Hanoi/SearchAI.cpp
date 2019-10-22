#include "SearchAI.h"

bool SearchAI::compareNode(SearchNode n1, SearchNode n2) //INCOMPLETE, TODO
{
	bool matches = false;
	bool hMatch = false, tAMatch = false, tBMatch = false, tCMatch = false;
	//compare the h values of the two game states
	if (n1.getH() == n2.getH())
	{
		hMatch = true;
		GameState gs1 = n1.getState();
		GameState gs2 = n2.getState();
		
		//compare the 3 towers of the two game states
		Tower gs1T = gs1.getTower(TowerSelection::TOWER_A);
		Tower gs2T = gs2.getTower(TowerSelection::TOWER_A);
		if (gs1T.getSize() == gs2T.getSize())
		{
			tAMatch = true;
			for (int i = 0; i < gs1T.getSize(); ++i) //compare each element in Tower A
			{
				if (gs1T.peekAt(i) != gs2T.peekAt(i))
				{
					tAMatch = false;
					i = gs1T.getSize() + 1; //end loop early
				}
			}
		}

		gs1T = gs1.getTower(TowerSelection::TOWER_B);
		gs2T = gs2.getTower(TowerSelection::TOWER_B);
		if (gs1T.getSize() == gs2T.getSize())
		{
			tBMatch = true;
			for (int i = 0; i < gs1T.getSize(); ++i) //compare each element in Tower B
			{
				if (gs1T.peekAt(i) != gs2T.peekAt(i))
				{
					tBMatch = false;
					i = gs1T.getSize() + 1; //end loop early
				}
			}
		}

		gs1T = gs1.getTower(TowerSelection::TOWER_C);
		gs2T = gs2.getTower(TowerSelection::TOWER_C);
		if (gs1T.getSize() == gs2T.getSize())
		{
			tCMatch = true;
			for (int i = 0; i < gs1T.getSize(); ++i) //compare each element in Tower C
			{
				if (gs1T.peekAt(i) != gs2T.peekAt(i))
				{
					tCMatch = false;
					i = gs1T.getSize() + 1; //end loop early
				}
			}
		}

	}

	return (hMatch && tAMatch && tBMatch&& tCMatch);
}

vector<SearchNode> SearchAI::generateMoves(SearchNode curr)
{
	vector<SearchNode> moves;

	//look at the current state
	GameState currState = curr.getState();

	//all possible moves consist of all combinations of moving the top disc from
	//one tower to the two other towers

	//algorithm for generating moves

	//for each Tower in currentState
	Tower srcTower;
	Tower destTower1, destTower2;

	//check A with B and C
	srcTower = currState.getTower(TowerSelection::TOWER_A);
	destTower1 = currState.getTower(TowerSelection::TOWER_B);
	destTower2 = currState.getTower(TowerSelection::TOWER_C);

	//check if current Tower holds any discs
	if (srcTower.getSize() > 0)
	{
		bool flagSrcToD1 = destTower1.isValidAction(srcTower.peek());
		bool flagSrcToD2 = destTower2.isValidAction(srcTower.peek());
		//if moves are valid
		//generate a new GameState and make the move
		if (flagSrcToD1)
		{
			//generate move
			GameState newgs = currState;
			newgs.move(TowerSelection::TOWER_A, TowerSelection::TOWER_B);

			//store move in a search node
			SearchNode newnode;
			newnode.setState(newgs);
			newnode.setG(curr.getG() + 1);
			newnode.setH(scoreGameState(newgs));

			//load node into moves vector
			moves.push_back(newnode);
		}
		if (flagSrcToD2)
		{
			//generate move
			GameState newgs = currState;
			newgs.move(TowerSelection::TOWER_A, TowerSelection::TOWER_C);

			//store move in a search node
			SearchNode newnode;
			newnode.setState(newgs);
			newnode.setG(curr.getG() + 1);
			newnode.setH(scoreGameState(newgs));

			//load node into moves vector
			moves.push_back(newnode);
		}
	}

	//check B with A and C
	srcTower = currState.getTower(TowerSelection::TOWER_B);
	destTower1 = currState.getTower(TowerSelection::TOWER_A);
	destTower2 = currState.getTower(TowerSelection::TOWER_C);

	//check if current Tower holds any discs
	if (srcTower.getSize() > 0)
	{
		bool flagSrcToD1 = destTower1.isValidAction(srcTower.peek());
		bool flagSrcToD2 = destTower2.isValidAction(srcTower.peek());
		//if moves are valid
		//generate a new GameState and make the move
		if (flagSrcToD1)
		{
			//generate move
			GameState newgs = currState;
			newgs.move(TowerSelection::TOWER_B, TowerSelection::TOWER_A);

			//store move in a search node
			SearchNode newnode;
			newnode.setState(newgs);
			newnode.setG(curr.getG() + 1);
			newnode.setH(scoreGameState(newgs));

			//load node into moves vector
			moves.push_back(newnode);
		}
		if (flagSrcToD2)
		{
			//generate move
			GameState newgs = currState;
			newgs.move(TowerSelection::TOWER_B, TowerSelection::TOWER_C);

			//store move in a search node
			SearchNode newnode;
			newnode.setState(newgs);
			newnode.setG(curr.getG() + 1);
			newnode.setH(scoreGameState(newgs));

			//load node into moves vector
			moves.push_back(newnode);
		}
	}

	//check C with A and B
	srcTower = currState.getTower(TowerSelection::TOWER_C);
	destTower1 = currState.getTower(TowerSelection::TOWER_A);
	destTower2 = currState.getTower(TowerSelection::TOWER_B);

	//check if current Tower holds any discs
	if (srcTower.getSize() > 0)
	{
		bool flagSrcToD1 = destTower1.isValidAction(srcTower.peek());
		bool flagSrcToD2 = destTower2.isValidAction(srcTower.peek());
		//if moves are valid
		//generate a new GameState and make the move
		if (flagSrcToD1)
		{
			//generate move
			GameState newgs = currState;
			newgs.move(TowerSelection::TOWER_C, TowerSelection::TOWER_A);

			//store move in a search node
			SearchNode newnode;
			newnode.setState(newgs);
			newnode.setG(curr.getG() + 1);
			newnode.setH(scoreGameState(newgs));

			//load node into moves vector
			moves.push_back(newnode);
		}
		if (flagSrcToD2)
		{
			//generate move
			GameState newgs = currState;
			newgs.move(TowerSelection::TOWER_C, TowerSelection::TOWER_B);

			//store move in a search node
			SearchNode newnode;
			newnode.setState(newgs);
			newnode.setG(curr.getG() + 1);
			newnode.setH(scoreGameState(newgs));

			//load node into moves vector
			moves.push_back(newnode);
		}
	}

	//total possible moves generated: 2 + 2 + 2 = 6 moves maximum per game state

	return moves;
}

void SearchAI::addNodeToOpen(SearchNode n)
{
	openNodes.add(n);
}

void SearchAI::addNodeToClosed(SearchNode n)
{
	closedNodes.push_back(n);
}

bool SearchAI::isOpen(SearchNode n)
{
	bool flag = false;

	for (int i = 0; i < openNodes.getSize(); ++i)
	{
		flag = compareNode(n, openNodes.peekAt(i));
		if (flag == true) { i = openNodes.getSize() + 1; /* end loop early */ }
	}

	return flag;
}

bool SearchAI::isClosed(SearchNode n)
{
	bool flag = false;

	for (int i = 0; i < closedNodes.size(); ++i)
	{
		flag = compareNode(n, closedNodes.at(i));
		if (flag == true) { i = closedNodes.size() + 1; /* end loop early */ }
	}

	return flag;
}

SearchAI::SearchAI()
{
}


SearchAI::~SearchAI()
{
}

void SearchAI::search(GameState initialState, GameState goalState)
{
	//setup the initialNode in the tree
	SearchNode rootNode;
	rootNode.setState(initialState);
	rootNode.setG(0);
	rootNode.setH(scoreGameState(initialState));

	//set up the goalNode for comparison
	//this->goalState = goalState;
	goalNode.setState(goalState);
	goalNode.setH(scoreGameState(goalState));

	//intialize the open nodes container
	if (openNodes.isEmpty() == false)
	{
		openNodes.clear();
	}

	//initialize the closed nodes container
	if (closedNodes.empty() == false)
	{
		closedNodes.clear();
	}

	//add the root node to open
	openNodes.add(rootNode);

	//run search loop
	do
	{
		SearchNode currN = openNodes.pop(); //get the top from the queue

		//compare currN with goal
		bool isGoal = compareNode(currN, goalNode);

		//if currN is goal node, stop search and return success
		if (isGoal == true)
		{

		}

		//else
		else
		{
			//generate children from currN
			vector<SearchNode> moves = generateMoves(currN);
			for (int i = 0; i < moves.size(); ++i)
			{
				//evaluate children
				//evaluation is done during generation

				//check if any children are already in open or closed
				bool inOpen = isOpen(moves.at(i));
				bool inClosed = isClosed(moves.at(i));

				//add any children not already in a queue to open queue
				if ((inOpen == false) && (inClosed == false))
				{
					addNodeToOpen(moves.at(i));
				}
			}
			moves.clear();
		}

		//repeat loop

	} while (openNodes.isEmpty() == false);
}
